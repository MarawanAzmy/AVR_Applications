#include <AVR/io.h>
#include <util/delay.h>
#include "I2C.h"

#define BIT_RATE 32 //either 100(32 reg val) or 400(2 reg val)


int main(void){
	DDRA = (1<<PA7)| (1<<PA6);
DDRD = 0xff;// 0000 1111 3la pinz D0 D1 D2 D3


	I2C_init(0x02);
	unsigned char  var ;
	unsigned char  units ;
	unsigned char  tenth ;

	while(1){
		var =I2C_Recieve_Data_Ack();
		PORTA |= (1<<PA6);
		if (var >50){
			PORTA |=(1<<PA7);
		}
		else{
			PORTA &=~(1<<PA7);
		}
		tenth = var%10;
		units = var/10;
		PORTD = tenth;
		PORTD&= ~(1<<PD4);
		PORTD|= (1<<PD5);


		_delay_ms(20);
		PORTD = units;
		PORTD|= (1<<PD4);
		PORTD&= ~(1<<PD5);



		_delay_ms(50);


	}


	return 0;
}
