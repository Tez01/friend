################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F/port.c 

OBJS += \
./Drivers/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F/port.o 

C_DEPS += \
./Drivers/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F/port.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F/%.o Drivers/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F/%.su: ../Drivers/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F/%.c Drivers/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I"/home/tej/programming_projects/friend/stm/Drivers/CMSIS/ARM" -I"/home/tej/programming_projects/friend/stm/Drivers/Third_Party/FreeRTOS" -I"/home/tej/programming_projects/friend/stm/Drivers/Third_Party/FreeRTOS/include" -I"/home/tej/programming_projects/friend/stm/Drivers/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F" -I"/home/tej/programming_projects/friend/stm/Drivers/CMSIS/ST" -I"/home/tej/programming_projects/friend/stm/Src/common" -I"/home/tej/programming_projects/friend/stm/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Third_Party-2f-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM4F

clean-Drivers-2f-Third_Party-2f-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM4F:
	-$(RM) ./Drivers/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F/port.d ./Drivers/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F/port.o ./Drivers/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F/port.su

.PHONY: clean-Drivers-2f-Third_Party-2f-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM4F

