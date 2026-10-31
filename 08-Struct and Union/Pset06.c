#include <io.h>
#include <delay.h>

typedef union {
    unsigned char byte;
    struct {
        unsigned char b0 : 1;
        unsigned char b1 : 1;
        unsigned char b2 : 1;
        unsigned char b3 : 1;
        unsigned char b4 : 1;
        unsigned char b5 : 1;
        unsigned char b6 : 1;
        unsigned char b7 : 1;
    } bits;
} REG8;

REG8 leds;

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        leds.byte = 0;

        leds.bits.b0 = 1;   PORTA = leds.byte;   delay_ms(300);
        leds.bits.b7 = 1;   PORTA = leds.byte;   delay_ms(300);
        leds.bits.b1 = 1;   PORTA = leds.byte;   delay_ms(300);
        leds.bits.b6 = 1;   PORTA = leds.byte;   delay_ms(300);
        leds.bits.b2 = 1;   PORTA = leds.byte;   delay_ms(300);
        leds.bits.b5 = 1;   PORTA = leds.byte;   delay_ms(300);
        leds.bits.b3 = 1;   PORTA = leds.byte;   delay_ms(300);
        leds.bits.b4 = 1;   PORTA = leds.byte;   delay_ms(300);

        leds.byte = 0xAA;  PORTA = leds.byte;   delay_ms(500);
        leds.byte = 0x55;  PORTA = leds.byte;   delay_ms(500);
    }
}
