/*
 * How to run this program:
 *   1. Open it in CodeVisionAVR, create a project for ATmega32 @ 8 MHz and build it.
 *   2. Take the generated .hex file and load it into Proteus.
 *   3. Run the simulation in Proteus.
 */

#include <io.h>
#include <delay.h>

typedef struct {
    unsigned char PA_DIR;
    unsigned char PB_DIR;
    unsigned char PC_DIR;
    unsigned char PD_DIR;
    
    unsigned char PA_VAL;
    unsigned char PB_VAL;
    unsigned char PC_VAL;
    unsigned char PD_VAL;
} GPIO_INIT;

void GPIO_INIT_PORT(GPIO_INIT *port)
{
    DDRA = port->PA_DIR;
    DDRB = port->PB_DIR;
    DDRC = port->PC_DIR;
    DDRD = port->PD_DIR;
    
    PORTA = port->PA_VAL;
    PORTB = port->PB_VAL;
    PORTC = port->PC_VAL;
    PORTD = port->PD_VAL;
}

#define GPIO_WRITEPIN(port, pin, val)  port = (val << pin)

#define OUTPUT     0xff
#define INPUT      0x00

#define SET_ALL    0xff
#define RESET_ALL  0x00

void main(void)
{
    GPIO_INIT GPIO;
    
    GPIO.PA_DIR = OUTPUT;
    GPIO.PA_VAL = RESET_ALL;
    
    GPIO.PB_DIR = OUTPUT;
    GPIO.PB_VAL = RESET_ALL;
    
    GPIO.PC_DIR = OUTPUT;
    GPIO.PC_VAL = RESET_ALL;
    
    GPIO.PD_DIR = OUTPUT;
    GPIO.PD_VAL = RESET_ALL;
    
    GPIO_INIT_PORT(&GPIO);
    
    while (1)
    {
        GPIO_WRITEPIN(PORTA, 0, 0x0f);
        delay_ms(500);
        GPIO_WRITEPIN(PORTA, 0, 0xf0);
        delay_ms(500);
        GPIO_WRITEPIN(PORTA, 0, 0x00);
        
        GPIO_WRITEPIN(PORTB, 0, 0x0f);
        delay_ms(500);
        GPIO_WRITEPIN(PORTB, 0, 0xf0);
        delay_ms(500);
        GPIO_WRITEPIN(PORTB, 0, 0x00);
        
        GPIO_WRITEPIN(PORTC, 0, 0x0f);
        delay_ms(500);
        GPIO_WRITEPIN(PORTC, 0, 0xf0);
        delay_ms(500);
        GPIO_WRITEPIN(PORTC, 0, 0x00);
        
        GPIO_WRITEPIN(PORTD, 0, 0x0f);
        delay_ms(500);
        GPIO_WRITEPIN(PORTD, 0, 0xf0);
        delay_ms(500);
        GPIO_WRITEPIN(PORTD, 0, 0x00);
    }
}
