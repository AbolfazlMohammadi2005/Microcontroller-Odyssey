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
        DOT  DOT  DOT
        LETTER_GAP;
        DASH DASH DASH
        LETTER_GAP;
        DOT  DOT  DOT

        delay_ms(2000);
    }
}
