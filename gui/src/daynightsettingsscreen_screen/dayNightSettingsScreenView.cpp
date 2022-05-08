#include <gui/daynightsettingsscreen_screen/dayNightSettingsScreenView.hpp>

dayNightSettingsScreenView::dayNightSettingsScreenView()
{

}

void dayNightSettingsScreenView::setupScreen()
{
	setDayBegin(presenter->getDayBeginHour(), presenter->getDayBeginMin());
	setDayEnd(presenter->getDayEndHour(), presenter->getDayEndMin());
}

void dayNightSettingsScreenView::tearDownScreen()
{

}

void dayNightSettingsScreenView::setDayBegin(int hours, int minutes)
{
	Unicode::snprintf(beginHourTxtBuffer, BEGINHOURTXT_SIZE, "%02d", hours);
	Unicode::snprintf(beginMinTxtBuffer, BEGINMINTXT_SIZE, "%02d", minutes);
	beginHourTxt.invalidate();
	beginMinTxt.invalidate();
}

void dayNightSettingsScreenView::setDayEnd(int hours, int minutes)
{
	Unicode::snprintf(endHourTxtBuffer, ENDHOURTXT_SIZE, "%02d", hours);
	Unicode::snprintf(endMinTxtBuffer, ENDMINTXT_SIZE, "%02d", minutes);
	endHourTxt.invalidate();
	endMinTxt.invalidate();
}

void dayNightSettingsScreenView::dayBeginHourDecBtnClicked()
{
	int currHour = presenter->getDayBeginHour();
	currHour--;
	currHour = currHour < 0 ? 23 : currHour;
	setDayBegin(currHour, presenter->getDayBeginMin());
	presenter->changeDayBeginHour(currHour);
}

void dayNightSettingsScreenView::dayBeginHourIncBtnClicked()
{
	int currHour = presenter->getDayBeginHour();
	currHour++;
	currHour = currHour > 23 ? 0 : currHour;
	setDayBegin(currHour, presenter->getDayBeginMin());
	presenter->changeDayBeginHour(currHour);
}

void dayNightSettingsScreenView::dayBeginMinDecBtnClicked()
{
	int curr = presenter->getDayBeginMin();
	curr--;
	curr = curr < 0 ? 59 : curr;
	setDayBegin(presenter->getDayBeginHour(), curr);
	presenter->changeDayBeginMin(curr);
}

void dayNightSettingsScreenView::dayBeginMinIncBtnClicked()
{
	int curr = presenter->getDayBeginMin();
	curr++;
	curr = curr > 59 ? 0 : curr;
	setDayBegin(presenter->getDayBeginHour(), curr);
	presenter->changeDayBeginMin(curr);
}

void dayNightSettingsScreenView::dayEndHourDecBtnClicked()
{
	int currHour = presenter->getDayEndHour();
	currHour--;
	currHour = currHour < 0 ? 23 : currHour;
	setDayEnd(currHour, presenter->getDayEndMin());
	presenter->changeDayEndHour(currHour);
}

void dayNightSettingsScreenView::dayEndHourIncBtnClicked()
{
	int currHour = presenter->getDayEndHour();
	currHour++;
	currHour = currHour > 23 ? 0 : currHour;
	setDayEnd(currHour, presenter->getDayEndMin());
	presenter->changeDayEndHour(currHour);
}

void dayNightSettingsScreenView::dayEndMinDecBtnClicked()
{
	int curr = presenter->getDayEndMin();
	curr--;
	curr = curr < 0 ? 59 : curr;
	setDayEnd(presenter->getDayEndHour(), curr);
	presenter->changeDayEndMin(curr);
}

void dayNightSettingsScreenView::dayEndMinIncBtnClicked()
{
	int curr = presenter->getDayEndMin();
	curr++;
	curr = curr > 59 ? 0 : curr;
	setDayEnd(presenter->getDayEndHour(), curr);
	presenter->changeDayEndMin(curr);
}
