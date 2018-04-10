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
	const std::string device_;	
	//Parity for input and output: EVEN, ODD, NONE
	const std::string parity_;	
	//BaudRate: 9600, 19200, 38400, 115200, 500000
	const int baudrate_;
	//Character size mask. Values are CS5, CS6, CS7, or CS8.
	const int datasize_;

	int serial_port_; // File descriptor

public:
	SerialDevice(const char *device, int baudrate,const char *parity, int datasize);	
	virtual ~SerialDevice();
	
	bool OpenPort();
	bool ClosePort();
	bool ReadPort( char *result, int bytes_to_read, int &bytes_read );

	const char* GetDevice() const { return device_.c_str(); }
	
private:
	//!	Set serial communication speed.
	bool SetTermSpeed(int speed);

};

#endif
