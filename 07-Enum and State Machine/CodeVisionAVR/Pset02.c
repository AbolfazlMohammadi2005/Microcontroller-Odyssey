#include <io.h>
#include <delay.h>

#define RED_LED     (1 << 0)
#define YELLOW_LED  (1 << 1)
#define GREEN_LED   (1 << 2)

enum s {
    ST_GREEN,
    ST_YELLOW,
    ST_RED,
    ST_RED_YELLOW
} state = ST_GREEN;

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        switch (state)
        {
            case ST_GREEN:
                PORTA = GREEN_LED;
                delay_ms(3000);
                state = ST_YELLOW;
                break;

            case ST_YELLOW:
                PORTA = YELLOW_LED;
                delay_ms(1000);
                state = ST_RED;
                break;

            case ST_RED:
                PORTA = RED_LED;
                delay_ms(3000);
                state = ST_RED_YELLOW;
                break;

            case ST_RED_YELLOW:
                PORTA = RED_LED | YELLOW_LED;
                delay_ms(1000);
                state = ST_GREEN;
                break;
        }
    }
}
