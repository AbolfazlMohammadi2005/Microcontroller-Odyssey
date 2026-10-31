#include <io.h>
#include <delay.h>

unsigned char count_calls(void)
{
    static unsigned char n = 0;
    n++;
    return n;
}

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        PORTA = count_calls();
        delay_ms(300);
    }
}
