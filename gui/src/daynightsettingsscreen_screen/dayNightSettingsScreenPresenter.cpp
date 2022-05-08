#include <gui/daynightsettingsscreen_screen/dayNightSettingsScreenView.hpp>
#include <gui/daynightsettingsscreen_screen/dayNightSettingsScreenPresenter.hpp>

dayNightSettingsScreenPresenter::dayNightSettingsScreenPresenter(dayNightSettingsScreenView& v)
    : view(v)
{
}

void dayNightSettingsScreenPresenter::activate()
{

}

void dayNightSettingsScreenPresenter::deactivate()
{

}

void dayNightSettingsScreenPresenter::changeDayBeginHour(int hours)
{
	model->changeDayBeginHour(hours);
}

void dayNightSettingsScreenPresenter::changeDayBeginMin(int minutes)
{
	model->changeDayBeginMin(minutes);
}

void dayNightSettingsScreenPresenter::changeDayEndHour(int hours)
{
	model->changeDayEndHour(hours);
}

void dayNightSettingsScreenPresenter::changeDayEndMin(int minutes)
{
	model->changeDayEndMin(minutes);
}

int dayNightSettingsScreenPresenter::getDayBeginHour()
{
	return model->getDayBeginHour();
}

int dayNightSettingsScreenPresenter::getDayBeginMin()
{
	return model->getDayBeginMin();
}

int dayNightSettingsScreenPresenter::getDayEndHour()
{
	return model->getDayEndHour();
}

int dayNightSettingsScreenPresenter::getDayEndMin()
{
	return model->getDayEndMin();
}
