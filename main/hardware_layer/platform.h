/*
 * platform.h
 *
 * Author: John Fuerlinger
 *
 * Desc: Define all the register addresses necessary to interface with the peripherals
 *       on a specific platform. Each CPU will have a different platform.h, and the
 *       hardware layer will use those definitions to create basic functions used by
 *       the library layer. The library layer should not use these functions, as doing
 *       so breaks the HAL layer architecture.
 *
 * (c) 2021, John Fuerlinger, all rights reserved
 */

#ifndef HARDWARE_LAYER_PLATFORM_H_
#define HARDWARE_LAYER_PLATFORM_H_

#include "com_inc.h"

/* This is going to take a while... */

#define     UART_BASE          0x4000c000    /* Note: this is for UART A0 only */
#define     UARTDR             *(volatile uint32_t *) (UART_BASE + (0x00))
#define     UARTRSR_UARTECR    *(volatile uint32_t *) (UART_BASE + (0x04))
#define     UARTFR             *(volatile uint32_t *) (UART_BASE + (0x18))
#define     UARTIBRD           *(volatile uint32_t *) (UART_BASE + (0x24))
#define     UARTFBRD           *(volatile uint32_t *) (UART_BASE + (0x28))
#define     UARTLCRH           *(volatile uint32_t *) (UART_BASE + (0x2c))
#define     UARTCTL            *(volatile uint32_t *) (UART_BASE + (0x30))
#define     UARTIFLS           *(volatile uint32_t *) (UART_BASE + (0x34))
#define     UARTIM             *(volatile uint32_t *) (UART_BASE + (0x38))
#define     UARTRIS            *(volatile uint32_t *) (UART_BASE + (0x3c))
#define     UARTMIS            *(volatile uint32_t *) (UART_BASE + (0x40))
#define     UARTICR            *(volatile uint32_t *) (UART_BASE + (0x44))
#define     UARTDMACTL         *(volatile uint32_t *) (UART_BASE + (0x48))

    #define BR_CLKVAL       80000000 /* 80 MHz Uart clock rate */

    #define UARTCTL_EN     (1U << 0)
    #define UARTCTL_EOT    (1U << 4)   /* End of Transmission (1 == TXRIS only set when everything clears serializer) */
    #define UARTCTL_RXE    (1U << 9)
    #define UARTCTL_TXE    (1U << 8)
    #define UARTLCRH_FEN   (1U << 4) /* Enable FIFOs (1 == enabled) */
    #define UARTLCRH_WLEN(x)  ((x-5) << 5) /* Word length (2 bits, 0->3 ranging from 5->8 data bits) */
    #define UARTDMACTL_TXDMAE  (1U << 1)   /* Transmit DMA enable (1 == enabled) */
    #define UARTDMACTL_RXDMAE  (1U << 0)   /* Receive DMA enable (1 == enabled) */
    #define UARTFR_BUSY        (1U << 3)
    #define UARTIFLS_RXIFLSEL(x)  (x << 3) /* RX side fifo trigger level (2 bits) */
    #define UARTIFLS_TXIFLSEL(x)  (x << 0) /* TX side fifo trigger level (2 bits) */


#define ARCM_BASE               0x44025000

