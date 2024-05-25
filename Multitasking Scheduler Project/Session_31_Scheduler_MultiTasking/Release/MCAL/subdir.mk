################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ADC.c \
../MCAL/PWM.c \
../MCAL/Timer1_CTC.c \
../MCAL/timer0.c 

OBJS += \
./MCAL/ADC.o \
./MCAL/PWM.o \
./MCAL/Timer1_CTC.o \
./MCAL/timer0.o 

C_DEPS += \
./MCAL/ADC.d \
./MCAL/PWM.d \
./MCAL/Timer1_CTC.d \
./MCAL/timer0.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c MCAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


