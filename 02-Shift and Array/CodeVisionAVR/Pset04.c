#include <io.h>
#include <delay.h>

flash unsigned char digit[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
unsigned char i = 0;

void main(void)
{
    DDRD = 0xff;

    while (1)
    {
        PORTD = digit[i];
        delay_ms(500);
        i++;

        if (i == 10)
        {
            i = 0;
        }
    }
}
