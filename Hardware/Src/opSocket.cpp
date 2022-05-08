#include "opSocket.hpp"

void opSocket::setOpState(bool state)
{
	HAL_GPIO_WritePin(port, pin, (GPIO_PinState) state);
}

bool opSocket::getOpState()
{
	return (bool) HAL_GPIO_ReadPin(port, pin);
}
