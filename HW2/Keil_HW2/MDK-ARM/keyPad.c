#include "keyPad.h"

unsigned char keys[12] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '0', '#'};


void toggle_led(keypad_struct* ledd){												// TOGGLING LED 
	HAL_GPIO_TogglePin(ledd->led_port, ledd->led_pin);
}

void set_led(keypad_struct* ledd){													// SETTING LED TO ON		
	HAL_GPIO_WritePin(ledd->led_port, ledd->led_pin, 1);	
}

void reset_led(keypad_struct* ledd){												// RESETTING LED TO OFF	
	HAL_GPIO_WritePin(ledd->led_port, ledd->led_pin, 0);			
}


unsigned char keypad_scan(){																// keypad_scan() FUNCTION CHECKS THE PRESSED KEYPAD		
	int position = 0x7;																				// position IS FIRST SET TO 0111 BINARY
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);									// PIN B13 IS SET
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 1);									// PIN B11 IS SET
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, 1);									// PIN E15 IS SET
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, 1);									// PIN E13 IS SET
	for(int i = 0; i < 4; i++){																// A FOR LOOP FOR SHIFTING position
		if((position & 0x8) == 0){															// CHECKING IF postion IS 0111 OR NOT	FOR FIRST ROW				
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);							// RESETTING THE PINT B13 					
			
			if(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_11))){					// CHECKING FIRST COLUMN						
				while(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_11)));											
				return keys[0];																			// RETURNS 1 IF PRESSED						
			}							
			if(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_9))){						// CHECKING SECOND COLUMN								
				while(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_9)));										
				return keys[1];																			// RETURNS 2 IF PRESSED								
			}
			if(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_7))){						// CHECKING THIRD COLUMN												
				while(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_7)));																				
				return keys[2];																			// RETURNS 3 IF PRESSED							
			}
			
		}
		if((position & 0x4) == 0){															// CHECKING IF postion IS 1011 OR NOT FOR SECOND ROW																		
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);							// SETTING THE PINT B13														
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 0);							// RESETTING THE PINT B11															
		
			if(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_11))){					// CHECKING FIRST COLUMN																	
				while(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_11)));																					
				return keys[3];																			// RETURNS 4 IF PRESSED												
			}
			if(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_9))){						// CHECKING SECOND COLUMN																	
				while(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_9)));																							
				return keys[4];																			// RETURNS 5 IF PRESSED													
			}
			if(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_7))){						// CHECKING THIRD COLUMN																		
				while(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_7)));																								
				return keys[5];																			// RETURNS 6 IF PRESSED														
			}
		
		}
		if((position & 0x2) == 0){															// CHECKING IF postion IS 1101 OR NOT FOR SECOND ROW											
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 1);							// SETTING THE PINT B11																							
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, 0);							// RESETTING THE PINT E15																											
			
			if(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_11))){					// CHECKING FIRST COLUMN																								
				while(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_11)));																							
				return keys[6];																			// RETURNS 7 IF PRESSED																							
			}
			if(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_9))){						// CHECKING SECOND COLUMN															
				while(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_9)));																			
				return keys[7];																			// RETURNS 8 IF PRESSED										
			}
			if(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_7))){						// CHECKING THIRD COLUMN																		
				while(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_7)));																								
				return keys[8];																			// RETURNS 9 IF PRESSED																					
			}
		
		}
		if((position & 0x1) == 0){															// CHECKING IF postion IS 1110 OR NOT FOR FORTH ROW						
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, 1);							// SETTING THE PINT E15																
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, 0);							// RESETTING THE PINT E13																	
			
			if(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_11))){					// CHECKING FIRST COLUMN																	
				while(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_11)));																							
				return keys[9];																			// RETURNS * IF PRESSED								
			}		
			if(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_9))){						// CHECKING SECOND COLUMN											
				while(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_9)));															
				return keys[10];																		// RETURNS 0 IF PRESSED										
			}
			if(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_7))){						// CHECKING THIRD COLUMN											
				while(!(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_7)));																		
				return keys[11];																		// RETURNS # IF PRESSED											
			}
		}
		
	  position = (position >> 1) | (position << (4 - 1));			// CIRCULAR RIGHT SHIFTING THE position														
    position = (position & 0xf);														// DELETING THE CARRY BIT										
			
	}
}

