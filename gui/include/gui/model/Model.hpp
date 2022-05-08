/******************************************************************************
 *
 * @brief     This file is part of the TouchGFX 4.8.0 evaluation distribution.
 *
 * @author    Draupner Graphics A/S <http://www.touchgfx.com>
 *
 ******************************************************************************
 *
 * @section Copyright
 *
 * This file is free software and is provided for example purposes. You may
 * use, copy, and modify within the terms and conditions of the license
 * agreement.
 *
 * This is licensed software for evaluation use, any use must strictly comply
 * with the evaluation license agreement provided with delivery of the
 * TouchGFX software.
 *
 * The evaluation license agreement can be seen on www.touchgfx.com
 *
 * @section Disclaimer
 *
 * DISCLAIMER OF WARRANTY/LIMITATION OF REMEDIES: Draupner Graphics A/S has
 * no obligation to support this software. Draupner Graphics A/S is providing
 * the software "AS IS", with no express or implied warranties of any kind,
 * including, but not limited to, any implied warranties of merchantability
 * or fitness for any particular purpose or warranties against infringement
 * of any proprietary rights of a third party.
 *
 * Draupner Graphics A/S can not be held liable for any consequential,
 * incidental, or special damages, or any other relief, or for any claim by
 * any third party, arising from your use of this software.
 *
 *****************************************************************************/
#ifndef MODEL_HPP
#define MODEL_HPP

#include "gpio.h"
#include "sensor.hpp"
#include "opSocket.hpp"
#include "clockTime.hpp"

extern "C" {
#include "stm32f7xx_hal_rtc.h"
}

class ModelListener;

/**
 * The Model class defines the data model in the model-view-presenter paradigm.
 * The Model is a singular object used across all presenters. The currently active
 * presenter will have a pointer to the Model through deriving from ModelListener.
 *
 * The Model will typically contain UI state information that must be kept alive
 * through screen transitions. It also usually provides the interface to the rest
 * of the system (the backend). As such, the Model can receive events and data from
 * the backend and inform the current presenter of such events through the modelListener
 * pointer, which is automatically configured to point to the current presenter.
 * Conversely, the current presenter can trigger events in the backend through the Model.
 */
class Model
{
public:
    Model();

    /**
     * Sets the modelListener to point to the currently active presenter. Called automatically
     * when switching screen.
     */
    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    /**
     * This function will be called automatically every frame. Can be used to e.g. sample hardware
     * peripherals or read events from the surrounding system and inject events to the GUI through
     * the ModelListener interface.
     */
    void tick();

	int getTemperature();
	int getHumidity();

	// Day-night settings screen functions
	void setDayNomTemp(int temp);
	void setNightNomTemp(int temp);
	void setDayNomHumi(int humi);
	void setNightNomHumi(int humi);
	int getDayNomTemp();
	int getNightNomTemp();
	int getDayNomHumi();
	int getNightNomHumi();

	// Main screen functions
	void changeManualOverrideState(bool state);
	void changeHumiOpState(bool state);
	void changeLightOpState(bool state);
	void changeHeatOpState(bool state);
	bool getManualOverrideState();
	bool getHumiOpState();
	bool getLightOpState();
	bool getHeatOpState();
	

	// Output config functions
	void changeHeaterOp(int op);
	void changeHumiOp(int op);
	void changeLightOp(int op);
	int getHeaterOp();
	int getHumiOp();
	int getLightOp();

	// Day end/begin functions
	void changeDayBeginHour(int hours);
	void changeDayBeginMin(int minutes);
	void changeDayEndHour(int hours);
	void changeDayEndMin(int minutes);
	int getDayBeginHour();
	int getDayBeginMin();
	int getDayEndHour();
	int getDayEndMin();

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

protected:
    /**
     * Pointer to the currently active presenter.
     */
    ModelListener* modelListener;

	// User stuff
	int temperature;
	int measureTemp;
	int humidity;
	int measureHumi;

	// Nominal values
	int dayNomTemp;
	int nightNomTemp;
	int dayNomHumi;
	int nightNomHumi;

	// Manual override states
	bool manualOverrideState;
	bool humiOpState;
	bool lightOpState;
	bool heatOpState;

	// Output configuration
	int heaterOp;
	int humiOp;
	int lightOp;

	// Day end/begin variables
	clockTime dayBegin;
	clockTime dayEnd;
	
	// Date variables
	RTC_TimeTypeDef htime;
	RTC_DateTypeDef hdate;
	int tmpMinute;
	clockTime time;
	
	// External Hardware
	sensor sens;
	
	void tempAction();
	void humiAction();
};

#endif /* MODEL_HPP */
