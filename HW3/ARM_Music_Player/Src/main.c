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
#include "dac.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
int sinewave[100] = {2048,2176,2304,2431,2557,2680,2801,2919,3034,3145,3251,3353,3449,3540,3625,3704,3776,3842,3900,3951,
	3995,4031,4059,4079,4091,4095,4091,4079,4059,4031,3995,3951,3900,3842,3776,3704,3625,3540,3449,3353,3251,3145,3034,2919,
	2801,2680,2557,2431,2304,2176,2048,1919,1791,1664,1538,1415,1294,1176,1061,950,844,742,646,555,470,391,319,253,195,144,
	100,64,36,16,4,0,4,16,36,64,100,144,195,253,319,391,470,555,646,742,844,950,1061,1176,1294,1415,1538,1664,1791,1919};
int A4 =440, C4 = 262, D4 = 294, E4 = 330, F4 = 349, G4 = 277;
int Q_Duration = 500;
int H_Duration = 1000; 
int i = 0;
int state = 1;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void play_note(int note_freq, int note_duration)
{
	if(note_freq == 440)
	{
		htim3.Instance ->CCR1 = 1909;
		__HAL_RCC_GPIOA_CLK_ENABLE();
		htim2.Init.Period = note_duration * 2;
		HAL_TIM_Base_Init(&htim2);
		HAL_TIM_Base_Start_IT(&htim2);
		HAL_TIM_OC_Start_IT(&htim3, TIM_CHANNEL_1);
		while(state)
		{
			
		}
		state = 1;
	}
	else if(note_freq == 262)
	{
		htim3.Instance ->CCR1 = 3200;
		__HAL_RCC_GPIOA_CLK_ENABLE();
		htim2.Init.Period = note_duration * 2;
		HAL_TIM_Base_Init(&htim2);
		HAL_TIM_Base_Start_IT(&htim2);
		HAL_TIM_OC_Start_IT(&htim3, TIM_CHANNEL_1);
		while(state)
		{
			
		}
		state = 1;
	}
	else if(note_freq == 294)
	{
		htim3.Instance ->CCR1 = 2857;
		__HAL_RCC_GPIOA_CLK_ENABLE();
		htim2.Init.Period = note_duration * 2;
		HAL_TIM_Base_Init(&htim2);
		HAL_TIM_Base_Start_IT(&htim2);
		HAL_TIM_OC_Start_IT(&htim3, TIM_CHANNEL_1);
				while(state)
		{
			
		}
		state = 1;
	}
	else if(note_freq == 330)
	{
		htim3.Instance ->CCR1 = 2545;
		__HAL_RCC_GPIOA_CLK_ENABLE();
		htim2.Init.Period = note_duration * 2;
		HAL_TIM_Base_Init(&htim2);
		HAL_TIM_Base_Start_IT(&htim2);
		HAL_TIM_OC_Start_IT(&htim3, TIM_CHANNEL_1);
		while(state)
		{
			
		}
		state = 1;
	}
	else if(note_freq == 349)
	{
		htim3.Instance ->CCR1 = 2407;
		__HAL_RCC_GPIOA_CLK_ENABLE();
		htim2.Init.Period = note_duration * 2;
		HAL_TIM_Base_Init(&htim2);
		HAL_TIM_Base_Start_IT(&htim2);
		HAL_TIM_OC_Start_IT(&htim3, TIM_CHANNEL_1);
		while(state)
		{
			
		}
		state = 1;
	}
	else if(note_freq == 277)
	{
		htim3.Instance ->CCR1 = 3032;
		__HAL_RCC_GPIOA_CLK_ENABLE();
		htim2.Init.Period = note_duration * 2;
		HAL_TIM_Base_Init(&htim2);
				HAL_TIM_Base_Start_IT(&htim2);
		HAL_TIM_OC_Start_IT(&htim3, TIM_CHANNEL_1);
		while(state)
		{
			
		}
		state = 1;
	}
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim ->Instance == TIM2)
	{
		state = 0;
	}
}
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
{
	__HAL_TIM_SetCounter(&htim3, 0);
	HAL_DAC_SetValue(&hdac, DAC1_CHANNEL_1, DAC_ALIGN_12B_R, sinewave[i]);
	i++;
	if(i >= 99)
	{
		i = 0;
	}
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

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
  MX_DAC_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
	HAL_DAC_Start(&hdac, DAC1_CHANNEL_1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
		play_note(C4, Q_Duration);
		play_note(C4, Q_Duration);
		play_note(G4, Q_Duration);
		play_note(G4, Q_Duration);
		play_note(A4, Q_Duration);
		play_note(A4, Q_Duration);
		play_note(G4, H_Duration);
		play_note(F4, Q_Duration);
		play_note(C4, Q_Duration);
		play_note(C4, Q_Duration);
		play_note(G4, Q_Duration);
		play_note(G4, Q_Duration);
		play_note(A4, Q_Duration);
		play_note(A4, Q_Duration);
		play_note(G4, H_Duration);
		play_note(F4, Q_Duration);
		play_note(C4, Q_Duration);
		play_note(C4, Q_Duration);
		play_note(G4, Q_Duration);
		play_note(G4, Q_Duration);
		play_note(A4, Q_Duration);
		play_note(A4, Q_Duration);
		play_note(G4, H_Duration);
		play_note(F4, Q_Duration);
		play_note(C4, Q_Duration);
		play_note(C4, Q_Duration);
		play_note(G4, Q_Duration);
		play_note(G4, Q_Duration);
		play_note(A4, Q_Duration);
		play_note(A4, Q_Duration);
		play_note(G4, H_Duration);
		play_note(F4, Q_Duration);
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
  RCC_OscInitStruct.PLL.PLLM = 25;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
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
