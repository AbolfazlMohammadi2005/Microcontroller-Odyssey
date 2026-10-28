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
