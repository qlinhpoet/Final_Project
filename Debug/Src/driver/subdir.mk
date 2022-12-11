################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/driver/stm32f407_can_driver.c \
../Src/driver/stm32f407_flash_driver.c \
../Src/driver/stm32f407_gpio_driver.c \
../Src/driver/stm32f407_rcc_driver.c \
../Src/driver/stm32f407_usart_driver.c 

OBJS += \
./Src/driver/stm32f407_can_driver.o \
./Src/driver/stm32f407_flash_driver.o \
./Src/driver/stm32f407_gpio_driver.o \
./Src/driver/stm32f407_rcc_driver.o \
./Src/driver/stm32f407_usart_driver.o 

C_DEPS += \
./Src/driver/stm32f407_can_driver.d \
./Src/driver/stm32f407_flash_driver.d \
./Src/driver/stm32f407_gpio_driver.d \
./Src/driver/stm32f407_rcc_driver.d \
./Src/driver/stm32f407_usart_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Src/driver/stm32f407_can_driver.o: ../Src/driver/stm32f407_can_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/driver/stm32f407_can_driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/driver/stm32f407_flash_driver.o: ../Src/driver/stm32f407_flash_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/driver/stm32f407_flash_driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/driver/stm32f407_gpio_driver.o: ../Src/driver/stm32f407_gpio_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/driver/stm32f407_gpio_driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/driver/stm32f407_rcc_driver.o: ../Src/driver/stm32f407_rcc_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/driver/stm32f407_rcc_driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/driver/stm32f407_usart_driver.o: ../Src/driver/stm32f407_usart_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/driver/stm32f407_usart_driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

