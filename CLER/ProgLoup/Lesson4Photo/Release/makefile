################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include arduino/core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
/home/loup/Documents/formationembeded/CLER/ProgLoup/Lesson4Photo/Release/arduino.ar \

ELF += \
Lesson4Photo.elf \

EEP += \
Lesson4Photo.eep \

FLASH_IMAGE += \
Lesson4Photo.hex \


# All Target
all: Lesson4Photo

# Tool invocations
Lesson4Photo: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/bin/avr-size" -A "/home/loup/Documents/formationembeded/CLER/ProgLoup/Lesson4Photo/Release/Lesson4Photo.elf"
	@echo 'Finished building target: $@'
	@echo ' '

/home/loup/Documents/formationembeded/CLER/ProgLoup/Lesson4Photo/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/bin/avr-ar" rcs  "/home/loup/Documents/formationembeded/CLER/ProgLoup/Lesson4Photo/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

Lesson4Photo.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/bin/avr-gcc" -Os -Wl,--gc-sections -mmcu=atmega328p  -o "/home/loup/Documents/formationembeded/CLER/ProgLoup/Lesson4Photo/Release/Lesson4Photo.elf"   $(LINK_OBJ) $(AR)  "/home/loup/Documents/formationembeded/CLER/ProgLoup/Lesson4Photo/Release/arduino.ar" "-L/home/loup/Documents/formationembeded/CLER/ProgLoup/Lesson4Photo/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

Lesson4Photo.eep: $(ELF)
	@echo 'Create eeprom image'
	"/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0  "/home/loup/Documents/formationembeded/CLER/ProgLoup/Lesson4Photo/Release/Lesson4Photo.elf" "/home/loup/Documents/formationembeded/CLER/ProgLoup/Lesson4Photo/Release/Lesson4Photo.eep"
	@echo 'Finished building: $@'
	@echo ' '

Lesson4Photo.hex: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"/bin/avr-objcopy" -O ihex -R .eeprom  "/home/loup/Documents/formationembeded/CLER/ProgLoup/Lesson4Photo/Release/Lesson4Photo.elf" "/home/loup/Documents/formationembeded/CLER/ProgLoup/Lesson4Photo/Release/Lesson4Photo.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_DEPS)$(AR)$(FLASH_IMAGE)$(EEP)$(CXX_DEPS)$(S_UPPER_DEPS)$(ELF)$(C++_DEPS)$(ASM_DEPS)$(CC_DEPS)$(INO_DEPS)$(AR_OBJ)$(CPP_DEPS)$(LINK_OBJ)$(C_UPPER_DEPS)$(SIZEDUMMY) Lesson4Photo
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
