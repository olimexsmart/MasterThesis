/*
	https://www.teuniz.net/RS-232/
*/

#ifndef __SERIALDEV_H
#define __SERIALDEV_H

#include <stdio.h>
#include <string>
#include "rs232.h"

class SerialDevice
{
private:
	//Device's name
	int device;
	//Parity for input and output: EVEN, ODD, NONE
	const char * mode;
	//BaudRate: 9600, 19200, 38400, 115200, 500000
	const int baudrate;


	int serial_port_; // File descriptor

public:
	SerialDevice(const char * Device, int Baudrate, const char * Mode);
	virtual ~SerialDevice();

	bool OpenPort();
	void ClosePort();
	bool ReadPort(unsigned char *result, int bytes_to_read, int &bytes_read);	

private:	

};

#endif
