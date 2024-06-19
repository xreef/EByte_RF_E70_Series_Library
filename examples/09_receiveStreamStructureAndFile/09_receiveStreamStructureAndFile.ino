/*
 * EBYTE RF E70
 * Receive a Stream (File) and structure to recreate the same origin file
 *
 * In continuous mode you must set ADDH ADDL and CHAN as the same value to create
 * a communication channel and send a Stream in the fastest way.
 *
 * I add an FTP server to download the file received.
 *
 * by Renzo Mischianti <https://www.mischianti.org>
 *
 * https://www.mischianti.org
 *
 * E70		  ----- WeMos D1 mini	----- esp32			----- Arduino Nano 33 IoT	----- Arduino MKR	----- Raspberry Pi Pico   ----- stm32               ----- ArduinoUNO
 * M0         ----- D6 				----- 23 			----- 4 					----- 2 			----- 9 			      ----- PB0 		       	----- 8 Volt div
 * M1         ----- D7 				----- 19 			----- 5 					----- 3 			----- 10 			      ----- PB1 		       	----- 7 Volt div
 * M1         ----- D8 				----- 22 			----- 6 					----- 4 			----- 11 			      ----- PB10 		      	----- 6 Volt div
 * TX         ----- D3 (PullUP)		----- TX2 (PullUP)	----- TX1 (PullUP)			----- 14 (PullUP)	----- 8 (PullUP)	      ----- PA2 TX2 (PullUP)    ----- 4 (PullUP)
 * RX         ----- D4 (PullUP)		----- RX2 (PullUP)	----- RX1 (PullUP)			----- 13 (PullUP)	----- 9 (PullUP)	      ----- PA3 RX2 (PullUP)    ----- 5 Volt div (PullUP)
 * AUX        ----- D5 (PullUP)		----- 18  (PullUP)	----- 2  (PullUP)			----- 0  (PullUP)	----- 2  (PullUP)	      ----- PA0  (PullUP)       ----- 3 (PullUP)
 * VCC        ----- 3.3v/5v			----- 3.3v/5v		----- 3.3v/5v				----- 3.3v/5v		----- 3.3v/5v		      ----- 3.3v/5v             ----- 3.3v/5v
 * GND        ----- GND				----- GND			----- GND					----- GND			----- GND			      ----- GND                 ----- GND
 *
 *	CONTINOUS can be emulated by set
 *	M0 = HIGH
 *	M1 = LOW
 *	M2 = LOW
 *
 */

#include "Arduino.h"
#include "RF_E70.h"

#include <WiFi.h>
#include "SPIFFS.h"

#include <SimpleFTPServer.h>

const char* ssid = "reef-casa-sopra";
const char* password = "aabbccdd77";


FtpServer ftpSrv;

void _callback(FtpOperation ftpOperation, unsigned int freeSpace, unsigned int totalSpace){
  switch (ftpOperation) {
    case FTP_CONNECT:
      Serial.println(F("FTP: Connected!"));
      break;
    case FTP_DISCONNECT:
      Serial.println(F("FTP: Disconnected!"));
      break;
    case FTP_FREE_SPACE_CHANGE:
      Serial.printf("FTP: Free space change, free %u of %u!\n", freeSpace, totalSpace);
      break;
    default:
      break;
  }
};
void _transferCallback(FtpTransferOperation ftpOperation, const char* name, unsigned int transferredSize){
  switch (ftpOperation) {
    case FTP_UPLOAD_START:
      Serial.println(F("FTP: Upload start!"));
      break;
    case FTP_UPLOAD:
      Serial.printf("FTP: Upload of file %s byte %u\n", name, transferredSize);
      break;
    case FTP_TRANSFER_STOP:
      Serial.println(F("FTP: Finish transfer!"));
      break;
    case FTP_TRANSFER_ERROR:
      Serial.println(F("FTP: Transfer error!"));
      break;
    default:
      break;
  }

  /* FTP_UPLOAD_START = 0,
   * FTP_UPLOAD = 1,
   *
   * FTP_DOWNLOAD_START = 2,
   * FTP_DOWNLOAD = 3,
   *
   * FTP_TRANSFER_STOP = 4,
   * FTP_DOWNLOAD_STOP = 4,
   * FTP_UPLOAD_STOP = 4,
   *
   * FTP_TRANSFER_ERROR = 5,
   * FTP_DOWNLOAD_ERROR = 5,
   * FTP_UPLOAD_ERROR = 5
   */
};


// ---------- esp8266 pins --------------
//RF_E70 e70ttl(RX, TX, AUX, M0, M1);  // Arduino RX <-- e70 TX, Arduino TX --> e70 RX
//RF_E70 e70ttl(D3, D4, D5, D7, D6); // Arduino RX <-- e70 TX, Arduino TX --> e70 RX AUX M0 M1
//RF_E70 e70ttl(D2, D3); // Config without connect AUX and M0 M1

