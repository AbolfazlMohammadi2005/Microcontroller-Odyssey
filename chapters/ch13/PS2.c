/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

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

char usart_getchar(void)
{
    while ((UCSRA & (1 << RXC)) == 0);
    return UDR;
}

char c;

void main(void)
{
    usart_init();

    while (1)
    {
        c = usart_getchar();

        if ((c >= 'a') && (c <= 'z'))
            c -= 32;

        usart_putchar(c);
    }
}
