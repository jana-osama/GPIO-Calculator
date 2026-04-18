#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdio.h>
#include "STD_TYPES.h"
#include "LCD_interface.h"
#include "KPD_interface.h"

int main(void)
{
   
    LCD_Init();
    KPD_Init();

    s32 n1 = 0, n2 = 0, res = 0;
    char op = 0, key;
    char buffer[16];

    while(1)
    {
        key = KPD_GetKey(); 

        if(key != 0) 
        {
            
            if(key >= '0' && key <= '9')
            {
                LCD_Char(key);
                if(op == 0) n1 = n1 * 10 + (key - '0');
                else n2 = n2 * 10 + (key - '0');
            }

            
            else if(key == '+' || key == '-' || key == '*' || key == '/')
            {
                op = key;
                LCD_Char(key);
            }

            
            else if(key == '=')
            {
                LCD_Clear();

                switch(op)
                {
                    case '+': res = n1 + n2; break;
                    case '-': res = n1 - n2; break;
                    case '*': res = n1 * n2; break;
                    case '/':
                        if(n2 == 0)
                        {
                            LCD_String((u8*)"Error");
                            n1 = n2 = op = 0;
                            _delay_ms(1000);
                            LCD_Clear();
                            continue;
                        }
                        res = n1 / n2;
                        break;
                }

                
                sprintf(buffer, "%ld", (long)res);
                LCD_String((u8*)buffer);

             
                n1 = n2 = res = 0;
                op = 0;
                _delay_ms(2000);
                LCD_Clear();
            }
           
            else if(key == 'C')
            {
                n1 = n2 = res = 0;
                op = 0;
                LCD_Clear();
            }
        }
    }
}