#include <io.h>
#include <delay.h>

flash unsigned char digit[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
unsigned char i, k;

void main(void)
{
    DDRD = 0xff;

    while (1)
    {
        i = 10;
        while (i > 0)
        {
            i--;
            PORTD = digit[i];
            delay_ms(500);
        }

        for (k = 0; k < 3; k++)
        {
            PORTD = 0x00;
            delay_ms(200);
            PORTD = digit[0];
            delay_ms(200);
        }
    }
}
