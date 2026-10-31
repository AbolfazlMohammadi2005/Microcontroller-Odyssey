#ifndef _GPIO_H
#define _GPIO_H

#include <io.h>

#define GPIO_SETPIN(port, pin)     port |= (1 << (pin))
#define GPIO_CLEARPIN(port, pin)   port &= ~(1 << (pin))
#define GPIO_TOGGLEPIN(port, pin)  port ^= (1 << (pin))
#define GPIO_READPIN(pinreg, pin)  (((pinreg) >> (pin)) & 1)

#define OUTPUT   0xff
#define INPUT    0x00

typedef struct {
    unsigned char ddr;
    unsigned char port;
} PORT_CFG;

typedef struct {
    PORT_CFG a;
    PORT_CFG b;
    PORT_CFG c;
    PORT_CFG d;
} GPIO_CFG;

void gpio_apply(GPIO_CFG *cfg);

#endif
