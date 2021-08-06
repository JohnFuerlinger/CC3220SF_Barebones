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

/* Common Includes */
#include "com_inc.h"

/* The below breaks the rules and is only for testing. bad bad bad */
#include "hardware_layer/uart.h"

/* Library Includes */
#include <library_layer/juprintf.h>



int main();

extern void _c_int00_noargs(void);
/* Can I get this to work..? */



int startup(void) {
    _c_int00_noargs();
    main();

    return 0;
}

/* Let's start with something basic */
int main(void)
{

    /* Let's start with something even more basic */







    //(*((volatile unsigned long *)(0x4402e0d0))) |= (1U << 7);

    /* This is a magic line of code that enables the peripheral clock to uDMA? */
    (*((volatile unsigned long *)(0x44025000 + 72))) |= 0x1;

    /* This is a magic line of code that enables the peripheral clock to UART? */
    (*((volatile unsigned long *)(0x44025000 + 128))) |= 0x101;

    init_uart();

    juprintf("Test");

    /* Start of Superloop */
    while (1) {



    }
    /* End Superloop */

}
