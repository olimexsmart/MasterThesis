/*
*/

#include "SerialDevice.h"

/*
*/
SerialDevice::SerialDevice(int Device, int Baudrate, const char * Mode)
	: device(Device), mode(Mode), baudrate(Baudrate)
{
	// Some info print here if are that inclined
}

/*
*/
SerialDevice::~SerialDevice()
{
	ClosePort();
}

/*
*/
bool SerialDevice::OpenPort()
{
	if (RS232_OpenComport(device, baudrate, mode))
	{
		printf("Can not open comport\n");

		return true;
	}

	return false;
}

/*
*/
void SerialDevice::ClosePort()
{
	// Sear into apis how to release resources
	RS232_CloseComport(device);
}

/*
*/
bool SerialDevice::ReadPort(unsigned char *buffer, int bytes_to_read, int &bytes_read)
{
	bytes_read = RS232_PollComport(device, buffer, bytes_to_read);

	return bytes_to_read >= 0;
}


