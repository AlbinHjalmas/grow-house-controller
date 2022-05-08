#include "sensor.hpp"
#include "gpio.h"

// Helper functions
void reset();
void startTransmit();
void writeData(uint8_t data);
void readData(uint8_t* pBuf, int size);
void writeCmd(uint8_t cmd);
void delay(uint32_t time);
int getTemp(uint8_t MSB, uint8_t LSB);
int getHumi(uint8_t MSB, uint8_t LSB);

// Some defines to make life easier (or not)
#define dioR HAL_GPIO_ReadPin(SENS_DIO_GPIO_Port, SENS_DIO_Pin)
#define dio1 HAL_GPIO_WritePin(SENS_DIO_GPIO_Port, SENS_DIO_Pin, (GPIO_PinState) 1);
#define dio0 HAL_GPIO_WritePin(SENS_DIO_GPIO_Port, SENS_DIO_Pin, (GPIO_PinState) 0);
#define clk1 HAL_GPIO_WritePin(SENS_CLK_GPIO_Port, SENS_CLK_Pin, (GPIO_PinState) 1);
#define clk0 HAL_GPIO_WritePin(SENS_CLK_GPIO_Port, SENS_CLK_Pin, (GPIO_PinState) 0);

sensor::sensor()
{
}

sensor::~sensor()
{
}

void sensor::trigTemp()
{
	writeCmd(0x03);
}

void sensor::trigHumi()
{
	writeCmd(0x05);
}

bool sensor::tempReady()
{
	return !dioR;
}

bool sensor::humiReady()
{
	return !dioR;
}

int sensor::getTemp()
{
	readData(tempBuf, 2);
	double v = (double)(((tempBuf[0] & 0x3F) << 8) | tempBuf[1]);
	double temp = 0.01*v - 39.6;
	return (int)(temp < 0 ? (temp - 0.5) : (temp + 0.5));
}	

int sensor::getHumi()
{
	readData(humiBuf, 2);
	double v = (double)(((humiBuf[0] & 0x0F) << 8) | humiBuf[1]);
	double humi = 0.0367*v -1.5955E-6*v*v - 2.0468;
	return (int)(humi < 0 ? (humi - 0.5) : (humi + 0.5));
}

void sensor::reset()
{
	for(int i=0; i<11; i++) {
		clk1
		delay(600);
		clk0
		delay(600);
	}
	delay(800);
}

/////////////////////////////////////////////////////////
// Helper functions
/////////////////////////////////////////////////////////

void startTransmit() 
{
	dio1
	delay(600);
	clk1
	delay(600);
	dio0
	delay(600);
	clk0
	delay(600);
	clk1
	delay(600);
	dio1
	delay(600);
	clk0
	delay(600);
}

void writeData(uint8_t data) 
{
	uint8_t mask = (1 << 7);
	uint8_t d = 0x00;
	for(int i=7; i>=0; i--) 
	{
		d = (data & mask) >> i;
		mask >>= 1;
		
		HAL_GPIO_WritePin(SENS_DIO_GPIO_Port, SENS_DIO_Pin, (GPIO_PinState) d);
		delay(600);
		clk1
		delay(600);
		clk0
		delay(600);
	}
	dio1
	delay(600);
	clk1
	delay(600);
	clk0;
	delay(600);
}

void readData(uint8_t* pBuf, int size) 
{
	// Clean buffer
	for(int i=0; i<size; i++) {
		pBuf[i] = 0;
	}
	
	for(int i=0; i<size; i++) {
		delay(600);
		for(int j=7; j>=0; j--) {
			clk1
			delay(600);
			pBuf[i] |= (dioR << j);
			clk0
			delay(600);
		}
		if(i == size - 1) 
		{
			dio1
		}
		else
		{
			dio0
		}
		delay(600);
		clk1
		delay(600);
		clk0
		delay(600);
		dio1
		delay(600);
	}
	dio1
}

void writeCmd(uint8_t cmd)
{
	startTransmit();
	writeData(cmd);
}

void delay(uint32_t delay) 
{
	volatile int i = 0;
	while(i < delay) {
		i++;
	}
}




