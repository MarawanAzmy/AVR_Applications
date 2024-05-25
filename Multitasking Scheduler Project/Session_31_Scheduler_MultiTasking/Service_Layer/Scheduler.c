/*
 * Scheduler.c
 *
 *  Created on: 25 May 2024
 *      Author: marmar
 */

#include "../MCAL/Timer1_CTC.h"

static volatile unsigned long Tic_Cnt = 0;
static void (*Task_Ptr[6]) (void);
static void Scheduler_Update(void);


void Scheduler_init(void){
	Timer1_init();
	Timer1_Set_Cbk(Scheduler_Update);

}
void Scheduler_Run(void){
	Timer1_start();

}
void Scheduler_2ms_Task_Create(void (*ptr) (void)){
	Task_Ptr[0] = ptr;
}
void Scheduler_5ms_Task_Create(void (*ptr) (void)){
	Task_Ptr[1] = ptr;


}
void Scheduler_10ms_Task_Create(void (*ptr) (void)){
	Task_Ptr[2] = ptr;


}
void Scheduler_100ms_Task_Create(void (*ptr) (void)){

	Task_Ptr[3] = ptr;

}
void Scheduler_500ms_Task_Create(void (*ptr) (void)){
	Task_Ptr[4] = ptr;


}
void Scheduler_1000ms_Task_Create(void (*ptr) (void)){

	Task_Ptr[5] = ptr;

}

/* Kernel Core */
static void Scheduler_Update(void){

	Tic_Cnt++;

	if(!(Tic_Cnt % 2))
	{
		Task_Ptr[0]();
	}

	if(!(Tic_Cnt % 5))
	{
		Task_Ptr[1]();
	}

	if(!(Tic_Cnt % 10))
	{
		Task_Ptr[2]();
	}

	if(!(Tic_Cnt % 100)){
		Task_Ptr[3]();
	}

	if(!(Tic_Cnt % 500))
	{
		Task_Ptr[4]();
	}

	if(!(Tic_Cnt % 1000))
	{
		Task_Ptr[5]();
	}



}

