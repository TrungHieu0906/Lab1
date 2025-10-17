/*
 * common.c
 *
 *  Created on: Oct 17, 2025
 *      Author: Trung Hieu
 */

#include "common.h"

int led_7seg_index = 0;
int led_7seg_buffer[4] = {0, 5, 0, 3};
int status_4digits[4] = {LED_ON, LED_ON, LED_ON, LED_ON};

int counter_way0 = 0;
int counter_way1 = 0;

int red_time = 15;
int yel_time = 3;
int grn_time = 12;

int red_temp_time = 5;
int yel_temp_time = 2;
int grn_temp_time = 3;
