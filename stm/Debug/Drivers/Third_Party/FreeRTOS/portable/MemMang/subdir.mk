################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Third_Party/FreeRTOS/portable/MemMang/heap_4.c 

OBJS += \
./Drivers/Third_Party/FreeRTOS/portable/MemMang/heap_4.o 

C_DEPS += \
./Drivers/Third_Party/FreeRTOS/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Third_Party/FreeRTOS/portable/MemMang/%.o Drivers/Third_Party/FreeRTOS/portable/MemMang/%.su: ../Drivers/Third_Party/FreeRTOS/portable/MemMang/%.c Drivers/Third_Party/FreeRTOS/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I"/home/tej/programming_projects/friend/stm/Drivers/CMSIS/ARM" -I"/home/tej/programming_projects/friend/stm/Drivers/CMSIS/ST" -I"/home/tej/programming_projects/friend/stm/Src/common" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Third_Party-2f-FreeRTOS-2f-portable-2f-MemMang

clean-Drivers-2f-Third_Party-2f-FreeRTOS-2f-portable-2f-MemMang:
	-$(RM) ./Drivers/Third_Party/FreeRTOS/portable/MemMang/heap_4.d ./Drivers/Third_Party/FreeRTOS/portable/MemMang/heap_4.o ./Drivers/Third_Party/FreeRTOS/portable/MemMang/heap_4.su

.PHONY: clean-Drivers-2f-Third_Party-2f-FreeRTOS-2f-portable-2f-MemMang

