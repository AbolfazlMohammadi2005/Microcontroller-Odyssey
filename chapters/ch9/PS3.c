/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

flash unsigned char digit[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

unsigned char pressed(unsigned char pin)
{
    if ((PINB & (1 << pin)) == 0)
    {
        delay_ms(20);
        if ((PINB & (1 << pin)) == 0)
        {
            while ((PINB & (1 << pin)) == 0);
            delay_ms(20);
            return 1;
        }
    }
    return 0;
}

unsigned char v = 0;

void main(void)
{
    DDRD = 0xff;
    DDRB = 0x00;
    PORTB = 0xff;

    while (1)
    {
        PORTD = digit[v];

        if (pressed(0))              // UP
        {
            v++;
            if (v == 10) v = 0;
        }

        if (pressed(1))              // DOWN
        {
            if (v == 0) v = 9;
            else        v--;
        }
    }
}
