/*
 * EBYTE RF E70
 * send a structured message to the device that have ADDH ADDL CHAN -> 0 DESTINATION_ADDL 23
 *
 * The receiver read the first part of the packet and undestand the type.
 * If the type is HUMI read the message and the humidity as int
 * else read the temperature as float.
 * I use byte array because some microcontroller can have different size for float
 *
 * You must configure 2 device: one as SENDER (with FIXED SENDER config) and uncomment the relative
 * define with the correct DESTINATION_ADDL, and one as RECEIVER (with FIXED RECEIVER config)
 * and uncomment the relative define with the correct DESTINATION_ADDL.
 *
 * Write a string on serial monitor or reset to resend default value.
 *
 * You must uncommend the correct constructor and set the correct AUX_PIN define.
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

#define MESSAGE_TYPE "HUMI"

// With FIXED SENDER configuration
//#define DESTINATION_ADDL 3
//#define ROOM "Kitchen"

// With FIXED RECEIVER configuration
#define DESTINATION_ADDL 2
#define ROOM "Bathroo"

#include "Arduino.h"
#include "RF_E70.h"

// ---------- esp8266 pins --------------
//RF_E70 e70ttl(RX, TX, AUX, M0, M1, M2);  // Arduino RX <-- e70 TX, Arduino TX --> e70 RX
//RF_E70 e70ttl(D3, D4, D5, D7, D6, D7); // Arduino RX <-- e70 TX, Arduino TX --> e70 RX AUX M0 M1
//RF_E70 e70ttl(D2, D3); // Config without connect AUX and M0 M1

//#include <SoftwareSerial.h>
//SoftwareSerial mySerial(D2, D3); // Arduino RX <-- e70 TX, Arduino TX --> e70 RX
//RF_E70 e70ttl(&mySerial, D5, D6, D7, D8); // AUX M0 M1
// -------------------------------------

// ---------- Arduino pins --------------
//RF_E70 e70ttl(4, 5, 3, 8, 7, 6); // Arduino RX <-- e70 TX, Arduino TX --> e70 RX AUX M0 M1
//RF_E70 e70ttl(4, 5); // Config without connect AUX and M0 M1

//#include <SoftwareSerial.h>
//SoftwareSerial mySerial(4, 5); // Arduino RX <-- e70 TX, Arduino TX --> e70 RX
//RF_E70 e70ttl(&mySerial, 3, 8, 7, 6); // AUX M0 M1
// -------------------------------------

// ------------- Arduino Nano 33 IoT -------------
// RF_E70 e70ttl(&Serial1, 2, 4, 5, 6); //  RX AUX M0 M1
// -------------------------------------------------

// ------------- Arduino MKR WiFi 1010 -------------
// RF_E70 e70ttl(&Serial1, 0, 2, 3, 4); //  RX AUX M0 M1
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
// RF_E70 e70ttl(&Serial2, 2, 10, 11, 12); //  RX AUX M0 M1
// -------------------------------------

// ---------------- STM32 --------------------
// HardwareSerial Serial2(USART2);   // PA3  (RX)  PA2  (TX)
// RF_E70 e70ttl(&Serial2, PA0, PB0, PB1, PB10); //  RX AUX M0 M1
// -------------------------------------------------

 struct MessageTemperature {
	char type[5];
	char message[8];
	byte temperature[4];
};

struct MessageHumidity {
	char type[5];
	char message[8];
	byte humidity;
};

void setup() {
	Serial.begin(9600);
	delay(500);

	// Startup all pins and UART
	e70ttl.begin();

	Serial.println("Hi, I'm going to send message!");

	struct MessageHumidity message = { "HUMI", ROOM, 80 };
	// Send message
	ResponseStatus rs = e70ttl.sendFixedMessage(0, DESTINATION_ADDL, 23, &message, sizeof(MessageHumidity));
	// Check If there is some problem of succesfully send
	Serial.println(rs.getResponseDescription());

	struct MessageTemperature messageT = { "TEMP", ROOM, 0 };
	*(float*)(messageT.temperature) = 19.2;

	// Send message
	ResponseStatus rsT = e70ttl.sendFixedMessage(0, DESTINATION_ADDL, 23, &messageT, sizeof(MessageTemperature));
	// Check If there is some problem of succesfully send
	Serial.println(rsT.getResponseDescription());
}

void loop() {
	// If something available
	if (e70ttl.available() > 1) {
		// read the String message
		char type[5]; // first part of structure
		ResponseContainer rs = e70ttl.receiveInitialMessage(sizeof(type));
		String typeStr = rs.data;

		// Is something goes wrong print error
		if (rs.status.code != 1) {
			Serial.println(rs.status.getResponseDescription());
		} else {
			Serial.println(typeStr);
			if (typeStr == "TEMP") {
				struct MessageTemperaturePartial {
					char message[8];
					byte temperature[4];
				};

				ResponseStructContainer rsc = e70ttl.receiveMessage( sizeof(MessageTemperaturePartial));
				struct MessageTemperaturePartial message = *(MessageTemperaturePartial*) rsc.data;

				Serial.println(*(float*)(message.temperature));
				Serial.println(message.message);
				rsc.close();
			} else if (typeStr == "HUMI") {
				struct MessageHumidityPartial {
					char message[8];
					byte humidity;
				};

				ResponseStructContainer rsc = e70ttl.receiveMessage(sizeof(MessageHumidityPartial));
				struct MessageHumidityPartial message = *(MessageHumidityPartial*) rsc.data;

				Serial.println(message.humidity);
				Serial.println(message.message);
				rsc.close();
			} else {
				Serial.println("Something goes wrong!!");
			}
		}
	}
 	if (Serial.available()) {
 		if (MESSAGE_TYPE == "HUMI") {
 			struct MessageHumidity message = { "HUMI", ROOM, 0 };
 			message.humidity = Serial.parseInt();

 	 		// Send message
 	 		ResponseStatus rs = e70ttl.sendFixedMessage(0, DESTINATION_ADDL, 23, &message, sizeof(MessageHumidity));
 	 		// Check If there is some problem of succesfully send
 	 		Serial.println(rs.getResponseDescription());
 		} else {
 			struct MessageTemperature message = { "TEMP", ROOM, 0 };
 			*(float*)(message.temperature) = Serial.parseFloat();

 	 		// Send message
 	 		ResponseStatus rs = e70ttl.sendFixedMessage(0, DESTINATION_ADDL, 23, &message, sizeof(MessageTemperature));
 	 		// Check If there is some problem of succesfully send
 	 		Serial.println(rs.getResponseDescription());
 		}
 	}
}
