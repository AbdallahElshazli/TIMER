/*
 * Timer_0.h
 *
 * Created: 9/9/2021 12:54:40 PM
 *  Author: Abdallah
 */ 


#ifndef TIMER_0_H_
#define TIMER_0_H_

#include "ATMEGA32_Regs.h"
#include "BIT_Math.h"

void TIMER_init (void);

void TIMER_start (void);

void TIMER_stop (void);

void TIMER_set (uint32 Delay_Ms);





#endif /* TIMER_0_H_ */