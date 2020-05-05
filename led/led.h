/// @file led.h
/// @brief LED header file.
//  Copyright 2020 Copyright Equipo 2
#ifndef LED_H_   /* Include guard */
#define LED_H_

#include "led_params.h" ///<LED params header include.

void led_setup(void);
void led_toggle(void);
void led_on(void);
void led_off(void);

#endif  // ABSTRACTION_AND_DOCUMENTATION_LED_H_
