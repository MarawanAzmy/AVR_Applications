/**
 * @file    main.c
 * @brief   UART terminal: 'y' turns the LED on PD5 on, 'n' turns it off.
 * @author  Marawan Azmy
 */

#include "UART.h"
#include <avr/io.h>

int main(){
	UART_Init(9600);
	UART_Send_String("Press y for ON, n for led off  \r");

	DDRD = (1<<PD5);

	while(1){
		char x = UART_Recieve_Byte();	/* Blocks until a byte arrives */

		switch (x){
		case 'y': PORTD |= (1<<PD5); UART_Send_String("LED is ON :D \r"); break;
		case 'n': PORTD &= ~(1<<PD5); UART_Send_String("LED is OFF :( \r"); break;
		default: UART_Send_String("Invalid char \r"); break;
		}
	}

	return 0;
}
