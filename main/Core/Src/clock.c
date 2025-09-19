/*
 * clock.c
 *
 *  Created on: Sep 19, 2025
 *      Author: Trung Hieu
 */
#include "clock.h"


GPIO_TypeDef* LED_PORT[12] = {
    LED_1_GPIO_Port, LED_2_GPIO_Port, LED_3_GPIO_Port, LED_4_GPIO_Port,
    LED_5_GPIO_Port, LED_6_GPIO_Port, LED_7_GPIO_Port, LED_8_GPIO_Port,
    LED_9_GPIO_Port, LED_10_GPIO_Port, LED_11_GPIO_Port, LED_12_GPIO_Port
};


uint16_t LED_PIN[12] = {
    LED_1_Pin, LED_2_Pin, LED_3_Pin, LED_4_Pin,
    LED_5_Pin, LED_6_Pin, LED_7_Pin, LED_8_Pin,
    LED_9_Pin, LED_10_Pin, LED_11_Pin, LED_12_Pin
};

//  EX 6
void testAllLEDs(void)
{
    for (int i = 0; i < 12; i++) {
        HAL_GPIO_WritePin(LED_PORT[i], LED_PIN[i], GPIO_PIN_SET);
        HAL_Delay(200);
        HAL_GPIO_WritePin(LED_PORT[i], LED_PIN[i], GPIO_PIN_RESET);
    }
}

// EX 7
void clearAllClock(void)
{
    for (int i = 0; i < 12; i++) {
        HAL_GPIO_WritePin(LED_PORT[i], LED_PIN[i], GPIO_PIN_RESET);
    }
}

// EX 8
void setNumberOnClock(int num)
{
    if (num >= 0 && num < 12) {
        HAL_GPIO_WritePin(LED_PORT[num], LED_PIN[num], GPIO_PIN_SET);
    }
}

// EX 9
void clearNumberOnClock(int num)
{
    if (num >= 0 && num < 12) {
        HAL_GPIO_WritePin(LED_PORT[num], LED_PIN[num], GPIO_PIN_RESET);
    }
}

