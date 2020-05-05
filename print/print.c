/// @file print.c
/// @brief Print functions definitions.
//  Copyright 2020 Copyright Equipo 2

#include "print.h" ///<Print header file.
#include "../uc_uart/uc_uart.h" ///<Lower level of UART code include.
#include "../miniprintf/miniprintf.h"   ///<Miniprint include.


/**
 * @brief Sets up parameters needed to print to console.
 */
void print_setup(void){
    uart_pin_setup(UART_TX_PORT, UART_TX_PIN, UART_RX_PORT, UART_RX_PIN);
    uart_setup(UART, BAUDRATE, DATABITS);
    uart_start(UART);
}

/**
 * @brief Function to print to console.
 * @param[in] format
 */
void print(const char *format, ...){
    va_list args;

    va_start(args, format);
    mini_vprintf_cooked(uart_putc, format, args);
    va_end(args);
}