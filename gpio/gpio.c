#include "gpio.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

void gpio_init_pin(uint32_t port, uint32_t pin, pinModeType mode){

}

pinStatusType gpio_get_pin_status(uint32_t port, uint32_t pin){
    return RESET;
}

void gpio_pin_toggle(uint32_t port, uint32_t pin){

}

void gpio_pin_set(uint32_t port, uint32_t pin){

}

void gpio_pin_reset(uint32_t port, uint32_t pin){

}