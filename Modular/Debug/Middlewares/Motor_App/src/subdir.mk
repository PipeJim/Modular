################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Motor_App/src/Mtr_App.c 

OBJS += \
./Middlewares/Motor_App/src/Mtr_App.o 

C_DEPS += \
./Middlewares/Motor_App/src/Mtr_App.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Motor_App/src/%.o Middlewares/Motor_App/src/%.su Middlewares/Motor_App/src/%.cyclo: ../Middlewares/Motor_App/src/%.c Middlewares/Motor_App/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Drivers/StpMotor/inc -I../Middlewares/Motor_App/inc -I"D:/STM32_Modular/Modular/Modular/Middlewares/uart_wrpr_drv/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Motor_App-2f-src

clean-Middlewares-2f-Motor_App-2f-src:
	-$(RM) ./Middlewares/Motor_App/src/Mtr_App.cyclo ./Middlewares/Motor_App/src/Mtr_App.d ./Middlewares/Motor_App/src/Mtr_App.o ./Middlewares/Motor_App/src/Mtr_App.su

.PHONY: clean-Middlewares-2f-Motor_App-2f-src

