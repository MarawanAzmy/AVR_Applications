/**
 * @file    UART.c
 * @brief   UART driver: asynchronous 8N1, polling.
 * @author  Marawan Azmy
 */

#include <avr/io.h>

void UART_Init(long Baud_rate){
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);	/* URSEL selects UCSRC; 8 data bits, no parity, 1 stop bit */
	UBRRL = (unsigned char) ((F_CPU / (16*Baud_rate))-1);	/* UBRR = F_CPU / (16 * baud) - 1, 51 for 9600 baud at 8 MHz */
}

void UART_Send_Byte(unsigned char byte_input){
	UDR = byte_input;
	while(!(UCSRA&(1<<TXC))){}	/* Wait until the frame is fully shifted out */
	UCSRA |= 1<<TXC;	/* Clear TXC by writing 1 */
}

void UART_Send_String(char *string_input){
	unsigned short i = 0;

	while(string_input[i] != '\0'){	/* The terminating '\0' is not sent */
		UART_Send_Byte(string_input[i]);
		i++;
	}
}

unsigned char UART_Recieve_Byte(void){
	while (!(UCSRA & (1<<RXC)));
	return UDR;
}

/* Receives bytes up to and including the terminating '\0'. */
void UART_Recieve_String(char *string_returned){
	unsigned short i = 0;

	do{
		string_returned[i] = UART_Recieve_Byte();
	}while(string_returned[i++] != '\0');
}
