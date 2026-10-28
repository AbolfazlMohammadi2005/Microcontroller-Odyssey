#include <io.h>
#include <delay.h>

#define CHAR_H  0x76
#define CHAR_E  0x79
#define CHAR_L  0x38
#define CHAR_P  0x73

enum s {
    ST_H,
    ST_E,
    ST_L,
    ST_P,
    ST_BLANK
} state = ST_H;

void main(void)
{
    DDRD = 0xff;

    while (1)
    {
        switch (state)
        {
            case ST_H:     PORTD = CHAR_H; delay_ms(600); state = ST_E;     break;
            case ST_E:     PORTD = CHAR_E; delay_ms(600); state = ST_L;     break;
            case ST_L:     PORTD = CHAR_L; delay_ms(600); state = ST_P;     break;
            case ST_P:     PORTD = CHAR_P; delay_ms(600); state = ST_BLANK; break;
            case ST_BLANK: PORTD = 0x00;   delay_ms(900); state = ST_H;     break;
        }
    }
}
