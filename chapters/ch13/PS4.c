/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

#define BUF_SIZE 16

volatile char rx_buf[BUF_SIZE];
volatile unsigned char head = 0, tail = 0;

interrupt [USART_RXC] void usart_rx_isr(void)
{
    char c = UDR;
    unsigned char next = (head + 1) % BUF_SIZE;

    if (next != tail)
    {
        rx_buf[head] = c;
        head = next;
    }
}

void usart_init(void)
{
    UCSRA = 0x00;
    UCSRB = (1 << RXCIE) | (1 << TXEN) | (1 << RXEN);
    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
    UBRRH = 0;
    UBRRL = 51;
}

void usart_putchar(char c)
{
    while ((UCSRA & (1 << UDRE)) == 0);
    UDR = c;
}

void main(void)
{
    usart_init();
    #asm("sei")

    while (1)
    {
        delay_ms(500);

        while (tail != head)
        {
            usart_putchar(rx_buf[tail]);
            tail = (tail + 1) % BUF_SIZE;
        }
    }
}
