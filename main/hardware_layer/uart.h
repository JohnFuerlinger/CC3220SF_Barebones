/*
 * uart.h
 *
 *  Created on: Jul 24, 2021
 *      Author: iuser
 */

#ifndef HARDWARE_LAYER_UART_H_
#define HARDWARE_LAYER_UART_H_

#include "platform.h"

#define BYTEOUT(byte) do {                                              \
                        while (jUARTFR & jUARTFR_BUSY) { ; }            \
                        jUARTDR = byte;                                 \
                        while (!(jUARTRIS & (1 << 5))) { ; }            \
                        jUARTICR |= (1U << 5);                          \
                    } while(0)                                          \


void init_uart();




#endif /* HARDWARE_LAYER_UART_H_ */
