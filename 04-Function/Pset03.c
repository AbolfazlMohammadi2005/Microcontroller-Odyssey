#include <io.h>
#include <delay.h>

unsigned char i;
void show(unsigned char v)
{
    unsigned char a, b;
    a = v / 10;
    b = v % 10;
    a <<= 4;
    a |= b;
    PORTA = a;
}

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        show(i);
        delay_ms(500);
        i++;
        if (i == 100)
            i = 0;
    }
}
