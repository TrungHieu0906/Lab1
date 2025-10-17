/*
 * common.h
 *
 *  Created on: Oct 17, 2025
 *      Author: Trung Hieu
 */

#ifndef INC_COMMON_H_
#define INC_COMMON_H_

#include "main.h"

// TRAFFIC LIGHT
#define MIN_COUNTER 1
#define MAX_COUNTER 99

// TIMER
#define TIMER_READ_BTN 0
#define TIME_READ_BTN 20 // ms

#define TIMER_TRAFFIC_LIGHT 1

#define TIMER_7SEG 2
#define TIME_7SEG 5

#define TIMER_7SEG_STATUS 3
#define TIME_7SEG_STATUS 250

#define TIMER_1SEC 4
#define TIME_1SEC 1000

#define TIMER_500MS 5
#define TIME_500MS 500

#define TIMER_250MS 6
#define TIME_250MS 250

#define TIMER_STATUS 7
#define TIME_STATUS 1000

// BUTTON
#define NORMAL_STATE 1
#define PRESSED_STATE 0
#define TIME_OUT_FOR_LONG_PRESSED 500 // ms

// LED CONTROL
#define LED_ON 0
#define LED_OFF 1
#define ENABLE 1
#define DISABLE 0

extern int led_7seg_index;
extern int led_7seg_buffer[4];
extern int status_4digits[4];

extern int counter_way0;
extern int counter_way1;

extern int red_time;
extern int yel_time;
extern int grn_time;

extern int red_temp_time;
extern int yel_temp_time;
extern int grn_temp_time;




#endif /* INC_COMMON_H_ */
