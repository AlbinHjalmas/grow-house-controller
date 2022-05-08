#include <gui/temphumisettingsscreen_screen/tempHumiSettingsScreenView.hpp>

tempHumiSettingsScreenView::tempHumiSettingsScreenView()
{

}

void tempHumiSettingsScreenView::setupScreen()
{
	dayTempSlider.setValue(presenter->getDayNomTemp());
	nightTempSlider.setValue(presenter->getNightNomTemp());
	dayHumiSlider.setValue(presenter->getDayNomHumi());
	nightHumiSlider.setValue(presenter->getNightNomHumi());
}

void tempHumiSettingsScreenView::tearDownScreen()
{

}

void tempHumiSettingsScreenView::setDayTempTxt(int temp)
{
	Unicode::snprintf(dayTempTxtBuffer, DAYTEMPTXT_SIZE, "%d", temp);
	dayTempTxt.invalidate();
}

void tempHumiSettingsScreenView::setNightTempTxt(int temp)
{
	Unicode::snprintf(nightTempTxtBuffer, NIGHTTEMPTXT_SIZE, "%d", temp);
	nightTempTxt.invalidate();
}

void tempHumiSettingsScreenView::setDayHumiTxt(int humi)
{
	Unicode::snprintf(dayHumiTxtBuffer, DAYHUMITXT_SIZE, "%d", humi);
	dayHumiTxt.invalidate();
}

void tempHumiSettingsScreenView::setNightHumiTxt(int humi)
{
	Unicode::snprintf(nightHumiTxtBuffer, NIGHTHUMITXT_SIZE, "%d", humi);
	nightHumiTxt.invalidate();
}

void tempHumiSettingsScreenView::dayTempSliderValueChanged(int value)
{
	setDayTempTxt(value);
	presenter->changeDayNomTemp(value);
}

void tempHumiSettingsScreenView::nightTempSliderValueChanged(int value)
{
	setNightTempTxt(value);
	presenter->changeNightNomTemp(value);
}

void tempHumiSettingsScreenView::dayHumiSliderValueChanged(int value)
{
	setDayHumiTxt(value);
	presenter->changeDayNomHumi(value);
}

void tempHumiSettingsScreenView::nightHumiSliderValueChanged(int value)
{
	setNightHumiTxt(value);
	presenter->changeNightNomHumi(value);
}
