#ifndef DAYNIGHTSETTINGSSCREEN_VIEW_HPP
#define DAYNIGHTSETTINGSSCREEN_VIEW_HPP

#include <gui_generated/daynightsettingsscreen_screen/dayNightSettingsScreenViewBase.hpp>
#include <gui/daynightsettingsscreen_screen/dayNightSettingsScreenPresenter.hpp>

class dayNightSettingsScreenView : public dayNightSettingsScreenViewBase
{
public:
    dayNightSettingsScreenView();
    virtual ~dayNightSettingsScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

	void setDayBegin(int hours, int minutes);
	void setDayEnd(int hours, int minutes);

protected:
	virtual void dayBeginHourDecBtnClicked();
	virtual void dayBeginHourIncBtnClicked();
	virtual void dayBeginMinDecBtnClicked();
	virtual void dayBeginMinIncBtnClicked();
	virtual void dayEndHourDecBtnClicked();
	virtual void dayEndHourIncBtnClicked();
	virtual void dayEndMinDecBtnClicked();
	virtual void dayEndMinIncBtnClicked();
};

#endif // DAYNIGHTSETTINGSSCREEN_VIEW_HPP