#define CAMCLKCFG               *(volatile uint32_t *) (ARCM_BASE + (0x00))
#define CAMCLKEN                *(volatile uint32_t *) (ARCM_BASE + (0x04))
#define CAMSWRST                *(volatile uint32_t *) (ARCM_BASE + (0x08))
#define MCASPCLKEN              *(volatile uint32_t *) (ARCM_BASE + (0x14))
#define MCASPSWRST              *(volatile uint32_t *) (ARCM_BASE + (0x18))
#define SDIOMCLKCFG             *(volatile uint32_t *) (ARCM_BASE + (0x20))
#define SDIOMCLKEN              *(volatile uint32_t *) (ARCM_BASE + (0x24))
#define SDIOMSWRST              *(volatile uint32_t *) (ARCM_BASE + (0x28))
#define APSPICLKCFG             *(volatile uint32_t *) (ARCM_BASE + (0x2C))
#define APSPICLKEN              *(volatile uint32_t *) (ARCM_BASE + (0x30))
#define APSPISWRST              *(volatile uint32_t *) (ARCM_BASE + (0x34))
#define DMACLKEN                *(volatile uint32_t *) (ARCM_BASE + (0x48))
#define DMASWRST                *(volatile uint32_t *) (ARCM_BASE + (0x4C))
#define GPIO0CLKEN              *(volatile uint32_t *) (ARCM_BASE + (0x50))
#define GPIO0SWRST              *(volatile uint32_t *) (ARCM_BASE + (0x54))
#define GPIO1CLKEN              *(volatile uint32_t *) (ARCM_BASE + (0x58))
#define GPIO1SWRST              *(volatile uint32_t *) (ARCM_BASE + (0x5C))
#define GPIO2CLKEN              *(volatile uint32_t *) (ARCM_BASE + (0x60))
#define GPIO2SWRST              *(volatile uint32_t *) (ARCM_BASE + (0x64))
#define GPIO3CLKEN              *(volatile uint32_t *) (ARCM_BASE + (0x68))
#define GPIO3SWRST              *(volatile uint32_t *) (ARCM_BASE + (0x6C))
#define GPIO4CLKEN              *(volatile uint32_t *) (ARCM_BASE + (0x70))
#define GPIO4SWRST              *(volatile uint32_t *) (ARCM_BASE + (0x74))
#define WDTCLKEN                *(volatile uint32_t *) (ARCM_BASE + (0x78))
#define WDTSWRST                *(volatile uint32_t *) (ARCM_BASE + (0x7C))
#define UART0CLKEN              *(volatile uint32_t *) (ARCM_BASE + (0x80))
#define UART0SWRST              *(volatile uint32_t *) (ARCM_BASE + (0x84))
#define UART1CLKEN              *(volatile uint32_t *) (ARCM_BASE + (0x88))
#define UART1SWRST              *(volatile uint32_t *) (ARCM_BASE + (0x8C))
#define GPT0CLKCFG              *(volatile uint32_t *) (ARCM_BASE + (0x90))
#define GPT0SWRST               *(volatile uint32_t *) (ARCM_BASE + (0x94))
#define GPT1CLKEN               *(volatile uint32_t *) (ARCM_BASE + (0x98))
#define GPT1SWRST               *(volatile uint32_t *) (ARCM_BASE + (0x9C))
#define GPT2CLKEN               *(volatile uint32_t *) (ARCM_BASE + (0xA0))
#define GPT2SWRST               *(volatile uint32_t *) (ARCM_BASE + (0xA4))
#define GPT3CLKEN               *(volatile uint32_t *) (ARCM_BASE + (0xA8))
#define GPT3SWRST               *(volatile uint32_t *) (ARCM_BASE + (0xAC))
#define MCASPCLKCFG0            *(volatile uint32_t *) (ARCM_BASE + (0xB0))
#define MCASPCLKCFG1            *(volatile uint32_t *) (ARCM_BASE + (0xB4))
#define I2CLCKEN                *(volatile uint32_t *) (ARCM_BASE + (0xD8))
#define I2CSWRST                *(volatile uint32_t *) (ARCM_BASE + (0xDC))
#define LPDSREQ                 *(volatile uint32_t *) (ARCM_BASE + (0xE4))
#define TURBOREQ                *(volatile uint32_t *) (ARCM_BASE + (0xEC))
#define DSLPWAKECFG             *(volatile uint32_t *) (ARCM_BASE + (0x108))
#define DSLPTIMRCFG             *(volatile uint32_t *) (ARCM_BASE + (0x10C))
#define SLPWAKEEN               *(volatile uint32_t *) (ARCM_BASE + (0x110))
#define SLPTMRCFG               *(volatile uint32_t *) (ARCM_BASE + (0x114))
#define WAKENWP                 *(volatile uint32_t *) (ARCM_BASE + (0x118))
#define RCM_IS                  *(volatile uint32_t *) (ARCM_BASE + (0x120))
#define RCM_IEN                 *(volatile uint32_t *) (ARCM_BASE + (0x124))


#endif /* HARDWARE_LAYER_PLATFORM_H_ */
