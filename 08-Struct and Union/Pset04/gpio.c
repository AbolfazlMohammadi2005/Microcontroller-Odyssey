#include "gpio.h"

void gpio_apply(GPIO_CFG *cfg)
{
    DDRA = cfg->a.ddr;
    DDRB = cfg->b.ddr;
    DDRC = cfg->c.ddr;
    DDRD = cfg->d.ddr;

    PORTA = cfg->a.port;
    PORTB = cfg->b.port;
    PORTC = cfg->c.port;
    PORTD = cfg->d.port;
}
