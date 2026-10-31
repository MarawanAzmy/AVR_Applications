/**
 * @file    Timer1_CTC.c
 * @brief   Timer1 in CTC mode: periodic compare-match interrupt with a callback.
 * @author  Marawan Azmy
 */

#include <avr/interrupt.h>

#include "Timer1_CTC.h"

static void (*PTR) (void) = NULL;

void Timer1_init(void){
	TCCR1A = (1<<FOC1A)|(1<<FOC1B);
	TCCR1B = (1<<WGM12);	/* CTC, TOP = OCR1A */
	OCR1A = 0;
	OCR1B = 0;
	ICR1 = 0;
	TIMSK = (1<<OCIE1A);
	SREG = (1<<7);	/* Global interrupt enable */
}

/*
 * 8 MHz / 64 = 125 kHz, so one timer tick = 8 us.
 * OCR1A = TimerPeriod (us) / 8, e.g. 1000 us / 8 = 125 ticks for 1 ms.
 */
void Timer1_start(void){
	OCR1A = (TimerPeriod / 8ul);
	TCCR1B = (1<<CS11)|(1<<CS10)|(1<<WGM12);	/* Prescaler 64, CTC */
}

void Timer1_stop(void){
	TCCR1B = (1<<WGM12);
}

void Timer1_clear(void){
	TCNT1 = 0;
}

uint16 Timer1_reading(void){
	return TCNT1;
}

void Timer1_Set_Cbk(void (*Cbk) (void)){
	PTR = Cbk;
}

ISR(TIMER1_COMPA_vect){
	if(PTR != NULL){
		PTR();
	}
}
