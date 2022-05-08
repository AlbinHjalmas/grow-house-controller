
/* Includes ------------------------------------------------------------------*/
#include "rtc.h"

RTC_HandleTypeDef hrtc;

/* RTC init function */
void MX_RTC_Init(void)
{
	RTC_TimeTypeDef sTime;
	RTC_DateTypeDef sDate;

	/* Initialize RTC Only */
	hrtc.Instance = RTC;
	hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
	hrtc.Init.AsynchPrediv = 124;
	hrtc.Init.SynchPrediv = 7999;
	hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
	hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
	hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
	if (HAL_RTC_Init(&hrtc) != HAL_OK)
	{
		while(1);
	}

    /* Initialize RTC and set the Time and Date */
	sTime.Hours = 0x21;
	sTime.Minutes = 0x15;
	sTime.Seconds = 0x12;
	sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sTime.StoreOperation = RTC_STOREOPERATION_RESET;
	if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK)
	{
		while(1);
	}

	sDate.WeekDay = RTC_WEEKDAY_THURSDAY;
	sDate.Month = RTC_MONTH_AUGUST;
	sDate.Date = 0x31;
	sDate.Year = 0x17;

	if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BCD) != HAL_OK)
	{
		while(1);
	}

}

void HAL_RTC_MspInit(RTC_HandleTypeDef* rtcHandle)
{
	if(rtcHandle->Instance==RTC)
	{
		__HAL_RCC_RTC_ENABLE();
	}
}

void HAL_RTC_MspDeInit(RTC_HandleTypeDef* rtcHandle)
{

  if(rtcHandle->Instance==RTC)
  {
  /* USER CODE BEGIN RTC_MspDeInit 0 */

  /* USER CODE END RTC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_RTC_DISABLE();
  }
  /* USER CODE BEGIN RTC_MspDeInit 1 */

  /* USER CODE END RTC_MspDeInit 1 */
} 

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
