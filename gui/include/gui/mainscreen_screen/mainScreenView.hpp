#ifndef MAINSCREEN_VIEW_HPP
#define MAINSCREEN_VIEW_HPP

#include <gui_generated/mainscreen_screen/mainScreenViewBase.hpp>
#include <gui/mainscreen_screen/mainScreenPresenter.hpp>

class mainScreenView : public mainScreenViewBase
{
public:
    mainScreenView();
    virtual ~mainScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
	void setTemperature(int temp);
	void setHumidity(int humi);
	void setDate(int year, int month, int day, int hour, int min);
	void setHeaterOpBtnState(bool state);
	void setHumiOpBtnState(bool state);
	void setLightOpBtnState(bool state);
protected:
	virtual void manualOverrideBtnClicked();
	virtual void humidifierOpBtnClicked();
	virtual void lightOpBtnClicked();
	virtual void heaterOpBtnClicked();
	virtual void mainPowerBtnClicked();
private:
	static bool pressState;
};

#endif // MAINSCREEN_VIEW_HPP
