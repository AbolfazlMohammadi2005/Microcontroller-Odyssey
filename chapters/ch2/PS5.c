/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

flash unsigned char digit[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
unsigned char i = 9;

void main(void)
{
    DDRD = 0xff;

    while (1)
    {
        PORTD = digit[i];
        delay_ms(500);

        if (i == 0)
        {
            i = 9;
        }
        else
        {
            i--;
        }
    }
}
