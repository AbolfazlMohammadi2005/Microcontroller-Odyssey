#include <io.h>
#include <delay.h>

flash unsigned char digit[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
unsigned char v = 99;

void main(void)
{
    DDRC = 0xff;
    DDRD = 0xff;

    while (1)
    {
        PORTC = digit[v / 10];
        PORTD = digit[v % 10];
        delay_ms(300);

        if (v == 0)
        {
            v = 99;
        }
        else
        {
            v--;
        }
    }
}
