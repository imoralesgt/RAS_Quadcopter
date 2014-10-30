################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Compiler'
	"C:/Users/Ivan/Downloads/energia-0101E0012/hardware/tools/lm4f/bin/arm-none-eabi-gcc.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fno-rtti -fno-exceptions -DF_CPU=80000000L -DARDUINO=101 -DENERGIA=10 -I"C:/Users/Ivan/Downloads/energia-0101E0012/hardware/tools/lm4f/arm-none-eabi/include" -I"C:/Users/Ivan/Downloads/energia-0101E0012/hardware/lm4f/cores/lm4f" -I"C:/Users/Ivan/Downloads/energia-0101E0012/hardware/lm4f/variants/stellarpad" -I"C:/Users/Ivan/Downloads/energia-0101E0012/hardware/lm4f/libraries/SPI" -Os -ffunction-sections -fdata-sections -fsingle-precision-constant -g -gstrict-dwarf -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


