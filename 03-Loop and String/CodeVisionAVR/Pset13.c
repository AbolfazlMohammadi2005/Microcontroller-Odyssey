#include <io.h>
#include <delay.h>

unsigned char seg[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
signed char i, j;

void main(void)
{
    DDRD = 0xff;
    DDRC = 0xff;
    DDRA.0 = 1;

    while (1)
    {
        for (j = 9; j >= 0; j--)
        {
            PORTD = seg[j];

            for (i = 9; i >= 0; i--)
            {
                PORTC = seg[i];
                delay_ms(75);

                if (i == 7 && j == 2)
                {
                    PORTA.0 = 1;
                }
            }
        }
    }
}
