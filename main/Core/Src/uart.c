/*
 * uart.c
 *
 *  Created on: Nov 25, 2025
 *      Author: Trung Hieu
 */
#include "uart.h"
#include "string.h"

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;
uint8_t str[32]; // tăng size để chứa ADC chuỗi dài hơn

uint32_t ADC_value = 0;

enum CommandType command_data = NONE;
uint8_t command_flag = 0;

enum UartCommunicationState FSM_UART_STATE = INIT;
enum CommandParserState FSM_CMD_PARSER_STATE = CMD_WAIT;

// Khởi tạo UART interrupt lần đầu (gọi ở main)
void uart_init_interrupt() {
    temp = 0;
    HAL_UART_Receive_IT(&huart2, &temp, 1);
}

// Callback khi nhận 1 byte
void get_uart_message(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART2)
    {
        // Lưu byte vào buffer
        buffer[index_buffer++] = temp;
        if (index_buffer >= MAX_BUFFER_SIZE) index_buffer = 0;
        buffer_flag = 1;

        // Echo lại byte vừa nhận
        HAL_UART_Transmit(&huart2, &temp, 1, HAL_MAX_DELAY);

        // Kích hoạt lại interrupt
        HAL_UART_Receive_IT(&huart2, &temp, 1);
    }
}

// FSM xử lý command
void fsm_command_parser()
{
    switch (FSM_CMD_PARSER_STATE) {
        case CMD_WAIT:
            if (temp == '!') // bắt đầu lệnh
            {
                index_buffer = 0;
                FSM_CMD_PARSER_STATE = CMD_GET;
            }
            break;

        case CMD_GET:
            if (temp == '#') // kết thúc lệnh
            {
                buffer[index_buffer] = '\0'; // terminate string
                if (strncmp((char*)buffer, "RST", 3) == 0)
                {
                    command_data = RST;
                    command_flag = 1;
                }
                else if (strncmp((char*)buffer, "OK", 2) == 0)
                {
                    command_data = OK;
                    command_flag = 1;
                }
                FSM_CMD_PARSER_STATE = CMD_WAIT;
            }
            break;

        default:
            FSM_CMD_PARSER_STATE = CMD_WAIT;
            break;
    }
}

// FSM UART chính
void fsm_uart_communication()
{
    switch (FSM_UART_STATE) {
        case INIT:
            FSM_UART_STATE = WAITING;
            break;

        case WAITING:
            if (command_flag == 1 && command_data == RST)
            {
                ADC_value = HAL_ADC_GetValue(&hadc1);
                sprintf((char*)str, "!ADC=%ld#\r\n", ADC_value);

                command_flag = 0;
                FSM_UART_STATE = SENDING;
            }
            break;

        case SENDING:
        {
            uint8_t len = strlen((char*)str);
            HAL_UART_Transmit(&huart2, str, len, HAL_MAX_DELAY);

            setTimer(0, 3000); // set timer 3s
            FSM_UART_STATE = WAIT_ACK;
            break;
        }

        case WAIT_ACK:
            if (command_flag == 1 && command_data == OK)
            {
                command_flag = 0;
                FSM_UART_STATE = WAITING;
            }
            else if (isFlag(0)) // timeout → resend
            {
                FSM_UART_STATE = SENDING;
            }
            break;

        default:
            FSM_UART_STATE = INIT;
            break;
    }
}

