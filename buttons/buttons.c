#include "buttons.h"
#include "../gpio/gpio.h"

void buttons_setup(void){


    gpio_init_pin(RESET_BUTTON_PORT, RESET_BUTTON_PIN,INPUT);
    gpio_init_pin(START_BUTTON_PORT, START_BUTTON_PIN,INPUT);
    gpio_init_pin(STOP_BUTTON_PORT, STOP_BUTTON_PIN,INPUT);
}
bool reset_button_pressed(void){
    if(gpio_get_pin_status(RESET_BUTTON_PORT, RESET_BUTTON_PIN) == SET){
        return true;
    }else{
        return false;
    }

}
bool start_button_pressed(void){
        if(gpio_get_pin_status(START_BUTTON_PORT, START_BUTTON_PIN) == SET){
        return true;
    }else{
        return false;
    }
}
bool stop_button_pressed(void){
        if(gpio_get_pin_status(STOP_BUTTON_PORT, STOP_BUTTON_PIN) == SET){
        return true;
    }else{
        return false;
    }
}