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
#include "stdint.h"

//extern void __TI_auto_init(void);

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
    //__TI_auto_init();

//    uint32_t j;
//    for (int i = 0; i < 100000; i++) {
//        j = *(volatile uint32_t *) (0x4000c030);
//    }

    //uint8_t tmp = 182;

    /* Peripheral clock enable....? */
    /* is this the magic fix..? No, it is not */
    //**********************************************************
    (*((volatile unsigned long *)( 0x44025000 + 0x48 ))) |= 0x101;
    //**********************************************************

    /* Note: something needs to happen before we initialize peripherals.. What is this? I don't know.
     * But once the CPU reboots (power cycle or reset signal), it no longer has access to memory mapped
     * registers for the peripherals. I believe that this is the "underprivileged mode" which is referenced
     * in the documentation, but I haven't found anything about how to elevate privileges.
     *
     * Going to reverse engineer how the TI driver sets this up and then imitate the important parts... without
     * creating a spider web mess of code like the TI driver does.
     *
     * Note: It appears that the peripheral clock needs to be enabled for every peripheral we want to use
     *       (except for ADC). This aligns with my observations, since we can read the ADC regs, but not the
     *       UART regs. The above line of code was supposed to enable peripheral clock to the UART regs, but
     *       it did not appear to work. Need to noodle this one out.
     */
    init_uart();

    //jprintf("Hello world, fprintf style!\n\ndid that work..?\n\nhow about this: %u", tmp);

    /* Start of Superloop */
    while (1) {

    }
    /* End Superloop */

}
