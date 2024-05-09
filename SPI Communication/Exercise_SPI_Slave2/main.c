#include"SPI.h"
#include<avr/io.h>
#include <util/delay.h>
#define MST_SLV = SLV//maybe use this

//change init in c file, master slave selection				// IMPORTANT change when slave
int main(){
	//SLAVE DDR config
	DDRB |= (1<<PB6); //MISO out
	DDRB &= ~(	(1<<PB5)|(1<<PB4)|(1<<PB7)	); // MOSI input // SS input // SCK input

	DDRD |= (1<<PD0);//LED

	SPI_init();//configured as slave

	unsigned char data ;
	while(1){

		data = SPI_Recieve_Byte();
		if (data =='y' ){
			PORTD  |= (1<<PD0);


		}else if (data =='n' )

			PORTD  &= ~(1<<PD0);
	}


	return 0;
}

