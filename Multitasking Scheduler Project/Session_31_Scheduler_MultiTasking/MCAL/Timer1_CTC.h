/*
 * Timer1_CTC.h
 *
 *  Created on: 25 May 2024
 *      Author: marmar
 */

#ifndef TIMER1_CTC_H_
#define TIMER1_CTC_H_

#include<avr/io.h>
#include "../Service_Layer/PLATFORM_TYPES.h"

#define _1ms_Period (1000UL)
#define _10ms_Period (10000UL)
#define _100ms_Period (100000UL)

#define TimerPeriod (_1ms_Period) //select the real time period before interrupt flag (will use compare match)

extern void Timer1_init(void);
extern void Timer1_start(void);
extern void Timer1_stop(void);
extern void Timer1_clear(void);
extern uint16 Timer1_reading(void);
extern void Timer1_Set_Cbk(void (*Cbk) (void)); //take pointer to fun that take void and return void



#endif /* TIMER1_CTC_H_ */
