/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

unsigned char i;
void show(void)
{
    unsigned char a, b;
    a = i / 10;
    b = i % 10;
    a <<= 4;
    a |= b;
    PORTA = a;
}

void main(void)
{
    DDRA = 0xff;
    
    while (1)
    {
        show();
        delay_ms(500);
        i++;
        if (i == 100)
            i = 0;
    }
}
