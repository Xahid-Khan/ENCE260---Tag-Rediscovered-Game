# File:   	Makefile
# @author 	Zahid Khan - ZKH22
# @author 	Thomas Mander - TCM56
# Date:   	18 Oct 2021
# Descr: 	Makefile for game

# Definitions.
CC = avr-gcc
CFLAGS = -mmcu=atmega32u2 -Os -Wall -Wstrict-prototypes -Wextra -g -I. -I../../utils -I../../fonts -I../../drivers -I../../drivers/avr
OBJCOPY = avr-objcopy
SIZE = avr-size
DEL = rm


# Default target.
all: game.out

# player.o: player.c player.h pio.h, sys
# Compile: create object files from C source files.
# game.o: game.c ../../drivers/avr/system.h ../../drivers/avr/system.h display_message.h
game.o: game.c play.h ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

system.o: ../../drivers/avr/system.c ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

display_message.o: display_message.c display_message.h ../../drivers/avr/system.h ../../utils/pacer.h ../../utils/tinygl.h ../../fonts/font5x7_1.h  ../../drivers/navswitch.h sound_effects.h
	$(CC) -c $(CFLAGS) $< -o $@

font.o: ../../utils/font.c ../../drivers/avr/system.h ../../utils/font.h
	$(CC) -c $(CFLAGS) $< -o $@

pacer.o: ../../utils/pacer.c ../../drivers/avr/system.h ../../drivers/avr/timer.h ../../utils/pacer.h
	$(CC) -c $(CFLAGS) $< -o $@

tinygl.o: ../../utils/tinygl.c ../../drivers/avr/system.h ../../drivers/display.h ../../utils/font.h ../../utils/tinygl.h
	$(CC) -c $(CFLAGS) $< -o $@

timer.o: ../../drivers/avr/timer.c ../../drivers/avr/system.h ../../drivers/avr/timer.h
	$(CC) -c $(CFLAGS) $< -o $@

display.o: ../../drivers/display.c ../../drivers/avr/system.h ../../drivers/display.h ../../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

ledmat.o: ../../drivers/ledmat.c ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

navswitch.o: ../../drivers/navswitch.c ../../drivers/avr/delay.h ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/navswitch.h
	$(CC) -c $(CFLAGS) $< -o $@

cpu.o: cpu.c cpu.h ../../drivers/avr/system.h ../../utils/pacer.h player.h
	$(CC) -c $(CFLAGS) $< -o $@

player.o: player.c player.h ../../drivers/avr/system.h ../../drivers/navswitch.h cpu.h
	$(CC) -c $(CFLAGS) $< -o $@

play.o: play.c play.h ../../drivers/avr/system.h ../../utils/tinygl.h player.h display_message.h ../../utils/pacer.h ../../drivers/navswitch.h cpu.h ../../drivers/avr/timer.h
	$(CC) -c $(CFLAGS) $< -o $@

sound_effects.o: sound_effects.c sound_effects.h ../../drivers/avr/system.h ../../drivers/avr/pio.h ../../utils/pacer.h
	$(CC) -c $(CFLAGS) $< -o $@



# Link: create ELF output file from object files.
game.out: game.o system.o display_message.o player.o play.o pacer.o tinygl.o font.o timer.o display.o ledmat.o navswitch.o cpu.o sound_effects.o
	$(CC) $(CFLAGS) $^ -o $@ -lm
	$(SIZE) $@


# Target: clean project.
.PHONY: clean
clean:
	-$(DEL) *.o *.out *.hex


# Target: program project.
.PHONY: program
program: game.out
	$(OBJCOPY) -O ihex game.out game.hex
	dfu-programmer atmega32u2 erase; dfu-programmer atmega32u2 flash game.hex; dfu-programmer atmega32u2 start
