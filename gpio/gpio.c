/// @file gpio.c
/// @brief GPIO function definitions.
#include "gpio.h"                       ///<GPIO Header
#include <libopencm3/stm32/rcc.h>       ///<libopencm3 RCC functions
#include <libopencm3/stm32/gpio.h>      ///<libopencm3 GPIO functions
#include <stdint.h>

/**
 * @brief Initialize a given GPIO pin.
 * @param[in] port - GPIO block port to be started
 * @param[in] pin - GPIO pin to be started
 * @param[in] mode - How will the pin be initialized <INPUT/OUTPUT>
 */
void gpio_init_pin(uint32_t port, uint32_t pin, pinModeType mode){
    
    rcc_periph_clock_enable(port);

    uint32_t pin_mode = mode == INPUT ? GPIO_MODE_INPUT: GPIO_MODE_OUTPUT_2_MHZ;
     /* Set GPIO8 (in GPIO port C) to 'output push-pull'. */
    gpio_set_mode(port, pin_mode,
              GPIO_CNF_OUTPUT_PUSHPULL, pin);
}

/**
 * @brief Returns the pin status when called.
 * @param[in] port - GPIO block port.
 * @param[in] pin - GPIO pin port.
 * @return pinStatus - Status of the given GPIO pin.
 */ 
pinStatusType gpio_get_pin_status(uint32_t port, uint32_t pin){
    uint16_t status = gpio_get(port, pin);
    return status == 1 ? SET:RESET;
}

/**
 * @brief Toggle a given GPIO pin.
 * @param[in] port - GPIO block port.
 * @param[in] pin - GPIO pin port.
 */
void gpio_pin_toggle(uint32_t port, uint32_t pin){
    gpio_toggle(port, pin);
}

/**
 * @brief Set a given GPIO pin.
 * @param[in] port - GPIO block port.
 * @param[in] pin - GPIO pin port.
 */
void gpio_pin_set(uint32_t port, uint32_t pin){
    gpio_set(port, pin);
}

/**
 * @brief Clear a given GPIO pin.
 * @param[in] port - GPIO block port.
 * @param[in] pin - GPIO pin port.
 */
void gpio_pin_reset(uint32_t port, uint32_t pin){
    gpio_clear(port, pin);
}