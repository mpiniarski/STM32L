# Universal makefile script for STM32L projects using CMSIS drivers
# Made by Marcin Piniarski

CC = arm-none-eabi-gcc

INC_PATH = ./Inc/
DRIVER_PATH = ../Drivers/
SRC_PATH = ./Src/

#Set up flags:
CFLAGS  = -Wall -g -mthumb -mcpu=cortex-m3 -mlittle-endian -Os -fdata-sections -DSTM32L100xC 
LFLAGS = -Wall -g -mthumb -mcpu=cortex-m3 -DSTM32L100xC -Os -TSrc/STM32L100RC_FLASH.ld

#Set up included header files

INCLUDES = -I$(INC_PATH) -I$(DRIVER_PATH)CMSIS/Device/ST/STM32L1xx/Include -I$(DRIVER_PATH)CMSIS/Include

#Set up sources of project

CSOURCES=$(shell (find -L $(SRC_PATH) -name '*.c' | sed -e 's!^./Src!./Res!' -e 's/\.c$$/\.o/' ))
ASMSOURCES=$(shell (find -L $(SRC_PATH) -name '*.s' | sed -e 's!^./Src!./Res!' -e 's/\.s$$/\.o/' ))

OBJECTS=$(ASMSOURCES) $(CSOURCES)

default: app.elf

#Link:
app.elf: $(OBJECTS)
	$(CC) $(LFLAGS) $^ -o $@
	@echo "Linking is done! Project is ready!"

#Compile:
Res/%.o: ./Src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiled "$<"!"
#Assemble:
Res/%.o: ./Src/%.s
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Assembled "$<"!"
	


clean:
	rm -f ./Res/* 
clean_all:
	rm -f ./Res/* && rm -f ./app.elf

















