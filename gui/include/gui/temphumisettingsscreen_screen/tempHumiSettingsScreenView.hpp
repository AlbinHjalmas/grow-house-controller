#ifndef TEMPHUMISETTINGSSCREEN_VIEW_HPP
#define TEMPHUMISETTINGSSCREEN_VIEW_HPP

#include <gui_generated/temphumisettingsscreen_screen/tempHumiSettingsScreenViewBase.hpp>
#include <gui/temphumisettingsscreen_screen/tempHumiSettingsScreenPresenter.hpp>

class tempHumiSettingsScreenView : public tempHumiSettingsScreenViewBase
{
public:
    tempHumiSettingsScreenView();
    virtual ~tempHumiSettingsScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
	
	void setDayTempTxt(int temp);
	void setNightTempTxt(int temp);
	void setDayHumiTxt(int humi);
	void setNightHumiTxt(int humi);

protected:
	virtual void dayTempSliderValueChanged(int value);
	virtual void nightTempSliderValueChanged(int value);
	virtual void dayHumiSliderValueChanged(int value);
	virtual void nightHumiSliderValueChanged(int value);
};

#endif // TEMPHUMISETTINGSSCREEN_VIEW_HPP
