#include "stm32f4xx_hal.h"

typedef struct{
	GPIO_TypeDef* led_port;
	uint16_t led_pin;
}keypad_struct;

void toggle_led(keypad_struct* ledd);		// TOGGLING LED
void set_led(keypad_struct* ledd);			// SETTING LED
void reset_led(keypad_struct* ledd);		// RESETTING LED
unsigned char keypad_scan();						// READING THE PRESSED KEYPAD BUTTON

