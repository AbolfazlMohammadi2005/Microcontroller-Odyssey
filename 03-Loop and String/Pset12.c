#include <io.h>
#include <delay.h>

unsigned char seg[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
unsigned char i, j;

void main(void)
{
    DDRD = 0xff;
    DDRC = 0xff;

    while (1)
    {
        for (j = 0; j <= 9; j++)
        {
            PORTD = seg[j];

            for (i = 0; i <= 9; i++)
            {
                PORTC = seg[i];
                delay_ms(50);
            }
        }
    }
}
