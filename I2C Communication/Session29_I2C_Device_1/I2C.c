//DONT put |= in TWCR, clear it every time by = ...
//Steps: 1)check 2)send 3) 2 flags int&enable 4)wait till done
//got this from from data sheet,,,,, you can also cancel the first step
//kol mara btktbo enta aflt el Ack khalle balk, eft7ha kol mra
// w kol mra hat3ml recieve no ack, enta hat2fl mo2akkatan el EA, w tft7o fl op eli b3dha
///khalle balk, fl I cond lma btt2kd mn el SR, bt3ml || msh | wa7da

#include <AVR/io.h>

void I2C_init(unsigned char MyAddress){
	TWBR = 32;//check da mn el video, checked mzboot

	TWCR =  (1<<TWEN) | (1<<TWEA);//Enable I2C //enable acknolagement // |= sa7 wla  = bas?
	TWAR = ((MyAddress<<1)&(0xfe)) ; //set MY slave address, momkn 7ad yd5l rkm bayz, sheel awl bit kda kda

	//shift by 1, 7 bits from bit 1 to bit 7,,,,,,
	//bit 0 in this reg is General call(announcememnt)
	//bit 0 i packet sent is R/w
}

void I2C_Send_Start(void){//hna momkn tsffar el general call kaman, m3 enhya zero

	TWCR = (1<<TWSTA)|(1<<TWINT)|(1<<TWEN)|(1<<TWEA); //start command, = msh |=, 3shn lw 3aml stop mt3mlsh parallel start wl 3aks

	while(!(TWCR&(1<<TWINT)));
	while (!( (TWSR == 0x08)|(TWSR == 0x10) ) );
	//while(!(   (TWCR&(1<<TWINT)) & ( (TWSR == 0x08)|(TWSR == 0x10) ) ));//why not do this/
	//while ! Inturrupt (TWINT) down and start/repeated start transmitted (same for any master mode)

}
void I2C_Send_End(void){//b3d el stop m3ndesh wla inturrupt wla ack,  you finished khalas

	TWCR = (1<<TWSTO)|(1<<TWEN)|(1<<TWINT)|(1<<TWEA); //End command

}

void I2C_Send_Address_Read(unsigned char address){

	//TWDR = 0x01;//assume W/R  read is 1, 3shn hna m3kosa// IMPORTANT HWA DA HAYGENERATE INTURRUPT ?
	//or m3 el 1 w rayya7 nfsk
	TWDR =  (address<<1) | 0x01 ;
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);

	while(!(TWCR&(1<<TWINT)));
	while (!( (TWSR == 0x40)|(TWSR == 0x48) ) ); // RRRRR
	//while ! Inturrupt (TWINT) and SLA+R transmitted down wz ack or not


}//momkn tda5alha m3 el init

void I2C_Send_Address_Write(unsigned char address){

	//	TWDR = 0x00;//assume W/R write is 0, 3shn hna m3kosa
	TWDR =  (address<<1) & 0xfe; //&1111 1110
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);

	while(!(TWCR&(1<<TWINT)));
	while (!( (TWSR == 0x18)|(TWSR == 0x20) ) );//WWWWW
	//while ! Inturrupt (TWINT) and SLA+W transmitted down wz ack or not

}
void I2C_Send_Data(unsigned char data){


	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(!(TWCR&(1<<TWINT)));
	while (!( (TWSR == 0x28)|(TWSR == 0x30)|(TWSR == 0xB8)|(TWSR == 0xC0) ) );
	//while ! Inturrupt (TWINT) down and data transmitted(master ac, nac, slave ack, nac)

}

unsigned char I2C_Recieve_Data_Ack(void){//tb lw geh int w msh recieve, meen hyw2fo? w2fo enta ysta

	while(1){
		while(!(   (TWCR&(1<<TWINT))  )){};

		if ( (TWSR == 0x50)||(TWSR == 0x80) ){	//galak inturrupt w by2olk feh daata revieved = Ack (naster or salve}
			TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
			break;
		}else{
			TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
		}
	}

	return TWDR ;
}
unsigned char I2C_Recieve_Data_No_Ack(void){//tb lw geh int w msh recieve, meen hyw2fo? w2fo enta ysta
	while(1){
		while(!(   (TWCR&(1<<TWINT))  )){};

		if ( (TWSR == 0x58)||(TWSR == 0x88) ){	//galak inturrupt w by2olk feh daata revieved = Ack (naster or salve}
			TWCR = (1<<TWINT)|(1<<TWEN);
			break;
		}else{
			TWCR = (1<<TWINT)|(1<<TWEN);
		}
	}

	return TWDR ;
}



void I2C_Send_Byte_Generic(unsigned char address,unsigned char data ){

	I2C_Send_Start();
	I2C_Send_Address_Write(address);
	I2C_Send_Data(data);
	I2C_Send_End();
}//Start, addr_Write, data, stop

