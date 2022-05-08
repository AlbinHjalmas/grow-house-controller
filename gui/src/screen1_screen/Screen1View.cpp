#include <gui/screen1_screen/Screen1View.hpp>
#include "stm32746g_discovery_lcd.h"
#include "stm32f7xx_hal_gpio.h"

Screen1View::Screen1View()
{
	
}

void clickAction()
{
	
}

void Screen1View::setupScreen()
{
	
}

void Screen1View::tearDownScreen()
{

}

void Screen1View::homeBtnClicked()
{
	HAL_GPIO_WritePin(LCD_BL_CTRL_GPIO_PORT, LCD_BL_CTRL_PIN, (GPIO_PinState) 1);
}
