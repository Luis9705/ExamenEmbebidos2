######################################################################
#  Project
######################################################################

BINARY		= main
SRCFILES	= main.c   delay/delay.c miniprintf/miniprintf.c system_common/system_common.c uc_timer/uc_timer.c print/print.c  uc_uart/uc_uart.c led/led.c timer/timer.c buttons/buttons.c gpio/gpio.c
 
all: elf bin

include ../Makefile.incl

# End
