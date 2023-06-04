################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Third_Party/FreeRTOS/croutine.c \
../Drivers/Third_Party/FreeRTOS/event_groups.c \
../Drivers/Third_Party/FreeRTOS/list.c \
../Drivers/Third_Party/FreeRTOS/queue.c \
../Drivers/Third_Party/FreeRTOS/stream_buffer.c \
../Drivers/Third_Party/FreeRTOS/tasks.c \
../Drivers/Third_Party/FreeRTOS/timers.c 

OBJS += \
./Drivers/Third_Party/FreeRTOS/croutine.o \
./Drivers/Third_Party/FreeRTOS/event_groups.o \
./Drivers/Third_Party/FreeRTOS/list.o \
./Drivers/Third_Party/FreeRTOS/queue.o \
./Drivers/Third_Party/FreeRTOS/stream_buffer.o \
./Drivers/Third_Party/FreeRTOS/tasks.o \
./Drivers/Third_Party/FreeRTOS/timers.o 

C_DEPS += \
./Drivers/Third_Party/FreeRTOS/croutine.d \
./Drivers/Third_Party/FreeRTOS/event_groups.d \
./Drivers/Third_Party/FreeRTOS/list.d \
./Drivers/Third_Party/FreeRTOS/queue.d \
./Drivers/Third_Party/FreeRTOS/stream_buffer.d \
./Drivers/Third_Party/FreeRTOS/tasks.d \
./Drivers/Third_Party/FreeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Third_Party/FreeRTOS/%.o Drivers/Third_Party/FreeRTOS/%.su: ../Drivers/Third_Party/FreeRTOS/%.c Drivers/Third_Party/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I"/home/tej/programming_projects/friend/stm/Drivers/CMSIS/ARM" -I"/home/tej/programming_projects/friend/stm/Drivers/Third_Party/FreeRTOS" -I"/home/tej/programming_projects/friend/stm/Drivers/Third_Party/FreeRTOS/include" -I"/home/tej/programming_projects/friend/stm/Drivers/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F" -I"/home/tej/programming_projects/friend/stm/Drivers/CMSIS/ST" -I"/home/tej/programming_projects/friend/stm/Src/common" -I"/home/tej/programming_projects/friend/stm/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Third_Party-2f-FreeRTOS

clean-Drivers-2f-Third_Party-2f-FreeRTOS:
	-$(RM) ./Drivers/Third_Party/FreeRTOS/croutine.d ./Drivers/Third_Party/FreeRTOS/croutine.o ./Drivers/Third_Party/FreeRTOS/croutine.su ./Drivers/Third_Party/FreeRTOS/event_groups.d ./Drivers/Third_Party/FreeRTOS/event_groups.o ./Drivers/Third_Party/FreeRTOS/event_groups.su ./Drivers/Third_Party/FreeRTOS/list.d ./Drivers/Third_Party/FreeRTOS/list.o ./Drivers/Third_Party/FreeRTOS/list.su ./Drivers/Third_Party/FreeRTOS/queue.d ./Drivers/Third_Party/FreeRTOS/queue.o ./Drivers/Third_Party/FreeRTOS/queue.su ./Drivers/Third_Party/FreeRTOS/stream_buffer.d ./Drivers/Third_Party/FreeRTOS/stream_buffer.o ./Drivers/Third_Party/FreeRTOS/stream_buffer.su ./Drivers/Third_Party/FreeRTOS/tasks.d ./Drivers/Third_Party/FreeRTOS/tasks.o ./Drivers/Third_Party/FreeRTOS/tasks.su ./Drivers/Third_Party/FreeRTOS/timers.d ./Drivers/Third_Party/FreeRTOS/timers.o ./Drivers/Third_Party/FreeRTOS/timers.su

.PHONY: clean-Drivers-2f-Third_Party-2f-FreeRTOS

