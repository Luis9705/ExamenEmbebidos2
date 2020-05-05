/// @file uc_uart.c
//  Copyright 2020 Copyright Equipo 2
#include "uc_uart.h"
#include <libopencm3/stm32/usart.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include "../miniprintf/miniprintf.h"

uint32_t current_uart;

/**
 * Starts UART transmission.
 * @param[in] character
 */
void uart_putc(char ch)  {
    usart_send_blocking(current_uart, ch);
}

/**
 * Prints UART message
 * param[in] format
 * param[out] rc
 */
int uart_printf(const char *format, ...)  {
    va_list args;
    int rc;

    va_start(args, format);
    rc = mini_vprintf_cooked(uart_putc, format, args);
    va_end(args);
    return rc;
}

/**
 * Sets up the UART peripheral pin ports needed.
 */
void uart_pin_setup(uint32_t tx_port, uint32_t tx_pin, uint32_t rx_port, uint32_t rx_pin) {
    rcc_periph_clock_enable(tx_port);
    rcc_periph_clock_enable(rx_port);
    // PA9 y PA10
    gpio_set_mode(tx_port,
        GPIO_MODE_OUTPUT_50_MHZ,
        GPIO_CNF_OUTPUT_ALTFN_PUSHPULL,
        tx_pin);
    gpio_set_mode(rx_port,  GPIO_MODE_INPUT,
        GPIO_CNF_INPUT_FLOAT,
        rx_pin);
}

/**
 * Sets up the UART configuration.
 */
void uart_setup(uint32_t uart, uint32_t baudrate, uint32_t databits) {
    rcc_periph_clock_enable(uart);
    usart_set_baudrate(uart, baudrate);
    usart_set_databits(uart, databits);
    usart_set_stopbits(uart, USART_STOPBITS_1);
    usart_set_mode(uart, USART_MODE_TX_RX);
    usart_set_parity(uart, USART_PARITY_NONE);
    usart_set_flow_control(uart, USART_FLOWCONTROL_NONE);
}


/**
 * Starts UART.
 */
void uart_start(uint32_t uart) {
    usart_enable(uart);
    usart_wait_send_ready(uart);
    current_uart = uart;
}
