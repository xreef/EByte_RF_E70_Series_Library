/*
 * EBYTE LoRa E70 Series
 *
 * AUTHOR:  Renzo Mischianti
 * VERSION: 0.0.10
 *
 * https://www.mischianti.org
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2022 Renzo Mischianti www.mischianti.org All right reserved.
 *
 * You may copy, alter and reuse this code in any way you like, but please leave
 * reference to www.mischianti.org in your comments if you redistribute this code.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef LoRa_E70_h
#define LoRa_E70_h

#if !defined(ARDUINO_ARCH_STM32) && !defined(ESP32) && !defined(ARDUINO_ARCH_SAMD) && !defined(ARDUINO_ARCH_MBED) && !defined(__STM32F1__) && !defined(__STM32F4__)
	#define ACTIVATE_SOFTWARE_SERIAL
#endif
#if defined(ESP32) || defined(ESP32C3)
	#define HARDWARE_SERIAL_SELECTABLE_PIN
#endif

#ifdef ACTIVATE_SOFTWARE_SERIAL
	#include <SoftwareSerial.h>
#endif

#include <includes/statesNaming.h>

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define MAX_SIZE_TX_PACKET 2048

// Uncomment to enable printing out nice debug messages.
//#define LoRa_E70_DEBUG

// Define where debug output will be printed.
#define DEBUG_PRINTER Serial

// Setup debug printing macros.
#ifdef LoRa_E70_DEBUG
	#define DEBUG_PRINT(...) { DEBUG_PRINTER.print(__VA_ARGS__); }
	#define DEBUG_PRINTLN(...) { DEBUG_PRINTER.println(__VA_ARGS__); }
#else
	#define DEBUG_PRINT(...) {}
	#define DEBUG_PRINTLN(...) {}
#endif

enum MODE_TYPE {
	MODE_RSSI_0 			= 0,
	MODE_CONTINUOUS_1    	= 1,
	MODE_SUB_PACKAGE_2   	= 2,
	MODE_CONFIGURATION_3	= 3,
	MODE_PROGRAM			= 3,
	MODE_WOR_4           	= 4,
	MODE_CONFIGURATION_5 	= 5, // SAME AS 3
//	MODE_PROGRAM_5			= 5,
	MODE_POWER_SAVING_6 	= 6,
	MODE_SLEEP_7 			= 7,
	MODE_INIT 				= 0xFF
};

enum PROGRAM_COMMAND {
	WRITE_CFG_PWR_DWN_SAVE 	= 0xC0,
	READ_CONFIGURATION 		= 0xC1,
	WRITE_CFG_PWR_DWN_LOSE 	= 0xC2,
    READ_VERSION     		= 0xC3,
    RESET_DEVICE     		= 0xC4,

    WRONG_FORMAT 			= 0xFF,
	RETURNED_COMMAND 		= 0xC0
};

enum REGISTER_ADDRESS {
	REG_ADDRESS_CFG			= 0x00,
	REG_ADDRESS_SPED 		= 0x02,
	REG_ADDRESS_TRANS_MODE 	= 0x03,
	REG_ADDRESS_CHANNEL 	= 0x04,
	REG_ADDRESS_OPTION	 	= 0x05,
	REG_ADDRESS_CRYPT	 	= 0x06,
	REG_ADDRESS_PID		 	= 0x08
};

enum PACKET_LENGHT {
	PL_CONFIGURATION 	= 0x08,

	PL_SPED				= 0x01,
	PL_OPTION			= 0x01,
	PL_TRANSMISSION_MODE= 0x01,
	PL_CHANNEL			= 0x01,
	PL_CRYPT			= 0x02,
	PL_PID				= 0x03
};

#pragma pack(push, 1)
struct Speed {
	uint8_t airDataRate :3; //bit 0-2
	String getAirDataRateDescription() {
		return getAirDataRateDescriptionByParams(this->airDataRate);
	}

	uint8_t uartBaudRate :3; //bit 3-5
	String getUARTBaudRateDescription() {
		return getUARTBaudRateDescriptionByParams(this->uartBaudRate);
	}

    uint8_t uartParity :2; //bit 6-7
    String getUARTParityDescription() {
        return getUARTParityDescriptionByParams(this->uartParity);
    }

};

struct Option {
	uint8_t transmissionPower :2; //bit 0-1
	String getTransmissionPowerDescription() {
		return getTransmissionPowerDescriptionByParams(this->transmissionPower);
	}

    byte ioDriveMode  		: 1; //bit 2
    String getIODroveModeDescription() {
        return getIODriveModeDescriptionDescriptionByParams(this->ioDriveMode);
    }

    byte fec       		: 1; //bit 3
    String getFECDescription() {
        return getFECDescriptionByParams(this->fec);
    }


    byte wirelessWakeupTime : 3; //bit 4-6
    String getWirelessWakeUPTimeDescription() {
        return getWirelessWakeUPTimeDescriptionByParams(this->wirelessWakeupTime);
    }

    byte fixedTransmission :1; //bit 7
    String getFixedTransmissionDescription() {
        return getFixedTransmissionDescriptionByParams(this->fixedTransmission);
    }

};

struct Channel {
    uint8_t CHAN :5; // bit 0-4
    String getChannelDescription( ) {
        return String(this->CHAN + OPERATING_FREQUENCY) + F("MHz");
    }

    uint8_t subPacketSetting :3; //bit 5-7
    String getSubPacketSetting() {
        return getSubPacketSettingByParams(this->subPacketSetting);
    }

};

struct Crypt {
	byte CRYPT_H = 0;
	byte CRYPT_L = 0;
};

struct Configuration {
	byte COMMAND = 0;

	byte ADDH = 0;
	byte ADDL = 0;

	struct Speed SPED;
    struct Channel CHAN;

	struct Option OPTION;
};

struct ModuleInformation {
	byte COMMAND = 0;

	byte model = 0;
	byte version = 0;
	byte features1 = 0;
	byte features2 = 0;
	byte features3 = 0;
	byte features4 = 0;
};

struct ResponseStatus {
	Status code;
	String getResponseDescription() {
		return getResponseDescriptionByParams(this->code);
	}
};

struct ResponseStructContainer {
	void *data;
	byte rssi;
	ResponseStatus status;
	void close() {
		free(this->data);
	}
};
struct ResponseContainer {
	String data;
	byte rssi;
	ResponseStatus status;
};

struct ConfigurationMessage
{
	byte specialCommand1 = 0xCF;
	byte specialCommand2 = 0xCF;

	unsigned char message[];
};

//struct FixedStransmission {
//		byte ADDL = 0;
//		byte ADDH = 0;
//		byte CHAN = 0;
//		void *message;
//};
#pragma pack(pop)

class LoRa_E70 {
	public:
#ifdef ACTIVATE_SOFTWARE_SERIAL
		LoRa_E70(byte txE70pin, byte rxE70pin, UART_BPS_RATE bpsRate = UART_BPS_RATE_9600);
		LoRa_E70(byte txE70pin, byte rxE70pin, byte auxPin, UART_BPS_RATE bpsRate = UART_BPS_RATE_9600);
		LoRa_E70(byte txE70pin, byte rxE70pin, byte auxPin, byte m0Pin, byte m1Pin, byte m2Pin, UART_BPS_RATE bpsRate = UART_BPS_RATE_9600);
#endif

		LoRa_E70(HardwareSerial* serial, UART_BPS_RATE bpsRate = UART_BPS_RATE_9600);
		LoRa_E70(HardwareSerial* serial, byte auxPin, UART_BPS_RATE bpsRate = UART_BPS_RATE_9600);
		LoRa_E70(HardwareSerial* serial, byte auxPin, byte m0Pin, byte m1Pin, byte m2Pin, UART_BPS_RATE bpsRate = UART_BPS_RATE_9600);

#ifdef HARDWARE_SERIAL_SELECTABLE_PIN
		LoRa_E70(byte txE70pin, byte rxE70pin, HardwareSerial* serial, UART_BPS_RATE bpsRate, uint32_t serialConfig = SERIAL_8N1);
		LoRa_E70(byte txE70pin, byte rxE70pin, HardwareSerial* serial, byte auxPin, UART_BPS_RATE bpsRate, uint32_t serialConfig = SERIAL_8N1);
		LoRa_E70(byte txE70pin, byte rxE70pin, HardwareSerial* serial, byte auxPin, byte m0Pin, byte m1Pin, byte m2Pin, UART_BPS_RATE bpsRate, uint32_t serialConfig = SERIAL_8N1);
#endif

#ifdef ACTIVATE_SOFTWARE_SERIAL
		LoRa_E70(SoftwareSerial* serial, UART_BPS_RATE bpsRate = UART_BPS_RATE_9600);
		LoRa_E70(SoftwareSerial* serial, byte auxPin, UART_BPS_RATE bpsRate = UART_BPS_RATE_9600);
		LoRa_E70(SoftwareSerial* serial, byte auxPin, byte m0Pin, byte m1Pin, byte m2Pin, UART_BPS_RATE bpsRate = UART_BPS_RATE_9600);
#endif

//		LoRa_E70(byte txE70pin, byte rxE70pin, UART_BPS_RATE bpsRate = UART_BPS_RATE_9600, MODE_TYPE mode = MODE_0_NORMAL);
//		LoRa_E70(HardwareSerial* serial = &Serial, UART_BPS_RATE bpsRate = UART_BPS_RATE_9600, MODE_TYPE mode = MODE_0_NORMAL);
//		LoRa_E70(SoftwareSerial* serial, UART_BPS_RATE bpsRate = UART_BPS_RATE_9600, MODE_TYPE mode = MODE_0_NORMAL);

		bool begin();
        Status setMode(MODE_TYPE mode);
        MODE_TYPE getMode();

		ResponseStructContainer getConfiguration();
		ResponseStatus setConfiguration(Configuration configuration, PROGRAM_COMMAND saveType = WRITE_CFG_PWR_DWN_LOSE);

		ResponseStructContainer getModuleInformation();
		ResponseStatus resetModule();

		ResponseStatus sendMessage(const void *message, const uint8_t size);

        ResponseStatus streamMessage(Stream *streamLocal);
        ResponseStatus streamStructMessage(const void *message, const uint8_t size, Stream *streamLocal);

	    ResponseContainer receiveMessageUntil(char delimiter = '\0');
		ResponseStructContainer receiveMessage(const uint8_t size);
	        
//		Stream getStream();
		int read();

		ResponseStatus sendMessage(const String message);
		ResponseContainer receiveMessage();
//		ResponseContainer receiveMessageRSSI();

		ResponseStatus sendFixedMessage(byte ADDH, byte ADDL, byte CHAN, const String message);
        ResponseStatus sendFixedMessage(byte ADDH,byte ADDL, byte CHAN, const void *message, const uint8_t size);

//        ResponseStatus sendFixedMessage(byte ADDH,byte ADDL, byte CHAN, Stream *stream);
        ResponseStatus sendBroadcastFixedMessage(byte CHAN, const void *message, const uint8_t size);
        ResponseStatus sendBroadcastFixedMessage(byte CHAN, const String message);

		ResponseContainer receiveInitialMessage(const uint8_t size);

		Status receiveStreamStruct(void *structureManaged, uint16_t size_);
		ResponseStructContainer receiveStreamMessage(const uint8_t size);

        int available();
		void flush();

	private:
		HardwareSerial* hs;

#ifdef ACTIVATE_SOFTWARE_SERIAL
		SoftwareSerial* ss;
#endif

		bool isSoftwareSerial = true;

		int16_t txE70pin = -1;
		int16_t rxE70pin = -1;
		int16_t auxPin = -1;

#ifdef HARDWARE_SERIAL_SELECTABLE_PIN
		uint32_t serialConfig = SERIAL_8N1;
#endif

		int16_t m0Pin = -1;
		int16_t m1Pin = -1;
		int16_t m2Pin = -1;

		unsigned long halfKeyloqKey = 0x06660708;
		unsigned long encrypt(unsigned long data);
		unsigned long decrypt(unsigned long data);

		UART_BPS_RATE bpsRate = UART_BPS_RATE_9600;

		struct NeedsStream {
			template<typename T>
			void begin(T &t, uint32_t baud) {
				DEBUG_PRINTLN("Begin ");
				t.setTimeout(500);
				t.begin(baud);
				stream = &t;
			}

#ifdef HARDWARE_SERIAL_SELECTABLE_PIN
//		  template< typename T >
//		  void begin( T &t, uint32_t baud, SerialConfig config ){
//			  DEBUG_PRINTLN("Begin ");
//			  t.setTimeout(500);
//			  t.begin(baud, config);
//			  stream = &t;
//		  }
//
			template< typename T >
			void begin( T &t, uint32_t baud, uint32_t config ) {
				DEBUG_PRINTLN("Begin ");
				t.setTimeout(500);
				t.begin(baud, config);
				stream = &t;
			}

			template< typename T >
			void begin( T &t, uint32_t baud, uint32_t config, int8_t txE70pin, int8_t rxE70pin ) {
				DEBUG_PRINTLN("Begin ");
				t.setTimeout(500);
				t.begin(baud, config, txE70pin, rxE70pin);
				stream = &t;
			}
#endif

			void listen() {}

			Stream *stream;
		};
		NeedsStream serialDef;

		MODE_TYPE mode = MODE_SUB_PACKAGE_2;

		void managedDelay(unsigned long timeout);
		Status waitCompleteResponse(unsigned long timeout = 1000, unsigned int waitNoAux = 100);
		void cleanUARTBuffer();

        ResponseStructContainer receiveMessageComplete(const uint8_t size);
		ResponseContainer receiveMessageComplete();

		ResponseStructContainer receiveStreamMessageComplete(const uint8_t size);

		Status sendStruct(void *structureManaged, uint16_t size_);
		Status receiveStruct(void *structureManaged, uint16_t size_);
		bool writeProgramCommand(PROGRAM_COMMAND cmd);

		RESPONSE_STATUS checkUARTConfiguration(MODE_TYPE mode);

#ifdef LoRa_E70_DEBUG
		void printParameters(struct Configuration *configuration);
#endif
};

#endif
