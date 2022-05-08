#include "clockTime.hpp"

void clockTime::incMin()
{
	mm = mm >= 59 ? 0 : mm + 1;
}

void clockTime::incHour()
{
	hh = hh >= 23 ? 0 : hh + 1;
}

int clockTime::getMin()
{
	return mm;
}

int clockTime::getHour()
{
	return hh;
}

bool clockTime::equals(clockTime& other)
{
	return (other.hh == hh) && (other.mm == mm);
}

bool clockTime::isDay(clockTime& dayBegin, clockTime& dayEnd)
{
	if (this->equals(dayBegin)) {
		return true;
	} else if (this->equals(dayEnd)) {
		return false;
	}

	bool dayBeginState = false;
	bool dayEndState = false;
	clockTime tmp(*this);
	for(int i=0; i<24*60; i++) {
		dayEndState = dayEnd.equals(tmp);
		dayBeginState = dayBegin.equals(tmp);
		if(dayEndState && !dayBeginState) {
			return true;
		} else if(!dayEndState && dayBeginState) {
			return false;
		} else if(dayEndState && dayBeginState) {
			return false;
		}
		tmp.incMin();
		if(tmp.getMin() == 0) {
			tmp.incHour();
		}
	}
}