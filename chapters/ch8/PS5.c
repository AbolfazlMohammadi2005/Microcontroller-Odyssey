/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

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
    } bit;
} REG8;

REG8 leds;

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        leds.byte = 0;

        leds.bit.b0 = 1;   PORTA = leds.byte;   delay_ms(300);
        leds.bit.b7 = 1;   PORTA = leds.byte;   delay_ms(300);
        leds.bit.b1 = 1;   PORTA = leds.byte;   delay_ms(300);
        leds.bit.b6 = 1;   PORTA = leds.byte;   delay_ms(300);
        leds.bit.b2 = 1;   PORTA = leds.byte;   delay_ms(300);
        leds.bit.b5 = 1;   PORTA = leds.byte;   delay_ms(300);
        leds.bit.b3 = 1;   PORTA = leds.byte;   delay_ms(300);
        leds.bit.b4 = 1;   PORTA = leds.byte;   delay_ms(300);

        leds.byte = 0xAA;  PORTA = leds.byte;   delay_ms(500);
        leds.byte = 0x55;  PORTA = leds.byte;   delay_ms(500);
    }
}
