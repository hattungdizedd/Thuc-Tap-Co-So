################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I"D:/stm32/stmlumi/ktgiuaky_thuctapcoso_group3/Driver/lib_stm" -I"D:/stm32/stmlumi/ktgiuaky_thuctapcoso_group3/Driver/shared/Drivers/CMSIS/Include" -I"D:/stm32/stmlumi/ktgiuaky_thuctapcoso_group3/Driver/shared/Drivers/CMSIS" -I"D:/stm32/stmlumi/ktgiuaky_thuctapcoso_group3/Driver/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"D:/stm32/stmlumi/ktgiuaky_thuctapcoso_group3/Driver/shared/Middle/button" -I"D:/stm32/stmlumi/ktgiuaky_thuctapcoso_group3/Driver/shared/Middle/buzzer" -I"D:/stm32/stmlumi/ktgiuaky_thuctapcoso_group3/Driver/shared/Middle/led" -I"D:/stm32/stmlumi/ktgiuaky_thuctapcoso_group3/Driver/shared/Middle/rtos" -I"D:/stm32/stmlumi/ktgiuaky_thuctapcoso_group3/Driver/shared/Middle/sensor" -I"D:/stm32/stmlumi/ktgiuaky_thuctapcoso_group3/Driver/shared/Middle/serial" -I"D:/stm32/stmlumi/ktgiuaky_thuctapcoso_group3/Driver/shared/Middle/ucglib" -I"D:/stm32/stmlumi/ktgiuaky_thuctapcoso_group3/Driver/shared/Utilities" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

