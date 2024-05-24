/*
 * main.c
 *
 *  Created on: 8 May 2024
 *      Author: marmar
 */


#include "UART.h"
//TRY to add null while sending w shof el fr2 m3ak pls
#include <avr/io.h>


int main(){

UART_Init(9600);
UART_Send_String("Press y for ON, n for led off  \r");

DDRD = (1<<PD5);

while(1){

 char x = UART_Recieve_Byte();//o2of hna estanna 3la mygelk 7aga,khleek wa2f mtnzlsh, 3l freq eli enta 3amlha

switch (x){
case 'y': PORTD |= (1<<PD5); UART_Send_String("LED is ON :D \r");break;
case 'n': PORTD &=~( 1<<PD5); UART_Send_String("LED is OFF :( \r");break;
default  :UART_Send_String("Invalid char \r"); break;
}


	}



	return 0;
}
