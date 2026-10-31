#include <io.h>
#include <delay.h>

flash unsigned char digit[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

void seg_show(unsigned char v)
{
    PORTC = digit[v / 10];
    PORTD = digit[v % 10];
}

unsigned char i;

void main(void)
{
    DDRC = 0xff;
    DDRD = 0xff;

    while (1)
    {
        seg_show(i);
        delay_ms(200);
        i++;
        if (i == 100)
            i = 0;
    }
}
