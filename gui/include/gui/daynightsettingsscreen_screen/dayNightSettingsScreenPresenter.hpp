#ifndef DAYNIGHTSETTINGSSCREEN_PRESENTER_HPP
#define DAYNIGHTSETTINGSSCREEN_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class dayNightSettingsScreenView;

class dayNightSettingsScreenPresenter : public Presenter, public ModelListener
{
public:
    dayNightSettingsScreenPresenter(dayNightSettingsScreenView& v);

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

    virtual ~dayNightSettingsScreenPresenter() {};

	// Day end/begin functions
	void changeDayBeginHour(int hours);
	void changeDayBeginMin(int minutes);
	void changeDayEndHour(int hours);
	void changeDayEndMin(int minutes);
	int getDayBeginHour();
	int getDayBeginMin();
	int getDayEndHour();
	int getDayEndMin();

private:
    dayNightSettingsScreenPresenter();

    dayNightSettingsScreenView& view;
};


#endif // DAYNIGHTSETTINGSSCREEN_PRESENTER_HPP
