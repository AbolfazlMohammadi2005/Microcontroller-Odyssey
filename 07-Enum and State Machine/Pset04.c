#include <io.h>
#include <delay.h>

flash unsigned char digit[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

enum m {
    MODE_UP,
    MODE_DOWN,
    MODE_BLINK
} mode = MODE_UP;

unsigned char n = 0;

void main(void)
{
    DDRD = 0xff;

    while (1)
    {
        switch (mode)
        {
            case MODE_UP:
                PORTD = digit[n];
                delay_ms(300);
                n++;
                if (n == 10)
                {
                    n = 8;
                    mode = MODE_DOWN;
                }
                break;

            case MODE_DOWN:
                PORTD = digit[n];
                delay_ms(300);
                if (n == 0)
                {
                    mode = MODE_BLINK;
                }
                else
                {
                    n--;
                }
                break;

            case MODE_BLINK:
                PORTD = digit[8];
                delay_ms(200);
                PORTD = 0x00;
                delay_ms(200);
                n++;
                if (n == 5)
                {
                    n = 0;
                    mode = MODE_UP;
                }
                break;
        }
    }
}
