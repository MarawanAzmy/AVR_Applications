/**
 * @file    PWM.c
 * @brief   Timer0 fast PWM on OC0 (PB3).
 * @author  Marawan Azmy
 */

#include <avr/io.h>

void init_PWM(void){
	TCCR0 = (1<<COM01) | (1<<WGM00) | (1<<WGM01);	/* Fast PWM, non-inverting */
	TCNT0 = 0;
	DDRB = (1<<PB3);
}

void start_PWM(short value){
	TCCR0 |= (1<<CS00);	/* Start timer, no prescaler */
	OCR0 = value;
}
