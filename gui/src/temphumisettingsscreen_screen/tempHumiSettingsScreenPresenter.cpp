#include <gui/temphumisettingsscreen_screen/tempHumiSettingsScreenView.hpp>
#include <gui/temphumisettingsscreen_screen/tempHumiSettingsScreenPresenter.hpp>

tempHumiSettingsScreenPresenter::tempHumiSettingsScreenPresenter(tempHumiSettingsScreenView& v)
    : view(v)
{
}

void tempHumiSettingsScreenPresenter::activate()
{

}

void tempHumiSettingsScreenPresenter::deactivate()
{

}

void tempHumiSettingsScreenPresenter::changeDayNomTemp(int value)
{
	model->setDayNomTemp(value);
}

void tempHumiSettingsScreenPresenter::changeNightNomTemp(int value)
{
	model->setNightNomTemp(value);
}

void tempHumiSettingsScreenPresenter::changeDayNomHumi(int value)
{
	model->setDayNomHumi(value);
}

void tempHumiSettingsScreenPresenter::changeNightNomHumi(int value)
{
	model->setNightNomHumi(value);
}

int tempHumiSettingsScreenPresenter::getDayNomTemp()
{
	return model->getDayNomTemp();
}

int tempHumiSettingsScreenPresenter::getNightNomTemp()
{
	return model->getNightNomTemp();
}

int tempHumiSettingsScreenPresenter::getDayNomHumi()
{
	return model->getDayNomHumi();
}

int tempHumiSettingsScreenPresenter::getNightNomHumi()
{
	return model->getNightNomHumi();
}
