/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

#define LOW_NIBBLE   0x0F
#define HIGH_NIBBLE  0xF0
#define EVEN_BITS    0x55   // 0101 0101
#define ODD_BITS     0xAA   // 1010 1010

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        PORTA = 0x00;
        PORTA |= LOW_NIBBLE;
        delay_ms(500);

        PORTA &= ~LOW_NIBBLE;
        PORTA |= HIGH_NIBBLE;
        delay_ms(500);

        PORTA &= ~HIGH_NIBBLE;
        PORTA |= EVEN_BITS;
        delay_ms(500);

        PORTA ^= 0xFF;
        delay_ms(500);

        PORTA |= EVEN_BITS | ODD_BITS;
        delay_ms(500);
        PORTA &= ~(EVEN_BITS | ODD_BITS);
        delay_ms(500);
    }
}
