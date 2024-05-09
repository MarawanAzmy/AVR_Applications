#include <avr/io.h>

void UART_Init(long Baud_rate){
	//											
	UCSRB = (1<<RXEN)|(1<<TXEN) ; 				
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0) ;	
	UBRRL =(unsigned char) ((F_CPU / (16*Baud_rate))-1);		
}
void UART_Send_Byte(unsigned char byte_input){
											
	UDR = byte_input;
	while( !(UCSRA&(1<<TXC)) ){}												
	UCSRA|=1<<TXC;								
}
void UART_Send_String( char * string_input){//not sure of string size to set counter var type
	unsigned short i = 0;  //a5ro 65000										
	while(string_input[i] != '\0'){
		UART_Send_Byte(string_input[i]); 
		i++;
	}
}
unsigned char UART_Recieve_Byte(void){			
	while (!(UCSRA & (1<<RXC)));
	return UDR;									
}
void UART_Recieve_String( char * string_returned){
	unsigned short i = 0;  							
	do{
		string_returned[i] =UART_Recieve_Byte();
	}while(string_returned[i++]  != '\0');		
}
