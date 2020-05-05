#include "print.h"
#include "../uc_uart/uc_uart.h"
#include "../miniprintf/miniprintf.h"

void print_setup(void){
    uart_pin_setup(UART_TX_PORT, UART_TX_PIN, UART_RX_PORT, UART_RX_PIN);
    uart_setup(UART, BAUDRATE, DATABITS);
    uart_start(UART);
}

void print(const char *format, ...){
    va_list args;

    va_start(args, format);
    mini_vprintf_cooked(uart_putc, format, args);
    va_end(args);
}