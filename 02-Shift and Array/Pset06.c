#include <io.h>
#include <delay.h>

unsigned char a = 0, b = 0, v = 0;

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        a = v / 10;
        b = v % 10;
        a <<= 4;
        a |= b;

        PORTA = a;
        delay_ms(500);

        v++;
        if (v == 100)
        {
            v = 0;
        }
    }
}
