#include <io.h>
#include <delay.h>

unsigned char n = 0;

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;

    while (1)
    {
        PORTA = n;
        PORTB = ~n;
        delay_ms(200);
        n++;
    }
}
