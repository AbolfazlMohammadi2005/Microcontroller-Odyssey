#include <io.h>
#include <delay.h>

unsigned char i;
void show(void)
{
    unsigned char a, b;
    a = i / 10;
    b = i % 10;
    a <<= 4;
    a |= b;
    PORTA = a;
}

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        show();
        delay_ms(500);
        i++;
        if (i == 100)
            i = 0;
    }
}
