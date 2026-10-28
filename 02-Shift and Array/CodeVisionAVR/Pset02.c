#include <io.h>
#include <delay.h>

unsigned char a = 0x01, b = 0x80, s = 0;

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        if (s == 0)
        {
            PORTA = a | b;
            delay_ms(100);
            a <<= 1;
            b >>= 1;

            if (a == 0x08)
            {
                s = 1;
            }
        }
        else
        {
            PORTA = a | b;
            delay_ms(100);
            a >>= 1;
            b <<= 1;

            if (a == 0x01)
            {
                s = 0;
            }
        }
    }
}
