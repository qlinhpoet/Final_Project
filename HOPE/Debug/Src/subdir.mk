################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Can.c \
../Src/Can_BxCan.c \
../Src/Can_IPW.c \
../Src/main.c \
../Src/stm32f407_gpio_driver.c \
../Src/stm32f407_usart_driver.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/Can.o \
./Src/Can_BxCan.o \
./Src/Can_IPW.o \
./Src/main.o \
./Src/stm32f407_gpio_driver.o \
./Src/stm32f407_usart_driver.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/Can.d \
./Src/Can_BxCan.d \
./Src/Can_IPW.d \
./Src/main.d \
./Src/stm32f407_gpio_driver.d \
./Src/stm32f407_usart_driver.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I"D:/ST/STM32CubeIDE_1.10.1/HOPE/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/Can.d ./Src/Can.o ./Src/Can.su ./Src/Can_BxCan.d ./Src/Can_BxCan.o ./Src/Can_BxCan.su ./Src/Can_IPW.d ./Src/Can_IPW.o ./Src/Can_IPW.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/stm32f407_gpio_driver.d ./Src/stm32f407_gpio_driver.o ./Src/stm32f407_gpio_driver.su ./Src/stm32f407_usart_driver.d ./Src/stm32f407_usart_driver.o ./Src/stm32f407_usart_driver.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

