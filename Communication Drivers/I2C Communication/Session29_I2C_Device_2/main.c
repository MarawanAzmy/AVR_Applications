/**
 * @file    main.c
 * @brief   I2C slave (address 0x02): shows the received value on a two-digit 7-segment display.
 * @author  Marawan Azmy
 */

#include <AVR/io.h>
#include <util/delay.h>
#include "I2C.h"

#define BIT_RATE 32	/* TWBR: 32 = 100 kHz, 2 = 400 kHz */

int main(void){
	DDRA = (1<<PA7)| (1<<PA6);
	DDRD = 0xff;

	I2C_init(0x02);
	unsigned char var;
	unsigned char units;
	unsigned char tenth;

	while(1){
		var = I2C_Recieve_Data_Ack();
		PORTA |= (1<<PA6);
		if (var > 50){
			PORTA |= (1<<PA7);
		}
		else{
			PORTA &= ~(1<<PA7);
		}
		tenth = var%10;
		units = var/10;
		PORTD = tenth;
		PORTD &= ~(1<<PD4);
		PORTD |= (1<<PD5);

		_delay_ms(20);
		PORTD = units;
		PORTD |= (1<<PD4);
		PORTD &= ~(1<<PD5);

		_delay_ms(50);
	}

	return 0;
}
