#include <io.h>
#include <delay.h>

unsigned char seg[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
signed char i, j;

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;
    DDRC = 0xff;
    DDRD = 0xff;

    while (1)
    {
        for (j = 9; j >= 0; j--)
        {
            PORTD = seg[j];

            for (i = 9; i >= 0; i--)
            {
                PORTC = seg[i];
                delay_ms(20);

                PORTA = 0x01;
                if (j >= 3)
                {
                    PORTB = 0x04;
                }
                else
                {
                    PORTB = 0x02;
                }
            }
        }

        PORTC = seg[0];

        for (j = 9; j >= 0; j--)
        {
            PORTD = seg[j];
            delay_ms(50);
        }
    }
}
