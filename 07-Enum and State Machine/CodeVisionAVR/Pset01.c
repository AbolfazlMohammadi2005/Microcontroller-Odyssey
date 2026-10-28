#include <io.h>
#include <delay.h>

unsigned char x = 1;

enum s {
    STATE_A,
    STATE_B,
    STATE_C,
    STATE_D
} state;

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;
    DDRC = 0xff;
    DDRD = 0xff;

    while (1)
    {
        switch (state)
        {
            case STATE_A:
                PORTA = x;
                delay_ms(100);
                x <<= 1;
                if (x == 0)
                {
                    x = 1;
                    PORTA = 0;
                    state = STATE_B;
                }
                break;

            case STATE_B:
                PORTB = x;
                delay_ms(100);
                x <<= 1;
                if (x == 0)
                {
                    x = 1;
                    PORTB = 0;
                    state = STATE_C;
                }
                break;

            case STATE_C:
                PORTC = x;
                delay_ms(100);
                x <<= 1;
                if (x == 0)
                {
                    x = 1;
                    PORTC = 0;
                    state = STATE_D;
                }
                break;

            case STATE_D:
                PORTD = x;
                delay_ms(100);
                x <<= 1;
                if (x == 0)
                {
                    x = 1;
                    PORTD = 0;
                    state = STATE_A;
                }
                break;
        }
    }
}
