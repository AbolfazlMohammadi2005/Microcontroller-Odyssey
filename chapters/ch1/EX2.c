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
    
    while (1)
    {
        PORTA ^= (1 << 7);
        delay_ms(500);
    }
}
