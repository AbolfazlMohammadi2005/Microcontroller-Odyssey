#include <io.h>
#include <delay.h>

void main(void)
{
    DDRA.0 = 1;
    DDRD.0 = 0;
    DDRB.0 = 1;

    while (1)
    {
        if (PIND.0 == 1)
        {
            PORTA.0 = PORTA.0;

            while (PIND.0 == 1)
            {
                PORTB.0 = 1;
                delay_ms(10);
                PORTB.0 = 0;
                delay_ms(10);
            }
        }

        PORTB.0 = 1;
        delay_ms(10);
        PORTB.0 = 0;
        delay_ms(10);
    }
}
