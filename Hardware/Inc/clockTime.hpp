#ifndef CLOCKTIME_HPP
#define CLOCKTIME_HPP


class clockTime
{
public:
	clockTime() {}
	~clockTime() {}
	clockTime(const clockTime& obj)
	{
		hh = obj.hh;
		mm = obj.mm;
	}
		
	clockTime(int hh, int mm) 
		: 
		hh(hh),
		mm(mm)
	{
		
	}
	
	void incMin();
	void incHour();
	void setHour(int hh) {this->hh = hh;}
	void setMin(int mm) {this->mm = mm;}
	int getMin();
	int getHour();
	bool equals(clockTime& other);
	bool isDay(clockTime& dayBegin, clockTime& dayEnd);
	
private:
	int hh;
	int mm;
};

#endif //CLOCKTIME_HPP








