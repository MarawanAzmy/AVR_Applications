#include <avr/interrupt.h>

#include "Timer1_CTC.h"//to get "TimerPeriod"

static void (*PTR) (void) = NULL;// pointer to a fun that take void and return void

void Timer1_init(void){
	TCCR1A = (1<<FOC1A)|(1<<FOC1B);
	TCCR1B = (1<<WGM12);
	OCR1A = 0;
	OCR1B = 0;
	ICR1 = 0;
	TIMSK = (1<<OCIE1A);
	SREG = (1<<7);

}
void Timer1_start(void){

	//freq is 8MHz
	//divider is 64, 8MHz.64 = 125k
	//	1/125k = 0.000008 sec, 8 Micro sec, 8us for every single increment in counter, max of 65535 steps
	// set the max no of steps for compare match to achieve 1000 micro sec, 1 melli sec, then stop and repeat counter
	// no of steps = needed time/step time  = 1000 micro/ 8 micro

	/* CTC -> clear timer1 on compare match (no of steps)*/
	OCR1A = (TimerPeriod / 8ul);

	/* 8MHZ/64 -> 1_Tic - 8us*/
	TCCR1B = (1<<CS11)|(1<<CS10)|(1<<WGM12);

}
void Timer1_stop(void){

	TCCR1B = (1<<WGM12);

}
void Timer1_clear(void){
	TCNT1 = 0;


}
uint16 Timer1_reading(void){


	return TCNT1;
}
void Timer1_Set_Cbk(void (*Cbk) (void)){//take pointer to fun that take void and return void


	PTR = Cbk;

}

ISR(TIMER1_COMPA_vect){
	/* Loading the timer register eith the desired value _1ms */
	if(PTR != NULL){
		PTR();
	}

}
