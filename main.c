/// @file main.c
//  Copyright 2020 Copyright Equipo 2

#include <stdlib.h>
#include "system_common/system_common.h"
#include "uc_timer/uc_timer.h"
#include "delay/delay.h"
#include "uc_uart/uc_uart.h"
#include "buttons/buttons.h"
#include "parameters.h"


typedef enum  {
  OFF,
  RUNNING,
  PAUSED
} timerStatusType;


timerStatusType timer_status = OFF;


int main(void)  {
    system_clock_setup();

     gpio_init_pin(LED_PORT, LED_PIN, OUTPUT);
    gpio_pin_set(LED_PORT, LED_PIN); //logica inversa para apagar led


    buttons_setup();

    delay_setup();

    uart_pin_setup();
    uart_setup();
    uart_start();

    timer_setup();


    for (;;)  {

        if(reset_button_pressed()){
            timer_reset();
            uart_printf("Timer Reset.\n");
            gpio_pin_set(LED_PORT, LED_PIN); //apagar led
            timer_status = OFF;
        }

        if(start_button_pressed()){
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

        if(stop_button_pressed()){
            timer_status = PAUSED;
            timer_stop();
            gpio_pin_set(LED_PORT, LED_PIN); //apagar led
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


