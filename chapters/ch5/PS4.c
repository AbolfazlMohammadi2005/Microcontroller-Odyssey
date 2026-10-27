/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

unsigned char flip(void)
{
    static unsigned char s = 0;
    s = !s;
    return s;
}

unsigned char every_n(unsigned char n)
{
    static unsigned char c = 0;
    c++;
    if (c >= n)
    {
        c = 0;
        return 1;
    }
    return 0;
}

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        if (flip())
            PORTA |= (1 << 0);
        else
            PORTA &= ~(1 << 0);

        if (every_n(5))
            PORTA ^= (1 << 1);

        delay_ms(100);
    }
}
