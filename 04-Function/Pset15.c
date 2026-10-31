#include <io.h>
#include <delay.h>

unsigned char sec = 0, min = 0;

unsigned char bcd(unsigned char v)
{
    return ((v / 10) << 4) | (v % 10);
}

void tick(void)
{
    sec++;
    if (sec == 60)
    {
        sec = 0;
        min++;
        if (min == 60)
            min = 0;
    }
}

void show(void)
{
    PORTA = bcd(sec);
    PORTB = bcd(min);
}

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;

    while (1)
    {
        show();
        delay_ms(1000);
        tick();
    }
}
