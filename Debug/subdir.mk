################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BUTTON.c \
../DIO_Program.c \
../LCD_Program.c \
../calculator.c \
../main.c 

OBJS += \
./BUTTON.o \
./DIO_Program.o \
./LCD_Program.o \
./calculator.o \
./main.o 

C_DEPS += \
./BUTTON.d \
./DIO_Program.d \
./LCD_Program.d \
./calculator.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


