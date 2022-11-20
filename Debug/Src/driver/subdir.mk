################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/driver/Can_BxCan.c \
../Src/driver/stm32f407_flash_driver.c \
../Src/driver/stm32f407_gpio_driver.c \
../Src/driver/stm32f407_usart_driver.c 

OBJS += \
./Src/driver/Can_BxCan.o \
./Src/driver/stm32f407_flash_driver.o \
./Src/driver/stm32f407_gpio_driver.o \
./Src/driver/stm32f407_usart_driver.o 

C_DEPS += \
./Src/driver/Can_BxCan.d \
./Src/driver/stm32f407_flash_driver.d \
./Src/driver/stm32f407_gpio_driver.d \
./Src/driver/stm32f407_usart_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Src/driver/%.o Src/driver/%.su: ../Src/driver/%.c Src/driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-driver

clean-Src-2f-driver:
	-$(RM) ./Src/driver/Can_BxCan.d ./Src/driver/Can_BxCan.o ./Src/driver/Can_BxCan.su ./Src/driver/stm32f407_flash_driver.d ./Src/driver/stm32f407_flash_driver.o ./Src/driver/stm32f407_flash_driver.su ./Src/driver/stm32f407_gpio_driver.d ./Src/driver/stm32f407_gpio_driver.o ./Src/driver/stm32f407_gpio_driver.su ./Src/driver/stm32f407_usart_driver.d ./Src/driver/stm32f407_usart_driver.o ./Src/driver/stm32f407_usart_driver.su

.PHONY: clean-Src-2f-driver

