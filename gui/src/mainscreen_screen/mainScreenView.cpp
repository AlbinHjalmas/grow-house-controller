#include <gui/mainscreen_screen/mainScreenView.hpp>
#include "stm32746g_discovery_lcd.h"
#include "stm32f7xx_hal_gpio.h"


mainScreenView::mainScreenView()
{
	
}

void mainScreenView::setupScreen()
{
	humidifierOpBtn.forceState(presenter->getHumiOpState());
	lightOpBtn.forceState(presenter->getLightOpState());
	heaterOpBtn.forceState(presenter->getHeatOpState());
	manualOverrideBtn.forceState(presenter->getManualOverrideState());

	if (!manualOverrideBtn.getState()) {
		manualOverrideBtnClicked();
	}

	setDate(presenter->getYear(), presenter->getMonth(), presenter->getDay(), presenter->getHour(), presenter->getMin());
	setTemperature(presenter->getTemperature());
	setHumidity(presenter->getHumidity());
}

void mainScreenView::tearDownScreen()
{

}

void mainScreenView::setTemperature(int temp)
{
	Unicode::snprintf(currTempTxtAreaBuffer, CURRTEMPTXTAREA_SIZE, "%d", temp);
	currTempTxtArea.invalidate();
}

void mainScreenView::setHumidity(int humi)
{
	Unicode::snprintf(currHumiTxtAreaBuffer, CURRHUMITXTAREA_SIZE, "%d", humi);
	currHumiTxtArea.invalidate();
}

void mainScreenView::setDate(int year, int month, int day, int hour, int min)
{
	Unicode::snprintf(dateTxtBuffer, DATETXT_SIZE, "%04d-%02d-%02d %02d:%02d", year, month, day, hour, min);
	dateTxt.invalidate();
}

void mainScreenView::manualOverrideBtnClicked()
{

	if (!manualOverrideBtn.getState()) 
	{
		humidifierOpBtn.setAlpha(70);
		lightOpBtn.setAlpha(70);
		heaterOpBtn.setAlpha(70);
		humidifierOpBtn.setTouchable(false);
		lightOpBtn.setTouchable(false);
		heaterOpBtn.setTouchable(false);
		presenter->changeManualOverrideState(false);
	}
	else 
	{
		humidifierOpBtn.setAlpha(255);
		lightOpBtn.setAlpha(255);
		heaterOpBtn.setAlpha(255);
		humidifierOpBtn.setTouchable(true);
		lightOpBtn.setTouchable(true);
		heaterOpBtn.setTouchable(true);
		presenter->changeManualOverrideState(true);
	}
	
	presenter->changeManualOverrideState(manualOverrideBtn.getState());

	humidifierOpBtn.invalidate();
	lightOpBtn.invalidate();
	heaterOpBtn.invalidate();
}

void mainScreenView::humidifierOpBtnClicked()
{
	presenter->changeHumiOpState(humidifierOpBtn.getState());
}

void mainScreenView::lightOpBtnClicked()
{
	presenter->changeLightOpState(lightOpBtn.getState());
}

void mainScreenView::heaterOpBtnClicked()
{
	presenter->changeHeatOpState(heaterOpBtn.getState());
}

void mainScreenView::mainPowerBtnClicked() 
{
	HAL_GPIO_WritePin(LCD_BL_CTRL_GPIO_PORT, LCD_BL_CTRL_PIN, (GPIO_PinState) 0);
}

void mainScreenView::setHeaterOpBtnState(bool state)
{
	heaterOpBtn.forceState(state);
	heaterOpBtn.invalidate();
}

void mainScreenView::setHumiOpBtnState(bool state)
{
	humidifierOpBtn.forceState(state);
	humidifierOpBtn.invalidate();
}
	
void mainScreenView::setLightOpBtnState(bool state)
{
	lightOpBtn.forceState(state);
	lightOpBtn.invalidate();
}



