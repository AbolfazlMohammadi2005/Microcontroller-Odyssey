/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

unsigned char sec = 0, min = 0;

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;

    while (1)
    {
        PORTA = ((sec / 10) << 4) | (sec % 10);
        PORTB = ((min / 10) << 4) | (min % 10);
        delay_ms(1000);

        sec++;
        if (sec == 60)
        {
            sec = 0;
            min++;
            if (min == 60)
            {
                min = 0;
            }
        }
    }
}
