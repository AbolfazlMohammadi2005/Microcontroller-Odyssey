#include <io.h>
#include <delay.h>

unsigned char a = 0x80;

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        PORTA = a;
        delay_ms(200);
        a >>= 1;

        if (a == 0)
        {
            a = 0x80;
        }
    }
}
