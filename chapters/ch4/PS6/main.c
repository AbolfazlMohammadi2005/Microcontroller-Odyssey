/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>
#include "bit_utils.h"

unsigned char v, i;

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;

    while (1)
    {
        for (i = 0; i < 8; i++)
        {
            v = bit_set(v, i);
            PORTA = v;
            PORTB = count_ones(v);
            delay_ms(250);
        }

        for (i = 0; i < 8; i++)
        {
            v = bit_clear(v, i);
            PORTA = v;
            PORTB = count_ones(v);
            delay_ms(250);
        }
    }
}
