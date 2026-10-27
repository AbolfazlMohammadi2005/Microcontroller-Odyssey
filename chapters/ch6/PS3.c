/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

unsigned int sum_array(unsigned char *p, unsigned char n)
{
    unsigned int s = 0;
    while (n > 0)
    {
        s += *p;
        p++;
        n--;
    }
    return s;
}

unsigned char v[5] = {10, 20, 30, 40, 50};
unsigned int s;

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;

    while (1)
    {
        s = sum_array(v, 5);
        PORTA = (unsigned char)s;   // 0x96
        PORTB = (unsigned char)(s / 5);   // 0x1E
        delay_ms(500);
    }
}
