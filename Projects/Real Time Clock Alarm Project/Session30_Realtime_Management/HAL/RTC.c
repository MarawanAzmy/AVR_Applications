/**
 * @file    RTC.c
 * @brief   DS1307 real-time clock driver over I2C.
 * @author  Marawan Azmy
 */

#include "RTC.h"

/* The DS1307 stores all time fields in BCD. */
static unsigned char DecToBcdConvert(unsigned char val){
	return val + 6*(val/10);
}

static unsigned char BCDToDecConvert(unsigned char val){
	return val - 6*(val>>4);
}

void RTC_init(void){
	I2C_init(0x10);
}

/* Writes registers 0x00-0x07, starting from the seconds register. */
void RTC_set_parameters(RTC * RTC_Settings){
	I2C_Send_Start();
	I2C_Send_Address_Write(RTC_Address);
	I2C_Send_Data(0x00);
	I2C_Send_Data(DecToBcdConvert(RTC_Settings->sec));
	I2C_Send_Data(DecToBcdConvert(RTC_Settings->min));
	/* Hours register bit 6: 0 = 24-hour mode, 1 = 12-hour mode */
	if (hr_12_24 == 24){
		I2C_Send_Data((DecToBcdConvert(RTC_Settings->hour)) & ~(1<<6));
	}
	if (hr_12_24 == 12){
		I2C_Send_Data((DecToBcdConvert(RTC_Settings->hour))|(1<<6));
	}
	I2C_Send_Data(DecToBcdConvert(RTC_Settings->day));
	I2C_Send_Data(DecToBcdConvert(RTC_Settings->date));
	I2C_Send_Data(DecToBcdConvert(RTC_Settings->month));
	I2C_Send_Data(DecToBcdConvert(RTC_Settings->year));
	I2C_Send_Data(DecToBcdConvert(RTC_Settings->control));
	I2C_Send_End();
}

/* Points the register address at 0x00, then reads seconds, minutes, hours and day. */
RTC RTC_get_parameters(void){
	RTC S1;
	unsigned char PM_AM=0;

	I2C_Send_Start();
	I2C_Send_Address_Write(RTC_Address);
	I2C_Send_Data(0x00);
	I2C_Send_End();

	I2C_Send_Start();
	I2C_Send_Address_Read(RTC_Address);
	S1.sec = I2C_Recieve_Data_Ack();
	S1.min = I2C_Recieve_Data_Ack();
	S1.hour = I2C_Recieve_Data_Ack();
	S1.day = I2C_Recieve_Data_No_Ack();
	I2C_Send_End();

	if (hr_12_24 == 24){
		S1.hour = ((S1.hour)&(0x3F));
	}
	if (hr_12_24 == 12){
		PM_AM = (S1.hour&(1<<5));	/* Bit 5 in 12-hour mode: 1 = PM */
		S1.hour = ((S1.hour)&(0x1F));
	}

	S1.sec = BCDToDecConvert(S1.sec);
	S1.min = BCDToDecConvert(S1.min);
	S1.hour = BCDToDecConvert(S1.hour);

	if (hr_12_24 == 12){
		if(PM_AM){
			S1.hour = (S1.hour)-12;
		}
	}

	return S1;
}
