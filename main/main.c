/**
 * main.c
 *
 * Author: John Fuerlinger
 *
 * Desc: This is a barebones project for bare metal dev. on the CC3220SF_LAUNCHXL.
 *
 * (c) 2021, John Fuerlinger, all rights reserved
 */

/* A note on "layers"...
 *
 * Hardware layer is for interfacing with CC3220SF peripherals, such as UARTs, GPIO,
 * timers, **wifi**, and all the other special things it has.
 *
 * Library layer is for building upon the hardware layer to interface with devices external
 * to the processor (such as boosterpack peripherals or other external IC's). The library
 * layer should not access registers directly, and as such can be a standalone entity.
 *
 * The app layer should be minimal, and implements whatever we want want the board to do.
 * It should only make calls from the library layer as to not interface directly with
 * CPU specific registers and intricacies. Therefore, in theory this app layer can be
 * reused on another processor, given that the platform has a respective hardware and
 * library layer with the same functions.
 *
 * This file (and CCS files) are the only files allowed to exist outside the layer structure
 * in this software architecture. This design favors code readability and cross-platform
 * opportunities at the expense of complexity.
 */

/* The below breaks the rules and is only for testing. bad bad bad */
#include "hardware_layer/uart.h"

/* Let's start with something basic */
int main(void)
{
    init_uart();

    /* Stupid but hopefully HUMS */
    BYTEOUT('H');
    BYTEOUT('e');
    BYTEOUT('l');
    BYTEOUT('l');
    BYTEOUT('o');
    BYTEOUT(' ');
    BYTEOUT('W');
    BYTEOUT('o');
    BYTEOUT('r');
    BYTEOUT('l');
    BYTEOUT('d');
    BYTEOUT('!');

    int i;
    int j = 1000;

    /* Run some random code */
    for (i = 0; i < 1000; i++) {
        j--;
    }

    /* Start of Superloop */
    while (1) {

    }
    /* End Superloop */

}
