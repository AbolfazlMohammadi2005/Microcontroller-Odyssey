#include <io.h>
#include <delay.h>

enum d {
    MOVE_LEFT,
    MOVE_RIGHT
} state = MOVE_LEFT;

unsigned char a = 0x01;

void main(void)
{
    DDRA = 0xff;

    while (1)
    {
        PORTA = a;
        delay_ms(150);

        switch (state)
        {
            case MOVE_LEFT:
                a <<= 1;
                if (a == 0x80)
                    state = MOVE_RIGHT;
                break;

            case MOVE_RIGHT:
                a >>= 1;
                if (a == 0x01)
                    state = MOVE_LEFT;
                break;
        }
    }
}
