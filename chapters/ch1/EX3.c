/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

#define po PORTA
#define pin_on(x)   po |= (1 << x)
#define pin_off(x)  po &= ~(1 << x)

void main(void)
{
    DDRA = 0xff;
    
    while (1)
    {
        pin_on(7);
        delay_ms(300);
        pin_off(7);
        delay_ms(300);
    }
}
