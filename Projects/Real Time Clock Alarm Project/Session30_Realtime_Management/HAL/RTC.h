/*
 * RTC.h
 *
 *  Created on: 24 May 2024
 *      Author: marmar
 */

#ifndef RTC_H_
#define RTC_H_

#include <util/delay.h>
#include "../MCAL/I2C.h"

typedef struct rtc{

	unsigned char sec;
	unsigned char min;
	unsigned char hour;
	unsigned char day;
	unsigned char date;
	unsigned char month;
	unsigned char year;
	unsigned char control;


}RTC;


#define RTC_Address (0b01101000)
#define hr_12_24  24
extern void RTC_init(void);
extern void RTC_set_parameters(RTC * RTC_Settings);
extern RTC RTC_get_parameters(void);


#endif /* RTC_H_ */
