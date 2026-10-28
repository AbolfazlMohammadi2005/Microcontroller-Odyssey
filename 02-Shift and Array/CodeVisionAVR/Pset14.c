#include <io.h>
#include <delay.h>

flash unsigned char hex[16] = {
    0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07,
    0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71
};

unsigned char i = 0, dp = 0;

void main(void)
{
    DDRD = 0xff;

    while (1)
    {
        PORTD = hex[i] | dp;
        delay_ms(500);

        dp ^= 0x80;
        i++;

        if (i == 16)
        {
            i = 0;
        }
    }
}
