/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

unsigned char n, k;

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        for (n = 1; n <= 5; n++)
        {
            for (k = 0; k < n; k++)
            {
                PORTA = 0x01;
                delay_ms(150);
                PORTA = 0x00;
                delay_ms(150);
            }
            delay_ms(1000);
        }
    }
}
