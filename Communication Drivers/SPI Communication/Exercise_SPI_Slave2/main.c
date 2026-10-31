/**
 * @file    main.c
 * @brief   SPI slave: turns the LED on PD0 on for 'y' and off for 'n'.
 * @author  Marawan Azmy
 */

#include "SPI.h"
#include <avr/io.h>
#include <util/delay.h>

#define MST_SLV = SLV

int main(){
	DDRB |= (1<<PB6);	/* MISO output */
	DDRB &= ~((1<<PB5)|(1<<PB4)|(1<<PB7));	/* MOSI, SS and SCK inputs */

	DDRD |= (1<<PD0);	/* LED */

	SPI_init();

	unsigned char data;
	while(1){
		data = SPI_Recieve_Byte();
		if (data == 'y'){
			PORTD |= (1<<PD0);
		}else if (data == 'n')
			PORTD &= ~(1<<PD0);
	}

	return 0;
}
