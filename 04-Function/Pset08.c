#include <io.h>
#include <stdio.h>

unsigned int x;
char str[20];

void delay(void)
{
    unsigned int i, j;
    for (i = 0; i < 5000; i++)
        for (j = 0; j < 50000; j++);
}

void usart_init(void)
{
    UCSRA = 0x00;
    UCSRB = (1 << TXEN) | (1 << RXEN);
    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
    UBRRH = 0;
    UBRRL = 51;
}

int main(void)
{
    usart_init();

    while (1)
    {
        sprintf(str, "Value=%4.4d\n", x);
        puts(str);
        delay();
        x++;
    }
}
