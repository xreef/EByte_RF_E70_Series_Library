/*
 * EBYTE LoRa E70
 * Stay in sleep mode and wait a wake up WOR message
 *
 * You must configure the address with 0 2 23 (FIXED RECEIVER configuration)
 * and pay attention that WOR period must be the same of sender
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
 *	Power saving can be emulated by set
 *	M0 = LOW
 *	M1 = HIGH
 *	M2 = HIGH
 *
 */

// With FIXED RECEIVER configuration
#define DESTINATION_ADDL 2

#define AUX_PIN 15

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

 bool interruptExecuted = false;
#ifdef ESP32
 void IRAM_ATTR wakeUp() {
	 // Do not use Serial on interrupt callback
	 interruptExecuted = true;
	 detachInterrupt(AUX_PIN);
 }
#elif define(ESP8266)
 ICACHE_RAM_ATTR void wakeUp() {
	 // Do not use Serial on interrupt callback
	 interruptExecuted = true;
	 detachInterrupt(AUX_PIN);
 }
#else
 void wakeUp() {
 	 // Do not use Serial on interrupt callback
 	 interruptExecuted = true;
 	 detachInterrupt(AUX_PIN);
  }
#endif

//The setup function is called once at startup of the sketch
void setup() {
	Serial.begin(9600);
	while (!Serial) {
		; // wait for serial port to connect. Needed for native USB
	}
	delay(100);

	e70ttl.begin();

	e70ttl.setMode(MODE_POWER_SAVING_6);

	delay(1000);
	Serial.println();
	Serial.println("Start sleep!");
	delay(100);
    attachInterrupt(AUX_PIN, wakeUp, FALLING);
}

// The loop function is called in an endless loop
void loop() {
	if (e70ttl.available() > 1) {
		Serial.println("Message arrived!");
		ResponseContainer rs = e70ttl.receiveMessage();
		// First of all get the data
		String message = rs.data;

		Serial.println(rs.status.getResponseDescription());
		Serial.println(message);

		// Work only with full connection
		e70ttl.setMode(MODE_SUB_PACKAGE_2);

		delay(1000);

		ResponseStatus rsSend = e70ttl.sendFixedMessage(0, DESTINATION_ADDL, 23, "We have received the message!");
		// Check If there is some problem of succesfully send
		Serial.println(rsSend.getResponseDescription());
	}

	if(interruptExecuted) {
		Serial.println("WakeUp Callback, AUX pin go LOW and start receive message!");
		Serial.flush();
		interruptExecuted = false;
	}
}
