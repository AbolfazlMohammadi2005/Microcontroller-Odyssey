#include <io.h>
#include <delay.h>

unsigned char a = 0x01, dir = 0;

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        PORTA = a;
        delay_ms(150);

        if (dir == 0)
        {
            a <<= 1;
            if (a == 0x80)
                dir = 1;
        }
        else
        {
            a >>= 1;
            if (a == 0x01)
                dir = 0;
        }
    }
}
