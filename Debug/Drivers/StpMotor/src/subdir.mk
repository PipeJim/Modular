################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/StpMotor/src/stpMotor.c 

OBJS += \
./Drivers/StpMotor/src/stpMotor.o 

C_DEPS += \
./Drivers/StpMotor/src/stpMotor.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/StpMotor/src/%.o Drivers/StpMotor/src/%.su Drivers/StpMotor/src/%.cyclo: ../Drivers/StpMotor/src/%.c Drivers/StpMotor/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../USB_HOST/App -I../USB_HOST/Target -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-StpMotor-2f-src

clean-Drivers-2f-StpMotor-2f-src:
	-$(RM) ./Drivers/StpMotor/src/stpMotor.cyclo ./Drivers/StpMotor/src/stpMotor.d ./Drivers/StpMotor/src/stpMotor.o ./Drivers/StpMotor/src/stpMotor.su

.PHONY: clean-Drivers-2f-StpMotor-2f-src

