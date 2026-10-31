/**
 * @file    timer0.c
 * @brief   Timer0 in normal mode with overflow interrupt.
 * @author  Marawan Azmy
 */

#include <avr/io.h>

void counter_initialize(void){
	TCCR0 = (0<<WGM01) |(0<<WGM01);	/* Normal mode */
	TIMSK |= (1<<TOIE0);
	SREG |= (1<<7);	/* Global interrupt enable */
}

/* Prescaler 8: 8 MHz / 8 = 1 MHz, so the 8-bit counter overflows every 256 us. */
void counter_start(void){
	TCCR0 &= 0xf8;
	TCCR0 |= (1<<CS01);
}
