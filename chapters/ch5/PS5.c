/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

unsigned char peak(unsigned char v, unsigned char reset)
{
    static unsigned char max = 0;

    if (reset)
        max = 0;

    if (v > max)
        max = v;

    return max;
}

unsigned char input[8] = {3, 9, 4, 12, 7, 15, 2, 8};
unsigned char i;

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;

    while (1)
    {
        for (i = 0; i < 8; i++)
        {
            PORTA = input[i];
            PORTB = peak(input[i], 0);
            delay_ms(400);
        }

        peak(0, 1);
        delay_ms(800);
    }
}
