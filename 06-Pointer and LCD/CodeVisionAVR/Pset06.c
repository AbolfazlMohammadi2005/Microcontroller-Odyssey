#include <io.h>
#include <delay.h>

unsigned int sum_array(unsigned char *p, unsigned char n)
{
    unsigned int s = 0;
    while (n > 0)
    {
        s += *p;
        p++;
        n--;
    }
    return s;
}

unsigned char v[5] = {10, 20, 30, 40, 50};
unsigned int s;

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;

    while (1)
    {
        s = sum_array(v, 5);
        PORTA = (unsigned char)s;
        PORTB = (unsigned char)(s / 5);
        delay_ms(500);
    }
}
