#include <io.h>
#include <delay.h>

#define LOW_NIBBLE   0x0F
#define HIGH_NIBBLE  0xF0
#define EVEN_BITS    0x55
#define ODD_BITS     0xAA

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
