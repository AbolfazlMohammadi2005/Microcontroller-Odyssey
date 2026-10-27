/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

unsigned char reverse_bits(unsigned char v);

unsigned char n;

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;

    while (1)
    {
        PORTA = n;
        PORTB = reverse_bits(n);
        delay_ms(300);
        n++;
    }
}

unsigned char reverse_bits(unsigned char v)
{
    unsigned char i, r = 0;
    for (i = 0; i < 8; i++)
    {
        r = (r << 1) | (v & 1);
        v >>= 1;
    }
    return r;
}
