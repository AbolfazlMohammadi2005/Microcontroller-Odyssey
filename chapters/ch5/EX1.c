/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

void show(void)
{
    static unsigned char v;
    unsigned char a, b;
    
    a = v / 10;
    b = v % 10;
    a <<= 4;
    a |= b;
    
    PORTA = a;
    delay_ms(500);
    
    v++;
    if (v == 100)
    {
        v = 0;
    }
}

void main(void)
{
    DDRA = 0xff;
    
    while (1)
    {
        show();
    }
}
