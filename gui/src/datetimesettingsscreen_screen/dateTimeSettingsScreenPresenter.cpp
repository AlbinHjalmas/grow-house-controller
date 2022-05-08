#include <gui/datetimesettingsscreen_screen/dateTimeSettingsScreenView.hpp>
#include <gui/datetimesettingsscreen_screen/dateTimeSettingsScreenPresenter.hpp>

dateTimeSettingsScreenPresenter::dateTimeSettingsScreenPresenter(dateTimeSettingsScreenView& v)
    : view(v)
{
}

void dateTimeSettingsScreenPresenter::activate()
{

}

void dateTimeSettingsScreenPresenter::deactivate()
{

}

void dateTimeSettingsScreenPresenter::changeYear(int year)
{
	model->changeYear(year);
}

void dateTimeSettingsScreenPresenter::changeMonth(int month)
{
	model->changeMonth(month);
}

void dateTimeSettingsScreenPresenter::changeDay(int day)
{
	model->changeDay(day);
}

void dateTimeSettingsScreenPresenter::changeHour(int hour)
{
	model->changeHour(hour);
}

void dateTimeSettingsScreenPresenter::changeMin(int min)
{
	model->changeMin(min);
}

int dateTimeSettingsScreenPresenter::getYear()
{
	return model->getYear();
}

int dateTimeSettingsScreenPresenter::getMonth()
{
	return model->getMonth();
}

int dateTimeSettingsScreenPresenter::getDay()
{
	return model->getDay();
}

int dateTimeSettingsScreenPresenter::getHour()
{
	return model->getHour();
}

int dateTimeSettingsScreenPresenter::getMin()
{
	return model->getMin();
}
