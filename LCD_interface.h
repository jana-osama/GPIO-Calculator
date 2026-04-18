#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include "STD_TYPES.h"

#define LCD_RS 0
#define LCD_EN 1

void LCD_Init(void);
void LCD_Command(u8 cmd);
void LCD_Char(u8 data);
void LCD_String(u8 *str);
void LCD_Clear(void);

#endif