#include <cstdio>
#include "SerialDevice.h"
#include <stdlib.h>

int main(void) {
	char TXbuffer[100] = "10000";
	char RXbuffer[10000];
	int baudrate = 57600;
	const char mode[] = { '8','N','1',0 };
	char portname[10] = "COM7";
	int bytesRead = 1;
	char c;
	/*
	printf("Port name:\t");
	scanf("%s", portname);
	printf("Baudrate:\t");
	scanf("%d", &baudrate);
	*/

	SerialDevice sd(portname, baudrate, mode);

	if (!sd.OpenPort()) {
		printf("Error opening port");
		return -1;
	}


	while (true) {

		if (bytesRead == 0) {
			scanf("%s", TXbuffer);
			sd.WritePort((unsigned char *)TXbuffer, strlen(TXbuffer));
		}

		sd.ReadPort((unsigned char *)RXbuffer, 1000, bytesRead);
		RXbuffer[bytesRead] = '\0';
		printf(RXbuffer);

		Sleep(100);
	}


	return 0;
}