//#include <SoftwareSerial.h>
//SoftwareSerial mySerial(D2, D3); // Arduino RX <-- e70 TX, Arduino TX --> e70 RX
//RF_E70 e70ttl(&mySerial, D5, D6, D7, D8); // AUX M0 M1
// -------------------------------------

// ---------- Arduino pins --------------
//RF_E70 e70ttl(4, 5, 3, 7, 6); // Arduino RX <-- e70 TX, Arduino TX --> e70 RX AUX M0 M1
//RF_E70 e70ttl(4, 5); // Config without connect AUX and M0 M1

//#include <SoftwareSerial.h>
//SoftwareSerial mySerial(4, 5); // Arduino RX <-- e70 TX, Arduino TX --> e70 RX
//RF_E70 e70ttl(&mySerial, 3, 7, 6); // AUX M0 M1
// -------------------------------------

// ------------- Arduino Nano 33 IoT -------------
// RF_E70 e70ttl(&Serial1, 2, 4, 5, 6); //  RX AUX M0 M1
// -------------------------------------------------

// ------------- Arduino MKR WiFi 1010 -------------
// RF_E70 e70ttl(&Serial1, 0, 2, 4); //  RX AUX M0 M1
// -------------------------------------------------

// ---------- esp32c3 pins --------------
// RF_E70 e70ttl(&Serial1,  1, 2, 3, 4,); //  RX AUX M0 M1

RF_E70 e70ttl(4, 5, &Serial1, 6, 1, 2, 3, UART_BPS_RATE_9600); //  esp32 RX <-- e70 TX, esp32 TX --> e70 RX AUX M0 M1
// -------------------------------------

// ---------- esp32 pins --------------
// RF_E70 e70ttl(&Serial2, 15, 23, 19, 22); //  RX AUX M0 M1

//RF_E70 e70ttl(&Serial2, 22, 4, 18, 21, 19, UART_BPS_RATE_9600); //  esp32 RX <-- e70 TX, esp32 TX --> e70 RX AUX M0 M1
// -------------------------------------

// ---------- Raspberry PI Pico pins --------------
// RF_E70 e70ttl(&Serial2, 2, 10, 11); //  RX AUX M0 M1
// -------------------------------------

// ---------------- STM32 --------------------
//HardwareSerial Serial2(USART2);   // PA3  (RX)  PA2  (TX)
//RF_E70 e70ttl(&Serial2, PA0, PB0, PB10); //  RX AUX M0 M1
// -------------------------------------------------

void printParameters(struct Configuration configuration);
struct FileInfoMsg {
	char filename[32];
	uint16_t size;
};

void setup() {
	Serial.begin(115200);
	delay(500);

	// Startup all pins and UART
	e70ttl.begin();

	e70ttl.setMode(MODE_CONTINUOUS_1);

	  WiFi.begin(ssid, password);
	  Serial.println("");

	  // Wait for connection
	  while (WiFi.status() != WL_CONNECTED) {
	    delay(500);
	    Serial.print(".");
	  }
	  Serial.println("");
	  Serial.print("Connected to ");
	  Serial.println(ssid);
	  Serial.print("IP address: ");
	  Serial.println(WiFi.localIP());
	  if (SPIFFS.begin(true)) {
	      ftpSrv.setCallback(_callback);
	      ftpSrv.setTransferCallback(_transferCallback);

	      Serial.println("SPIFFS opened!");
	      ftpSrv.begin("user","password");    //username, password for ftp.   (default 21, 50009 for PASV)
	  }

}

void loop() {
  ftpSrv.handleFTP();        //make sure in loop you call handleFTP()!!

    if (e70ttl.available()>0) {
    	Serial.println("Start!");

    	ResponseStructContainer rsc = e70ttl.receiveStreamMessage(sizeof(FileInfoMsg));
		Serial.println(rsc.status.getResponseDescription());

		struct FileInfoMsg fileInfoMsg = *(FileInfoMsg*) rsc.data;

		Serial.println(fileInfoMsg.filename);
		Serial.println(fileInfoMsg.size);

  	  // read the String message
    	File output = SPIFFS.open(fileInfoMsg.filename, FTP_FILE_WRITE_CREATE);

    	long size = 0;
    	while (e70ttl.available()>0 || size > fileInfoMsg.size) {
			while (e70ttl.available()>0) {
				if (output.write(e70ttl.read())==0) {Serial.println("ERROR WRITE!"); };
				size++;
			}
	    	delay(10);
    	}

    	output.close();

    	Serial.println("Complete!");
    }

}
