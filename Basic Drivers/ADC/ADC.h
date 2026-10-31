/**
 * @file    ADC.h
 * @brief   ADC driver API.
 * @author  Marawan Azmy
 */

#ifndef ADC_H_
#define ADC_H_

#include "StdTypes.h"
#include <AVR/io.h>

void ADC_Init(void);
uint16 ADC_Read(uint8 Channel);	/* Returns the 10-bit result (0-1023) */

#endif /* ADC_H_ */
