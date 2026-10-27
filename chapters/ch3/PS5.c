/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

unsigned char v[8] = {23, 7, 91, 45, 3, 64, 18, 56};
unsigned char i, max, min;

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;

    while (1)
    {
        max = v[0];
        min = v[0];

        for (i = 1; i < 8; i++)
        {
            if (v[i] > max) max = v[i];
            if (v[i] < min) min = v[i];
        }

        PORTA = max;     // 91 = 0x5B
        PORTB = min;     // 3  = 0x03
        delay_ms(500);
    }
}
