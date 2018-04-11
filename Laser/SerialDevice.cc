/*
*/

#include "SerialDevice.h"

/*
*/
SerialDevice::SerialDevice(const char * Device, int Baudrate, const char * Mode)
	: device(RS232_GetPortnr(Device)), mode(Mode), baudrate(Baudrate)
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

		return false;
	}

	// Flush buffers to make sure are empty
	RS232_flushRXTX(device);

	return true;
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

bool SerialDevice::WritePort(unsigned char * buffer, int size) {
	
	return RS232_SendBuf(device, buffer, size) != -1;
}