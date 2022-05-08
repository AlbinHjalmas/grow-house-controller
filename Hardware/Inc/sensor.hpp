#ifndef SENSOR_HPP
#define SENSOR_HPP
#include <cstdint>
#include <cmath>

using namespace std;

class sensor
{
public:
	sensor();
	~sensor();

	void trigTemp();
	void trigHumi();
	bool tempReady();
	bool humiReady();
	int getTemp();
	int getHumi();

	void reset();

private:
	uint8_t tempBuf[2];
	uint8_t humiBuf[2];
};

#endif // SENSOR_HPP