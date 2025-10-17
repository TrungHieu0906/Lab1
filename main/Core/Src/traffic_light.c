/*
 * traffic_light.c
 *
 *  Created on: Oct 17, 2025
 *      Author: Trung Hieu
 */
#include "traffic_light.h"

enum TrafficLightState TRAFFIC_LIGHT_STATE = INIT;

void fsm_traffic_light()
{
	switch (TRAFFIC_LIGHT_STATE) {
		case INIT:
			// TODO

			// CHANGE STATE
			if (1) // -> AUTO_RED_GRN
			{
				init_auto_red_grn();
				TRAFFIC_LIGHT_STATE = AUTO_RED_GRN;
			}
			break;
		case AUTO_RED_GRN:
			auto_red_grn();

			// CHANGE STATE
			if (isFlag(TIMER_TRAFFIC_LIGHT)) // -> AUTO_RED_YEL
			{
				init_auto_red_yel();
				TRAFFIC_LIGHT_STATE = AUTO_RED_YEL;
			}
			else if (isButtonPressed(&button0)) // -> RED_TIME_CONFIG
			{
				init_red_time_config();
				TRAFFIC_LIGHT_STATE = RED_TIME_CONFIG;
			}
			else if (isButtonPressed(&button1)) // -> YEL_BLINKY
			{
				init_yel_blinky();
				TRAFFIC_LIGHT_STATE = YEL_BLINKY;
			}
			else if (isButtonPressed(&button2)) // -> MAN_RED_GRN
			{
				init_man_red_grn();
				TRAFFIC_LIGHT_STATE = MAN_RED_GRN;
			}

			break;
		case AUTO_RED_YEL:
			auto_red_yel();

			// CHANGE STATE
			if (isFlag(TIMER_TRAFFIC_LIGHT)) // -> AUTO_GRN_RED
			{
				init_auto_grn_red();
				TRAFFIC_LIGHT_STATE = AUTO_GRN_RED;
			}
			else if (isButtonPressed(&button0)) // -> RED_TIME_CONFIG
			{
				init_red_time_config();
				TRAFFIC_LIGHT_STATE = RED_TIME_CONFIG;
			}
			else if (isButtonPressed(&button1)) // -> YEL_BLINKY
			{
				init_yel_blinky();
				TRAFFIC_LIGHT_STATE = YEL_BLINKY;
			}
			break;
		case AUTO_GRN_RED:
			auto_grn_red();

			if (isFlag(TIMER_TRAFFIC_LIGHT)) // -> AUTO_YEL_RED
			{
				init_auto_yel_red();
				TRAFFIC_LIGHT_STATE = AUTO_YEL_RED;
			}
			else if (isButtonPressed(&button0)) // -> RED_TIME_CONFIG
			{
				init_red_time_config();
				TRAFFIC_LIGHT_STATE = RED_TIME_CONFIG;
			}
			else if (isButtonPressed(&button1)) // -> YEL_BLINKY
			{
				init_yel_blinky();
				TRAFFIC_LIGHT_STATE = YEL_BLINKY;
			}
			else if (isButtonPressed(&button2)) // -> MAN_GRN_RED
			{
				init_man_grn_red();
				TRAFFIC_LIGHT_STATE = MAN_GRN_RED;
			}
			break;
		case AUTO_YEL_RED:
			auto_yel_red();

			if (isFlag(TIMER_TRAFFIC_LIGHT)) // -> AUTO_RED_GRN
			{
				init_auto_red_grn();
				TRAFFIC_LIGHT_STATE = AUTO_RED_GRN;
			}
			else if (isButtonPressed(&button0)) // -> RED_TIME_CONFIG
			{
				init_red_time_config();
				TRAFFIC_LIGHT_STATE = RED_TIME_CONFIG;
			}
			else if (isButtonPressed(&button1)) // -> YEL_BLINKY
			{
				init_yel_blinky();
				TRAFFIC_LIGHT_STATE = YEL_BLINKY;
			}
			break;
		case MAN_RED_GRN:
			man_red_grn();

			if (isButtonPressed(&button1)) // -> MAN_RED_YEL
			{
				init_man_red_yel();
				TRAFFIC_LIGHT_STATE = MAN_RED_YEL;
			}
			else if (isButtonPressed(&button2)) // -> AUTO_RED_GRN
			{
				init_auto_red_grn();
				TRAFFIC_LIGHT_STATE = AUTO_RED_GRN;
			}
			break;
		case MAN_RED_YEL:
			man_red_yel();

			if (isFlag(TIMER_TRAFFIC_LIGHT)) // -> MAN_GRN_RED
			{
				init_man_grn_red();
				TRAFFIC_LIGHT_STATE = MAN_GRN_RED;
			}
			break;
		case MAN_GRN_RED:
			man_grn_red();

			if (isButtonPressed(&button1)) // -> MAN_YEL_RED
			{
				init_man_yel_red();
				TRAFFIC_LIGHT_STATE = MAN_YEL_RED;
			}
			else if (isButtonPressed(&button2)) // -> AUTO_GRN_RED
			{
				init_auto_grn_red();
				TRAFFIC_LIGHT_STATE = AUTO_GRN_RED;
			}
			break;
		case MAN_YEL_RED:
			man_yel_red();

			if (isFlag(TIMER_TRAFFIC_LIGHT)) // -> MAN_RED_GRN
			{
				init_man_red_grn();
				TRAFFIC_LIGHT_STATE = MAN_RED_GRN;
			}
			break;
		case RED_TIME_CONFIG:
			red_time_config();

			if (isButtonPressed(&button0)) // -> YEL_TIME_CONFIG
			{
				init_yel_time_config();
				TRAFFIC_LIGHT_STATE = YEL_TIME_CONFIG;
			}
			else if (red_temp_time != red_time) // -> RED_TIME_CONFIG_CHANGE
			{
				init_red_time_config_change();
				TRAFFIC_LIGHT_STATE = RED_TIME_CONFIG_CHANGE;
			}
			break;
		case RED_TIME_CONFIG_CHANGE:
			red_time_config_change();

			if (isButtonPressed(&button0)) // -> YEL_TIME_CONFIG
			{
				init_yel_time_config();
				TRAFFIC_LIGHT_STATE = YEL_TIME_CONFIG;
			}
			else if (red_temp_time == red_time) // -> RED_TIME_CONFIG
			{
				init_red_time_config();
				TRAFFIC_LIGHT_STATE = RED_TIME_CONFIG;
			}
			break;
		case YEL_TIME_CONFIG:
			yel_time_config();

			if (isButtonPressed(&button0)) // -> GRN_TIME_CONFIG
			{
				init_grn_time_config();
				TRAFFIC_LIGHT_STATE = GRN_TIME_CONFIG;
			}
			else if (yel_temp_time != yel_time) // -> YEL_TIME_CONFIG_CHANGE
			{
				init_yel_time_config_change();
				TRAFFIC_LIGHT_STATE = YEL_TIME_CONFIG_CHANGE;
			}
			break;
		case YEL_TIME_CONFIG_CHANGE:
			yel_time_config_change();

			if (isButtonPressed(&button0)) // -> GRN_TIME_CONFIG
			{
				init_grn_time_config();
				TRAFFIC_LIGHT_STATE = GRN_TIME_CONFIG;
			}
			else if (yel_temp_time == yel_time) // -> YEL_TIME_CONFIG
			{
				init_yel_time_config();
				TRAFFIC_LIGHT_STATE = YEL_TIME_CONFIG;
			}
			break;
		case GRN_TIME_CONFIG:
			grn_time_config();

			if (isButtonPressed(&button0)) // -> AUTO_RED_GRN
			{
				init_auto_red_grn();
				TRAFFIC_LIGHT_STATE = AUTO_RED_GRN;
			}
			else if (grn_temp_time != grn_time) // -> GRN_TIME_CONFIG_CHANGE
			{
				init_grn_time_config_change();
				TRAFFIC_LIGHT_STATE = GRN_TIME_CONFIG_CHANGE;
			}
			break;
		case GRN_TIME_CONFIG_CHANGE:
			grn_time_config_change();

			if (isButtonPressed(&button0)) // -> AUTO_RED_GRN
			{
				init_auto_red_grn();
				TRAFFIC_LIGHT_STATE = AUTO_RED_GRN;
			}
			else if (grn_temp_time == grn_time) // -> GRN_TIME_CONFIG
			{
				init_grn_time_config();
				TRAFFIC_LIGHT_STATE = GRN_TIME_CONFIG;
			}
			break;
		case YEL_BLINKY:
			yel_blinky();

			if (isButtonPressed(&button1)) // -> AUTO_RED_GRN
			{
				init_auto_red_grn();
				TRAFFIC_LIGHT_STATE = AUTO_RED_GRN;
			}
			break;
		default:
			break;
	}
}

