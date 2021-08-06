/*
 * uart.c
 *
 * Author: John Fuerlinger
 *
 * Desc: Hardware level access to CC3220SF UART module.
 *
 * (c) 2021, John Fuerlinger, all rights reserved
 */

#include "uart.h"

void init_uart() {

    while (UARTFR & UARTFR_BUSY) {;}

    /* Disable FIFO */
    UARTLCRH &= ~UARTLCRH_FEN;

    /* Disable UART */
    UARTCTL &= ~(UARTCTL_EN | UARTCTL_TXE | UARTCTL_RXE) ;

    UARTLCRH &= ~UARTLCRH_FEN;  /* Flush FIFO's */
    UARTCTL |= UARTCTL_EOT;   /* Only set TXRIS when entire fifo is empty */

    UARTIFLS &= ~UARTIFLS_RXIFLSEL(2); /* Clear bit 2, which sets the trigger to minimum level */
    UARTIFLS |= UARTIFLS_RXIFLSEL(1);
    UARTIFLS &= ~UARTIFLS_TXIFLSEL(2); /* Clear bit 2, which sets the trigger to minimum level */
    UARTIFLS |= UARTIFLS_TXIFLSEL(1);

    //UARTCTL |= (1U << 15); /* Clear to send enabled...? */


    UARTCTL |= (1U << 8);
    UARTCTL |= (1U << 9);


    /* Write Integer & Fractional part of BRD */
    UARTIBRD = 0x2b;
    UARTFBRD = 0x1a;

    /* Write settings to UARTLCRH */
    UARTLCRH |= UARTLCRH_FEN;         /* Enable fifos */
    UARTLCRH |= UARTLCRH_WLEN(8);     /* Select 8 data bits */

    /* Optionally configure uDMA settings */
    //UARTDMACTL |= (UARTDMACTL_TXDMAE | UARTDMACTL_RXDMAE); /* Enable Rx & Tx DMA control */

    /* Enable UART */
    UARTCTL |= (UARTCTL_EN | UARTCTL_TXE | UARTCTL_RXE);
}




