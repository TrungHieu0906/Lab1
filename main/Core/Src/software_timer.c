/*
 * software_timer.c
 *
 *  Created on: Oct 17, 2025
 *      Author: Trung Hieu
 */

#include "software_timer.h"

#define TICK 1 // ms

struct TimerStruct timer[10];

void setTimer(int idx, int counter)
{
	timer[idx].counter = counter / TICK;
	timer[idx].flag = 0;
}

void timerRun()
{
	for (int i = 0; i < 10; ++i)
	{
		if (timer[i].counter > 0)
		{
			--timer[i].counter;
			if (timer[i].counter <= 0)
			{
				timer[i].flag = 1;
			}
		}
	}
}

int isFlag(int idx)
{
	if (timer[idx].flag)
	{
		return 1;
	}
	return 0;
}
