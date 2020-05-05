//  Copyright 2020 Copyright Equipo 2
#ifndef GPIO_H_   /* Include guard */
#define GPIO_H_

#include <stdint.h>

typedef enum  {
  INPUT,
  OUPUT
} pinModeType;

typedef enum  {
  SET,
  RESET
} pinStatusType;


void gpio_init_pin(uint32_t port, uint32_t pin, pinModeType mode);
pinStatusType gpio_get_pin_status(uint32_t port, uint32_t pin);
void gpio_pin_toggle(uint32_t port, uint32_t pin);
void gpio_pin_set(uint32_t port, uint32_t pin);
void gpio_pin_reset(uint32_t port, uint32_t pin);


#endif  // ABSTRACTION_AND_DOCUMENTATION_UC_TIMER_GPIO_H_
