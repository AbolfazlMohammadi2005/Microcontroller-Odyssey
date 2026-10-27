/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <stdio.h>

float f;
char str[20];

void delay(void)
{
    unsigned int i, j;
    for (i = 0; i < 5000; i++)
        for (j = 0; j < 50000; j++);
}

int main(void)
{
    while (1)
    {
        sprintf(str, "Value=%0.2f\n", f);
        puts(str);
        delay();
        f += 0.1;
    }
}
