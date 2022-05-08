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
#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <actuator.hpp>

using namespace std;

// External C stuff
extern "C" {
	extern RTC_HandleTypeDef hrtc;
}

bool measTemp = true;
bool tempTrig = false;
bool humiTrig = false;
int currSec = 0;
int oldHour = 0;
int oldMin = 0;
opSocket socket1(op1_GPIO_Port, op1_Pin);
opSocket socket2(op2_GPIO_Port, op2_Pin);
opSocket socket3(op3_GPIO_Port, op3_Pin);
opSocket* sockets[] = {&socket1, &socket2, &socket3};
actuator lightAc(socket1, false);
actuator heatAc(socket2, false);
actuator humiAc(socket3, false);

Model::Model() : modelListener(0), dayNomTemp(15), dayNomHumi(10), nightNomTemp(15), nightNomHumi(10),
manualOverrideState(false), humiOpState(false), lightOpState(false), heatOpState(false),
heaterOp(1), humiOp(2), lightOp(3), tmpMinute(0),
dayBegin(0,0), dayEnd(0,0)
{

}

void Model::tempAction() 
{
	temperature = sens.getTemp();
	modelListener->temperatureChanged(temperature); // Update UI
	if(!manualOverrideState) { //set outputs
		if(time.isDay(dayBegin, dayEnd)) {
			lightAc.setState(true);
			modelListener->lightOpStateChanged(true);
			if(temperature < dayNomTemp - 2) {
				heatAc.setState(true);
				modelListener->heatOpStateChanged(true);
			} else if(temperature >= dayNomTemp + 2) {
				heatAc.setState(false);
				modelListener->heatOpStateChanged(false);
			}
		} else {
			lightAc.setState(false);
			modelListener->lightOpStateChanged(false);
			if(temperature < nightNomTemp - 2) {
				heatAc.setState(true);
				modelListener->heatOpStateChanged(true);
			} else if(temperature >= nightNomTemp + 2) {
				heatAc.setState(false);
				modelListener->heatOpStateChanged(false);
			}
		}
	}
	tempTrig = false;
	measTemp = false;
}

void Model::humiAction()
{
	humidity = sens.getHumi();
	modelListener->humidityChanged(humidity); // Update UI
	if(!manualOverrideState) { //Set outputs
		if(time.isDay(dayBegin, dayEnd)) {
			if(humidity <= dayNomHumi - 2) {
				humiAc.setState(true);
				modelListener->humiOpStateChanged(true);
			} else if(humidity >= dayNomHumi + 2) {
				humiAc.setState(false);
				modelListener->humiOpStateChanged(false);
			}
		} else {
			if(humidity <= nightNomHumi - 2) {
				humiAc.setState(true);
				modelListener->humiOpStateChanged(true);
			} else if(humidity >= nightNomHumi + 2) {
				humiAc.setState(false);
				modelListener->humiOpStateChanged(false);
			}
		}
	}
	humiTrig = false;
	measTemp = true;
}

void Model::tick()
{	
	// Update the current time & date
	HAL_RTC_GetTime(&hrtc, &htime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &hdate, RTC_FORMAT_BIN);
	if(htime.Minutes != tmpMinute) 
	{
		modelListener->dateChanged(hdate.Year + 2000, hdate.Month, hdate.Date, htime.Hours, htime.Minutes);
		time.setMin(htime.Minutes);
		time.setHour(htime.Hours);
	}
	tmpMinute = htime.Minutes;

	// Measure temperature & humidity
	if(currSec != htime.Seconds) // Only 1 measurment/second
	{
		if(measTemp && !tempTrig) {
			sens.reset();
			sens.trigTemp();
			tempTrig = true;
		} else if(measTemp && tempTrig) {
			tempAction();
		} else if(!(measTemp || humiTrig)) { 
			sens.trigHumi();
			humiTrig = true;
		} else if(!measTemp && humiTrig) {
			humiAction();
		}
		currSec = htime.Seconds;
	}
}

int Model::getTemperature()
{
	return temperature;
}

int Model::getHumidity()
{
	return humidity;
}

void Model::setDayNomTemp(int temp)
{
	dayNomTemp = temp;
}

void Model::setNightNomTemp(int temp)
{
	nightNomTemp = temp;
}

int Model::getDayNomTemp()
{
	return dayNomTemp;
}

