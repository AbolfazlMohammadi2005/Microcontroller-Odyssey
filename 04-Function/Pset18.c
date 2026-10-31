#include <io.h>
#include <delay.h>
#include <stdio.h>

char str[32];

void usart_init(void)
{
    UCSRA = 0x00;
    UCSRB = (1 << TXEN) | (1 << RXEN);
    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
    UBRRH = 0;
    UBRRL = 51;
}

float c2f(float c)
{
    return (c * 9.0 / 5.0) + 32.0;
}

float c;

void main(void)
{
    usart_init();

    while (1)
    {
        for (c = 0; c <= 100; c += 10)
        {
            sprintf(str, "%5.1f C = %5.1f F", c, c2f(c));
            puts(str);
            delay_ms(300);
        }
        puts("");
        delay_ms(2000);
    }
}
