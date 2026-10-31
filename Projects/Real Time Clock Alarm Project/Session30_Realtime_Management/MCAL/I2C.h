/**
 * @file    I2C.h
 * @brief   I2C (TWI) driver API. The caller sends START, the address and STOP
 *          explicitly, so multi-byte and repeated-START transfers are possible.
 * @author  Marawan Azmy
 */

#ifndef I2C_H_
#define I2C_H_

extern void I2C_init(unsigned char MyAddress);

extern void I2C_Send_Start(void);
extern void I2C_Send_Address_Read(unsigned char address);
extern void I2C_Send_Address_Write(unsigned char address);
extern void I2C_Send_Data(unsigned char data);
extern unsigned char I2C_Recieve_Data_Ack(void);
extern unsigned char I2C_Recieve_Data_No_Ack(void);
extern void I2C_Send_End(void);

extern void I2C_Send_Byte_Generic(unsigned char address, unsigned char data);	/* START, SLA+W, data, STOP */

#endif /* I2C_H_ */
