/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f7xx_hal.h"
#include "rtc.h"
#include "gpio.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void Error_Handler(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */
void reset();
void startTransmit();
void writeData(uint8_t data);
void readData(uint8_t* pBuf, int size);
void writeCmd(uint8_t cmd);
void delay();
int getTemp(uint8_t MSB, uint8_t LSB);
int getHumi(uint8_t MSB, uint8_t LSB);

#define dioR HAL_GPIO_ReadPin(SENS_DIO_GPIO_Port, SENS_DIO_Pin)
#define dio1 HAL_GPIO_WritePin(SENS_DIO_GPIO_Port, SENS_DIO_Pin, 1);
#define dio0 HAL_GPIO_WritePin(SENS_DIO_GPIO_Port, SENS_DIO_Pin, 0);
#define clk1 HAL_GPIO_WritePin(SENS_CLK_GPIO_Port, SENS_CLK_Pin, 1);
#define clk0 HAL_GPIO_WritePin(SENS_CLK_GPIO_Port, SENS_CLK_Pin, 0);

void reset() 
{
	for(int i=0; i<11; i++) {
		clk1
		delay(100);
		clk0
		delay(100);
	}
	delay(200);
}

void startTransmit() 
{
	dio1
	delay(100);
	clk1
	delay(100);
	dio0
	delay(100);
	clk0
	delay(100);
	clk1
	delay(100);
	dio1
	delay(100);
	clk0
	delay(100);
}

void writeData(uint8_t data) 
{
	uint8_t mask = (1 << 7);
	uint8_t d = 0x00;
	for(int i=7; i>=0; i--) 
	{
		d = (data & mask) >> i;
		mask >>= 1;
		
		HAL_GPIO_WritePin(SENS_DIO_GPIO_Port, SENS_DIO_Pin, d);
		delay(100);
		clk1
		delay(100);
		clk0
		delay(100);
	}
	dio1
	delay(100);
	clk1
	delay(100);
	clk0;
	delay(100);
}

void readData(uint8_t* pBuf, int size) 
{
	// Clean buffer
	for(int i=0; i<size; i++) {
		pBuf[i] = 0;
	}
	
	for(int i=0; i<size; i++) {
		delay(100);
		for(int j=7; j>=0; j--) {
			clk1
			delay(100);
			pBuf[i] |= (dioR << j);
			clk0
			delay(100);
		}
		if(i == size - 1) 
		{
			dio1
		}
		else
		{
			dio0
		}
		delay(100);
		clk1
		delay(100);
		clk0
		delay(100);
		dio1
		delay(100);
	}
	dio1
}

void writeCmd(uint8_t cmd)
{
	startTransmit();
	writeData(cmd);
}

void delay(uint32_t delay) 
{
	volatile int i = 0;
	while(i < delay) {
		i++;
	}
}

int getTemp(uint8_t MSB, uint8_t LSB)
{
	float v = (float)(((MSB & 0x3F) << 8) | LSB);
	float temp = 0.01f*v - 39.6f;
	return (int) nearbyint(temp);
}	

int getHumi(uint8_t MSB, uint8_t LSB)
{
	float v = (float)(((MSB & 0x0F) << 8) | LSB);
	float humi = 0.0367f*v -1.5955E-6f*v*v - 2.0468f;
	return (int) nearbyint(humi);
}

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_RTC_Init();

  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	uint8_t buf[3];
	volatile int t = 0;
	volatile int h = 0;
	reset();
	while (1)
	{
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
		writeCmd(0x03);
		HAL_Delay(1000);
		readData(buf, 2);
		t = getTemp(buf[0], buf[1]);
		writeCmd(0x05);
		HAL_Delay(1000);
		readData(buf, 2);
		h = getHumi(buf[0], buf[1]);
	}
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 400;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

    /**Activate the Over-Drive mode 
    */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_6) != HAL_OK)
  {
    Error_Handler();
  }

  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_HSE_DIV25;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
