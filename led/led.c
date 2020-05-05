#include "led.h"
#include "../gpio/gpio.h"

void led_setup(void){

    gpio_init_pin(LED_PORT, LED_PIN, OUTPUT);
    gpio_pin_set(LED_PORT, LED_PIN); //logica inversa para apagar led

}

void led_toggle(void){
    gpio_pin_toggle(LED_PORT, LED_PIN);
}

void led_on(void){
    gpio_pin_reset(LED_PORT, LED_PIN);
}

void led_off(void){
    gpio_pin_set(LED_PORT, LED_PIN);
}