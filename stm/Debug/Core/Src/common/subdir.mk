################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/common/d_uart.c 

OBJS += \
./Core/Src/common/d_uart.o 

C_DEPS += \
./Core/Src/common/d_uart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/common/%.o Core/Src/common/%.su: ../Core/Src/common/%.c Core/Src/common/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I"/home/tej/programming_projects/gulaam/uart_slv_src_code/Drivers/CMSIS/ARM" -I"/home/tej/programming_projects/gulaam/uart_slv_src_code/Drivers/CMSIS/ST" -I"/home/tej/programming_projects/gulaam/uart_slv_src_code/Core/Src/common" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-common

clean-Core-2f-Src-2f-common:
	-$(RM) ./Core/Src/common/d_uart.d ./Core/Src/common/d_uart.o ./Core/Src/common/d_uart.su

.PHONY: clean-Core-2f-Src-2f-common

