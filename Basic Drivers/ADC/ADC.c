/**
 * @file    ADC.c
 * @brief   ADC driver: AVCC reference, single conversion, polling.
 * @author  Marawan Azmy
 */

#include "ADC.h"

void ADC_Init(void){
	ADMUX = (1<<REFS0);
	ADCSRA = (1<<ADEN) | (1<<ADPS1) | (1<<ADPS2);	/* Prescaler 64: 8 MHz / 64 = 125 kHz */
}

uint16 ADC_Read(uint8 Channel){
	Channel = Channel & 0x07;
	ADMUX &= 0xE0;	/* Clear MUX4:0 */
	ADMUX |= Channel;

	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADSC));	/* ADSC clears when the conversion completes */

	return ADC;
}
