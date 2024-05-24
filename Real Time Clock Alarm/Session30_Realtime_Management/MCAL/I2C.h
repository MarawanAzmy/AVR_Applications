#ifndef I2C_H_
#define I2C_H_
//hna enta elli btb3t el start wl stop 3shan lw 3yz multi start aw 7aga
//hna enta eli btb3t el address 3shan pure network


extern void I2C_init(unsigned char MyAddress);

extern void I2C_Send_Start(void);//extra 3n SPI

extern void I2C_Send_Address_Read(unsigned char address);//extra 3n SPI //momkn tda5alha m3 el init
extern void I2C_Send_Address_Write(unsigned char address);//extra 3n SPI

extern void I2C_Send_Data(unsigned char data);

extern unsigned char I2C_Recieve_Data_Ack(void);
extern unsigned char I2C_Recieve_Data_No_Ack(void);

extern void I2C_Send_End(void);//extra 3n SPI


extern void I2C_Send_Byte_Generic(unsigned char address,unsigned char data );//Start, addr_Write, data, stop
//momkn t3ml send generic(start, address, data, stop) bs kda momkn t limitak le 1 byte bas


#endif /* I2C_H_ */
