#include <io.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX 16

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

unsigned char read_line(char *line)
{
    unsigned char n = 0, ok = 1;
    char c;

    while (1)
    {
        c = usart_getchar();
        if (c == '\r')
            break;
        if (c == '\n')
            continue;

        if (n < (LINE_MAX - 1))
            line[n++] = c;
        else
            ok = 0;
    }
    line[n] = 0;
    return ok;
}

char line[LINE_MAX];
int v;

void main(void)
{
    DDRA = 0xff;
    usart_init();

    while (1)
    {
        if (!read_line(line))
        {
            usart_puts("ERR\r\n");
            continue;
        }

        if (strncmp(line, "ON ", 3) == 0)
        {
            v = atoi(line + 3);
            if ((v >= 0) && (v <= 7)) { PORTA |= (1 << v); usart_puts("OK\r\n"); }
            else usart_puts("ERR\r\n");
        }
        else if (strncmp(line, "OFF ", 4) == 0)
        {
            v = atoi(line + 4);
            if ((v >= 0) && (v <= 7)) { PORTA &= ~(1 << v); usart_puts("OK\r\n"); }
            else usart_puts("ERR\r\n");
        }
        else if (strncmp(line, "SET ", 4) == 0)
        {
            v = atoi(line + 4);
            if ((v >= 0) && (v <= 255)) { PORTA = (unsigned char)v; usart_puts("OK\r\n"); }
            else usart_puts("ERR\r\n");
        }
        else
        {
            usart_puts("ERR\r\n");
        }
    }
}
