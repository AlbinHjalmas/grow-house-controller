#include "actuator.hpp"

void actuator::setState(bool state)
{
	if(disconnected) return;
	socket.setOpState(state);
}

bool actuator::getState()
{
	return disconnected ? false : socket.getOpState();
}

void actuator::setOpSocket(const opSocket & socket)
{
	this->socket = socket;
	disconnected = false;
}

opSocket & actuator::getOpSocket()
{
	return socket;
}

void actuator::disconnect()
{
	socket.setOpState(false);
	disconnected = true;
}
