/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

void main(void)
{
    DDRA = 0xff;
    PORTA = 0x01;

    while (1)
    {
        delay_ms(400);
        PORTA ^= 0x03;
    }
}
