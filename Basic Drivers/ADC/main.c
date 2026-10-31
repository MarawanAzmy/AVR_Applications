/**
 * @file    main.c
 * @brief   Temperature control: reads a 10 mV/C sensor on ADC6 and turns on PC5 above 30 C.
 * @author  Marawan Azmy
 */

#include "ADC.h"

int main(){
	ADC_Init();

	f32 Sensor = 0;
	DDRC |= (1<<PC5);

	while(1){
		Sensor = ADC_Read(6);	/* 0-1023 */
		Sensor *= 5;
		Sensor /= 1023;	/* Volts */
		Sensor *= 100;	/* Degrees C */

		if(Sensor > 30){
			PORTC |= (1<<PC5);
		}
		else{
			PORTC &= ~(1<<PC5);
		}
	}

	return 0;
}
