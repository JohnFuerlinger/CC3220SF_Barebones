/*
 * uart.c
 *
 *  Created on: Jul 24, 2021
 *      Author: iuser
 */

#include "uart.h"

void init_uart() {

    /* Disable UART */
    jUARTCTL &= ~jUARTCTL_EN;

    jUARTLCRH &= ~jUARTLCRH_FEN;  /* Flush FIFO's */
    jUARTCTL |= jUARTCTL_EOT;   /* Only set TXRIS when entire fifo is empty */

    jUARTIFLS &= ~jUARTIFLS_RXIFLSEL(2); /* Clear bit 2, which sets the trigger to minimum level */
    jUARTIFLS |= jUARTIFLS_RXIFLSEL(1);
    jUARTIFLS &= ~jUARTIFLS_TXIFLSEL(2); /* Clear bit 2, which sets the trigger to minimum level */
    jUARTIFLS |= jUARTIFLS_TXIFLSEL(1);

    jUARTCTL |= (1U << 15); /* Clear to send enabled...? */


    /* Write Integer & Fractional part of BRD */
    jUARTIBRD = 0x2b;
    jUARTFBRD = 0x1a;

    /* Write settings to UARTLCRH */
    jUARTLCRH |= jUARTLCRH_FEN;         /* Enable fifos */
    jUARTLCRH |= jUARTLCRH_WLEN(8);     /* Select 8 data bits */

    /* Optionally configure uDMA settings */
    jUARTDMACTL |= (jUARTDMACTL_TXDMAE | jUARTDMACTL_RXDMAE); /* Enable Rx & Tx DMA control */

    /* Enable UART */
    jUARTCTL |= jUARTCTL_EN;
}




