/*
 * PWM.c
 *
 *  Created on: 2 May 2024
 *      Author: marmar
 */
#include <avr/io.h>

void init_PWM(void){

TCCR0 = (1<<COM01) | (1<<WGM00) | (1<<WGM01) ;//|(1<<CS01);//must be greater than switching freq w khalas, msh fr2a divide kam
TCNT0 = 0;
DDRB = (1<<PB3);
}
void start_PWM(short value){


	TCCR0 |= (1<<CS00);
	OCR0 = value;
}
