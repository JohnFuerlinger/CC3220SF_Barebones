/*
 * uart.h
 *
 * Author: John Fuerlinger
 *
 * Desc: Hardware level access to CC3220SF UART module.
 *
 * (c) 2021, John Fuerlinger, all rights reserved
 */

#ifndef HARDWARE_LAYER_UART_H_
#define HARDWARE_LAYER_UART_H_

#include "platform.h"


#define BYTEOUT_D(byte) do {                                              \
                        while (UARTFR & UARTFR_BUSY) { ; }            \
                        UARTDR = byte;                                 \
                        while (!(UARTRIS & (1 << 5))) { ; }            \
                        UARTICR |= (1U << 5);                          \
                    } while(0)                                          \


void init_uart();




#endif /* HARDWARE_LAYER_UART_H_ */