void turn_red_on()
{
	HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_0_GPIO_Port, LED_GRN_0_Pin, LED_OFF);

	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_1_GPIO_Port, LED_GRN_1_Pin, LED_OFF);
}

void turn_yel_on()
{
	HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_GRN_0_GPIO_Port, LED_GRN_0_Pin, LED_OFF);

	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_GRN_1_GPIO_Port, LED_GRN_1_Pin, LED_OFF);
}

void turn_grn_on()
{
	HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_0_GPIO_Port, LED_GRN_0_Pin, LED_ON);

	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_1_GPIO_Port, LED_GRN_1_Pin, LED_ON);
}

void turn_on_red_grn()
{
	HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_0_GPIO_Port, LED_GRN_0_Pin, LED_OFF);

	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_1_GPIO_Port, LED_GRN_1_Pin, LED_ON);
}

void turn_on_red_yel()
{
	HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_0_GPIO_Port, LED_GRN_0_Pin, LED_OFF);

	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_GRN_1_GPIO_Port, LED_GRN_1_Pin, LED_OFF);
}

void turn_on_grn_red()
{
	HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_0_GPIO_Port, LED_GRN_0_Pin, LED_ON);

	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_1_GPIO_Port, LED_GRN_1_Pin, LED_OFF);
}

void turn_on_yel_red()
{
	HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_GRN_0_GPIO_Port, LED_GRN_0_Pin, LED_OFF);

	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GRN_1_GPIO_Port, LED_GRN_1_Pin, LED_OFF);
}

