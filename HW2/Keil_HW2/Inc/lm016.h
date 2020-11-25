#ifndef __LM016__H
#define __LM016__H

#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"
#include "string.h"
#include "stdio.h"

#define LCD_RS_PORT    GPIOC										// DEFINING THE PORT AND PINS 		
#define LCD_RS_PIN     GPIO_PIN_0

#define LCD_E_PORT     GPIOC
#define LCD_E_PIN  		 GPIO_PIN_1

#define LCD_D4_PORT 	 GPIOC
#define LCD_D4_PIN 		 GPIO_PIN_4

#define LCD_D5_PORT 	 GPIOC
#define LCD_D5_PIN 		 GPIO_PIN_5

#define LCD_D6_PORT 	 GPIOC
#define LCD_D6_PIN 		 GPIO_PIN_6

#define LCD_D7_PORT 	 GPIOC
#define LCD_D7_PIN 		 GPIO_PIN_7


#define rs(x)      x?HAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_SET):HAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET)  // IF x IS 1 THEN RS PIN IS SET ELSE IS RESET
#define en(x)      x?HAL_GPIO_WritePin(LCD_E_PORT, LCD_E_PIN, GPIO_PIN_SET):HAL_GPIO_WritePin(LCD_E_PORT, LCD_E_PIN, GPIO_PIN_RESET)			// IF x IS 1 THEN ENABLE PIN IS SET ELSE IS RESET

#define d4(x)      x?HAL_GPIO_WritePin(LCD_D4_PORT, LCD_D4_PIN, GPIO_PIN_SET):HAL_GPIO_WritePin(LCD_D4_PORT, LCD_D4_PIN, GPIO_PIN_RESET)	// IF x IS 1 THEN D4 PIN IS SET ELSE IS RESET
#define d5(x)      x?HAL_GPIO_WritePin(LCD_D5_PORT, LCD_D5_PIN, GPIO_PIN_SET):HAL_GPIO_WritePin(LCD_D5_PORT, LCD_D5_PIN, GPIO_PIN_RESET)	// IF x IS 1 THEN D5 PIN IS SET ELSE IS RESET
#define d6(x)      x?HAL_GPIO_WritePin(LCD_D6_PORT, LCD_D6_PIN, GPIO_PIN_SET):HAL_GPIO_WritePin(LCD_D6_PORT, LCD_D6_PIN, GPIO_PIN_RESET)	// IF x IS 1 THEN D6 PIN IS SET ELSE IS RESET
#define d7(x)      x?HAL_GPIO_WritePin(LCD_D7_PORT, LCD_D7_PIN, GPIO_PIN_SET):HAL_GPIO_WritePin(LCD_D7_PORT, LCD_D7_PIN, GPIO_PIN_RESET)	// IF x IS 1 THEN D7 PIN IS SET ELSE IS RESET


static void lcd_send_4bit(uint8_t data);				// SENDING 4 BIT OF DATA
static void lcd_send(int8_t rs,uint8_t data);		// SENDIGN ALL DATA USING lcd_send_4bit() FUNCTION
static void delay_us(uint32_t delay);						// DELAY TO us									
void lcd_data(char c);													// GETS THE CHARACTERS AND PASS IT TO THE lcd_send() FUNCTION
void lcd_init(void);														// INITIALIZING THE LCD
void lcd_clr(void);															// CLEARING LCD
void lcd_gotoxy(char x, char y);								// SETTING CURSER POSITION
void lcd_puts(char *text);											// PRINTING GIVEN TEXT IN THE FUNCTION ON LCD


#endif