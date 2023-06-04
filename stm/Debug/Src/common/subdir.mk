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
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I"/home/tej/programming_projects/friend/stm/Drivers/CMSIS/ARM" -I"/home/tej/programming_projects/friend/stm/Drivers/Third_Party/FreeRTOS" -I"/home/tej/programming_projects/friend/stm/Drivers/Third_Party/FreeRTOS/include" -I"/home/tej/programming_projects/friend/stm/Drivers/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F" -I"/home/tej/programming_projects/friend/stm/Drivers/CMSIS/ST" -I"/home/tej/programming_projects/friend/stm/Src/common" -I"/home/tej/programming_projects/friend/stm/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-common

clean-Src-2f-common:
	-$(RM) ./Src/common/d_uart.d ./Src/common/d_uart.o ./Src/common/d_uart.su

.PHONY: clean-Src-2f-common