void init_auto_red_grn()
{
	// TIMER_TRAFFIC_LIGHT, BTN_0, BTN_1, BTN_2
	setTimer(TIMER_TRAFFIC_LIGHT, grn_time * 1000);
	resetButton(&button0);
	resetButton(&button1);
	resetButton(&button2);

	// OTHER PRECONDITIONS
	set_on_4digits();
	setTimer(TIMER_7SEG, TIME_7SEG);
	setTimer(TIMER_1SEC, TIME_1SEC);
	counter_way0 = red_time;
	counter_way1 = grn_time;
	update_led_7seg_buffer();

}
void auto_red_grn()
{
	if (1)
	{
		turn_on_red_grn();
	}

	if (isFlag(TIMER_7SEG))
	{
		display_4digits();
		setTimer(TIMER_7SEG, TIME_7SEG);
	}

	if (isFlag(TIMER_1SEC))
	{
		--counter_way0;
		--counter_way1;
		update_led_7seg_buffer();
		setTimer(TIMER_1SEC, TIME_1SEC);
	}
}

void init_auto_red_yel()
{
	// TIMER_TRAFFIC_LIGHT, BTN_0, BTN_1
	setTimer(TIMER_TRAFFIC_LIGHT, yel_time * 1000);
	resetButton(&button0);
	resetButton(&button1);

	// OTHER PRECONDITIONS
	set_on_4digits();
	setTimer(TIMER_7SEG, TIME_7SEG);
	setTimer(TIMER_1SEC, TIME_1SEC);
	counter_way0 = yel_time;
	counter_way1 = yel_time;
	update_led_7seg_buffer();
}
void auto_red_yel()
{
	if (1)
	{
		turn_on_red_yel();
	}

	if (isFlag(TIMER_7SEG))
	{
		display_4digits();
		setTimer(TIMER_7SEG, TIME_7SEG);
	}

	if (isFlag(TIMER_1SEC))
	{
		--counter_way0;
		--counter_way1;
		update_led_7seg_buffer();
		setTimer(TIMER_1SEC, TIME_1SEC);
	}
}

void init_auto_grn_red()
{
	// TIMER_TRAFFIC_LIGHT, BTN_0, BTN_1, BTN_2
	setTimer(TIMER_TRAFFIC_LIGHT, grn_time * 1000);
	resetButton(&button0);
	resetButton(&button1);
	resetButton(&button2);

	// OTHER PRECONDITIONS
	set_on_4digits();
	setTimer(TIMER_7SEG, TIME_7SEG);
	setTimer(TIMER_1SEC, TIME_1SEC);
	counter_way0 = grn_time;
	counter_way1 = red_time;
	update_led_7seg_buffer();
}
void auto_grn_red()
{
	if (1)
	{
		turn_on_grn_red();
	}

	if (isFlag(TIMER_7SEG))
	{
		display_4digits();
		setTimer(TIMER_7SEG, TIME_7SEG);
	}

	if (isFlag(TIMER_1SEC))
	{
		--counter_way0;
		--counter_way1;
		update_led_7seg_buffer();
		setTimer(TIMER_1SEC, TIME_1SEC);
	}
}

