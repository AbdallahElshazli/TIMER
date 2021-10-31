/*
 * GccApplication2.c
 *
 * Created: 10/31/2021 8:17:40 PM
 * Author : Abdalla
 */ 


#include <avr/interrupt.h>
#include "Timer.h"
#include "LED.h"

extern uint8 Init_Value ;
extern uint32 Number_OVflows ;

int main(void)
{
	
	
	LED0_Init();
	
	TIMER_init();
	TIMER_set(50);
	TIMER_start();
	
	
	
	
	while (1)
	{
	}
}



ISR(TIMER0_OVF_vect){
	
	static uint32  cnt  = 0;
	cnt++;
	if(cnt == Number_OVflows){
		
		TCNT0 = Init_Value ;
		cnt =0;
		
		LED0_Toggle();
	}
}