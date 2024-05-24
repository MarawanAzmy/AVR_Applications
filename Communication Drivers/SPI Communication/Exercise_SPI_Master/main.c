#include"SPI.h"
#include<avr/io.h>
#include <util/delay.h>
#define MST_SLV = MST//maybe use this

//change init in c file, master slave selection				// IMPORTANT change when slave
 int main(){
	//master DDR config
	DDRB |= (1<<PB7)|(1<<PB5)|(1<<PB4)|(1<<PB0)|(1<<PB1); //SCK, MOSI, SS output//pins zero,one to control slave selection
	DDRB &= ~(1<<PB6); // MISO

	SPI_init();


	while(1){
		PORTB &= ~(1<<PB0);
		PORTB |= (1<<PB1);
		SPI_Send_Byte('y',0);
		_delay_ms(1000);
		SPI_Send_Byte('n',0);
		_delay_ms(1000);


		PORTB |=(1<<PB0);
		PORTB &= ~ (1<<PB1);
		SPI_Send_Byte('y',0);
		_delay_ms(1000);
		SPI_Send_Byte('n',0);
		_delay_ms(1000);

	}


	return 0;
}

