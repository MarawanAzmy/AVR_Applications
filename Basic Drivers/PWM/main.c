#include <avr/io.h>
#include <avr/interrupt.h>
#include "PWM.h"
#include <util/delay.h>
int main(){
//	PORTB = 0x00;
	init_PWM();



	while (1){

	start_PWM(254);//, short pin
	_delay_ms(1000);
	start_PWM(128);
	_delay_ms(1000);
	start_PWM(20);
	_delay_ms(1000);

	}

	return 0;
}