int Model::getNightNomTemp()
{
	return nightNomTemp;
}

void Model::setDayNomHumi(int humi)
{
	dayNomHumi = humi;
}

void Model::setNightNomHumi(int humi)
{
	nightNomHumi = humi;
}

int Model::getDayNomHumi()
{
	return dayNomHumi;
}

int Model::getNightNomHumi()
{
	return nightNomHumi;
}

bool Model::getManualOverrideState()
{
	return manualOverrideState;
}

bool Model::getHumiOpState()
{
	return humiAc.getState();
}

bool Model::getLightOpState()
{
	return lightAc.getState();
}

bool Model::getHeatOpState()
{
	return heatAc.getState();
}

void Model::changeManualOverrideState(bool state)
{
	manualOverrideState = state;
}

void Model::changeHumiOpState(bool state)
{
	humiAc.setState(state);
}

void Model::changeLightOpState(bool state)
{
	lightAc.setState(state);
}

void Model::changeHeatOpState(bool state)
{
	heatAc.setState(state);
}

void Model::changeHeaterOp(int op)
{
	heaterOp = op;
	if(op == 0) {
		heatAc.disconnect();
	} else {
		heatAc.setOpSocket(*sockets[op-1]);
	}
}

void Model::changeHumiOp(int op)
{
	humiOp = op;
	if(op == 0) {
		humiAc.disconnect();
	} else {
		humiAc.setOpSocket(*sockets[op-1]);
	}
}

void Model::changeLightOp(int op)
{
	lightOp = op;
	if(op == 0) {
		lightAc.disconnect();
	} else {
		lightAc.setOpSocket(*sockets[op-1]);
	}
}

int Model::getHeaterOp()
{
	return heaterOp;
}

int Model::getHumiOp()
{
	return humiOp;
}

int Model::getLightOp()
{
	return lightOp;
}

void Model::changeDayBeginHour(int hours)
{
	dayBegin.setHour(hours);
}

void Model::changeDayBeginMin(int minutes)
{
	dayBegin.setMin(minutes);
}

void Model::changeDayEndHour(int hours)
{
	dayEnd.setHour(hours);
}

void Model::changeDayEndMin(int minutes)
{
	dayEnd.setMin(minutes);
}

int Model::getDayBeginHour()
{
	return dayBegin.getHour();
}

int Model::getDayBeginMin()
{
	return dayBegin.getMin();
}

int Model::getDayEndHour()
{
	return dayEnd.getHour();
}

int Model::getDayEndMin()
{
	return dayEnd.getMin();
}

void Model::changeYear(int year)
{
	hdate.Year = year - 2000;
	HAL_RTC_SetDate(&hrtc, &hdate, RTC_FORMAT_BIN);
	modelListener->dateChanged(hdate.Year + 2000, hdate.Month, hdate.Date, htime.Hours, htime.Minutes);
}

void Model::changeMonth(int month)
{
	hdate.Month = month;
	HAL_RTC_SetDate(&hrtc, &hdate, RTC_FORMAT_BIN);
	modelListener->dateChanged(hdate.Year + 2000, hdate.Month, hdate.Date, htime.Hours, htime.Minutes);
}

void Model::changeDay(int day)
{
	hdate.Date = day;
	HAL_RTC_SetDate(&hrtc, &hdate, RTC_FORMAT_BIN);
	modelListener->dateChanged(hdate.Year + 2000, hdate.Month, hdate.Date, htime.Hours, htime.Minutes);
}
void Model::changeHour(int hour)
{
	htime.Hours = hour;
	HAL_RTC_SetTime(&hrtc, &htime, RTC_FORMAT_BIN);
	modelListener->dateChanged(hdate.Year + 2000, hdate.Month, hdate.Date, htime.Hours, htime.Minutes);
}

void Model::changeMin(int min)
{
	htime.Minutes = min;
	HAL_RTC_SetTime(&hrtc, &htime, RTC_FORMAT_BIN);
	modelListener->dateChanged(hdate.Year + 2000, hdate.Month, hdate.Date, htime.Hours, htime.Minutes);
}

int Model::getYear()
{
	return hdate.Year + 2000;
}

int Model::getMonth()
{
	return hdate.Month;
}

int Model::getDay()
{
	return hdate.Date;
}

int Model::getHour()
{
	return htime.Hours;
}

int Model::getMin()
{
	return htime.Minutes;
}


