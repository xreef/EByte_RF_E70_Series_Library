Ebyte LoRa E70 CC1310: library (esp32, esp8266, STM32, Arduino, Raspberry Pi Pico)
============================================================================================

![Renzo Mischianti](https://lh3.googleusercontent.com/a/ACg8ocKfEyFEMAl0BWM4Ues1akNqg3-3VFJhAjaXyauxNOrVrnln=s96-c?sz=50) Renzo Mischianti

[Support forum](https://mischianti.org/forums/forum/mischiantis-libraries/ebyte-lora-e70-uart-devices-cc1310/)

![Cover](https://mischianti.org/wp-content/uploads/2024/01/Ebyte-LoRa-E70-CC1310-exploring-library-esp32-STM32-Arduino-Raspberry-Pi-Pico-1024x552.jpg)

Ebyte LoRa E70 CC1310: exploring library (esp32, STM32, Arduino, Raspberry Pi Pico)

The world of wireless communication has been revolutionized by the advent of Long Range (LoRa) technology, offering a blend of long-range capabilities and low power consumption. The EByte LoRa E70 module stands out as a prominent player among the various emerging modules. This article delves into the features, applications, and operational modes of the EByte E70, providing insights into its capabilities and potential uses.

The E70 is based on CC1310 series device. This device is not just a microcontroller (MCU); it is a fully integrated wireless MCU designed specifically for low-power, long-range wireless applications. The CC1310 combines a powerful ARM Cortex-M3 processor with a highly efficient sub-1 GHz radio, making it an ideal solution for a wide range of applications, from smart metering to industrial automation and environmental monitoring.

Introduction to EByte LoRa E70
------------------------------

The EByte E70 is a LoRa module designed for long-range wireless communication. It operates in the sub-gigahertz frequency bands, making it ideal for various applications that require long-range communication and low power consumption. Its versatility and efficiency have made it a popular choice in IoT (Internet of Things) applications, smart city projects, and industrial automation.

Key Features of the EByte E70
-----------------------------

1.  **Long-Range Communication**: The E70 module is known for its exceptional range, capable of transmitting data over several kilometers, depending on environmental conditions.
2.  **Low Power Consumption**: It’s optimized for low power usage, extending the battery life of devices, which is crucial for IoT applications.
3.  **Multiple Operation Modes**: The E70 supports various modes like transparent mode, fixed mode, continuous mode, and sub-package mode, offering flexibility in different use cases.
4.  **Configurable Parameters**: Users can configure parameters like frequency, power output, and data rate, making them adaptable to various communication needs.
5.  **Forward Error Correction (FEC)**: FEC is a method for error control in data transmission. It adds redundancy to the transmitted information using a predetermined algorithm. This redundancy allows the receiver to detect and correct errors without the need for retransmission.

![FEC](https://mischianti.org/wp-content/uploads/2023/12/EByte-LoRa-FEC-Forward-Error-Correction-example.jpg)


Device specifications
---------------------

*   The communication distance tested is up to 1.5/6km
*   Maximum transmission power of 1W, software multi-level adjustable；
*   Support air date rate of 2.5kbps～168kbps；
*   Low power consumption for battery-supplied applications；
*   Can achieve up to 115200bps continuous frame unlimited-packet length transmission
*   E70-xxxT30S Support 2.6 ~ 5.5V power supply, more than 5V power supply to ensure the best performance;
*   E70-xxxT14S/S2 support 2.2 ~ 3.8V power supply, more than 3.3V power supply to ensure the best performance;
*   Industrial grade standard design, support -40 ~ 85 °C for working over a long time；

*   Support high-speed continuous transmission, send and receive unlimited data packet length；
*   Support continuous data frame without packetization, perfect support for ModBus protocol；
*   Support custom subcontracting settings to improve communication efficiency；
*   Support fixed-point transmission/broadcast transmission/channel monitoring;
*   Support RSSI signal strength reading;
*   Support over-the-air wake-up, i.e. low-power function, suitable for battery-powered solutions;
*   Developed based on CC1310 chip, built-in dual-core ARM;
*   Ultra-small volume design;
*   Ultra-low receiving current, only about 8mA;
*   E70-433 T30S maximum transmit power of 30dBm, the other three models are 25mW, softwaremulti-level adjustable;
*   Under ideal conditions, the communication distance can reach 1.5km;
*   E70-433T30S built-in PA+LNA, transmission power 1W, communication distance up to 6km;
*   Supports the global license-free ISM 433MHz band;
*   Support 2.5K~168kbps air transmission rate;
*   Support 2.2~3.8V power supply, greater than 3.3V power supply can ensure the best performance;
*   E70-433T30S supports 2.6~5.5V power supply , morethan 5V power supply can ensure the best performance;
*   Dual antenna optional (IPEX/stamp hole) is convenient for users to develop and facilitate integration.

Library
-------

I created a library to simplify usage. You can find It on my GitHub

![](https://github-readme-stats.vercel.app/api/pin/?username=xreef&repo=EByte_LoRa_E70_Series_Library&show_owner=true)

Or you can directly download from Arduino library manager.

LoRa E70 variants
-----------------

E70 has various form factors, the design changes, and also specifications.

![Dimensions of EByte LoRa E70 xxxTxxS Module](https://mischianti.org/wp-content/uploads/2023/12/EByte-LoRa-e70-xxxTxxS-size-1.jpg)

**E70-433T30S**:

*   Logic level voltage: 3.3v and 5v support
*   Transmit Power: **30dBm** (higher power, capable of longer-distance transmission)
*   Receive Sensitivity: **\-107 to -109 dBm**
*   Reference Distance: **6000m**

![EByte LoRa E70 xxxT1xxS Module Dimensions](https://mischianti.org/wp-content/uploads/2023/12/EByte-LoRa-e70-xxxT1xxS-size.jpg)

**E70-433T14S**:

![Advertisement](https://mischianti.org/wp-content/uploads/2020/05/pcbWay-banner-mobile-300x200-1.gif)

*   Logic level voltage: only 3.3v
*   Transmit Power: **14dBm** (lower power compared to the T30S)
*   Receive Sensitivity: **\-109 to -111 dBm** for T14S and **\-108 dBm** for T14S2 (slightly better sensitivity for the T14S)
*   Reference Distance: **1500m**

![Dimensions of the EByte LoRa E70 xxxT1xxS2 Module](https://mischianti.org/wp-content/uploads/2023/12/EByte-LoRa-e70-xxxT1xxS2-size-1.jpg)

**E70-433T14S2**:

*   Logic level voltage: only 3.3v
*   Update of S version.
*   Receive Sensitivity: **\-109 to -111 dBm** for T14S and **\-108 dBm** for T14S2 (slightly better sensitivity for the T14S)
*   Form factors are simpler to manage.

![Dimensions of EByte LoRa e70 xxxMTxxS](https://mischianti.org/wp-content/uploads/2023/12/EByte-LoRa-e70-xxxMTxxS-size.jpg)

**E70-433MT14S**:

*   Logic level voltage: only 3.3v
*   Transmit Power: **14dBm** (same as T14S and T14S2)
*   Receive Sensitivity: **\-108 dBm** (same as T14S2)
*   Reference Distance: **1500m** (same as T14S and T14S2)

### RF Parameters

![img.png](resources/EByte%20E70%20RF%20parameter.png)

### Pinout
![Advertisement](https://www.mischianti.org/wp-content/uploads/2023/01/sunfounder_mobile_300x200.jpg)

### Hardware parameters

![img.png](resources/EByte%20E70%20hardware%20parameter.png)

Pinout E70 xxxT14S2
-------------------

For my test, I’m going to use an E70 S2 version because It’s a comfortable form factor with an onboard SMA antenna.

![EByte E70 400/433/868/900/915 T14S2 pinout](https://mischianti.org/wp-content/uploads/2023/12/EByte-E70-xxxT14S2-pinout-low-res.jpg)

Connections note
----------------

**You can find all kinds of wiring diagrams in the previous articles of the series.**

![img.png](resources/EByte%20E70%20modes.png)
Constructor
-----------

I made a set of numerous constructors because we can have more options and situations to manage.

		LoRa\_E70(byte txE70pin, byte rxE70pin, UART\_BPS\_RATE bpsRate = UART\_BPS\_RATE\_9600);
		LoRa\_E70(byte txE70pin, byte rxE70pin, byte auxPin, UART\_BPS\_RATE bpsRate = UART\_BPS\_RATE\_9600);
		LoRa\_E70(byte txE70pin, byte rxE70pin, byte auxPin, byte m0Pin, byte m1Pin, byte m2Pin, UART\_BPS\_RATE bpsRate = UART\_BPS\_RATE\_9600);

The first set of constructors is created to delegate Serial and other pins to the library.

*   `txE70pin` and `rxE70pin` are the pins to connect to UART. They are **mandatory**.
*   `auxPin` is a pin that checks the operation, transmission, and receiving status (we are going to explain better next), that pin **isn’t mandatory**; if you don’t set It, I apply a delay to permit the operation to complete itself (with latency, i**f you have trouble, like freeze device, you must put a pull-up 4.7k resistor or better connect to the device** ).
*   `m0pin`, `m1Pin` and `m2Pin` are the pins to change operation MODE (see the table upper); I think these pins in “production” are going to connect directly to HIGH or LOW. Still, for a test, they are helpful for the library to manage.
*   `bpsRate` is the baud rate of SoftwareSerial is typically 9600 (the only baud rate in programming/sleep mode)

A simple example is

A simple example is

#include "LoRa_E70.h"

LoRa_E70 e70ttl(2, 3);  // e70 TX e70 RX
// LoRa_E70 e70ttl(2, 3, 5, 6, 7);  // e70 TX e70 RX
We can use a SoftwareSerial directly with another constructor

		LoRa_E70(HardwareSerial* serial, UART_BPS_RATE bpsRate = UART_BPS_RATE_9600);
		LoRa_E70(HardwareSerial* serial, byte auxPin, UART_BPS_RATE bpsRate = UART_BPS_RATE_9600);
		LoRa_E70(HardwareSerial* serial, byte auxPin, byte m0Pin, byte m1Pin, byte m2Pin, UART_BPS_RATE bpsRate = UART_BPS_RATE_9600);
The example upper with this constructor can be done like so.

#include <SoftwareSerial.h>
#include "LoRa_E70.h"

SoftwareSerial mySerial(2, 3); // e70 TX e70 RX
LoRa_E70 e70ttl(&mySerial);
// LoRa_E70 e70ttl(&mySerial, 5, 6, 7, 8);
The last set of constructors is to permit an HardwareSerial instead of SoftwareSerial.

		LoRa_E70(SoftwareSerial* serial, UART_BPS_RATE bpsRate = UART_BPS_RATE_9600);
		LoRa_E70(SoftwareSerial* serial, byte auxPin, UART_BPS_RATE bpsRate = UART_BPS_RATE_9600);
		LoRa_E70(SoftwareSerial* serial, byte auxPin, byte m0Pin, byte m1Pin, byte m2Pin, UART_BPS_RATE bpsRate = UART_BPS_RATE_9600);
For esp32, you have three additional constructors to permit to manage pins for HardWare serial.

			LoRa_E70(byte txE70pin, byte rxE70pin, HardwareSerial* serial, UART_BPS_RATE bpsRate = UART_BPS_RATE_9600, uint32_t serialConfig = SERIAL_8N1);
			LoRa_E70(byte txE70pin, byte rxE70pin, HardwareSerial* serial, byte auxPin, UART_BPS_RATE bpsRate = UART_BPS_RATE_9600, uint32_t serialConfig = SERIAL_8N1);
			LoRa_E70(byte txE70pin, byte rxE70pin, HardwareSerial* serial, byte auxPin, byte m0Pin, byte m1Pin, byte m2Pin, UART_BPS_RATE bpsRate = UART_BPS_RATE_9600, uint32_t serialConfig = SERIAL_8N1);


Begin
-----

The begin command is used to startup Serial and pins in input and output mode.

void begin();
in execution is

	// Startup all pins and UART
	e70ttl.begin();
Configuration and method to get information
There are many methods for managing configuration and getting information about the device.


### Response containers

To simplify the response management, I created a set of containers, which is very useful for managing errors and returning generic data.

### ResponseStatus

The ResponseStatus is a status container and has two simple entry points, with this you can get the status code and the description of the status code

	Serial.println(c.getResponseDescription()); // Description of code
	Serial.println(c.code); // 1 if Success
The code is

```
E70_SUCCESS = 1,
ERR_E70_UNKNOWN,	/* something shouldn't happened */
ERR_E70_NOT_SUPPORT,
ERR_E70_NOT_IMPLEMENT,
ERR_E70_NOT_INITIAL,
ERR_E70_INVALID_PARAM,
ERR_E70_DATA_SIZE_NOT_MATCH,
ERR_E70_BUF_TOO_SMALL,
ERR_E70_TIMEOUT,
ERR_E70_HARDWARE,
ERR_E70_HEAD_NOT_RECOGNIZED,
ERR_E70_NO_RESPONSE_FROM_DEVICE,
ERR_E70_WRONG_UART_CONFIG,
ERR_E70_WRONG_FORMAT,
ERR_E70_PACKET_TOO_BIG,
ERR_E70_NO_STREAM_FOUND
```

### ResponseContainer

This container is created to manage String response and has two entry points.

`data` with the string returned from the message and `status` an instance of `RepsonseStatus`.

		ResponseContainer rs = e70ttl.receiveMessage();
		String message = rs.data;

		Serial.println(rs.status.getResponseDescription());
		Serial.println(message);

But this command goes to read all the data in the buffer. If you receive three messages, you are going to read all three notes at one time, and my simple solution is to use an end character to send at the end of the message, to default I use \\0 (null character)

		ResponseContainer rs = e70ttl.receiveMessageUntil();
                // You can specify a custom delimiter also
		// ResponseContainer rs = e70ttl.receiveMessageUntil('|');

		String message = rs.data;

		Serial.println(rs.status.getResponseDescription());
		Serial.println(message);

### ResponseStructContainer

The `ResponseStructContainer` is the more “complex” container. I use this to manage structures. It has the same entry points as ResponseContainer, but data is a void pointer to manage complex structures.

	ResponseStructContainer c;
	c = e70ttl.getConfiguration();
	// It's important get configuration pointer before all other operation
	Configuration configuration = \*(Configuration\*) c.data;
	Serial.println(c.status.getResponseDescription());
	Serial.println(c.status.code);
    c.close();

Every time you use a `ResponseStructContainer` you must close It with `close()`

getConfiguration and setConfiguration
-------------------------------------

The first method is getConfiguration, and you can use It to retrieve all data stored on the device.

		ResponseStructContainer getConfiguration();

Here is a usage example.


	ResponseStructContainer c;
	c = e70ttl.getConfiguration();
	// It's important get configuration pointer before all other operation
	Configuration configuration = \*(Configuration\*) c.data;
	Serial.println(c.status.getResponseDescription());
	Serial.println(c.status.code);
    Serial.println(configuration.SPED.getUARTBaudRate());
    c.close();

The structure of the configuration has all the data of settings, and I added a series of functions to get all the descriptions of a single data.

	configuration.ADDL = 0x00;  // First part of address
	configuration.ADDH = 0x00; // Second part


	configuration.SPED.uartBaudRate = UART\_BPS\_9600; // Serial baud rate
	configuration.SPED.airDataRate = AIR\_DATA\_RATE\_000\_025; // Air baud rate
	configuration.SPED.uartParity = MODE\_00\_8N1; // Parity bit

	configuration.CHAN.CHAN = 4;
	configuration.CHAN.subPacketSetting = SPS\_0064\_010;

	configuration.OPTION.fec = FEC\_1\_ON; // Packet size
	configuration.OPTION.fixedTransmission = FT\_TRANSPARENT\_TRANSMISSION; // Need to send special command
	configuration.OPTION.transmissionPower = POWER\_30; // Device power
	configuration.OPTION.ioDriveMode = IO\_D\_MODE\_PUSH\_PULLS\_PULL\_UPS; // IO Drive
	configuration.OPTION.wirelessWakeupTime = WAKE\_UP\_1000; // Wake up time

You have the equivalent function for all attributes to get all descriptions:

void printParameters(struct Configuration configuration) {
Serial.println("----------------------------------------");

	Serial.print(F("Configuration packet: "));
    byte\* byteArray = (byte\*)&configuration;  // Cast the address of config to a byte pointer
    for (int i = 0; i < sizeof(Configuration); i++) {
        if (byteArray\[i\] < 16) {
            Serial.print('0');  // Print a leading zero for single-digit hex values
        }
        Serial.print(byteArray\[i\], HEX);  // Print each byte of the struct in hexadecimal
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

In the same way, setConfiguration wants a configuration structure, so I think the better way to manage configuration is to retrieve the current one, apply the only change you need and set It again.

		ResponseStatus setConfiguration(Configuration configuration, PROGRAM\_COMMAND saveType = WRITE\_CFG\_PWR\_DWN\_LOSE);

`configuration` is the structure previously shown, `saveType` permit you to choose if the change becomes permanent or only for the current session.

	ResponseStructContainer c;
	c = e70ttl.getConfiguration();
	// It's important get configuration pointer before all other operation
	Configuration configuration = \*(Configuration\*) c.data;
	Serial.println(c.status.getResponseDescription());
	Serial.println(c.status.code);

	printParameters(configuration);
	configuration.ADDL = 0x00;  // First part of address
	configuration.ADDH = 0x00; // Second part


	configuration.SPED.uartBaudRate = UART\_BPS\_9600; // Serial baud rate
	configuration.SPED.airDataRate = AIR\_DATA\_RATE\_000\_025; // Air baud rate
	configuration.SPED.uartParity = MODE\_00\_8N1; // Parity bit

	configuration.CHAN.CHAN = 4;
	configuration.CHAN.subPacketSetting = SPS\_0064\_010;

	configuration.OPTION.fec = FEC\_1\_ON; // Packet size
	configuration.OPTION.fixedTransmission = FT\_TRANSPARENT\_TRANSMISSION; // Need to send special command
	configuration.OPTION.transmissionPower = POWER\_30; // Device power
	configuration.OPTION.ioDriveMode = IO\_D\_MODE\_PUSH\_PULLS\_PULL\_UPS; // IO Drive
	configuration.OPTION.wirelessWakeupTime = WAKE\_UP\_1000; // Wake up time

	// Set configuration changed and set to not hold the configuration
	ResponseStatus rs = e70ttl.setConfiguration(configuration, WRITE\_CFG\_PWR\_DWN\_LOSE);
	Serial.println(rs.getResponseDescription());
	Serial.println(rs.code);
	printParameters(configuration);
    c.close()

The parameters are all managed as constant:


Check buffer
------------

First, we must introduce a simple but practical method to check if something is in the receiving buffer.

int available();

It’s simple to return how many bytes you have in the current stream.

Send receive messages
---------------------

### Normal transmission mode

Normal/Transparent transmission mode sends messages to all devices with the same address and channel.

![EByte LoRa Transmission Types Comparative Diagram](https://mischianti.org/wp-content/uploads/2023/12/EByte-LoRa-difference-from-transmission-type-diagram-1024x579.jpg)

There are a lot of methods to send/receive messages, and we are going to explain in detail:

        ResponseStatus sendMessage(const String message);
        ResponseContainer receiveMessage();

The first method is sendMessage, which sends a String to a device in **Normal mode**.

	ResponseStatus rs = e70ttl.sendMessage("Prova");
	Serial.println(rs.getResponseDescription());

The other device does on the loop.

       if (e70ttl.available()  > 1){
		ResponseContainer rs = e70ttl.receiveMessage();
		String message = rs.data; // First ever get the data
		Serial.println(rs.status.getResponseDescription());
		Serial.println(message);
	}

Pay attention if you receive multiple messages in the buffer and don’t want to read them all at one time. You must use `ResponseContainer rs = e70ttl.receiveMessageUntil();` with a delimiter put on the end of sending a message.

#### Manage structure

If you want to send a complex structure, you can use this method

        ResponseStatus sendMessage(const void \*message, const uint8\_t size);
        ResponseStructContainer receiveMessage(const uint8\_t size);

It’s used to send structure, for example:

	struct Messaggione {
		char type\[5\];
		char message\[8\];
		bool mitico;
	};
        struct Messaggione messaggione = {"TEMP", "Peple", true};
        ResponseStatus rs = e70ttl.sendMessage(&messaggione, sizeof(Messaggione));
	Serial.println(rs.getResponseDescription());

and the other side, you can receive the message so

		ResponseStructContainer rsc = e70ttl.receiveMessage(sizeof(Messaggione));
		struct Messaggione messaggione = \*(Messaggione\*) rsc.data;
		Serial.println(messaggione.message);
		Serial.println(messaggione.mitico);
        rsc.close();

#### Read partial structure

If you want to read the first part of the message to manage more types of structure, you can use this method.

ResponseContainer receiveInitialMessage(const uint8\_t size);

I create It to receive a string with type or other to identify the structure to load.

		struct Messaggione { // Partial structure without type
			char message\[8\];
			bool mitico;
		};

		char type\[5\]; // first part of structure
		ResponseContainer rs = e70ttl.receiveInitialMessage(sizeof(type));
                // Put string in a char array (not needed)
		memcpy ( type, rs.data.c\_str(), sizeof(type) );

		Serial.println("READ TYPE: ");
		Serial.println(rs.status.getResponseDescription());
		Serial.println(type);

                // Read the rest of structure
		ResponseStructContainer rsc = e70ttl.receiveMessage(sizeof(Messaggione));
		struct Messaggione messaggione = \*(Messaggione\*) rsc.data;
        rsc.close();

Fixed mode instead of normal mode
---------------------------------

Similarly, I create a set of methods to use with the fixed transmission.

### Fixed transmission

**You need to change only the sending method** because the destination device doesn’t **receive the preamble with Address and Channel when setting the fixed mode.**

So for the String message, you have

        ResponseStatus sendFixedMessage(byte ADDH, byte ADDL, byte CHAN, const String message);
        ResponseStatus sendBroadcastFixedMessage(byte CHAN, const String message);

and for the structure, you have

        ResponseStatus sendFixedMessage(byte ADDH, byte ADDL, byte CHAN, const void \*message, const uint8\_t size);
        ResponseStatus sendBroadcastFixedMessage(byte CHAN, const void \*message, const uint8\_t size );

Here is a simple example

	ResponseStatus rs = e70ttl.sendFixedMessage(0, 0, 0x17, &messaggione, sizeof(Messaggione));
//	ResponseStatus rs = e70ttl.sendFixedMessage(0, 0, 0x17, "Ciao");

Fixed transmission has more scenarios

![EByte LoRa Fixed Transmission Example Diagram](https://mischianti.org/wp-content/uploads/2023/12/EByte-LoRa-Fixed-Transmission-example-schema.jpg)

If you send it to a specific device (second scenario Fixed transmission), you must add ADDL, ADDH, and CHAN to identify It directly.

ResponseStatus rs = e70ttl.sendFixedMessage(2, 2, 0x17, "Message to a device");

If you want to send a message to all devices in a specified Channel, you can use this method.

ResponseStatus rs = e70ttl.sendBroadcastFixedMessage(0x17, "Message to a devices of a channel");

![EByte LoRa Network Broadcast Transmission Diagram](https://mischianti.org/wp-content/uploads/2023/12/EByte-LoRa-Broadcast-Transmission-example-schema.jpg)

EByte LoRa Network Broadcast Transmission Diagram

If you wish to receive all broadcast messages in the network, you must set your `ADDH` and `ADDL` with `BROADCAST_ADDRESS`.

        ResponseStructContainer c;
	c = e70ttl.getConfiguration();
	// It's important get configuration pointer before all other operation
	Configuration configuration = \*(Configuration\*) c.data;
	Serial.println(c.status.getResponseDescription());
	Serial.println(c.status.code);

	printParameters(configuration);
	configuration.ADDL = BROADCAST\_ADDRESS;
	configuration.ADDH = BROADCAST\_ADDRESS;

	// Set configuration changed and set to not hold the configuration
	ResponseStatus rs = e70ttl.setConfiguration(configuration, WRITE\_CFG\_PWR\_DWN\_LOSE);
	Serial.println(rs.getResponseDescription());
	Serial.println(rs.code);
	printParameters(configuration);
        c.close();

Continuous mode
---------------

E70 offers the continuous mode by setting the same ADDH, ADDL, and CHAN. You can stream a lot of data or continuous data.

![EByte LoRa continuous mode diagram](https://mischianti.org/wp-content/uploads/2024/01/EByte-LoRa-continuous-mode-diagram.jpg)

EByte LoRa continuous mode diagram

### Continuous Mode

1.  **Operation**: In continuous mode, the EByte E70 module sends or receives data in a continuous stream. This means that once the transmission starts, it will keep sending data until stopped. It’s similar to a traditional radio broadcast.
2.  **Usage**: This mode is useful for applications where a constant flow of information is needed, without interruptions. It’s ideal for real-time data transmission, like streaming audio or telemetry.
3.  **Advantages**:
    *   **Real-time data transmission**: Useful for applications requiring live updates.
    *   **No interruption**: Continuous data flow without the need for packet reassembly or handling.
4.  **Challenges**:
    *   **Power consumption**: Typically, continuous mode consumes more power due to the constant transmission.
    *   **Bandwidth usage**: It can use more bandwidth, which might not be ideal in crowded RF environments.

### Sub-Packet Mode

1.  **Operation**: In sub-packet mode, data is divided into smaller packets before transmission. Each packet is sent separately and then reassembled at the receiver’s end.
2.  **Usage**: This mode is ideal for applications that don’t require real-time transmission and can tolerate some delay, such as sending sensor data at intervals.
3.  **Advantages**:
    *   **Energy efficiency**: More energy-efficient as the module can go into a low-power state between transmissions.
    *   **Error handling**: Easier to implement error checking and correction, as it’s done on a per-packet basis.
    *   **Adaptive data rates**: Can adjust the data rate for each packet depending on network conditions.
4.  **Challenges**:
    *   **Latency**: There is a delay in data reassembly, which might not be suitable for real-time applications.
    *   **Complexity**: Requires more complex logic for packet handling and reassembly.

### Key Differences

*   **Data Transmission Method**: Continuous mode transmits data in a constant stream, while sub-packet mode breaks data into smaller packets.
*   **Power Consumption**: Continuous mode generally consumes more power due to the constant transmission.
*   **Real-time Capability**: Continuous mode is better for real-time data needs, whereas sub-packet mode is suitable for delayed or periodic data transmission.
*   **Error Handling and Flexibility**: Sub-packet mode provides more flexibility in error handling and adjusting to network conditions.

When you use continuous transmission mode, the module sends a continuous stream of data. To target this data to a specific address, you would typically configure the sender and receiver with matching addresses. This means that both the transmitting and receiving modules should be set up to recognize and use these specified addresses.

### Simple stream

To send a simple stream (without any preamble) you can use

ResponseStatus LoRa\_E70::streamMessage(Stream \*streamLocal)

A possible implementation can be the stream of a file.

			File inputFile = SPIFFS.open(input);

			if (!inputFile) {
			    Serial.println("There was an error opening the file for reading");
			} else  {
				ResponseStatus rs = e70ttl.streamMessage(&inputFile);
				// Check If there is some problem of succesfully send
				Serial.println(rs.getResponseDescription());
			}

That takes a stream as a parameter. To receive It, you can wait for the data.

    if (e70ttl.available()>0) {
    	Serial.println("Start!");

  	  // open file in write 
    	File output = SPIFFS.open("/tmp.png", FTP\_FILE\_WRITE\_CREATE);

    	while (e70ttl.available()>0) {
			while (e70ttl.available()>0) {
				if (output.write(e70ttl.read())==0) {Serial.println("ERROR WRITE!"); };
			}
	    	delay(10);
    	}

    	output.close();

    	Serial.println("Complete!");
    }

As you can see, you can use read, which is a classical `stream.read()`.

### Stream with preamble

Not all situations can be a continuous stream; sometimes, we need to send data as a byte array; in this situation, you need a preamble with the file information, and you can use the command.

ResponseStatus LoRa\_E70::streamStructMessage(const void \*message, const uint8\_t size, Stream \*streamLocal)

You can identify the first part of the send method It’s the same as the send struct described before; the last parameter is the stream to send.

To receive all, you must first call the command to get the structure (preamble)

ResponseStructContainer LoRa\_E70::receiveStreamMessage(const uint8\_t size)

Then, we get the stream as already described.

Thanks
------

