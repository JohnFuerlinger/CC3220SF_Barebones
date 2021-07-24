/*
 * uart_l.c
 *
 * Author: John Fuerlinger
 *
 * Desc: UART library designed to be hardware-agnostic
 *
 * (c) 2021, John Fuerlinger, all rights reserved
 */

/* Note: this needs to be hardware-agnostic, since some systems may have different serial
 * interfaces in place (RS485/RS422, half vs. full duplex, etc..)
 */

#include "uart_l.h"

/* Take a uint8_t and generate the ascii characters required to print it out to
 * the terminal... Wonder if there's a more efficient way to do this..?
 */
void uint8_2ascii(uint8_t num, char * conv) {
    static uint8_t offset = 48; /* ascii based logic */
    uint8_t ones = num % 10;
    uint8_t tens = ((num % 100) - ones) / 10;
    uint8_t hunds = (num - (tens * 10) - ones) / 100;
    conv[2] = ones + offset;
    conv[1] = tens + offset;
    conv[0] = hunds + offset;
}



/* Going to add '%' escape char to do formatting soon. For now this is a
 * basic printing command that will walk a C-String and print each byte
 */
void jprintf(const char * msg, ...) {

    /*
     * Prefixes:
     * l: long
     *
     *
     * Intrinsics:
     * d or i: signed integer
     * u: unsigned int
     *
     * f: floating point
     *
     * x: raw hex (no 0x prefix)
     *
     * e: scientific notation
     *
     * c: character
     *
     * s: string
     *
     */

    va_list valist;
    //uint8_t argcnt = 0;
    char buf[10];

    va_start(valist, msg);

    uint16_t len = strlen(msg);

    /* Next we need to add escape chars */
    for (uint16_t i = 0; i < len; i++) {

        /* Handle newlines */
        if (msg[i] == '\n') {
            BYTEOUT_L('\n');
            BYTEOUT_L('\r');

        } else if (msg[i] == '%') { /* The escape character */

            /* TODO: Need to handle seg fault? Test this */

            /* Handle other cases */

            /* ignoring length specifiers for now... */

            /* Unsigned int (uint8_t) */
            if (msg[i+1] == 'u') {
                uint8_2ascii(va_arg(valist, uint8_t), buf);

                /* Only have to print 3 digits max for a uint8_t */
                for (int k = 0; k < 3; k++) {
                    BYTEOUT_L(buf[k]);
                }
            }


            i++; /* Need to increment past the format character */

        } else {
            BYTEOUT_L(msg[i]); /* This is the default */
        }
    }

    va_end(valist);
}

