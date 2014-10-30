################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/Users/Ivan/Downloads/energia-0101E0012/hardware/tools/lm4f

ORDERED_OBJS += \
"./inc/Enrf24.o" \
"./Enrf24_TXdemo.o" \
$(GEN_CMDS__FLAG) \
-Wl,--start-group \
-Wl,-T"C:/Users/Ivan/Downloads/energia-0101E0012/hardware/lm4f/cores/lm4f/lm4fcpp_blizzard.ld" \
-l"c" \
-l"lptm4c1230c3pm_core" \
-l"m" \
-l"gcc" \
-l"lptm4c1230c3pm_SPI" \
-Wl,--end-group \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include inc/subdir_vars.mk
-include subdir_rules.mk
-include inc/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
Enrf24_TXdemo.out \

EXE_OUTPUTS__QUOTED += \
"Enrf24_TXdemo.out" \

BIN_OUTPUTS += \
Enrf24_TXdemo.hex \

BIN_OUTPUTS__QUOTED += \
"Enrf24_TXdemo.hex" \


# All Target
all: Enrf24_TXdemo.out

dependents:
	-cd C:/Users/Ivan/workspace_v6_0/lptm4c1230c3pm_core/Debug && $(MAKE) all
	-cd C:/Users/Ivan/workspace_v6_0/lptm4c1230c3pm_SPI/Debug && $(MAKE) all

# Tool invocations
Enrf24_TXdemo.out: $(OBJS) $(GEN_CMDS) C:/Users/Ivan/workspace_v6_0/lptm4c1230c3pm_core/Debug/liblptm4c1230c3pm_core.a C:/Users/Ivan/workspace_v6_0/lptm4c1230c3pm_SPI/Debug/liblptm4c1230c3pm_SPI.a
	@echo 'Building target: $@'
	@echo 'Invoking: GNU Linker'
	"C:/Users/Ivan/Downloads/energia-0101E0012/hardware/tools/lm4f/bin/arm-none-eabi-gcc.exe" -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fno-rtti -fno-exceptions -DF_CPU=80000000L -DARDUINO=101 -DENERGIA=10 -Os -ffunction-sections -fdata-sections -fsingle-precision-constant -g -gstrict-dwarf -Wall -Wl,-Map,"Enrf24_TXdemo.map" --entry ResetISR -nostartfiles -nostdlib -Wl,--gc-sections -L"C:/Users/Ivan/workspace_v6_0/lptm4c1230c3pm_core/Debug" -L"C:/Users/Ivan/workspace_v6_0/lptm4c1230c3pm_SPI/Debug" -o"Enrf24_TXdemo.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

Enrf24_TXdemo.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: GNU Objcopy Utility'
	"C:/Users/Ivan/Downloads/energia-0101E0012/hardware/tools/lm4f/bin/arm-none-eabi-objcopy.exe"  $(EXE_OUTPUTS__QUOTED) "Enrf24_TXdemo.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "Enrf24_TXdemo.d" "inc\Enrf24.d" 
	-$(RM) "Enrf24_TXdemo.o" "inc\Enrf24.o" 
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-C:/Users/Ivan/Downloads/energia-0101E0012/hardware/tools/lm4f/bin/arm-none-eabi-objcopy -O binary Enrf24_TXdemo.out Enrf24_TXdemo.bin
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build
C:/Users/Ivan/workspace_v6_0/lptm4c1230c3pm_core/Debug/liblptm4c1230c3pm_core.a:
C:/Users/Ivan/workspace_v6_0/lptm4c1230c3pm_SPI/Debug/liblptm4c1230c3pm_SPI.a:

-include ../makefile.targets

