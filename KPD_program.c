#include "KPD_interface.h"
#include "GPIO_interface.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include <avr/io.h>

static char keys[4][4] = {
    {'1','2','3','/'},
    {'4','5','6','*'},
    {'7','8','9','-'},
    {'#','0','=','+'}
};


void KPD_Init(void)
{
    
    GPIO_SetPortDirection(GPTO_PORTD, 0x0F); 
    GPIO_SetPortValue(GPTO_PORTD, 0xFF);     
}


char KPD_GetKey(void)
{
    u8 row, col;

    for(row = 0; row < 4; row++)
    {
       
        GPIO_SetPortValue(GPTO_PORTD, 0x0F);
        CLR_BIT(PORTD, row); 

        for(col = 4; col < 8; col++)
        {
            
            if(GET_BIT(PIND, col) == 0)
            {
                _delay_ms(30);
                while(GET_BIT(PIND, col) == 0);
                return keys[row][col - 4];
            }
        }
    }
    return 0;
}