/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

#define po PORTA
#define pin_on(x)      po |= (1 << (x))
#define pin_off(x)     po &= ~(1 << (x))
#define pin_toggle(x)  po ^= (1 << (x))

#define RED     0
#define YELLOW  1
#define GREEN   2

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        pin_off(RED);
        pin_on(GREEN);
        delay_ms(3000);

        pin_off(GREEN);
        pin_on(YELLOW);   delay_ms(125);
        pin_toggle(YELLOW); delay_ms(125);
        pin_toggle(YELLOW); delay_ms(125);
        pin_toggle(YELLOW); delay_ms(125);
        pin_toggle(YELLOW); delay_ms(125);
        pin_toggle(YELLOW); delay_ms(125);
        pin_toggle(YELLOW); delay_ms(125);
        pin_toggle(YELLOW); delay_ms(125);
        pin_off(YELLOW);

        pin_on(RED);
        delay_ms(3000);
    }
}
