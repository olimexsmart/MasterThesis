#include "sicks3000.h"
//#include "SerialDevice.h"
#include <stdlib.h>
#define WAIT 60

int main() {
	int baudrate = 500000;
	const char mode[] = { '8','N','1',0 };
	char portname[10] = "COM10";	
	char terminalBuff[10000] = "\0";
	char formatBuff[30];

	// Decomment if needed to change default values
	//printf("Port name:\t");
	//scanf("%s", portname);
	//printf("Baudrate:\t");
	//scanf("%d", &baudrate);

	// Struct to hold data from the laser scanner
	SickS3000::LaserData ld;
	// Laser instance
	SickS3000 laser(portname, baudrate, mode);
	laser.Open();

	while (true) {
		if (laser.ReadLaser(ld)) {			
			// Print the data
			sprintf(formatBuff, "%u\n", ld.timestamp);
			strcat(terminalBuff, formatBuff);
			int i = 0;
			for (auto const & r : ld.ranges) {
				i++;
				if (i % 20 == 0)
					sprintf(formatBuff, "%.2f\n", r);
				else
					sprintf(formatBuff, "%.2f\t", r);

				strcat(terminalBuff, formatBuff);
			}
			system("cls");
			puts(terminalBuff);
			terminalBuff[0] = '\0';
		}
		/*else
			break;
			*/
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