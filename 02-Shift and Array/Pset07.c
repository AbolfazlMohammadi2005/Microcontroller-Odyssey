#include <io.h>
#include <delay.h>

unsigned char state = 0, x = 1;

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
            case 0:
                PORTA = x;
                delay_ms(100);
                x <<= 1;
                if (x == 0)
                {
                    x = 1;
                    PORTA = 0;
                    state = 1;
                }
                break;

            case 1:
                PORTB = x;
                delay_ms(100);
                x <<= 1;
                if (x == 0)
                {
                    x = 1;
                    PORTB = 0;
                    state = 2;
                }
                break;

            case 2:
                PORTC = x;
                delay_ms(100);
                x <<= 1;
                if (x == 0)
                {
                    x = 1;
                    PORTC = 0;
                    state = 3;
                }
                break;

            case 3:
                PORTD = x;
                delay_ms(100);
                x <<= 1;
                if (x == 0)
                {
                    x = 1;
                    PORTD = 0;
                    state = 0;
                }
                break;
        }
    }
}
