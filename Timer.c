/*
 * Timer_0.c
 *
 * Created: 9/9/2021 12:54:22 PM
 *  Author: Abdallah
 */ 


#include "Timer.h"


// ISR & TimerSetDelay share on them 

uint8   Init_Value = 0;
uint32  Number_OVflows = 0;


 

void TIMER_init(void){
	
	TCCR0 |= 0x00;    // Select the normal mode 
	TIMSK |= 0x01;    // Set the interrupt overflow Enable 
	SREG  |= 0x08;    // Set the global Interrupt Enable 
	
}
	
	
void TIMER_start(void){  // Connect the CLK
	
       TCCR0 |= 0x05;        
}


void TIMER_stop(void){    // Disconnect the CLK
	
		CLR_BIT(TCCR0,0);
		CLR_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);
}


void TIMER_set(uint32 Delay_Ms){
	
	uint8 Tick_Time = (1024 / 8);             
	
	uint32 Total_Ticks = (Delay_Ms * 1000);  
	
	Number_OVflows = Total_Ticks / 256 ;     
	
	Init_Value = 265 -(Total_Ticks % 265);    
	
	
	TCNT0 = Init_Value ;
	
	Number_OVflows++;
	
}

