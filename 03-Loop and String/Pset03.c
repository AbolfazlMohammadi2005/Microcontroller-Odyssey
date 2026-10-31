#include <io.h>
#include <delay.h>

unsigned char a = 0, b = 0, t = 0, i = 0, data[31] = "time is:10 AM, Location TEHRAN";

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        for (i = 0; i < 14; i++)
        {
            if ((data[i] == 'i') && (data[i+1] == 's') && (data[i+2] == ':'))
                break;
        }

        t = (((data[i+3] - 48) * 10) + (data[i+4] - 48));

        a = t / 10;
        b = t % 10;
        a <<= 4;
        a |= b;

        PORTA = a;
        delay_ms(500);
    }
}
