#include <io.h>
#include <delay.h>

typedef struct {
    unsigned char value;
    unsigned char max;
} COUNTER;

unsigned char counter_inc(COUNTER *c)
{
    c->value++;
    if (c->value > c->max)
    {
        c->value = 0;
        return 1;
    }
    return 0;
}

flash unsigned char digit[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

COUNTER cnt[4] = {{0, 9}, {0, 9}, {0, 9}, {0, 9}};

void main(void)
{
    DDRA = 0xff;
    DDRB = 0xff;
    DDRC = 0xff;
    DDRD = 0xff;

    while (1)
    {
        PORTA = digit[cnt[0].value];
        PORTB = digit[cnt[1].value];
        PORTC = digit[cnt[2].value];
        PORTD = digit[cnt[3].value];
        delay_ms(100);

        if (counter_inc(&cnt[0]))
            if (counter_inc(&cnt[1]))
                if (counter_inc(&cnt[2]))
                    counter_inc(&cnt[3]);
    }
}
