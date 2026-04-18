#include "GPIO_interface.h"
#include <avr/io.h>
#include "BIT_MATH.h"

/* Direction */
void GPIO_SetPinDirection(u8 port, u8 pin, u8 direction)
{
    switch(port)
    {
        case GPTO_PORTB:
            if(direction) SET_BIT(DDRB, pin);
            else CLR_BIT(DDRB, pin);
            break;

        case GPTO_PORTC:
            if(direction) SET_BIT(DDRC, pin);
            else CLR_BIT(DDRC, pin);
            break;

        case GPTO_PORTD:
            if(direction) SET_BIT(DDRD, pin);
            else CLR_BIT(DDRD, pin);
            break;
    }
}

/* Value */
void GPIO_SetPinValue(u8 port, u8 pin, u8 value)
{
    switch(port)
    {
        case GPTO_PORTB:
            if(value) SET_BIT(PORTB, pin);
            else CLR_BIT(PORTB, pin);
            break;

        case GPTO_PORTC:
            if(value) SET_BIT(PORTC, pin);
            else CLR_BIT(PORTC, pin);
            break;

        case GPTO_PORTD:
            if(value) SET_BIT(PORTD, pin);
            else CLR_BIT(PORTD, pin);
            break;
    }
}

/* Get */
u8 GPIO_GetPinValue(u8 port, u8 pin)
{
    switch(port)
    {
        case GPTO_PORTB: return GET_BIT(PINB, pin);
        case GPTO_PORTC: return GET_BIT(PINC, pin);
        case GPTO_PORTD: return GET_BIT(PIND, pin);
    }
    return 0;
}

/* Port direction */
void GPIO_SetPortDirection(u8 port, u8 direction)
{
    switch(port)
    {
        case GPTO_PORTB: DDRB = direction; break;
        case GPTO_PORTC: DDRC = direction; break;
        case GPTO_PORTD: DDRD = direction; break;
    }
}

/* Port value */
void GPIO_SetPortValue(u8 port, u8 value)
{
    switch(port)
    {
        case GPTO_PORTB: PORTB = value; break;
        case GPTO_PORTC: PORTC = value; break;
        case GPTO_PORTD: PORTD = value; break;
    }
}