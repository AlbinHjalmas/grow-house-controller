#ifndef OPCONFIGSETTINGSSCREEN_VIEW_HPP
#define OPCONFIGSETTINGSSCREEN_VIEW_HPP

#include <gui_generated/opconfigsettingsscreen_screen/opConfigSettingsScreenViewBase.hpp>
#include <gui/opconfigsettingsscreen_screen/opConfigSettingsScreenPresenter.hpp>

class opConfigSettingsScreenView : public opConfigSettingsScreenViewBase
{
public:
    opConfigSettingsScreenView();
    virtual ~opConfigSettingsScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
	virtual void op1HeaterBtnClicked();
	virtual void op1HumiBtnClicked();
	virtual void op1LightBtnClicked();
	virtual void op2HeaterBtnClicked();
	virtual void op2HumiBtnClicked();
	virtual void op2LightBtnClicked();
	virtual void op3HeaterBtnClicked();
	virtual void op3HumiBtnClicked();
	virtual void op3LightBtnClicked();
};

#endif // OPCONFIGSETTINGSSCREEN_VIEW_HPP
