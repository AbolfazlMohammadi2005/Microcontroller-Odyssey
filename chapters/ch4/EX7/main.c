/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include "two_digit.h"

unsigned char i;

void main(void)
{
    DDRA = 0xff;
    
    while (1)
    {
        PORTA = show(i);
        DELAY_MS(500);
        i++;
        if (i == 100)
            i = 0;
    }
}