void init_auto_yel_red()
{
	// TIMER_TRAFFIC_LIGHT, BTN_0, BTN_1
	setTimer(TIMER_TRAFFIC_LIGHT, yel_time * 1000);
	resetButton(&button0);
	resetButton(&button1);

	// OTHER PRECONDITIONS
	set_on_4digits();
	setTimer(TIMER_7SEG, TIME_7SEG);
	setTimer(TIMER_1SEC, TIME_1SEC);
	counter_way0 = yel_time;
	counter_way1 = yel_time;
	update_led_7seg_buffer();
}
void auto_yel_red()
{
	if (1)
	{
		turn_on_yel_red();
	}

	if (isFlag(TIMER_7SEG))
	{
		display_4digits();
		setTimer(TIMER_7SEG, TIME_7SEG);
	}

	if (isFlag(TIMER_1SEC))
	{
		--counter_way0;
		--counter_way1;
		update_led_7seg_buffer();
		setTimer(TIMER_1SEC, TIME_1SEC);
	}
}

void init_man_red_grn()
{
	// BTN_1, BTN_2
	resetButton(&button1);
	resetButton(&button2);

	// OTHER PRECONDITIONS
	setTimer(TIMER_7SEG, TIME_7SEG);
}
void man_red_grn()
{
	if (1)
	{
		unable_4digit();
		turn_on_red_grn();
	}
}

void init_man_red_yel()
{
	// TIMER_TRAFFIC_LIGHT
	setTimer(TIMER_TRAFFIC_LIGHT, yel_time * 1000);
}
void man_red_yel()
{
	if (1)
	{
		unable_4digit();
		turn_on_red_yel();
	}
}

void init_man_grn_red()
{
	// BTN_1, BTN_2
	resetButton(&button1);
	resetButton(&button2);
}
void man_grn_red()
{
	if (1)
	{
		unable_4digit();
		turn_on_grn_red();
	}
}

void init_man_yel_red()
{
	// TIMER_TRAFFIC_LIGHT
	setTimer(TIMER_TRAFFIC_LIGHT, yel_time * 1000);
}
void man_yel_red()
{
	if (1)
	{
		unable_4digit();
		turn_on_yel_red();
	}
}

void init_red_time_config()
{
	// BTN_0, red_temp_time
	resetButton(&button0);
	red_temp_time = red_time;

	// OTHER PRECONDITIONS
	turn_red_on();
	setTimer(TIMER_250MS, TIME_250MS);

	set_on_4digits();
	counter_way0 = red_temp_time;
	counter_way1 = 9;
	update_led_7seg_buffer();
	setTimer(TIMER_7SEG, TIME_7SEG);
}
void red_time_config()
{
	if (1)
	{
		if (isButtonPressed(&button1))
		{
			++red_temp_time;
		}
		if (isButtonLongPressed(&button1))
		{
			red_temp_time += 5;
		}
		if (red_temp_time > MAX_COUNTER)
		{
			red_temp_time = MIN_COUNTER;
		}

		counter_way0 = red_temp_time;
		counter_way1 = red_temp_time;
		update_led_7seg_buffer();
	}

	if (isFlag(TIMER_250MS))
	{
		HAL_GPIO_TogglePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin);
		HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);

		setTimer(TIMER_250MS, TIME_250MS);
	}

	if (isFlag(TIMER_7SEG))
	{
		display_4digits();
		setTimer(TIMER_7SEG, TIME_7SEG);
	}
}

