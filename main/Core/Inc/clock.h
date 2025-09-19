/*
 * clock.h
 *
 *  Created on: Sep 19, 2025
 *      Author: Trung Hieu
 */
#include "main.h"
#ifndef INC_CLOCK_H_
#define INC_CLOCK_H_

extern GPIO_TypeDef* LED_PORT[12];
extern uint16_t LED_PIN[12];

// Bài 6: Test lần lượt tất cả LED
void testAllLEDs(void);

// Bài 7: Tắt toàn bộ LED (clear all)
void clearAllClock(void);

// Bài 8: Bật LED theo số thứ tự 0–11
void setNumberOnClock(int num);

// Bài 9: Tắt LED theo số thứ tự 0–11
void clearNumberOnClock(int num);

#endif /* INC_CLOCK_H_ */
