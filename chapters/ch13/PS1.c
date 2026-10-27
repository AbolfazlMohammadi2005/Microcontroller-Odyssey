/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>
#include <stdio.h>

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
    {
        usart_putchar(*s);
        s++;
    }
}

char buf[32];
unsigned int count = 0;

void main(void)
{
    usart_init();

    while (1)
    {
        sprintf(buf, "Hello AVR  count=%u\r\n", count);
        usart_puts(buf);
        count++;
        delay_ms(1000);
    }
}
