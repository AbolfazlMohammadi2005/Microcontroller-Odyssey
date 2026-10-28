#include <io.h>
#include <delay.h>

unsigned char str_len(char *s)
{
    char *p = s;
    while (*p != 0)
        p++;
    return (unsigned char)(p - s);
}

void str_rev(char *s)
{
    char *e = s + str_len(s) - 1;
    char t;

    while (s < e)
    {
        t = *s;
        *s = *e;
        *e = t;
        s++;
        e--;
    }
}

char text[16] = "micro";

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;

    PORTA = str_len(text);
    delay_ms(1000);

    str_rev(text);
    PORTB = text[0];

    while (1)
    {
    }
}
