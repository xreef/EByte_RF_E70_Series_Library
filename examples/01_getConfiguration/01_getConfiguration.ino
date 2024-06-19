/*
 * RF E70
 * Get configuration.
 * You must uncommend the correct constructor.
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
 *	Configuration can be emulated by set
 *	M0 = HIGH
 *	M1 = HIGH
 *	M2 = LOW
 *
 */

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

// ---------- esp32 s3 pins --------------
//RF_E70 e70ttl(&Serial2,  4, 5, 6, 7, UART_BPS_RATE_9600);
// -------------------------------------

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

void printParameters(struct Configuration configuration);
void printModuleInformation(struct ModuleInformation moduleInformation);

void setup() {
	Serial.begin(9600);
#if defined(ARDUINO_ARCH_STM32) || defined(__STM32F1__) || defined(__STM32F4__)
	Serial.dtr(false);
#endif

	while(!Serial){};
	delay(500);

	Serial.println("INIT!!");

	// Startup all pins and UART
	e70ttl.begin();

	ResponseStructContainer c;
	c = e70ttl.getConfiguration();
	// It's important get configuration pointer before all other operation
	Configuration configuration = *(Configuration*) c.data;
	Serial.println(c.status.getResponseDescription());
	Serial.println(c.status.code);

	printParameters(configuration);

	ResponseStructContainer cMi;
	cMi = e70ttl.getModuleInformation();
	// It's important get information pointer before all other operation
	ModuleInformation mi = *(ModuleInformation*)cMi.data;

	Serial.println(cMi.status.getResponseDescription());
	Serial.println(cMi.status.code);

	printModuleInformation(mi);

	c.close();
	cMi.close();
}

void loop() {

}
void printParameters(struct Configuration configuration) {
	Serial.println("----------------------------------------");

	Serial.print(F("Configuration packet: "));
    byte* byteArray = (byte*)&configuration;  // Cast the address of config to a byte pointer
    for (int i = 0; i < sizeof(Configuration); i++) {
        if (byteArray[i] < 16) {
            Serial.print('0');  // Print a leading zero for single-digit hex values
        }
        Serial.print(byteArray[i], HEX);  // Print each byte of the struct in hexadecimal
        Serial.print(" ");
    }
    Serial.println(F(" "));

	Serial.print(F("HEAD : "));  Serial.print(configuration.COMMAND, HEX);Serial.print(" ");
	Serial.println(F(" "));
	Serial.print(F("AddH : "));  Serial.println(configuration.ADDH, HEX);
	Serial.print(F("AddL : "));  Serial.println(configuration.ADDL, HEX);
	Serial.println(F(" "));
	Serial.print(F("Chan : "));  Serial.print(configuration.CHAN.CHAN, DEC); Serial.print(" -> "); Serial.println(configuration.CHAN.getChannelDescription());
	Serial.println(F(" "));
	Serial.print(F("SpeedParityBit     : "));  Serial.print(configuration.SPED.uartParity, BIN);Serial.print(" -> "); Serial.println(configuration.SPED.getUARTParityDescription());
	Serial.print(F("SpeedUARTDatte     : "));  Serial.print(configuration.SPED.uartBaudRate, BIN);Serial.print(" -> "); Serial.println(configuration.SPED.getUARTBaudRateDescription());
	Serial.print(F("SpeedAirDataRate   : "));  Serial.print(configuration.SPED.airDataRate, BIN);Serial.print(" -> "); Serial.println(configuration.SPED.getAirDataRateDescription());
	Serial.println(F(" "));
	Serial.print(F("OptionFECPacketSett: "));  Serial.print(configuration.OPTION.fec, BIN);Serial.print(" -> "); Serial.println(configuration.OPTION.getFECDescription());
	Serial.print(F("OptionTranPower    : "));  Serial.print(configuration.OPTION.transmissionPower, BIN);Serial.print(" -> "); Serial.println(configuration.OPTION.getTransmissionPowerDescription());
	Serial.print(F("OptionIODrive: "));  Serial.print(configuration.OPTION.ioDriveMode, BIN);Serial.print(" -> "); Serial.println(configuration.OPTION.getIODroveModeDescription());
	Serial.print(F("OptionFixedTransmission: "));  Serial.print(configuration.OPTION.fixedTransmission, BIN);Serial.print(" -> "); Serial.println(configuration.OPTION.getFixedTransmissionDescription());
	Serial.print(F("OptionWirelessWakeUPTime: "));  Serial.print(configuration.OPTION.wirelessWakeupTime, BIN);Serial.print(" -> "); Serial.println(configuration.OPTION.getWirelessWakeUPTimeDescription());


	Serial.println("----------------------------------------");
}
void printModuleInformation(struct ModuleInformation moduleInformation) {
	Serial.println("----------------------------------------");
	Serial.print(F("HEAD: "));  Serial.print(moduleInformation.COMMAND, HEX);Serial.print(" ");

	Serial.print(F("Model no.: "));  Serial.println(moduleInformation.model, HEX);
	Serial.print(F("Version  : "));  Serial.println(moduleInformation.version, HEX);
	Serial.print(F("Features : "));  Serial.println(moduleInformation.features1, HEX);
	Serial.print(F("Features : "));  Serial.println(moduleInformation.features2, HEX);
	Serial.print(F("Features : "));  Serial.println(moduleInformation.features3, HEX);
	Serial.print(F("Features : "));  Serial.println(moduleInformation.features4, HEX);
	Serial.println("----------------------------------------");
}

