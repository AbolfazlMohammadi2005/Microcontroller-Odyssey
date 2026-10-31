#include <io.h>
#include <delay.h>

unsigned char auto_counter(void)
{
    unsigned char n = 0;
    n++;
    return n;
}

unsigned char static_counter(void)
{
    static unsigned char n = 0;
    n++;
    return n;
}

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;

    while (1)
    {
        PORTA = auto_counter();
        PORTB = static_counter();
        delay_ms(300);
    }
}
