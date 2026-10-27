/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

unsigned char a = 1, b = 1, c = 1, d = 1, t = 0;

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;
    DDRC = 0xff;
    DDRD = 0xff;

    while (1)
    {
        t++;
        delay_ms(10);

        if ((t % 8) == 0)
        {
            PORTA = a;
            a <<= 1;
            if (a == 0) a = 1;
        }

        if ((t % 29) == 0)
        {
            PORTB = b;
            b <<= 1;
            if (b == 0) b = 1;
        }

        if ((t % 63) == 0)
        {
            PORTC = c;
            c <<= 1;
            if (c == 0) c = 1;
        }

        if ((t % 95) == 0)
        {
            PORTD = d;
            d <<= 1;
            if (d == 0) d = 1;
        }
    }
}
