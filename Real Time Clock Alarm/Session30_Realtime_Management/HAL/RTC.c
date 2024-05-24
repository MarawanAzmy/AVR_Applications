/*
 * RTC.c
 *
 *  Created on: 24 May 2024
 *      Author: marmar
 */


#include "RTC.h"

static unsigned char DecToBcdConvert(unsigned char val){

	return val+ 6*(val/10);

}

static unsigned char BCDToDecConvert(unsigned char val){

	return val- 6*(val>>4);

}

void RTC_init(void){
	I2C_init(0x10);
}

void RTC_set_parameters(RTC * RTC_Settings){

	I2C_Send_Start();
	I2C_Send_Address_Write(RTC_Address);
	I2C_Send_Data(0x00);
	I2C_Send_Data(DecToBcdConvert(RTC_Settings->sec));
	I2C_Send_Data(DecToBcdConvert(RTC_Settings->min));
	//set 12 or 24 h
//24 hr
	if (hr_12_24 == 24){
		I2C_Send_Data((DecToBcdConvert(RTC_Settings->hour)) & ~(1<<6) );
	}
	//12 hr
	if  (hr_12_24 == 12){
	I2C_Send_Data((DecToBcdConvert(RTC_Settings->hour))|(1<<6) );//set bit 5 as 1 if PM
	}
	I2C_Send_Data(DecToBcdConvert(RTC_Settings->day));
	I2C_Send_Data(DecToBcdConvert(RTC_Settings->date));
	I2C_Send_Data(DecToBcdConvert(RTC_Settings->month));
	I2C_Send_Data(DecToBcdConvert(RTC_Settings->year));
	I2C_Send_Data(DecToBcdConvert(RTC_Settings->control));
	I2C_Send_End();
}


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



	if (hr_12_24 == 24){	//if 24 h
		S1.hour = ((S1.hour)&(0x3F));
	}
	if  (hr_12_24 == 12){//if 12 h
		PM_AM = (S1.hour&(1<<5));//1 --> pm / 0 --> am
		S1.hour = ((S1.hour)&(0x1F));
		}




	S1.sec=BCDToDecConvert(S1.sec);
	S1.min=BCDToDecConvert(S1.min);
	S1.hour=BCDToDecConvert(S1.hour);
	//S1.day=BCDToDecConvert(S1.day);

	/*if(PM is true ---> Night Mode) */
	if  (hr_12_24 == 12){//if 12 h
		if( PM_AM){
			S1.hour=(S1.hour)-12;
		}
		}


	return S1;
}





