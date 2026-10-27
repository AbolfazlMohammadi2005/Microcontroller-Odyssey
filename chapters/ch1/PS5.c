/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

#define pin_on(x)   PORTA |= (1 << (x))
#define pin_off(x)  PORTA &= ~(1 << (x))

#define LED 0

#define DOT   { pin_on(LED); delay_ms(200); pin_off(LED); delay_ms(200); }
#define DASH  { pin_on(LED); delay_ms(600); pin_off(LED); delay_ms(200); }
#define LETTER_GAP  delay_ms(400)

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        DOT  DOT  DOT      // S
        LETTER_GAP;
        DASH DASH DASH     // O
        LETTER_GAP;
        DOT  DOT  DOT      // S

        delay_ms(2000);
    }
}
