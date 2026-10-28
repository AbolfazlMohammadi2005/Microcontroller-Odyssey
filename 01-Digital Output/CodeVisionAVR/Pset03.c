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
