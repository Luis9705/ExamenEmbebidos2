/// @file led.c
/// @brief Defines LED functions.
//  Copyright 2020 Copyright Equipo 2
#include "led.h"
#include "../gpio/gpio.h"

/**
 * @brief Sets up the LED port and pins
 */
void led_setup(void){
    gpio_init_pin(LED_PORT, LED_PIN, OUTPUT);
    gpio_pin_set(LED_PORT, LED_PIN); //logica inversa para apagar led
}

/**
 * @brief Toggles the LED.
 */
void led_toggle(void){
    gpio_pin_toggle(LED_PORT, LED_PIN);
}

/**
 * @brief Turns on the LED.
 */
void led_on(void){
    gpio_pin_reset(LED_PORT, LED_PIN);
}

/**
 * @brief Turns off the LED.
 */
void led_off(void){
    gpio_pin_set(LED_PORT, LED_PIN);
}