#include <io.h>
#include <delay.h>

unsigned char a = 0;

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        PORTA = a;
        delay_ms(200);

        if (a == 0xff)
        {
            a = 0;
        }
        else
        {
            a = (a << 1) | 1;
        }
    }
}
