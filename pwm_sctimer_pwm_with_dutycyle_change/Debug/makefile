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
all: pwm_sctimer_pwm_with_dutycyle_change.axf

# Tool invocations
pwm_sctimer_pwm_with_dutycyle_change.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/sukhvir/Documents/MCUXpresso_10.3.1_2233/workspace/pwm_sctimer_pwm_with_dutycyle_change/libs" -Xlinker -Map="pwm_sctimer_pwm_with_dutycyle_change.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -T pwm_sctimer_pwm_with_dutycyle_change_Debug.ld -o "pwm_sctimer_pwm_with_dutycyle_change.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) pwm_sctimer_pwm_with_dutycyle_change.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "pwm_sctimer_pwm_with_dutycyle_change.axf"; # arm-none-eabi-objcopy -v -O binary "pwm_sctimer_pwm_with_dutycyle_change.axf" "pwm_sctimer_pwm_with_dutycyle_change.bin" ; # checksum -p LPC54114J256 -d "pwm_sctimer_pwm_with_dutycyle_change.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
