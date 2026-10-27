/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

void blink(unsigned char pin, unsigned char n)
{
    unsigned char k;
    for (k = 0; k < n; k++)
    {
        PORTA |= (1 << pin);
        delay_ms(150);
        PORTA &= ~(1 << pin);
        delay_ms(150);
    }
}

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        blink(0, 1);
        blink(1, 2);
        blink(2, 3);
        delay_ms(1000);
    }
}
