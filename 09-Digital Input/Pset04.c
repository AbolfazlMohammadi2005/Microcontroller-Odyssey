#include <io.h>
#include <delay.h>

unsigned char a = 0x01, sw, k, steps;

void main(void)
{
    DDRA = 0xff;
    DDRB = 0x00;
    PORTB = 0xff;

    while (1)
    {
        sw = (~PINB) & 0x0F;

        PORTA = a;
        steps = sw + 1;
        for (k = 0; k < steps; k++)
            delay_ms(50);

        a <<= 1;
        if (a == 0)
            a = 0x01;
    }
}
