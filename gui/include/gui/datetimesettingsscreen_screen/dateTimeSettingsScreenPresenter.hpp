#ifndef DATETIMESETTINGSSCREEN_PRESENTER_HPP
#define DATETIMESETTINGSSCREEN_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class dateTimeSettingsScreenView;

class dateTimeSettingsScreenPresenter : public Presenter, public ModelListener
{
public:
    dateTimeSettingsScreenPresenter(dateTimeSettingsScreenView& v);

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

    virtual ~dateTimeSettingsScreenPresenter() {};

	// Date/Time functions
	void changeYear(int year);
	void changeMonth(int month);
	void changeDay(int day);
	void changeHour(int hour);
	void changeMin(int min);
	int getYear();
	int getMonth();
	int getDay();
	int getHour();
	int getMin();
private:
    dateTimeSettingsScreenPresenter();

    dateTimeSettingsScreenView& view;
};


#endif // DATETIMESETTINGSSCREEN_PRESENTER_HPP
