#include <io.h>

unsigned char overflows = 0;

void main(void)
{
    DDRA = 0xff;

    TCNT0 = 0;
    TCCR0 = (1 << CS02) | (1 << CS00);

    while (1)
    {
        while ((TIFR & (1 << TOV0)) == 0);
        TIFR |= (1 << TOV0);

        overflows++;
        if (overflows == 30)
        {
            overflows = 0;
            PORTA ^= (1 << 0);
        }
    }
}
