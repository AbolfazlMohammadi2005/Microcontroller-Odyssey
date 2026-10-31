#include <io.h>
#include <delay.h>

flash unsigned char digit[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

enum s {
    ST_FILL,
    ST_WASH,
    ST_DRAIN,
    ST_SPIN,
    ST_DONE
} state = ST_FILL;

unsigned char t = 5;
unsigned char k;

void main(void)
{
    DDRA = 0xff;
    DDRD = 0xff;

    while (1)
    {
        switch (state)
        {
            case ST_FILL:
                PORTA = 0x01;
                PORTD = digit[t];
                delay_ms(1000);
                if (t == 0) { state = ST_WASH;  t = 9; } else t--;
                break;

            case ST_WASH:
                PORTA = 0x02;
                PORTD = digit[t];
                delay_ms(1000);
                if (t == 0) { state = ST_DRAIN; t = 4; } else t--;
                break;

            case ST_DRAIN:
                PORTA = 0x04;
                PORTD = digit[t];
                delay_ms(1000);
                if (t == 0) { state = ST_SPIN;  t = 6; } else t--;
                break;

            case ST_SPIN:
                PORTA = 0x08;
                PORTD = digit[t];
                delay_ms(1000);
                if (t == 0) { state = ST_DONE; } else t--;
                break;

            case ST_DONE:
                PORTD = 0x00;
                for (k = 0; k < 4; k++)
                {
                    PORTA = 0x80;
                    delay_ms(250);
                    PORTA = 0x00;
                    delay_ms(250);
                }
                t = 5;
                state = ST_FILL;
                break;
        }
    }
}
