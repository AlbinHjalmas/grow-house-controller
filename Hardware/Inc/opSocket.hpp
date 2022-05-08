#ifndef OPSOCKET_HPP
#define OPSOCKET_HPP

#include <cstdint>
#include "stm32f7xx_hal_gpio.h"

using namespace std;

class opSocket
{
public:
	opSocket() {}
	opSocket(GPIO_TypeDef* port, uint32_t pin) : port(port), pin(pin) {}
	~opSocket() {};

	void setOpState(bool state);
	bool getOpState();
private:
	GPIO_TypeDef* port;
	uint32_t pin;
};

#endif //OPSOCKET_HPP
