#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "STD_TYPES.h"

/* Ports */
#define GPTO_PORTB 0
#define GPTO_PORTC 1
#define GPTO_PORTD 2

/* Values */
#define GPIO_HIGH 1
#define GPIO_LOW  0

/* Directions */
#define GPIO_INPUT  0
#define GPIO_OUTPUT 1

#define GPIO_OUTPUT_ALL 0xFF

/* APIs */
void GPIO_SetPinDirection(u8 port, u8 pin, u8 direction);
void GPIO_SetPinValue(u8 port, u8 pin, u8 value);
u8   GPIO_GetPinValue(u8 port, u8 pin);

void GPIO_SetPortDirection(u8 port, u8 direction);
void GPIO_SetPortValue(u8 port, u8 value);

#endif