/// @file main.c
//  Copyright 2020 Copyright Equipo 2

#include <stdlib.h>
#include "system_common/system_common.h"
#include "timer/timer.h"
#include "delay/delay.h"
#include "print/print.h"
#include "buttons/buttons.h"
#include "led/led.h"


typedef enum  {
  OFF,
  RUNNING,
  PAUSED
} timerStatusType;


timerStatusType timer_status = OFF;


int main(void)  {


    system_clock_setup();
    buttons_setup();
    led_setup();
    delay_setup();
    print_setup();
    timer_setup();


    for (;;)  {

        if(reset_button_pressed()){
            timer_rst();
            print("Timer Reset.\n");
            led_off(); 
            timer_status = OFF;
        }

        if(start_button_pressed()){
            if(timer_status == OFF){

                timer_status = RUNNING;
                timer_start();
                print("Timer Started.\n");

            }else if(timer_status == PAUSED){

                timer_status = RUNNING;
                timer_continue();
                print("Timer Continued.\n");

            }
        }

        if(stop_button_pressed()){
            timer_status = PAUSED;
            timer_stop();
            led_off(); 
            int seconds = timer_get_seconds();
            print("Timer Stopped, time is: %d seconds\n", seconds);
        }

        if(timer_status == RUNNING){
            led_toggle();
            delay_ms(1000);
        }

    }

    return 0;
}


