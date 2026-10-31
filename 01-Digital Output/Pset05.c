#include <io.h>
#include <delay.h>

void main(void)
{
    DDRA.0 = 1;
    DDRA.1 = 1;

    while (1)
    {
        PORTA.0 = 1;
        PORTA.1 = 0;
        delay_ms(400);

        PORTA.0 = 0;
        PORTA.1 = 1;
        delay_ms(400);
    }
}