#ifndef MAINSCREEN_PRESENTER_HPP
#define MAINSCREEN_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class mainScreenView;

class mainScreenPresenter : public Presenter, public ModelListener
{
public:
    mainScreenPresenter(mainScreenView& v);

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

    virtual ~mainScreenPresenter() {};

	virtual void temperatureChanged(int temp);
	virtual void humidityChanged(int humi);
	virtual void dateChanged(int year, int month, int day, int hour, int min);
	virtual void lightOpStateChanged(bool state);
	virtual void humiOpStateChanged(bool state);
	virtual void heatOpStateChanged(bool state);

	// Main screen functions
	bool getManualOverrideState();
	bool getHumiOpState();
	bool getLightOpState();
	bool getHeatOpState();
	void changeManualOverrideState(bool state);
	void changeHumiOpState(bool state);
	void changeLightOpState(bool state);
	void changeHeatOpState(bool state);

	int getYear();
	int getMonth();
	int getDay();
	int getHour();
	int getMin();
		
	int getTemperature();
	int getHumidity();

private:
    mainScreenPresenter();

    mainScreenView& view;

};


#endif // MAINSCREEN_PRESENTER_HPP
