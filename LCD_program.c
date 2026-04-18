#include "LCD_interface.h"
#include "GPIO_interface.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include <avr/io.h>

static void LCD_EnablePulse(void)
{
    GPIO_SetPinValue(GPTO_PORTC, LCD_EN, GPIO_HIGH);
    _delay_ms(2);
    GPIO_SetPinValue(GPTO_PORTC, LCD_EN, GPIO_LOW);
    _delay_ms(2);
}

void LCD_Command(u8 cmd)
{
    GPIO_SetPinValue(GPTO_PORTC, LCD_RS, GPIO_LOW);
    GPIO_SetPortValue(GPTO_PORTB, cmd);
    LCD_EnablePulse();
}

void LCD_Char(u8 data)
{
    GPIO_SetPinValue(GPTO_PORTC, LCD_RS, GPIO_HIGH);
    GPIO_SetPortValue(GPTO_PORTB, data);
    LCD_EnablePulse();
}

void LCD_Init(void)
{
    GPIO_SetPortDirection(GPTO_PORTB, GPIO_OUTPUT_ALL);
    GPIO_SetPinDirection(GPTO_PORTC, LCD_RS, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPTO_PORTC, LCD_EN, GPIO_OUTPUT);

    _delay_ms(20);

    LCD_Command(0x38);
    LCD_Command(0x0C);
    LCD_Command(0x06);
    LCD_Command(0x01);
}

void LCD_String(u8 *str)
{
    while(*str)
    {
        LCD_Char(*str++);
    }
}

void LCD_Clear(void)
{
    LCD_Command(0x01);
    _delay_ms(2);
}