void init_red_time_config_change()
{
	// BTN_0, BTN_2, red_temp_time
	resetButton(&button0);
	resetButton(&button2);

	// OTHER PRECONDITIONS
	turn_red_on();
	setTimer(TIMER_250MS, TIME_250MS);

	set_on_4digits();
	counter_way0 = red_temp_time;
	counter_way1 = 10;
	update_led_7seg_buffer();
	setTimer(TIMER_7SEG, TIME_7SEG);

	setTimer(TIMER_7SEG_STATUS, TIME_7SEG_STATUS);
}
void red_time_config_change()
{
	if (1)
	{
		if (isButtonPressed(&button1))
		{
			++red_temp_time;
		}
		if (isButtonLongPressed(&button1))
		{
			red_temp_time += 5;
		}
		if (red_temp_time > MAX_COUNTER)
		{
			red_temp_time = MIN_COUNTER;
		}

		if (isButtonPressed(&button2))
		{
			if (red_temp_time > yel_time)
			{
				red_time = red_temp_time;
				grn_time = red_time - yel_time;
			}
		}

		counter_way0 = red_temp_time;
		counter_way1 = counter_way0;
		update_led_7seg_buffer();
	}

	if (isFlag(TIMER_250MS))
	{
		HAL_GPIO_TogglePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin);
		HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
		setTimer(TIMER_250MS, TIME_250MS);
	}

	if (isFlag(TIMER_7SEG))
	{
		display_4digits();
		setTimer(TIMER_7SEG, TIME_7SEG);
	}

	if (isFlag(TIMER_7SEG_STATUS))
	{
		if (status_4digits[0] == LED_ON)
		{
			status_4digits[0] = LED_OFF;
			status_4digits[1] = LED_OFF;
		}
		else
		{
			status_4digits[0] = LED_ON;
			status_4digits[1] = LED_ON;
		}
		setTimer(TIMER_7SEG_STATUS, TIME_7SEG_STATUS);
	}
}

void init_yel_time_config()
{
	// BTN_0, yel_temp_time
	resetButton(&button0);
	yel_temp_time = yel_time;

	// OTHER PRECONDITIONS
	turn_yel_on();
	setTimer(TIMER_250MS, TIME_250MS);

	set_on_4digits();
	counter_way0 = yel_temp_time;
	counter_way1 = 11;
	update_led_7seg_buffer();
	setTimer(TIMER_7SEG, TIME_7SEG);
}
void yel_time_config()
{
	if (1)
	{
		if (isButtonPressed(&button1))
		{
			++yel_temp_time;
		}
		if (isButtonLongPressed(&button1))
		{
			yel_temp_time += 5;
		}
		if (yel_temp_time > MAX_COUNTER)
		{
			yel_temp_time = MIN_COUNTER;
		}

		counter_way0 = yel_temp_time;
		counter_way1 = yel_temp_time;
		update_led_7seg_buffer();
	}

	if (isFlag(TIMER_250MS))
	{
		HAL_GPIO_TogglePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin);
		HAL_GPIO_TogglePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin);

		setTimer(TIMER_250MS, TIME_250MS);
	}

	if (isFlag(TIMER_7SEG))
	{
		display_4digits();
		setTimer(TIMER_7SEG, TIME_7SEG);
	}
}

void init_yel_time_config_change()
{
	// BTN_0, BTN_2, yel_temp_time
	resetButton(&button0);
	resetButton(&button2);

	// OTHER PRECONDITIONS
	turn_yel_on();
	setTimer(TIMER_250MS, TIME_250MS);

	set_on_4digits();
	counter_way0 = yel_temp_time;
	counter_way1 = 12;
	update_led_7seg_buffer();
	setTimer(TIMER_7SEG, TIME_7SEG);

	setTimer(TIMER_7SEG_STATUS, TIME_7SEG_STATUS);
}
void yel_time_config_change()
{
	if (1)
	{
		if (isButtonPressed(&button1))
		{
			++yel_temp_time;
		}
		if (isButtonLongPressed(&button1))
		{
			yel_temp_time += 5;
		}
		if (yel_temp_time > MAX_COUNTER)
		{
			yel_temp_time = MIN_COUNTER;
		}

		if (isButtonPressed(&button2))
		{
			if (red_time > yel_temp_time)
			{
				yel_time = yel_temp_time;
				grn_time = red_time - yel_time;
			}
		}

		counter_way0 = yel_temp_time;
		counter_way1 = counter_way0;
		update_led_7seg_buffer();
	}

	if (isFlag(TIMER_250MS))
	{
		HAL_GPIO_TogglePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin);
		HAL_GPIO_TogglePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin);
		setTimer(TIMER_250MS, TIME_250MS);
	}

	if (isFlag(TIMER_7SEG))
	{
		display_4digits();
		setTimer(TIMER_7SEG, TIME_7SEG);
	}

	if (isFlag(TIMER_7SEG_STATUS))
	{
		if (status_4digits[0] == LED_ON)
		{
			status_4digits[0] = LED_OFF;
			status_4digits[1] = LED_OFF;
		}
		else
		{
			status_4digits[0] = LED_ON;
			status_4digits[1] = LED_ON;
		}
		setTimer(TIMER_7SEG_STATUS, TIME_7SEG_STATUS);
	}
}

