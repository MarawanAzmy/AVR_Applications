/**
 * @file    main.c
 * @brief   I2C master (address 0x01): sends two values to slave 0x02, one per second.
 * @author  Marawan Azmy
 */

#include <AVR/io.h>
#include <util/delay.h>
#include "I2C.h"

#define BIT_RATE 32	/* TWBR: 32 = 100 kHz, 2 = 400 kHz */

int main(void){
	DDRA = (1<<PA6);

	I2C_init(0x01);

	while(1){
		I2C_Send_Start();
		PORTA |= (1<<PA6);
		I2C_Send_Address_Write(0x02);
		I2C_Send_Data((unsigned char)91);
		I2C_Send_End();
		_delay_ms(1000);
		PORTA &= ~(1<<PA6);

		I2C_Send_Start();
		I2C_Send_Address_Write(0x02);
		I2C_Send_Data((unsigned char)17);
		I2C_Send_End();
		_delay_ms(1000);
	}

	return 0;
}
