/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

/*
 *      00011000
 *      00111100
 *      01111110
 *      11111111
 *      01111110
 *      00111100
 *      00011000
 *      00000000
 */
#include <io.h>
#include <delay.h>

flash unsigned char pattern[8] = {0x18, 0x3C, 0x7E, 0xFF, 0x7E, 0x3C, 0x18, 0x00};
unsigned char i = 0;

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        PORTA = pattern[i];
        delay_ms(200);
        i++;

        if (i == 8)
        {
            i = 0;
        }
    }
}
