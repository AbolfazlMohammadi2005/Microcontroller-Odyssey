/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <stdio.h>

void get_val(int *x, int *y)
{
    *x = 10;
    *y = 20;
}

int main(void)
{
    int a, b;
    get_val(&a, &b);
    return 0;
}
