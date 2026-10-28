#include <io.h>
#include <delay.h>

unsigned char digit[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
unsigned char i = 0, j = 0;

void main(void)
{
    DDRC = 0xff;
    DDRD = 0xff;

    while (1)
    {
        PORTC = digit[i];
        PORTD = digit[j];
        delay_ms(500);

        i++;
        if (i == 10)
        {
            i = 0;
            j++;
            if (j == 10)
            {
                j = 0;
            }
        }
    }
}
