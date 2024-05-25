/*
 * Scheduler.h
 *
 *  Created on: 25 May 2024
 *      Author: marmar
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

extern void Scheduler_init(void);
extern void Scheduler_Run(void);
extern void Scheduler_2ms_Task_Create(void (*ptr) (void));
extern void Scheduler_5ms_Task_Create(void (*ptr) (void));
extern void Scheduler_10ms_Task_Create(void (*ptr) (void));
extern void Scheduler_100ms_Task_Create(void (*ptr) (void));
extern void Scheduler_500ms_Task_Create(void (*ptr) (void));
extern void Scheduler_1000ms_Task_Create(void (*ptr) (void));



#endif /* SCHEDULER_H_ */
