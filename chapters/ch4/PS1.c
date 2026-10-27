/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

/*
 *        gray = b ^ (b >> 1)
 */
#include <io.h>
#include <delay.h>

unsigned char bin2gray(unsigned char b)
{
    return b ^ (b >> 1);
}

unsigned char n;

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;

    while (1)
    {
        PORTA = n;
        PORTB = bin2gray(n);
        delay_ms(300);
        n++;
    }
}
