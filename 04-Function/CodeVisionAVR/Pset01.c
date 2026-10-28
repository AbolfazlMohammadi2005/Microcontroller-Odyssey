#include <io.h>
#include <delay.h>

unsigned char show(unsigned char v)
{
    unsigned char a, b;
    a = v / 10;
    b = v % 10;
    a <<= 4;
    a |= b;
    return a;
}

unsigned char i;

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        PORTA = show(i);
        delay_ms(500);
        i++;
        if (i == 100)
            i = 0;
    }
}
