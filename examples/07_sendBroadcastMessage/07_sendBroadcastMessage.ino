/*
 * EBYTE LoRa E70
 *
 * Send a string message to all devices of the Channel CHAN 23
 *
 * Write a string on serial monitor or reset to send the string to all device on channel 23.
 *
 * Send a fixed message, you must check that the transmitter and receiver have different
 * ADDL or ADDH, check the configuration down
 *
 * For the test you can use
 *  - BROADCAST MESSAGE 1
 *  - BROADCAST MESSAGE 2
 *  - BROADCAST MESSAGE 3
 *
 * and uncomment #define ENABLE_RSSI true in this sketch
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
 *	Sub-packet can be emulated by set
 *	M0 = LOW
 *	M1 = HIGH
 *	M2 = LOW
 *	Continuous
 *	M0 = HIGH
 *	M1 = LOW
 *	M2 = LOW
 *
 */

#include "Arduino.h"
#include "LoRa_E70.h"

// ---------- esp8266 pins --------------
//LoRa_E70 e70ttl(RX, TX, AUX, M0, M1, M2);  // Arduino RX <-- e70 TX, Arduino TX --> e70 RX
//LoRa_E70 e70ttl(D3, D4, D5, D7, D6, D7); // Arduino RX <-- e70 TX, Arduino TX --> e70 RX AUX M0 M1
//LoRa_E70 e70ttl(D2, D3); // Config without connect AUX and M0 M1

//#include <SoftwareSerial.h>
//SoftwareSerial mySerial(D2, D3); // Arduino RX <-- e70 TX, Arduino TX --> e70 RX
//LoRa_E70 e70ttl(&mySerial, D5, D6, D7, D8); // AUX M0 M1
// -------------------------------------

// ---------- Arduino pins --------------
//LoRa_E70 e70ttl(4, 5, 3, 8, 7, 6); // Arduino RX <-- e70 TX, Arduino TX --> e70 RX AUX M0 M1
//LoRa_E70 e70ttl(4, 5); // Config without connect AUX and M0 M1

//#include <SoftwareSerial.h>
//SoftwareSerial mySerial(4, 5); // Arduino RX <-- e70 TX, Arduino TX --> e70 RX
//LoRa_E70 e70ttl(&mySerial, 3, 8, 7, 6); // AUX M0 M1
// -------------------------------------

// ------------- Arduino Nano 33 IoT -------------
// LoRa_E70 e70ttl(&Serial1, 2, 4, 5, 6); //  RX AUX M0 M1
// -------------------------------------------------

// ------------- Arduino MKR WiFi 1010 -------------
// LoRa_E70 e70ttl(&Serial1, 0, 2, 3, 4); //  RX AUX M0 M1
// -------------------------------------------------

// ---------- esp32c3 pins --------------
// LoRa_E70 e70ttl(&Serial1,  1, 2, 3, 4,); //  RX AUX M0 M1

LoRa_E70 e70ttl(4, 5, &Serial1, 6, 1, 2, 3, UART_BPS_RATE_9600); //  esp32 RX <-- e70 TX, esp32 TX --> e70 RX AUX M0 M1
// -------------------------------------

// ---------- esp32 pins --------------
// LoRa_E70 e70ttl(&Serial2, 15, 23, 19, 22); //  RX AUX M0 M1

//LoRa_E70 e70ttl(&Serial2, 22, 4, 18, 21, 19, UART_BPS_RATE_9600); //  esp32 RX <-- e70 TX, esp32 TX --> e70 RX AUX M0 M1
// -------------------------------------

// ---------- Raspberry PI Pico pins --------------
// LoRa_E70 e70ttl(&Serial2, 2, 10, 11, 12); //  RX AUX M0 M1
// -------------------------------------

// ---------------- STM32 --------------------
// HardwareSerial Serial2(USART2);   // PA3  (RX)  PA2  (TX)
// LoRa_E70 e70ttl(&Serial2, PA0, PB0, PB1, PB10); //  RX AUX M0 M1
// -------------------------------------------------

void setup() {
  Serial.begin(9600);
  delay(500);

  // Startup all pins and UART
  e70ttl.begin();

  Serial.println("Hi, I'm going to send message!");

  // Send message
  ResponseStatus rs = e70ttl.sendBroadcastFixedMessage(23, "Hello, world?");
  // Check If there is some problem of succesfully send
  Serial.println(rs.getResponseDescription());
}

void loop() {
	// If something available
  if (e70ttl.available()>1) {
	  // read the String message
#ifdef ENABLE_RSSI
	ResponseContainer rc = e70ttl.receiveMessageRSSI();
#else
	ResponseContainer rc = e70ttl.receiveMessage();
#endif
	// Is something goes wrong print error
	if (rc.status.code!=1){
		Serial.println(rc.status.getResponseDescription());
	}else{
		// Print the data received
		Serial.println(rc.status.getResponseDescription());
		Serial.println(rc.data);
#ifdef ENABLE_RSSI
		Serial.print("RSSI: "); Serial.println(rc.rssi, DEC);
#endif
	}
  }
  if (Serial.available()) {
	  String input = Serial.readString();
	  ResponseStatus rs = e70ttl.sendBroadcastFixedMessage(23, input);
	  // Check If there is some problem of succesfully send
	  Serial.println(rs.getResponseDescription());
  }
}

