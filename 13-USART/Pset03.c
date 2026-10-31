#include <io.h>

void usart_init(void)
{
    UCSRA = 0x00;
    UCSRB = (1 << TXEN) | (1 << RXEN);
    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
    UBRRH = 0;
    UBRRL = 51;
}

void usart_putchar(char c)
{
    while ((UCSRA & (1 << UDRE)) == 0);
    UDR = c;
}

void usart_puts(char *s)
{
    while (*s != 0)
        usart_putchar(*s++);
}

char usart_getchar(void)
{
    while ((UCSRA & (1 << RXC)) == 0);
    return UDR;
}

char c;

void main(void)
{
    DDRA = 0xff;
    usart_init();

    while (1)
    {
        c = usart_getchar();

        if ((c >= '0') && (c <= '7'))
        {
            PORTA ^= (1 << (c - '0'));
            usart_puts("OK\r\n");
        }
        else if (c == 'a')
        {
            PORTA = 0xFF;
            usart_puts("OK\r\n");
        }
        else if (c == 'z')
        {
            PORTA = 0x00;
            usart_puts("OK\r\n");
        }
        else if ((c != '\r') && (c != '\n'))
        {
            usart_puts("ERR\r\n");
        }
    }
}
