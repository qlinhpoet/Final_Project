################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/middleware/stm32f407_flash_middleware.c 

OBJS += \
./Src/middleware/stm32f407_flash_middleware.o 

C_DEPS += \
./Src/middleware/stm32f407_flash_middleware.d 


# Each subdirectory must supply rules for building sources it contributes
Src/middleware/%.o Src/middleware/%.su: ../Src/middleware/%.c Src/middleware/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-middleware

clean-Src-2f-middleware:
	-$(RM) ./Src/middleware/stm32f407_flash_middleware.d ./Src/middleware/stm32f407_flash_middleware.o ./Src/middleware/stm32f407_flash_middleware.su

.PHONY: clean-Src-2f-middleware

