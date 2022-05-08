#ifndef ACTUATOR_HPP
#define ACTUATOR_HPP

#include "opSocket.hpp"

using namespace std;

class actuator
{
public:

	actuator() {
		disconnected = true;
	}

	actuator(opSocket& socket, bool initState) : socket(socket), opState(initState)
	{
		// Set outputstate according to initState
		if (this->socket.getOpState() != opState) 
		{
			this->socket.setOpState(opState);
		}
		
		disconnected = false;
	}

	~actuator()
	{
		socket.~opSocket();
	}

	void disconnect();
	void setState(bool state);
	bool getState();
	void setOpSocket(const opSocket& socket);
	opSocket& getOpSocket();

private:
	bool opState;
	bool disconnected;
	opSocket socket;
};

#endif

