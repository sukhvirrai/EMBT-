################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include utilities/subdir.mk
-include startup/subdir.mk
-include source/subdir.mk
-include drivers/subdir.mk
-include device/subdir.mk
-include component/uart/subdir.mk
-include component/serial_manager/subdir.mk
-include component/lists/subdir.mk
-include board/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: lpcxpresso54114_sctimer_simple_pwm.axf

# Tool invocations
lpcxpresso54114_sctimer_simple_pwm.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/sukhvir/Documents/MCUXpresso_10.3.1_2233/workspace/lpcxpresso54114_sctimer_simple_pwm/libs" -Xlinker -Map="lpcxpresso54114_sctimer_simple_pwm.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -T lpcxpresso54114_sctimer_simple_pwm_Debug.ld -o "lpcxpresso54114_sctimer_simple_pwm.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) lpcxpresso54114_sctimer_simple_pwm.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "lpcxpresso54114_sctimer_simple_pwm.axf"; # arm-none-eabi-objcopy -v -O binary "lpcxpresso54114_sctimer_simple_pwm.axf" "lpcxpresso54114_sctimer_simple_pwm.bin" ; # checksum -p LPC54114J256 -d "lpcxpresso54114_sctimer_simple_pwm.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
