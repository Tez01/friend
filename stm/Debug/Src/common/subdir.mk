################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/common/d_uart.c 

OBJS += \
./Src/common/d_uart.o 

C_DEPS += \
./Src/common/d_uart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/common/%.o Src/common/%.su: ../Src/common/%.c Src/common/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -I/home/tej/programming_projects/stm32/stm32_chip_headers -I/home/tej/programming_projects/stm32/stm32_chip_headers/Include -I"/home/tej/programming_projects/gulaam/uart_slv_src_code/Src/common" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-common

clean-Src-2f-common:
	-$(RM) ./Src/common/d_uart.d ./Src/common/d_uart.o ./Src/common/d_uart.su

.PHONY: clean-Src-2f-common
