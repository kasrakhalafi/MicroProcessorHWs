#include "lm016.h"


static void delay_us(uint32_t delay){							// DELAY FUNCTION
	delay*=32;
	while(delay--);
}

static void lcd_send_4bit(uint8_t data){					// SENDING 4 BIT DATA
	
	if(data & 0x10) d4(1); else d4(0);							// SHIFT CURSER POSITION TO LEFT
	if(data & 0x20) d5(1); else d5(0);							// CONFIGURE DISPLAY AND INTERFACE
	if(data & 0x40) d6(1); else d6(0);							// SET CHARACTER GENERATOR RAM ADDRESS
	if(data & 0x80) d7(1); else d7(0);							// FORCE CURSER TO BEGIN
	
}

static void lcd_send(int8_t rs,uint8_t data){			// SENDING ALL DATA USING lcd_send_4bit() FUNCTION
	rs(rs);
	lcd_send_4bit(data);														// SENDING 4 BITS BECAUSE 4 PINS ARE USED
	en(1);																					// ENABLING THE ENABLE PIN
	delay_us(100);																	// 100 us DELAY
	en(0);																					// DISABLING THE ENABLE PIN
	lcd_send_4bit(data<<4);													// SHIFTING DATA 4 BIT TO SEND THE REMAINING DATA
	en(1);																					// ENABLING THE ENABLE PIN
	delay_us(100);																	// 100 us DELAY
	en(0);																					// DISABLING THE ENABLE PIN
}



void lcd_data(char c){														// GETS THE CHARACTERS AND PASS IT TO THE lcd_send() FUNCTION
	lcd_send(1,(uint8_t)c);
}

void lcd_init(void){															// INITIALIZING THE LCD
	lcd_send(0,0x33);																// SEND FOR 4 BIT INITIALIZATION OF LCD
  lcd_send(0,0x32);																// SEND FOR 4 BIT INITIALIZATION OF LCD
  lcd_send(0,0x28);																// 4-BIT MODE - 2 LINE, 5*7 MATRIX																
  lcd_send(0,0x0C);																// DISPLAY ON CURSER OFF
  lcd_send(0,0x06);																// INCREMENT CURESER
  lcd_send(0,0x01);																// CLEAR DISPLAY
	HAL_Delay(2);
}

void lcd_clr(void){																// CLEARING LCD
    lcd_send(0,0x01);
    HAL_Delay(2);
}

void lcd_gotoxy(char x, char y){									// CURSER GOES TO x AND y POSITION ON LCD
    lcd_send(0,0x80+x+(y*0x40));
}

void lcd_puts(char *text){												// SENDIGN DATA TO LCD TO BE PRINTED
    while(*text){																	// READING ALL THE TEXT
        lcd_data(*text);													// SENDING ONE CHARACTER OF TEXT TO lcd_data FUNCTION
        text++;																		// GOING TO NEXT CHARACTER OF THE TEXT
    }
}
