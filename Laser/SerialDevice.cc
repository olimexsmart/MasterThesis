/*
*  Copyright (c) 2012, Robotnik Automation, SLL
* 
*   This file is part of sick-s3000-ros-pkg.
*
*   sick-s3000-ros-pkg is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/
/** \file SerialDevice.cc
 * \author Robotnik Automation S.L.L.
 * \version 1.1
 * \date    2009
 *
 * \brief SerialDevice Class 
 * (C) 2009 Robotnik Automation, SLL
 * Class to manage a serial connection
*/

#include "SerialDevice.h"




/*! \fn SerialDevice::SerialDevice()
 	* Constructor by default
*/
SerialDevice::SerialDevice(const char *device, int baudrate, const char *parity, int datasize)
	: device_(device), parity_(parity), baudrate_(baudrate), datasize_(datasize)
{
	// Some info print here if are that inclined
}

/*! \fn SerialDevice::~SerialDevice()
 	* Destructor by default
*/
SerialDevice::~SerialDevice()
{
	ClosePort();
}

/*! \fn int SerialDevice::OpenPort2(char *dev)
 	* Opens serial port for communication
*/
bool SerialDevice::OpenPort()
{
	
	
}

/*! \fn int SerialDevice::ClosePort()
 	* Closes serial port
*/
bool SerialDevice::ClosePort()
{
	
}

/*!	\fn int SerialDevice::ReadPort(char *buffer, int *bytes_read, int bytes_to_read)
 * @brief Reads serial port
 * @param buffer as char *, output buffer
 * @param bytes_read as int, number of read bytes
 * @param bytes_to_read as *int, number of desired bytes to read
 * @return OK
 * @return NOT_INITIALIZED
 * @return ERROR
*/
bool SerialDevice::ReadPort(char *buffer, int bytes_to_read, int &bytes_read)
{
	
}

/*!	\fn int SerialDevice::SetTermSpeed(int speed)
	* Set serial communication speed.
	* Valid values: 9600, 19200, 38400, 115200, 500000
	* @return false if error occured
*/
bool SerialDevice::SetTermSpeed(int baudrate)
{

}
