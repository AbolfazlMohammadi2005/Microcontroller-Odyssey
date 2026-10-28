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
        usart_putchar(*s++);
}

unsigned int read_adc(unsigned char ch)
{
    ADMUX = (1 << REFS0) | ch;
    delay_us(10);
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));
    return ADCW;
}

char buf[32];
unsigned int adc, mv;

void main(void)
{
    usart_init();
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);

    while (1)
    {
        adc = read_adc(0);
        mv  = (unsigned int)(((unsigned long)adc * 5000UL) / 1024UL);

        sprintf(buf, "ADC=%u V=%umV\r\n", adc, mv);
        usart_puts(buf);
        delay_ms(500);
    }
}
