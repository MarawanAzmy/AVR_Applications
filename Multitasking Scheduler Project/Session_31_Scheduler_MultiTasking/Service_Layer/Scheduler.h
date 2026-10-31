/**
 * @file    Scheduler.h
 * @brief   Time-triggered scheduler API: one task slot per period (2, 5, 10, 100, 500 and 1000 ms).
 * @author  Marawan Azmy
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
