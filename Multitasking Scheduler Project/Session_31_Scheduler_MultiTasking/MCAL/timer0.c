/*
 * timer.c
 *
 *  Created on: 30 Apr 2024
 *      Author: Marawan
 */

#include <avr/io.h>


void counter_initialize(void){
	//TCCR0 = 1<<FOC0;
	//TCNT0 = 0;
	TCCR0 = (0<<WGM01) |(0<<WGM01);
	TIMSK |= (1<<TOIE0);
	SREG |= (1<<7);

}

void counter_start(void){
	TCCR0 &= 0xf8;
	TCCR0 |= (1<<CS01);// divide 8MHZ with 8 = el freq= 1 MHz, count = 1/1Mhz = 1Microsec, 256 reg, inturrupt every 265 Micro sec
	//TCNT0 = 0;
	//1 sec = 1000 000 micro
	//2.5 sec = 2500 000 micro
	//2500 000 /256 = 9765.6 = 9434
	//2.5 sec will pass in 9434 inturrupts
}



