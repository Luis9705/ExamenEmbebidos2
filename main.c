/// @file main.c
//  Copyright 2020 Copyright Equipo 2
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include "system_common/system_common.h"
#include "uc_timer/uc_timer.h"
#include "delay/delay.h"
#include "uc_uart/uc_uart.h"
#include <stdlib.h>



typedef enum  {
  OFF,
  RUNNING,
  PAUSED
} timerStatusType;


timerStatusType timer_status = OFF;


int main(void)  {
    system_clock_setup();

    gpio_init_pin(LED_PORT, LED_PIN,OUTPUT);

    gpio_init_pin(RESET_BUTTON_PORT, RESET_BUTTON_PIN,INPUT);
    gpio_init_pin(START_BUTTON_PORT, START_BUTTON_PIN,INPUT);
    gpio_init_pin(STOP_BUTTON_PORT, STOP_BUTTON_PIN,INPUT);

    delay_setup();
    uart_setup();

    timer_setup();


    for (;;)  {

        if(gpio_get_pin_status(RESET_BUTTON_PORT, RESET_BUTTON_PIN) == SET){
            timer_reset();
            uart_printf("Timer Reset.\n");
            timer_status = OFF;
        }

        if(gpio_get_pin_status(START_BUTTON_PORT, START_BUTTON_PIN) == SET){
            if(timer_status == OFF){

                timer_status = RUNNING;
                timer_start();
                uart_printf("Timer Started.\n");

            }else if(timer_status == PAUSED){

                timer_status = RUNNING;
                timer_continue();
                uart_printf("Timer Continued.\n");

            }
        }

        if(gpio_get_pin_status(STOP_BUTTON_PORT, STOP_BUTTON_PIN) == SET){
            timer_status = PAUSED;
            timer_stop();
            int seconds = timer_get_seconds();
            uart_printf("Timer Stopped, time is: %d seconds\n", seconds);
        }

        if(timer_status == RUNNING){
            gpio_pin_toggle(LED_PORT, LED_PIN);
            delay(1000);
        }

    }

    return 0;
}


