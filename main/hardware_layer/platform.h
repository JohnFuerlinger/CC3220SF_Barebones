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
    #define UARTLCRH_FEN   (1U << 4) /* Enable FIFOs (1 == enabled) */
    #define UARTLCRH_WLEN(x)  ((x-5) << 5) /* Word length (2 bits, 0->3 ranging from 5->8 data bits) */
    #define UARTDMACTL_TXDMAE  (1U << 1)   /* Transmit DMA enable (1 == enabled) */
    #define UARTDMACTL_RXDMAE  (1U << 0)   /* Receive DMA enable (1 == enabled) */
    #define UARTFR_BUSY        (1U << 3)
    #define UARTIFLS_RXIFLSEL(x)  (x << 3) /* RX side fifo trigger level (2 bits) */
    #define UARTIFLS_TXIFLSEL(x)  (x << 0) /* TX side fifo trigger level (2 bits) */





#endif /* HARDWARE_LAYER_PLATFORM_H_ */



//#define TERATERM
//#ifdef TERATERM
//    #define ENTER_KEYSTROKE     '\r'
//#endif

//
///* This function will eventually evolve into a printf-like function. For now it will
// * be the naive version, which can only take 1 argument (char pointer to C-Style string).
// * It simply prints the string until it finds the null terminator.
// *
// * TODO: NOTE: THIS IS A POTENTIALLY DANGEROUS FUNCTION. IF NO NULL TERMINATOR IS FOUND THE DSP WILL FAIL.
// * This needs to be handled.
// */
//
//
///*
// * Format specifiers:
// *
// * %s: string (char *)
// * %d or %u: integer - 16 bit
// *      %lu or %du (long integer - 32 bit)
// * %f: float (standard single precision (32 bit))
// *
// *
// * ***Fix
// *
// */
//void muprintf(char * buf) {
//    for(int i = 0; i < strlen(buf); i++) {
//        BYTEOUT(buf[i]);
//    }
//}
//
///* This function is used to determine if two string pointers are equal.
// * Return 1 = equal (true), return 0 = not equal (false)
// * This function is assuming that both pointers we are passing actually point to arrays of characters ending with a null terminator.
// * If we pass in pointers that do not point to an array of characters with a null terminator our entire project breaks - tread carefully.
// */
//uint8_t gstrcmp(char * str1, char * str2) {
//
//    if (strlen(str1) != strlen(str2)) {
//        return 0;
//    }
//
//    for(int i = 0; i < strlen(str1); i++) {
//        if (str1[i] != str2[i]) {
//            return 0;
//        }
//    }
//
//    return 1;
//}
//
//
///* This is a foundation for our terminal. It will simply receive a character and echo it back
// * over the UART. Next, we should build a "command" buffer and command list. This will allow the
// * user to enter a command, press enter, and then the DSP will execute the command.
// */
//void example_task(void *arg0) {
//
//    init_myuart(); /* Rewriting driver library for added control */
//
//    /* Init term color as white */
//    termcol = WHITE;
//
//    uint8_t bufsize = 0;
//    char mybuf[20];
//
//    /* Initialize buf */
//    for (int i = 0; i < 20; i++) {
//        mybuf[i] = 0;
//    }
//
//    char byte;
//
//    muprintf("\r\n\r\nPrompt> ");
//
//    while(1) {
//
//        if (!(jUARTFR & (1 << 4))) { /* See if we have a byte available on RX side */
//
//            byte = (jUARTDR & (0xff)); /* Read the byte */
//
//            /* First check to see if we have room in the buffer */
//            if (bufsize > 19 && byte != '\010') {
//                ERRORPRNT("\r\nError: Too many characters");
//                muprintf("\r\n\r\nPrompt> ");
//
//                /* Clear the buffer */
//                for (int i = 0; i < 20; i++) {
//                    mybuf[i] = 0;
//                }
//                bufsize = 0; /* Reset buffer counter */
//                continue;
//            }
//
//            /* Check for special characters */
//
//            if (byte == '\r') {
//               /* Enter */
//
//                if (bufsize != 0) {
//                    /* Parse and execute commands */
//
//                    /* This is a high-level wrapper to execute functions. Maybe it should be renamed. In any case, it will completely handle command
//                     * execution with the use of no global variables (which in this case is good design)
//                     */
//                    parse_command(mybuf);
//
//                    muprintf("\r\n\r\nPrompt> ");
//
//                    /* Clear the buffer */
//                    for (int i = 0; i < 20; i++) {
//                        mybuf[i] = 0;
//                    }
//                    bufsize = 0; /* Reset buffer counter */
//                } else {
//                    muprintf("\r\n\r\nPrompt> ");
//                }
//            } else if (byte == '\010' || byte == 0x7F) {
//                /* Backspace */
//
//                if (bufsize != 0) {
//                    /* The below is a terminal hack to make it appear to the user that they 'erased' the previous character */
//                    muprintf("\010 \010");
//
//                    mybuf[bufsize-1] = 0;
//                    bufsize--;
//                }
//
//            } else if ((byte >= 'a' && byte <= 'z') || byte == ' ') { /* Accept all lowerchar chars */
//                /* All other characters */
//
//                BYTEOUT(byte); /* Just echo the char */
//                mybuf[bufsize] = byte; /* Track this byte in our buffer */
//                bufsize++;
//            }
//        }
//    }
//}
