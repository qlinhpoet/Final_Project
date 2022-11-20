################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/app/stm32f407_flash_app.c 

OBJS += \
./Src/app/stm32f407_flash_app.o 

C_DEPS += \
./Src/app/stm32f407_flash_app.d 


# Each subdirectory must supply rules for building sources it contributes
Src/app/%.o Src/app/%.su: ../Src/app/%.c Src/app/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-app

clean-Src-2f-app:
	-$(RM) ./Src/app/stm32f407_flash_app.d ./Src/app/stm32f407_flash_app.o ./Src/app/stm32f407_flash_app.su

.PHONY: clean-Src-2f-app

