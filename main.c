/// @file main.c
/// @brief Main code for this project.
//  Copyright 2020 Copyright Equipo 2

#include "system_common/system_common.h" ///<System common defines.
#include "timer/timer.h" ///<Timer header file include.
#include "delay/delay.h" ///<Delay header file include.
#include "print/print.h" ///<Print header file include.
#include "buttons/buttons.h" ///<Button header file include.
#include "led/led.h" ///<LED header file include.

/// Enum class defining the timer status. 
typedef enum  {
  OFF,  ///<Timer is off.
  RUNNING,  ///<Timer is running.
  PAUSED   ///<Timer is paused.
} timerStatusType;

timerStatusType timer_status = OFF; ///<Timer default status.

/**
 * @brief Main function.
 */
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


