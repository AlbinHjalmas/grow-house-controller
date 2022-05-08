#ifndef DATETIMESETTINGSSCREEN_VIEW_HPP
#define DATETIMESETTINGSSCREEN_VIEW_HPP

#include <gui_generated/datetimesettingsscreen_screen/dateTimeSettingsScreenViewBase.hpp>
#include <gui/datetimesettingsscreen_screen/dateTimeSettingsScreenPresenter.hpp>

class dateTimeSettingsScreenView : public dateTimeSettingsScreenViewBase
{
public:
    dateTimeSettingsScreenView();
    virtual ~dateTimeSettingsScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);
	void setHour(int hour);
	void setMin(int min);

protected:
	virtual void hourDecBtnClicked();
	virtual void hourIncBtnClicked();
	virtual void minDecBtnClicked();
	virtual void minIncBtnClicked();
	virtual void yearDecBtnClicked();
	virtual void yearIncBtnClicked();
	virtual void monthDecBtnClicked();
	virtual void monthIncBtnClicked();
	virtual void dayDecBtnClicked();
	virtual void dayIncBtnClicked();
};

#endif // DATETIMESETTINGSSCREEN_VIEW_HPP
