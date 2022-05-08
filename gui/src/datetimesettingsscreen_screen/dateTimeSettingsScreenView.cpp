#include <gui/datetimesettingsscreen_screen/dateTimeSettingsScreenView.hpp>

dateTimeSettingsScreenView::dateTimeSettingsScreenView()
{

}

void dateTimeSettingsScreenView::setupScreen()
{
	setYear(presenter->getYear());
	setMonth(presenter->getMonth());
	setDay(presenter->getDay());
	setHour(presenter->getHour());
	setMin(presenter->getMin());
}

void dateTimeSettingsScreenView::tearDownScreen()
{

}

void dateTimeSettingsScreenView::setYear(int year)
{
	Unicode::snprintf(yearBuffer, YEAR_SIZE, "%04d", year);
	this->year.invalidate();
}

void dateTimeSettingsScreenView::setMonth(int month)
{
	Unicode::snprintf(monthBuffer, MONTH_SIZE, "%02d", month);
	this->month.invalidate();
}

void dateTimeSettingsScreenView::setDay(int day)
{
	Unicode::snprintf(dayBuffer, DAY_SIZE, "%02d", day);
	this->day.invalidate();
}

void dateTimeSettingsScreenView::setHour(int hour)
{
	Unicode::snprintf(hourBuffer, HOUR_SIZE, "%02d", hour);
	this->hour.invalidate();
}

void dateTimeSettingsScreenView::setMin(int min)
{
	Unicode::snprintf(minBuffer, MIN_SIZE, "%02d", min);
	this->min.invalidate();
}

void dateTimeSettingsScreenView::hourDecBtnClicked()
{
	int tmp = presenter->getHour();
	tmp--;
	tmp = tmp < 0 ? 23 : tmp;
	setHour(tmp);
	presenter->changeHour(tmp);
}

void dateTimeSettingsScreenView::hourIncBtnClicked()
{
	int tmp = presenter->getHour();
	tmp++;
	tmp = tmp > 23 ? 0 : tmp;
	setHour(tmp);
	presenter->changeHour(tmp);
}

void dateTimeSettingsScreenView::minDecBtnClicked()
{
	int tmp = presenter->getMin();
	tmp--;
	tmp = tmp < 0 ? 59 : tmp;
	setMin(tmp);
	presenter->changeMin(tmp);
}

void dateTimeSettingsScreenView::minIncBtnClicked()
{
	int tmp = presenter->getMin();
	tmp++;
	tmp = tmp > 59 ? 0 : tmp;
	setMin(tmp);
	presenter->changeMin(tmp);
}

void dateTimeSettingsScreenView::yearDecBtnClicked()
{
	int tmp = presenter->getYear();
	tmp--;
	tmp = tmp < 0 ? 0 : tmp;
	setYear(tmp);
	presenter->changeYear(tmp);
}

void dateTimeSettingsScreenView::yearIncBtnClicked()
{
	int tmp = presenter->getYear();
	tmp++;
	setYear(tmp);
	presenter->changeYear(tmp);
}

void dateTimeSettingsScreenView::monthDecBtnClicked()
{
	int tmp = presenter->getMonth();
	tmp--;
	tmp = tmp < 1 ? 12 : tmp;
	setMonth(tmp);
	presenter->changeMonth(tmp);
}

void dateTimeSettingsScreenView::monthIncBtnClicked()
{
	int tmp = presenter->getMonth();
	tmp++;
	tmp = tmp > 12 ? 1 : tmp;
	setMonth(tmp);
	presenter->changeMonth(tmp);
}

void dateTimeSettingsScreenView::dayDecBtnClicked()
{
	int tmp = presenter->getDay();
	tmp--;
	tmp = tmp < 1 ? 31 : tmp;
	setDay(tmp);
	presenter->changeDay(tmp);
}

void dateTimeSettingsScreenView::dayIncBtnClicked()
{
	int tmp = presenter->getDay();
	tmp++;
	tmp = tmp > 31 ? 1 : tmp;
	setDay(tmp);
	presenter->changeDay(tmp);
}


