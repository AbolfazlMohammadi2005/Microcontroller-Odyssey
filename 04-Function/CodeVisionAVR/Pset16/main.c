#include <io.h>
#include <delay.h>
#include "bit_utils.h"

unsigned char v, i;

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;

    while (1)
    {
        for (i = 0; i < 8; i++)
        {
            v = bit_set(v, i);
            PORTA = v;
            PORTB = count_ones(v);
            delay_ms(250);
        }

        for (i = 0; i < 8; i++)
        {
            v = bit_clear(v, i);
            PORTA = v;
            PORTB = count_ones(v);
            delay_ms(250);
        }
    }
}
