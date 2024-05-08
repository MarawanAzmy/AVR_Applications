//read reg bit if(reg& 1<<bit3) t2reban, & wa7da 3shn yb2a bitwise operation, msh && eli hya logic true false :D da haydeek ay rakam akbr ml zero, therefore TRUE, laken lw msh set hydeek false
//write reg bit reg = 1<<bit

#include <avr/io.h>

void UART_Init(long Baud_rate){
	//											//mlhash lzma, el speed division
	UCSRB = (1<<RXEN)|(1<<TXEN) ; 				//feh bit m2gleeno lel gadwal UCSZ2
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0) ;	//selector to write in this reg(default 1), asynchronus set bu default
	//|(0<<UMSEL)|(0<<UPM0)|(0<<UPM1) THIS IS NOT WRITING ZERO!!! reg &= ~(1<<bit)											//note koll dol default aslan,  7ta UCZ1 w 0 w 2
	//UCSRC &=(~(1<<URSEL)); //da 3shn troo7 UBRRH, enta hna msh m7tago aslan							//momknUCSRC w momkn esm tani URRH
	UBRRL =(unsigned char) ((F_CPU / (16*Baud_rate))-1);		//low bs 3shn ghalbn 9600, msh m7tag high hna//ghalbn htb2a 51 for 9600
}

void UART_Send_Byte(unsigned char byte_input){
												//IMPORTANT
												//dint forget to send start and end bits, wla dol automatic????????
	UDR = byte_input;
	while( !(UCSRA&(1<<TXC)) ){}				//while not reg empty and last frame shifted
												//this line after writing, 3shn a clear t7t br7ty, maclearsh w hwa lesa byb3t lw kan el satr da foo2
	UCSRA|=1<<TXC;								//clear reg
}
void UART_Send_String( char * string_input){//not sure of string size to set counter var type
	unsigned short i = 0;  //a5ro 65000
												//tnf3 while msh lazm do while
	while(string_input[i] != '\0'){
		UART_Send_Byte(string_input[i]); //mat7otesh el nulll char, hwa 3aml kda, es2l leeh!!!
		i++;
	}

}

unsigned char UART_Recieve_Byte(void){			//each byte is a char

	while (!(UCSRA & (1<<RXC)));
	return UDR;									//hwa el UDR feh el data bas mn gher start w end? ah hwa aslan 8 bits bs

}
void UART_Recieve_String( char * string_returned){//ezay a recieve entire string? each byte is a char

	unsigned short i = 0;  							//a5ro 65000

	do{
		string_returned[i] =UART_Recieve_Byte();

	}while(string_returned[i++]  != '\0');		//do while 3shn akoon sayyevt el char f variable
	// w kaman do while 3shn t7ot el null char mn gher satr zyada
	//he puts null whule recieving, and do not put it while sending, why is this?


}
