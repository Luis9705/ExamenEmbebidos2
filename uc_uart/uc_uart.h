//  Copyright 2020 Copyright Equipo 2
#ifndef UC_UART_H_   /* Include guard */
#define UC_UART_H_



void uart_pin_setup(uint32_t tx_port, uint32_t tx_pin, uint32_t rx_port, uint32_t rx_pin);
void uart_setup(uint32_t uart, uint32_t baudrate, uint32_t databits) ;
void uart_start(uint32_t uart);
void uart_putc(char ch);
int uart_printf(const char *format, ...);




#endif  // ABSTRACTION_AND_DOCUMENTATION_UC_UART_UC_UART_H_
