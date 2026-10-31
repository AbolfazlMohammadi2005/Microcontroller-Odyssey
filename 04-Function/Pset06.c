#include <io.h>

void DELAY_MS(unsigned int x)
{
    unsigned int i, j;
    for (i = 0; i < x; i++)
        for (j = 0; j < 1000; j++);
}

unsigned char show(unsigned char v)
{
    unsigned char a, b;
    a = v / 10;
    b = v % 10;
    a <<= 4;
    a |= b;
    return a;
}

unsigned char v = 0;

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        PORTA = show(v);
        DELAY_MS(500);
        v++;
        if (v == 100)
            v = 0;
    }
}
