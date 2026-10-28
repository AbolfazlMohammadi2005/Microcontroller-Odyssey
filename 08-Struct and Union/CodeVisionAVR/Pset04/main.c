#include <io.h>
#include <delay.h>
#include "gpio.h"

GPIO_CFG cfg;

void main(void)
{
    cfg.a.ddr = OUTPUT;  cfg.a.port = 0x00;
    cfg.b.ddr = OUTPUT;  cfg.b.port = 0x00;
    cfg.c.ddr = OUTPUT;  cfg.c.port = 0xFF;
    cfg.d.ddr = OUTPUT;  cfg.d.port = 0x00;

    gpio_apply(&cfg);

    while (1)
    {
        GPIO_SETPIN(PORTA, 0);
        GPIO_SETPIN(PORTB, 7);
        GPIO_CLEARPIN(PORTC, 0);
        delay_ms(500);

        GPIO_CLEARPIN(PORTA, 0);
        GPIO_CLEARPIN(PORTB, 7);
        GPIO_SETPIN(PORTC, 0);
        delay_ms(500);

        GPIO_TOGGLEPIN(PORTD, 4);
    }
}
