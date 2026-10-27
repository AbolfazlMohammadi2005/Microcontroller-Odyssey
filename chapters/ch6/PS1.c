/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

void swap(unsigned char *x, unsigned char *y)
{
    unsigned char t;
    t = *x;
    *x = *y;
    *y = t;
}

unsigned char a = 0x0F, b = 0xF0;

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;

    while (1)
    {
        PORTA = a;
        PORTB = b;
        delay_ms(1000);
        swap(&a, &b);
    }
}
