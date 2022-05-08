#include <gui/mainscreen_screen/mainScreenView.hpp>
#include <gui/mainscreen_screen/mainScreenPresenter.hpp>

mainScreenPresenter::mainScreenPresenter(mainScreenView& v)
    : view(v)
{
}

void mainScreenPresenter::activate()
{

}

void mainScreenPresenter::deactivate()
{

}

void mainScreenPresenter::temperatureChanged(int temp)
{
	view.setTemperature(temp);
}

void mainScreenPresenter::humidityChanged(int humi)
{
	view.setHumidity(humi);
}

void mainScreenPresenter::dateChanged(int year, int month, int day, int hour, int min)
{
	view.setDate(year, month, day, hour, min);
}

void mainScreenPresenter::lightOpStateChanged(bool state) 
{
	view.setLightOpBtnState(state);
}

void mainScreenPresenter::humiOpStateChanged(bool state) 
{
	view.setHumiOpBtnState(state);
}

void mainScreenPresenter::heatOpStateChanged(bool state) 
{
	view.setHeaterOpBtnState(state);
}

bool mainScreenPresenter::getManualOverrideState()
{
	return model->getManualOverrideState();
}

bool mainScreenPresenter::getHumiOpState()
{
	return model->getHumiOpState();
}

bool mainScreenPresenter::getLightOpState()
{
	return model->getLightOpState();
}

bool mainScreenPresenter::getHeatOpState()
{
	return model->getHeatOpState();
}

void mainScreenPresenter::changeManualOverrideState(bool state)
{
	model->changeManualOverrideState(state);
}

void mainScreenPresenter::changeHumiOpState(bool state)
{
	model->changeHumiOpState(state);
}

void mainScreenPresenter::changeLightOpState(bool state)
{
	model->changeLightOpState(state);
}

void mainScreenPresenter::changeHeatOpState(bool state)
{
	model->changeHeatOpState(state);
}

int mainScreenPresenter::getYear()
{
	return model->getYear();
}

int mainScreenPresenter::getMonth()
{
	return model->getMonth();
}

int mainScreenPresenter::getDay()
{
	return model->getDay();
}

int mainScreenPresenter::getHour()
{
	return model->getHour();
}

int mainScreenPresenter::getMin()
{
	return model->getMin();
}

int mainScreenPresenter::getTemperature()
{
	return model->getTemperature();
}

int mainScreenPresenter::getHumidity()
{
	return model->getHumidity();
}
