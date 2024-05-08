/*
 * main.c
 *
 *  Created on: 8 May 2024
 *      Author: marmar
 */


#include "UART.h"
//TRY to add null while sending w shof el fr2 m3ak pls
#include <avr/io.h>
#include <util/delay.h>

int main(){

	UART_Init(9600);

	while(1){

		UART_Send_Byte('y');
		_delay_ms(1000);

		UART_Send_Byte('n');
		_delay_ms(1000);
	}
	return 0;
}
