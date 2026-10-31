/**
 * @file    main.c
 * @brief   PWM demo: steps the duty cycle every second.
 * @author  Marawan Azmy
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "PWM.h"
#include <util/delay.h>

int main(){
	init_PWM();

	while (1){
		start_PWM(254);
		_delay_ms(1000);
		start_PWM(128);
		_delay_ms(1000);
		start_PWM(20);
		_delay_ms(1000);
	}

	return 0;
}
