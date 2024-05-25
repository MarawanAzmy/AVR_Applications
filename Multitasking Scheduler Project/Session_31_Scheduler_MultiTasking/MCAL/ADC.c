
#include "ADC.h"


void ADC_Init(void){
	ADMUX = (1<<REFS0);
	ADCSRA = (1<<ADEN) | (1<<ADPS1) | (1<<ADPS2) ;//enable, set division freq 8M/64
}


uint16 ADC_Read(uint8 Channel){
	Channel = Channel &0x07; // filtering channel 3 bits
	ADMUX &=0xE0	;//clearing least 5 bits "0"
	ADMUX |= Channel;

	ADCSRA|= (1<<ADSC);//start conversion;
	while(ADCSRA & (1<<ADSC));//wait till bit 0 and new reading available, blocking code will be solved later


	return ADC;
}
