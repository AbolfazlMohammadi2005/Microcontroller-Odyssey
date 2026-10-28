#include <io.h>
#include <delay.h>

unsigned char a = 1, i = 0;

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        for (i = 0; i < 7; i++)
        {
            PORTA = a;
            delay_ms(300);
            a <<= 1;
        }

        for (i = 0; i < 7; i++)
        {
            PORTA = a;
            delay_ms(300);
            a >>= 1;
        }
    }
}
