#include <io.h>
#include <delay.h>

unsigned char a = 1, i = 0;

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        while (i < 7)
        {
            PORTA = a;
            delay_ms(300);
            a <<= 1;
            i++;
        }

        i = 0;

        while (i < 7)
        {
            PORTA = a;
            delay_ms(300);
            a >>= 1;
            i++;
        }

        i = 0;
    }
}
