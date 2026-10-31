#include <io.h>
#include <delay.h>

void main(void)
{
    DDRA.7 = 1;

    while (1)
    {
        PORTA.7 = 1;
        delay_ms(500);

        PORTA.7 = 0;
        delay_ms(500);
    }
}