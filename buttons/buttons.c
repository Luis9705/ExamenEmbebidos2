/// @file buttons.c
/// @brief Button function definitions.
//  Copyright 2020 Copyright Equipo 2
#include "buttons.h" ///<Buttons include file.
#include "../gpio/gpio.h" ///<Lower level GPIO include.

/**
 * @brief Sets up the buttons needed for this project.
 */
void buttons_setup(void){
    gpio_init_pin(RESET_BUTTON_PORT, RESET_BUTTON_PIN,INPUT);
    gpio_init_pin(START_BUTTON_PORT, START_BUTTON_PIN,INPUT);
    gpio_init_pin(STOP_BUTTON_PORT, STOP_BUTTON_PIN,INPUT);
}

/**
 * @brief Returns whether the reset button is pressed.
 * @return reset_button_status
 */
bool reset_button_pressed(void){
    if(gpio_get_pin_status(RESET_BUTTON_PORT, RESET_BUTTON_PIN) == SET){
        return true;
    }else{
        return false;
    }

}

/**
 * @brief Returns whether the start button is pressed.
 * @return start_button_status
 */
bool start_button_pressed(void){
        if(gpio_get_pin_status(START_BUTTON_PORT, START_BUTTON_PIN) == SET){
        return true;
    }else{
        return false;
    }
}

/**
 * @brief Returns whether the stop button is pressed.
 * @return stop_button_status
 */
bool stop_button_pressed(void){
        if(gpio_get_pin_status(STOP_BUTTON_PORT, STOP_BUTTON_PIN) == SET){
        return true;
    }else{
        return false;
    }
}