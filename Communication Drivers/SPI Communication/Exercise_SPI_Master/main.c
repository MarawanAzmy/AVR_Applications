/**
 * @file    main.c
 * @brief   SPI master: sends 'y' then 'n' to each of two slaves in turn (slave select on PB0/PB1).
 * @author  Marawan Azmy
 */

#include "SPI.h"
#include <avr/io.h>
#include <util/delay.h>

#define MST_SLV = MST

int main(){
	DDRB |= (1<<PB7)|(1<<PB5)|(1<<PB4)|(1<<PB0)|(1<<PB1);	/* SCK, MOSI, SS and slave selects as outputs */
	DDRB &= ~(1<<PB6);	/* MISO input */

	SPI_init();

	while(1){
		PORTB &= ~(1<<PB0);
		PORTB |= (1<<PB1);
		SPI_Send_Byte('y',0);
		_delay_ms(1000);
		SPI_Send_Byte('n',0);
		_delay_ms(1000);

		PORTB |= (1<<PB0);
		PORTB &= ~(1<<PB1);
		SPI_Send_Byte('y',0);
		_delay_ms(1000);
		SPI_Send_Byte('n',0);
		_delay_ms(1000);
	}

	return 0;
}
