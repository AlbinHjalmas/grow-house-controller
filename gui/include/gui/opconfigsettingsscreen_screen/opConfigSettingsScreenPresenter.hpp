#ifndef OPCONFIGSETTINGSSCREEN_PRESENTER_HPP
#define OPCONFIGSETTINGSSCREEN_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class opConfigSettingsScreenView;

class opConfigSettingsScreenPresenter : public Presenter, public ModelListener
{
public:
    opConfigSettingsScreenPresenter(opConfigSettingsScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~opConfigSettingsScreenPresenter() {};

	// Output config functions
	void changeHeaterOp(int op);
	void changeHumiOp(int op);
	void changeLightOp(int op);
	int getHeaterOp();
	int getHumiOp();
	int getLightOp();

private:
    opConfigSettingsScreenPresenter();

    opConfigSettingsScreenView& view;
};


#endif // OPCONFIGSETTINGSSCREEN_PRESENTER_HPP
