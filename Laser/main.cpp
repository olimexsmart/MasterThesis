#include "sicks3000.h"
//#include "SerialDevice.h"
#include <stdlib.h>
#define WAIT 50

int main() {
	char TXbuffer[100] = "10000";
	char RXbuffer[10000];
	int baudrate = 500000;
	const char mode[] = { '8','N','1',0 };
	char portname[10] = "COM10";
	int bytesRead;

	// Decomment if needed to change default values
	//printf("Port name:\t");
	//scanf("%s", portname);
	//printf("Baudrate:\t");
	//scanf("%d", &baudrate);

	// Struct to hold data from the laser scanner
	SickS3000::LaserData ld;
	// Laser instance
	SickS3000 laser(portname, baudrate, mode);

	while (true) {
		if (laser.ReadLaser(ld)) {
			// Print the data
			printf("%u\n", ld.timestamp);
			int i = 0;
			for (auto const & r : ld.ranges) {
				i++;
				if (i % 10 == 0)
					printf("\n");

				printf("%.2f\t", r);
			}
		}
		else
			break;

		Sleep(WAIT);
	}

	return 0;
}



/* // Main to test serial port with an Arduino and prime number test sketch
int main(void) {
	char TXbuffer[100] = "10000";
	char RXbuffer[10000];
	int baudrate = 57600;
	const char mode[] = { '8','N','1',0 };
	char portname[10] = "COM7";
	int bytesRead = 1;
	char c;

	//printf("Port name:\t");
	//scanf("%s", portname);
	//printf("Baudrate:\t");
	//scanf("%d", &baudrate);


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
*/