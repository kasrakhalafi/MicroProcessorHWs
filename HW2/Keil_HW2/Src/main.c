/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "keyPad.h"
#include "lm016.h"


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */




/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */



/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
keypad_struct led;
	led.led_pin = GPIO_PIN_15;
	led.led_port = GPIOD;
/*lcd_t lcd;
	   
	lcd.data_ports[4] = LCD_D4_PORT;
	lcd.data_pins[4] = LCD_D4_PIN;
	   
	lcd.data_ports[5] = LCD_D5_PORT;
	lcd.data_pins[5] = LCD_D5_PIN;
	   
	lcd.data_ports[6] = LCD_D6_PORT;
	lcd.data_pins[6] = LCD_D6_PIN;
	   
	lcd.data_ports[7] = LCD_D7_PORT;
	lcd.data_pins[7] = LCD_D7_PIN;
	   
	lcd.en_port = LCD_E_PORT;
	lcd.en_pin = LCD_E_PIN;
	   
	lcd.rs_port = LCD_RS_PORT;
	lcd.rs_pin = LCD_RS_PIN;
	lcd.mode = BIT_4;
lcd_init(&lcd);
lcd_puts(&lcd ,"biiii adab" , 11);*/





  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

lcd_init();

unsigned char check = '7';
unsigned char t_open;
unsigned char press = '7';

check = keypad_scan();
	

uint_fast32_t tick = HAL_GetTickFreq();
	

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
 while (1)
  {
    /* USER CODE END WHILE */
		press = '7';																					// CLEANING FILLED DATA ON press
		check = '7';																					// CLEANING FILLED DATA ON check

		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) == 1){ 				// CHECKING FOR DRY SITUATION
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, 1); 					// TURNING ON AN LED FOR ALARM
			lcd_clr();																					// CLEARING LCD
			lcd_gotoxy(0,0);																		// CURSER GOES TO FIRST LINE
			lcd_puts("ALERT, DRY SOIL");												// PRINTING ALART ON LCD
			lcd_gotoxy(0,1);																		// CURSER GOES TO SECOND LINE
			lcd_puts("ENABLE: PRESS *");												// TELLING USER TO PRESS * TO CHOOSE TIME OF WATERING
			
			while(check != '*'){																// WAITS FOR USER TO PRESS *
				check = keypad_scan();
			};
			
			lcd_clr();																					// CLEARING LCD
			lcd_gotoxy(0, 0);																		// CURSER GOES TO FIRST LINE
			lcd_puts("Choose Time From");												// PRINT ON LCD TO CHOOSE TIME
			lcd_gotoxy(0, 1);																		// CURSER GOES TO SECOND LINE
			lcd_puts("{1,2,3}Min:");														// PRINTING AVAILABLE DURATIONS

			while(1){																						// WAITS FOR USER TO ENTER ONE OF THE WRITTEN DURATIONS
				press = keypad_scan();														// FILLING THE INPUT FROM KEYPAD IN press 
				if((press == '1')|(press == '2')|(press == '3')){ // CHECKING FOR ENTERED DURATION
					t_open = press;																	// SAVING ENTERED DURATION IN t_open
					press = '7';																		// CLEARING FILLED DATA ON press
					break;																	
				}
			};

			
			if(t_open == '1'){																	// ENTERS THE IF CONDITION IF DURATION IS 1 MIN
				lcd_clr();																				// CLEARING LCD								
				lcd_gotoxy(0, 0);																	// CURSER GOES TO FIRST LINE
				lcd_puts("Moisture: Dry");												// PRINTING MOISTURE CONDITION
				lcd_gotoxy(0, 1);																	// CURSER GOES TO SECOND LINE
				lcd_puts("Open Time: 1 Min");											// PRINTING DURATION OF OPEN TIME
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);					// OPENING THE VALVE
				HAL_Delay(1 * 60000);															// WAITING TILL 1 MIN 
			}
			
			if(t_open == '2'){																	// ENTERS THE IF CONDITION IF DURATION IS 2 MIN
				lcd_clr();																				// CLEARING LCD
				lcd_gotoxy(0, 0);																	// CURSER GOES TO FIRST LINE		
				lcd_puts("Moisture: Dry");												// PRINTING MOISTURE CONDITION
				lcd_gotoxy(0, 1);																	// CURSER GOES TO SECOND LINE
				lcd_puts("Open Time: 2 Min");											// PRINTING DURATION OF OPEN TIME
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);					// OPENING THE VALVE	
				HAL_Delay(2 * 60000);															// WAITING TILL 2 MIN
			}
			
			if(t_open == '3'){																	// ENTERS THE IF CONDITION IF DURATION IS 3 MIN	
				lcd_clr();																				// CLEARING LCD		
				lcd_gotoxy(0, 0);																	// CURSER GOES TO FIRST LINE	
				lcd_puts("Moisture: Dry");												// PRINTING MOISTURE CONDITION			
				lcd_gotoxy(0, 1);																	// CURSER GOES TO SECOND LINE			
				lcd_puts("Open Time: 3 Min");											// PRINTING DURATION OF OPEN TIME					
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);					// OPENING THE VALVE						
				HAL_Delay(3 * 60000);															// WAITING TILL 3 MIN							
			}
			
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);																	
						
			lcd_clr();																															
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, 0);																	
				
		}
		
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) == 0){ // CHECKING FOR WET SITUATION
				lcd_clr();																														
				lcd_gotoxy(0, 0);																													
				lcd_puts("Moisture: WET");																											
				lcd_gotoxy(0, 1);																															
				lcd_puts("Open Time: NONE! ");																							
				HAL_Delay(5000);																																									
		}
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
