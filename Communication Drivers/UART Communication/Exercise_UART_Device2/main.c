/**
 * @file    main.c
 * @brief   UART sender: sends 'y' and 'n' alternately, one per second.
 * @author  Marawan Azmy
 */

#include "UART.h"
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
