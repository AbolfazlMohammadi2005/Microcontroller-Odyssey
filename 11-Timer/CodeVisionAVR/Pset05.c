#include <io.h>

volatile unsigned char sec = 0, min = 0;

interrupt [TIM1_COMPA] void timer1_compa_isr(void)
{
    sec++;
    if (sec == 60)
    {
        sec = 0;
        min++;
        if (min == 60)
            min = 0;
    }
}

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;

    TCCR1A = 0x00;
    TCCR1B = (1 << WGM12) | (1 << CS12);
    OCR1A = 31249;
    TCNT1 = 0;
    TIMSK |= (1 << OCIE1A);
    #asm("sei")

    while (1)
    {
        PORTA = ((sec / 10) << 4) | (sec % 10);
        PORTB = ((min / 10) << 4) | (min % 10);
    }
}
