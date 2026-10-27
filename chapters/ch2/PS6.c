/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

flash unsigned char hex[16] = {
    0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07,   // 0..7
    0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71    // 8..9 A b C d E F
};

unsigned char i = 0, dp = 0;

void main(void)
{
    DDRD = 0xff;

    while (1)
    {
        PORTD = hex[i] | dp;
        delay_ms(500);

        dp ^= 0x80;
        i++;

        if (i == 16)
        {
            i = 0;
        }
    }
}
