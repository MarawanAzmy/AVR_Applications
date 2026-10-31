/**
 * @file    Timer1_CTC.h
 * @brief   Timer1 CTC driver API and tick period selection.
 * @author  Marawan Azmy
 */

#ifndef TIMER1_CTC_H_
#define TIMER1_CTC_H_

#include <avr/io.h>
#include "../Service_Layer/PLATFORM_TYPES.h"

#define _1ms_Period (1000UL)
#define _10ms_Period (10000UL)
#define _100ms_Period (100000UL)

#define TimerPeriod (_1ms_Period)	/* Interrupt period in us */

extern void Timer1_init(void);
extern void Timer1_start(void);
extern void Timer1_stop(void);
extern void Timer1_clear(void);
extern uint16 Timer1_reading(void);
extern void Timer1_Set_Cbk(void (*Cbk) (void));	/* Called from the compare-match ISR */

#endif /* TIMER1_CTC_H_ */
