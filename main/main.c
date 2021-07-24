/**
 * main.c
 *
 * Author: John Fuerlinger
 *
 * Desc: This is a barebones project for bare metal dev. on the CC3220SF_LAUNCHXL.
 *
 * (c) 2021, John Fuerlinger, all rights reserved
 */





/* Let's start with something basic */
int main(void)
{
    int i;
    int j = 1000;

    for (i = 0; i < 1000; i++) {
        j--;
    }

	return 0;
}
