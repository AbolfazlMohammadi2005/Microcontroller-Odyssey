#include <io.h>
#include <delay.h>

unsigned char a = 1;

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        PORTA = a;
        delay_ms(300);
        a <<= 1;

        if (a == 0)
        {
            a = 1;
        }
    }
}
