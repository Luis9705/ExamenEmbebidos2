/// @file gpio.h
//  Copyright 2020 Copyright Equipo 2
#ifndef GPIO_H_   /* Include guard */
#define GPIO_H_

#include <stdint.h>

/// Enum class defining the pin mode.
typedef enum  {
  INPUT, ///<Input mode.
  OUPUT  ///<Output mode.
} pinModeType;

/// Enum class defining different pin status.
typedef enum  {
  SET,  ///<Pin is set.
  RESET ///<Pin is cleared.
} pinStatusType;


void gpio_init_pin(uint32_t port, uint32_t pin, pinModeType mode);
pinStatusType gpio_get_pin_status(uint32_t port, uint32_t pin);
void gpio_pin_toggle(uint32_t port, uint32_t pin);
void gpio_pin_set(uint32_t port, uint32_t pin);
void gpio_pin_reset(uint32_t port, uint32_t pin);


#endif  // ABSTRACTION_AND_DOCUMENTATION_UC_TIMER_GPIO_H_