void init_grn_time_config()
{
	// BTN_0, grn_temp_time
	resetButton(&button0);
	grn_temp_time = grn_time;

	// OTHER PRECONDITIONS
	turn_grn_on();
	setTimer(TIMER_250MS, TIME_250MS);

	set_on_4digits();
	counter_way0 =grn_temp_time;
	counter_way1 = 13;
	update_led_7seg_buffer();
	setTimer(TIMER_7SEG, TIME_7SEG);
}
void grn_time_config()
{
	if (1)
	{
		if (isButtonPressed(&button1))
		{
			++grn_temp_time;
		}
		if (isButtonLongPressed(&button1))
		{
			grn_temp_time += 5;
		}
		if (grn_temp_time > MAX_COUNTER)
		{
			grn_temp_time = MIN_COUNTER;
		}

		counter_way0 = grn_temp_time;
		counter_way1 = grn_temp_time;
		update_led_7seg_buffer();
	}

	if (isFlag(TIMER_250MS))
	{
		HAL_GPIO_TogglePin(LED_GRN_0_GPIO_Port, LED_GRN_0_Pin);
		HAL_GPIO_TogglePin(LED_GRN_1_GPIO_Port, LED_GRN_1_Pin);

		setTimer(TIMER_250MS, TIME_250MS);
	}

	if (isFlag(TIMER_7SEG))
	{
		display_4digits();
		setTimer(TIMER_7SEG, TIME_7SEG);
	}
}

void init_grn_time_config_change()
{
	// BTN_0, BTN_2, grn_temp_time
	resetButton(&button0);
	resetButton(&button2);

	// OTHER PRECONDITIONS
	turn_grn_on();
	setTimer(TIMER_250MS, TIME_250MS);

	set_on_4digits();
	counter_way0 = grn_temp_time;
	counter_way1 = 14;
	update_led_7seg_buffer();
	setTimer(TIMER_7SEG, TIME_7SEG);

	setTimer(TIMER_7SEG_STATUS, TIME_7SEG_STATUS);
}
void grn_time_config_change()
{
	if (1)
	{
		if (isButtonPressed(&button1))
		{
			++grn_temp_time;
		}
		if (isButtonLongPressed(&button1))
		{
			grn_temp_time += 5;
		}
		if (grn_temp_time > MAX_COUNTER)
		{
			grn_temp_time = MIN_COUNTER;
		}

		if (isButtonPressed(&button2))
		{
			if (1)
			{
				grn_time = grn_temp_time;
				red_time = grn_time + yel_time;
			}
		}

		counter_way0 = grn_temp_time;
		counter_way1 = counter_way0;
		update_led_7seg_buffer();
	}

	if (isFlag(TIMER_250MS))
	{
		HAL_GPIO_TogglePin(LED_GRN_0_GPIO_Port, LED_GRN_0_Pin);
		HAL_GPIO_TogglePin(LED_GRN_1_GPIO_Port, LED_GRN_1_Pin);
		setTimer(TIMER_250MS, TIME_250MS);
	}

	if (isFlag(TIMER_7SEG))
	{
		display_4digits();
		setTimer(TIMER_7SEG, TIME_7SEG);
	}

	if (isFlag(TIMER_7SEG_STATUS))
	{
		if (status_4digits[0] == LED_ON)
		{
			status_4digits[0] = LED_OFF;
			status_4digits[1] = LED_OFF;
		}
		else
		{
			status_4digits[0] = LED_ON;
			status_4digits[1] = LED_ON;
		}
		setTimer(TIMER_7SEG_STATUS, TIME_7SEG_STATUS);
	}
}

void init_yel_blinky()
{
	// BTN_1
	resetButton(&button1);

	// OTHER PRECONDITIONS
	turn_yel_on();
	unable_4digit();
	setTimer(TIMER_500MS, TIME_500MS);
}
void yel_blinky()
{
	if (isFlag(TIMER_500MS))
	{
		HAL_GPIO_TogglePin(LED_YEL_0_GPIO_Port, LED_YEL_0_Pin);
		HAL_GPIO_TogglePin(LED_YEL_1_GPIO_Port, LED_YEL_1_Pin);
		setTimer(TIMER_500MS, TIME_500MS);
	}
}

