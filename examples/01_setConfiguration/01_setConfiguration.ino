/*
 * LoRa E70
 * Set configuration.
 *
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

void printParameters(struct Configuration configuration);
void printModuleInformation(struct ModuleInformation moduleInformation);

void setup() {
	Serial.begin(9600);
#if defined(ARDUINO_ARCH_STM32) || defined(__STM32F1__) || defined(__STM32F4__)
	Serial.dtr(false);
#endif

	while(!Serial){};
	delay(500);

	Serial.println();


	// Startup all pins and UART
	e70ttl.begin();

	ResponseStructContainer c;
	c = e70ttl.getConfiguration();
	// It's important get configuration pointer before all other operation
	Configuration configuration = *(Configuration*) c.data;
	Serial.println(c.status.getResponseDescription());
	Serial.println(c.status.code);

	printParameters(configuration);

//	----------------------- DEFAULT TRANSPARENT -----------------------
	configuration.ADDL = 0x00;  // First part of address
	configuration.ADDH = 0x00; // Second part


	configuration.SPED.uartBaudRate = UART_BPS_9600; // Serial baud rate
	configuration.SPED.airDataRate = AIR_DATA_RATE_000_025; // Air baud rate
	configuration.SPED.uartParity = MODE_00_8N1; // Parity bit

	configuration.CHAN.CHAN = 4;
	configuration.CHAN.subPacketSetting = SPS_0064_010;

	configuration.OPTION.fec = FEC_1_ON; // Packet size
	configuration.OPTION.fixedTransmission = FT_TRANSPARENT_TRANSMISSION; // Need to send special command
	configuration.OPTION.transmissionPower = POWER_22; // Device power
	configuration.OPTION.ioDriveMode = IO_D_MODE_PUSH_PULLS_PULL_UPS; // IO Drive
	configuration.OPTION.wirelessWakeupTime = WAKE_UP_1000; // Wake up time
//	----------------------- FIXED SENDER -----------------------
//	configuration.ADDL = 0x02;  // First part of address
//	configuration.ADDH = 0x00; // Second part
//
//
//	configuration.SPED.uartBaudRate = UART_BPS_9600; // Serial baud rate
//	configuration.SPED.airDataRate = AIR_DATA_RATE_000_025; // Air baud rate
//	configuration.SPED.uartParity = MODE_00_8N1; // Parity bit
//
//	configuration.CHAN.CHAN = 4;
//	configuration.CHAN.subPacketSetting = SPS_0064_010;
//
//	configuration.OPTION.fec = FEC_1_ON; // Packet size
//	configuration.OPTION.fixedTransmission = FT_FIXED_TRANSMISSION; // Need to send special command
//	configuration.OPTION.transmissionPower = POWER_22; // Device power
//	configuration.OPTION.ioDriveMode = IO_D_MODE_PUSH_PULLS_PULL_UPS; // IO Drive
//	configuration.OPTION.wirelessWakeupTime = WAKE_UP_1000; // Wake up time
//
//	----------------------- FIXED RECEIVER -----------------------
//	configuration.ADDL = 0x03;  // First part of address
//	configuration.ADDH = 0x00; // Second part
//
//
//	configuration.SPED.uartBaudRate = UART_BPS_9600; // Serial baud rate
//	configuration.SPED.airDataRate = AIR_DATA_RATE_000_025; // Air baud rate
//	configuration.SPED.uartParity = MODE_00_8N1; // Parity bit
//
//	configuration.CHAN.CHAN = 4;
//	configuration.CHAN.subPacketSetting = SPS_0064_010;
//
//	configuration.OPTION.fec = FEC_1_ON; // Packet size
//	configuration.OPTION.fixedTransmission = FT_FIXED_TRANSMISSION; // Need to send special command
//	configuration.OPTION.transmissionPower = POWER_22; // Device power
//	configuration.OPTION.ioDriveMode = IO_D_MODE_PUSH_PULLS_PULL_UPS; // IO Drive
//	configuration.OPTION.wirelessWakeupTime = WAKE_UP_1000; // Wake up time
//
//	----------------------- CONTINOUS RECEIVER & SENDER -----------------------
//	configuration.ADDL = 0x01;  // First part of address
//	configuration.ADDH = 0x00; // Second part
//
//
//	configuration.SPED.uartBaudRate = UART_BPS_9600; // Serial baud rate
//	configuration.SPED.airDataRate = AIR_DATA_RATE_000_025; // Air baud rate
//	configuration.SPED.uartParity = MODE_00_8N1; // Parity bit
//
//	configuration.CHAN.CHAN = 4;
//	configuration.CHAN.subPacketSetting = SPS_0064_010;
//
//	configuration.OPTION.fec = FEC_1_ON; // Packet size
//	configuration.OPTION.fixedTransmission = FT_FIXED_TRANSMISSION; // Need to send special command
//	configuration.OPTION.transmissionPower = POWER_22; // Device power
//	configuration.OPTION.ioDriveMode = IO_D_MODE_PUSH_PULLS_PULL_UPS; // IO Drive
//	configuration.OPTION.wirelessWakeupTime = WAKE_UP_1000; // Wake up time
//
//	----------------------- BROADCAST MESSAGE 1 -----------------------
//	configuration.ADDL = 0x04;  // First part of address
//	configuration.ADDH = 0x00; // Second part
//
//
//	configuration.SPED.uartBaudRate = UART_BPS_9600; // Serial baud rate
//	configuration.SPED.airDataRate = AIR_DATA_RATE_000_025; // Air baud rate
//	configuration.SPED.uartParity = MODE_00_8N1; // Parity bit
//
//	configuration.CHAN.CHAN = 4;
//	configuration.CHAN.subPacketSetting = SPS_0064_010;
//
//	configuration.OPTION.fec = FEC_1_ON; // Packet size
//	configuration.OPTION.fixedTransmission = FT_FIXED_TRANSMISSION; // Need to send special command
//	configuration.OPTION.transmissionPower = POWER_22; // Device power
//	configuration.OPTION.ioDriveMode = IO_D_MODE_PUSH_PULLS_PULL_UPS; // IO Drive
//	configuration.OPTION.wirelessWakeupTime = WAKE_UP_1000; // Wake up time
//	----------------------- BROADCAST MESSAGE 2 -----------------------
//	configuration.ADDL = 0x05;  // First part of address
//	configuration.ADDH = 0x00; // Second part
//
//
//	configuration.SPED.uartBaudRate = UART_BPS_9600; // Serial baud rate
//	configuration.SPED.airDataRate = AIR_DATA_RATE_000_025; // Air baud rate
//	configuration.SPED.uartParity = MODE_00_8N1; // Parity bit
//
//	configuration.CHAN.CHAN = 4;
//	configuration.CHAN.subPacketSetting = SPS_0064_010;
//
//	configuration.OPTION.fec = FEC_1_ON; // Packet size
//	configuration.OPTION.fixedTransmission = FT_FIXED_TRANSMISSION; // Need to send special command
//	configuration.OPTION.transmissionPower = POWER_22; // Device power
//	configuration.OPTION.ioDriveMode = IO_D_MODE_PUSH_PULLS_PULL_UPS; // IO Drive
//	configuration.OPTION.wirelessWakeupTime = WAKE_UP_1000; // Wake up time
//	----------------------- BROADCAST MESSAGE 3 -----------------------
//	configuration.ADDL = 0x05;  // First part of address
//	configuration.ADDH = 0x00; // Second part
//
//
//	configuration.SPED.uartBaudRate = UART_BPS_9600; // Serial baud rate
//	configuration.SPED.airDataRate = AIR_DATA_RATE_000_025; // Air baud rate
//	configuration.SPED.uartParity = MODE_00_8N1; // Parity bit
//
//	configuration.CHAN.CHAN = 4;
//	configuration.CHAN.subPacketSetting = SPS_0064_010;
//
//	configuration.OPTION.fec = FEC_1_ON; // Packet size
//	configuration.OPTION.fixedTransmission = FT_FIXED_TRANSMISSION; // Need to send special command
//	configuration.OPTION.transmissionPower = POWER_22; // Device power
//	configuration.OPTION.ioDriveMode = IO_D_MODE_PUSH_PULLS_PULL_UPS; // IO Drive
//	configuration.OPTION.wirelessWakeupTime = WAKE_UP_1000; // Wake up time
//	----------------------- MONITORING -----------------------
//	configuration.ADDL = BROADCAST_ADDRESS;  // First part of address
//	configuration.ADDH = BROADCAST_ADDRESS; // Second part
//
//
//	configuration.SPED.uartBaudRate = UART_BPS_9600; // Serial baud rate
//	configuration.SPED.airDataRate = AIR_DATA_RATE_000_025; // Air baud rate
//	configuration.SPED.uartParity = MODE_00_8N1; // Parity bit
//
//	configuration.CHAN.CHAN = 4;
//	configuration.CHAN.subPacketSetting = SPS_0064_010;
//
//	configuration.OPTION.fec = FEC_1_ON; // Packet size
//	configuration.OPTION.fixedTransmission = FT_FIXED_TRANSMISSION; // Need to send special command
//	configuration.OPTION.transmissionPower = POWER_22; // Device power
//	configuration.OPTION.ioDriveMode = IO_D_MODE_PUSH_PULLS_PULL_UPS; // IO Drive
//	configuration.OPTION.wirelessWakeupTime = WAKE_UP_1000; // Wake up time

	// Set configuration changed and set to not hold the configuration
	ResponseStatus rs = e70ttl.setConfiguration(configuration, WRITE_CFG_PWR_DWN_SAVE);
	Serial.println(rs.getResponseDescription());
	Serial.println(rs.code);

	c = e70ttl.getConfiguration();
	// It's important get configuration pointer before all other operation
	configuration = *(Configuration*) c.data;
	Serial.println(c.status.getResponseDescription());
	Serial.println(c.status.code);

	printParameters(configuration);
	c.close();
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
	Serial.print(F("Packet size : "));  Serial.print(configuration.CHAN.subPacketSetting, BIN); Serial.print(" -> "); Serial.println(configuration.CHAN.getSubPacketSetting());
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
