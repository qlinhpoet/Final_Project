################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/middleware/stm32f407_can_middleware.c \
../Src/middleware/stm32f407_flash_middleware.c \
../Src/middleware/stm32f407_gpio_middleware.c 

OBJS += \
./Src/middleware/stm32f407_can_middleware.o \
./Src/middleware/stm32f407_flash_middleware.o \
./Src/middleware/stm32f407_gpio_middleware.o 

C_DEPS += \
./Src/middleware/stm32f407_can_middleware.d \
./Src/middleware/stm32f407_flash_middleware.d \
./Src/middleware/stm32f407_gpio_middleware.d 


# Each subdirectory must supply rules for building sources it contributes
Src/middleware/stm32f407_can_middleware.o: ../Src/middleware/stm32f407_can_middleware.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/middleware/stm32f407_can_middleware.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/middleware/stm32f407_flash_middleware.o: ../Src/middleware/stm32f407_flash_middleware.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/middleware/stm32f407_flash_middleware.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/middleware/stm32f407_gpio_middleware.o: ../Src/middleware/stm32f407_gpio_middleware.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/middleware/stm32f407_gpio_middleware.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

