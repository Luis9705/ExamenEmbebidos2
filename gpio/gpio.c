/// @file gpio.c

#include "gpio.h"                       ///<GPIO Header
#include <libopencm3/stm32/rcc.h>       ///<libopencm3 RCC functions
#include <libopencm3/stm32/gpio.h>      ///<libopencm3 GPIO functions


/**
 * @brief Initialize a given GPIO pin.
 * @param[in] port - GPIO block port to be started
 * @param[in] pin - GPIO pin to be started
 * @param[in] mode - How will the pin be initialized <INPUT/OUTPUT>
 */
void gpio_init_pin(uint32_t port, uint32_t pin, pinModeType mode){

}

/**
 * @brief Returns the pin status when called.
 * @param[in] port - GPIO block port.
 * @param[in] pin - GPIO pin port.
 * @param[out] pinStatus - Status of the given GPIO pin.
 */ 
pinStatusType gpio_get_pin_status(uint32_t port, uint32_t pin){
    return RESET;
}

/**
 * @brief Toggle a given GPIO pin.
 * @param[in] port - GPIO block port.
 * @param[in] pin - GPIO pin port.
 */
void gpio_pin_toggle(uint32_t port, uint32_t pin){

}

/**
 * @brief Set a given GPIO pin.
 * @param[in] port - GPIO block port.
 * @param[in] pin - GPIO pin port.
 */
void gpio_pin_set(uint32_t port, uint32_t pin){

}

/**
 * @brief Clear a given GPIO pin.
 * @param[in] port - GPIO block port.
 * @param[in] pin - GPIO pin port.
 */
void gpio_pin_reset(uint32_t port, uint32_t pin){

}