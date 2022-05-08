

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __gpio_H
#define __gpio_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"

/* Defines -------------------------------------------------------------------*/
#define SENS_CLK_Pin GPIO_PIN_8
#define SENS_CLK_GPIO_Port GPIOB
#define SENS_DIO_Pin GPIO_PIN_9
#define SENS_DIO_GPIO_Port GPIOB
#define op1_Pin GPIO_PIN_3
#define op1_GPIO_Port GPIOI
#define op2_Pin GPIO_PIN_6
#define op2_GPIO_Port GPIOH
#define op3_Pin GPIO_PIN_8
#define op3_GPIO_Port GPIOA


/* Prototypes ------------------------------------------------------------------*/
void MX_GPIO_Init(void);




#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */
