
#ifndef ADC_H_
#define ADC_H_
#include "../Service_Layer/PLATFORM_TYPES.h"
#include <AVR/io.h>

void ADC_Init(void);//init without setting any additional things


uint16 ADC_Read(uint8 Channel); // hayrga3lk 10 bits, m3ndksh types gher 8w 16,
								//akeed 16 w msh hanfks le bits



#endif /* ADC_H_ */
