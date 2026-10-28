#include <io.h>
#include <delay.h>
#include <stdio.h>

char str[32];
unsigned int n, sq, cube;

void usart_init(void)
{
    UCSRA = 0x00;
    UCSRB = (1 << TXEN) | (1 << RXEN);
    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
    UBRRH = 0;
    UBRRL = 51;
}

void main(void)
{
    usart_init();

    while (1)
    {
        for (n = 1; n <= 10; n++)
        {
            sq   = n * n;
            cube = n * n * n;
            sprintf(str, "n=%2d sq=%4d cube=%5d", n, sq, cube);
            puts(str);
            delay_ms(300);
        }
        puts("-----------------");
        delay_ms(2000);
    }
}
