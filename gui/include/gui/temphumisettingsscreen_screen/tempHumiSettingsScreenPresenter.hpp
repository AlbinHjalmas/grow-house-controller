#ifndef TEMPHUMISETTINGSSCREEN_PRESENTER_HPP
#define TEMPHUMISETTINGSSCREEN_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class tempHumiSettingsScreenView;

class tempHumiSettingsScreenPresenter : public Presenter, public ModelListener
{
public:
    tempHumiSettingsScreenPresenter(tempHumiSettingsScreenView& v);

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

    virtual ~tempHumiSettingsScreenPresenter() {};

	void changeDayNomTemp(int value);
	void changeNightNomTemp(int value);
	void changeDayNomHumi(int value);
	void changeNightNomHumi(int value);

	int getDayNomTemp();
	int getNightNomTemp();
	int getDayNomHumi();
	int getNightNomHumi();

private:
    tempHumiSettingsScreenPresenter();

    tempHumiSettingsScreenView& view;
};


#endif // TEMPHUMISETTINGSSCREEN_PRESENTER_HPP
