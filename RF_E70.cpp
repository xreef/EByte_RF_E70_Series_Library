/*
 * EBYTE RF E700 Series
 * https://www.mischianti.org/category/my-libraries/rf-e70-devices/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Renzo Mischianti www.mischianti.org All right reserved.
 *
 * You may copy, alter and reuse this code in any way you like, but please leave
 * reference to www.mischianti.org in your comments if you redistribute this code.
 *
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

#include "RF_E70.h"

#ifdef ACTIVATE_SOFTWARE_SERIAL
RF_E70::RF_E70(byte txE70pin, byte rxE70pin, UART_BPS_RATE bpsRate){
    this->txE70pin = txE70pin;
    this->rxE70pin = rxE70pin;
    SoftwareSerial* mySerial = new SoftwareSerial((uint8_t)this->txE70pin, (uint8_t)this->rxE70pin); // "RX TX" // @suppress("Abstract class cannot be instantiated")
    this->ss = mySerial;
    this->hs = NULL;

    this->bpsRate = bpsRate;
}
RF_E70::RF_E70(byte txE70pin, byte rxE70pin, byte auxPin, UART_BPS_RATE bpsRate){
    this->txE70pin = txE70pin;
    this->rxE70pin = rxE70pin;
    this->auxPin = auxPin;
    SoftwareSerial* mySerial = new SoftwareSerial((uint8_t)this->txE70pin, (uint8_t)this->rxE70pin); // "RX TX" // @suppress("Abstract class cannot be instantiated")
    this->ss = mySerial;
    this->hs = NULL;

    this->bpsRate = bpsRate;
}
RF_E70::RF_E70(byte txE70pin, byte rxE70pin, byte auxPin, byte m0Pin, byte m1Pin, byte m2Pin, UART_BPS_RATE bpsRate){
    this->txE70pin = txE70pin;
    this->rxE70pin = rxE70pin;

    this->auxPin = auxPin;

    this->m0Pin = m0Pin;
    this->m1Pin = m1Pin;
    this->m2Pin = m2Pin;

    SoftwareSerial* mySerial = new SoftwareSerial((uint8_t)this->txE70pin, (uint8_t)this->rxE70pin); // "RX TX" // @suppress("Abstract class cannot be instantiated")
    this->ss = mySerial;
    this->hs = NULL;

    this->bpsRate = bpsRate;
}
#endif

RF_E70::RF_E70(HardwareSerial* serial, UART_BPS_RATE bpsRate){ //, uint32_t serialConfig
    this->txE70pin = txE70pin;
    this->rxE70pin = rxE70pin;

	#ifdef ACTIVATE_SOFTWARE_SERIAL
    	this->ss = NULL;
	#endif

    this->hs = serial;

//    this->serialConfig = serialConfig;

    this->bpsRate = bpsRate;
}
RF_E70::RF_E70(HardwareSerial* serial, byte auxPin, UART_BPS_RATE bpsRate){ // , uint32_t serialConfig
    this->txE70pin = txE70pin;
    this->rxE70pin = rxE70pin;
    this->auxPin = auxPin;

	#ifdef ACTIVATE_SOFTWARE_SERIAL
		this->ss = NULL;
	#endif

	this->hs = serial;

//    this->serialConfig = serialConfig;

    this->bpsRate = bpsRate;
}
RF_E70::RF_E70(HardwareSerial* serial, byte auxPin, byte m0Pin, byte m1Pin, byte m2Pin, UART_BPS_RATE bpsRate){ //, uint32_t serialConfig
    this->txE70pin = txE70pin;
    this->rxE70pin = rxE70pin;

    this->auxPin = auxPin;

    this->m0Pin = m0Pin;
    this->m1Pin = m1Pin;
    this->m2Pin = m2Pin;

	#ifdef ACTIVATE_SOFTWARE_SERIAL
		this->ss = NULL;
	#endif

    this->hs = serial;
//    this->serialConfig = serialConfig;

    this->bpsRate = bpsRate;
}

#ifdef HARDWARE_SERIAL_SELECTABLE_PIN
RF_E70::RF_E70(byte txE70pin, byte rxE70pin, HardwareSerial* serial, UART_BPS_RATE bpsRate, uint32_t serialConfig){
    this->txE70pin = txE70pin;
    this->rxE70pin = rxE70pin;

	#ifdef ACTIVATE_SOFTWARE_SERIAL
    	this->ss = NULL;
	#endif

    this->serialConfig = serialConfig;

    this->hs = serial;

    this->bpsRate = bpsRate;
}
RF_E70::RF_E70(byte txE70pin, byte rxE70pin, HardwareSerial* serial, byte auxPin, UART_BPS_RATE bpsRate, uint32_t serialConfig){
    this->txE70pin = txE70pin;
    this->rxE70pin = rxE70pin;
    this->auxPin = auxPin;

	#ifdef ACTIVATE_SOFTWARE_SERIAL
		this->ss = NULL;
	#endif

	this->serialConfig = serialConfig;

	this->hs = serial;

    this->bpsRate = bpsRate;
}
RF_E70::RF_E70(byte txE70pin, byte rxE70pin, HardwareSerial* serial, byte auxPin, byte m0Pin, byte m1Pin, byte m2Pin, UART_BPS_RATE bpsRate, uint32_t serialConfig){
    this->txE70pin = txE70pin;
    this->rxE70pin = rxE70pin;

    this->auxPin = auxPin;

    this->m0Pin = m0Pin;
    this->m1Pin = m1Pin;
    this->m2Pin = m2Pin;

	#ifdef ACTIVATE_SOFTWARE_SERIAL
		this->ss = NULL;
	#endif

	this->serialConfig = serialConfig;

    this->hs = serial;

    this->bpsRate = bpsRate;
}
#endif

#ifdef ACTIVATE_SOFTWARE_SERIAL

RF_E70::RF_E70(SoftwareSerial* serial, UART_BPS_RATE bpsRate){
    this->txE70pin = txE70pin;
    this->rxE70pin = rxE70pin;

    this->ss = serial;
    this->hs = NULL;

    this->bpsRate = bpsRate;
}
RF_E70::RF_E70(SoftwareSerial* serial, byte auxPin, UART_BPS_RATE bpsRate){
    this->txE70pin = txE70pin;
    this->rxE70pin = rxE70pin;
    this->auxPin = auxPin;

    this->ss = serial;
    this->hs = NULL;

    this->bpsRate = bpsRate;
}
RF_E70::RF_E70(SoftwareSerial* serial, byte auxPin, byte m0Pin, byte m1Pin, byte m2Pin, UART_BPS_RATE bpsRate){
    this->txE70pin = txE70pin;
    this->rxE70pin = rxE70pin;

    this->auxPin = auxPin;

    this->m0Pin = m0Pin;
    this->m1Pin = m1Pin;
    this->m2Pin = m2Pin;

    this->ss = serial;
    this->hs = NULL;

    this->bpsRate = bpsRate;
}
#endif

bool RF_E70::begin(){
	DEBUG_PRINT("RX MIC ---> ");
	DEBUG_PRINTLN(this->txE70pin);
	DEBUG_PRINT("TX MIC ---> ");
	DEBUG_PRINTLN(this->rxE70pin);
	DEBUG_PRINT("AUX ---> ");
	DEBUG_PRINTLN(this->auxPin);
	DEBUG_PRINT("M0 ---> ");
	DEBUG_PRINTLN(this->m0Pin);
	DEBUG_PRINT("M1 ---> ");
	DEBUG_PRINTLN(this->m1Pin);
	DEBUG_PRINT("M2 ---> ");
	DEBUG_PRINTLN(this->m2Pin);

	if (this->auxPin != -1) {
		pinMode(this->auxPin, INPUT);
		DEBUG_PRINTLN("Init AUX pin!");
	}
	if (this->m0Pin != -1) {
		pinMode(this->m0Pin, OUTPUT);
		DEBUG_PRINTLN("Init M0 pin!");
		digitalWrite(this->m0Pin, HIGH);

	}
	if (this->m1Pin != -1) {
		pinMode(this->m1Pin, OUTPUT);
		DEBUG_PRINTLN("Init M1 pin!");
		digitalWrite(this->m1Pin, HIGH);
	}
	if (this->m2Pin != -1) {
		pinMode(this->m2Pin, OUTPUT);
		DEBUG_PRINTLN("Init M2 pin!");
		digitalWrite(this->m2Pin, HIGH);
	}

    DEBUG_PRINTLN("Begin ex");
    if (this->hs){
        DEBUG_PRINTLN("Begin Hardware Serial");

#ifdef HARDWARE_SERIAL_SELECTABLE_PIN
        if(this->txE70pin != -1 && this->rxE70pin != -1) {
        	DEBUG_PRINTLN("PIN SELECTED!!");
			this->serialDef.begin(*this->hs, this->bpsRate, this->serialConfig, this->txE70pin, this->rxE70pin);
		}else{
			this->serialDef.begin(*this->hs, this->bpsRate, this->serialConfig);
		}
#endif
#ifndef HARDWARE_SERIAL_SELECTABLE_PIN
        this->serialDef.begin(*this->hs, this->bpsRate);
#endif
        while (!this->hs) {
          ; // wait for serial port to connect. Needed for native USB
        }

#ifdef ACTIVATE_SOFTWARE_SERIAL
    }else if (this->ss){
        DEBUG_PRINTLN("Begin Software Serial");

		this->serialDef.begin(*this->ss, this->bpsRate);
	}	else{
        DEBUG_PRINTLN("Begin Software Serial Pin");
        SoftwareSerial* mySerial = new SoftwareSerial((int)this->txE70pin, (int)this->rxE70pin); // "RX TX" // @suppress("Abstract class cannot be instantiated")
        this->ss = mySerial;

//		SoftwareSerial mySerial(this->txE70pin, this->rxE70pin);
        DEBUG_PRINT("RX Pin: ");
        DEBUG_PRINT((int)this->txE70pin);
        DEBUG_PRINT("TX Pin: ");
        DEBUG_PRINTLN((int)this->rxE70pin);

		this->serialDef.begin(*this->ss, this->bpsRate);
#endif
	}

    this->serialDef.stream->setTimeout(100);
    Status status = setMode(MODE_SUB_PACKAGE_2);

    return status==E70_SUCCESS;
}

/*

Utility method to wait until module is doen tranmitting
a timeout is provided to avoid an infinite loop

*/

Status RF_E70::waitCompleteResponse(unsigned long timeout, unsigned int waitNoAux) {

	Status result = E70_SUCCESS;

	unsigned long t = millis();

	// make darn sure millis() is not about to reach max data type limit and start over
	if (((unsigned long) (t + timeout)) == 0){
		t = 0;
	}

	// if AUX pin was supplied and look for HIGH state
	// note you can omit using AUX if no pins are available, but you will have to use delay() to let module finish
	if (this->auxPin != -1) {
		while (digitalRead(this->auxPin) == LOW) {
			if ((millis() - t) > timeout){
				result = ERR_E70_TIMEOUT;
				DEBUG_PRINTLN("Timeout error!");
				return result;
			}
		}
		DEBUG_PRINTLN("AUX HIGH!");
	}
	else {
		// if you can't use aux pin, use 4K7 pullup with Arduino
		// you may need to adjust this value if transmissions fail
		this->managedDelay(waitNoAux);
		DEBUG_PRINTLN(F("Wait no AUX pin!"));
	}


	// per data sheet control after aux goes high is 2ms so delay for at least that long)
	this->managedDelay(20);
	DEBUG_PRINTLN(F("Complete!"));
	return result;
}

/*

delay() in a library is not a good idea as it can stop interrupts
just poll internal time until timeout is reached

*/


void RF_E70::managedDelay(unsigned long timeout) {

	unsigned long t = millis();

	// make darn sure millis() is not about to reach max data type limit and start over
	if (((unsigned long) (t + timeout)) == 0){
		t = 0;
	}

	while ((millis() - t) < timeout) 	{ 	}

}

/*

Method to indicate availability

*/

//int RF_E70::available(unsigned long timeout) {
int RF_E70::available() {
//	unsigned long t = millis();
//
//	// make darn sure millis() is not about to reach max data type limit and start over
//	if (((unsigned long) (t + timeout)) == 0){
//		t = 0;
//	}
//
//	if (this->auxPin != -1) {
//		if (digitalRead(this->auxPin) == HIGH){
//			return 0;
//		}else{
//			while (digitalRead(this->auxPin) == LOW) {
//				if ((millis() - t) > timeout){
//					DEBUG_PRINTLN("Timeout error!");
//					return 0;
//				}
//			}
//			DEBUG_PRINTLN("AUX HIGH!");
//			return 2;
//		}
//	}else{
		return this->serialDef.stream->available();
//	}
}

int RF_E70::read() {
	return this->serialDef.stream->read();
}

/*

Method to indicate availability

*/

void RF_E70::flush() {
	this->serialDef.stream->flush();
}


void RF_E70::cleanUARTBuffer()
{
//  bool IsNull = true;

  while (this->available())
  {
//    IsNull = false;

    this->serialDef.stream->read();
  }
}


/*

Method to send a chunk of data provided data is in a struct--my personal favorite as you
need not parse or worry about sprintf() inability to handle floats

TTP: put your structure definition into a .h file and include in both the sender and reciever
sketches

NOTE: of your sender and receiver MCU's are different (Teensy and Arduino) caution on the data
types each handle ints floats differently

*/

Status RF_E70::sendStruct(void *structureManaged, uint16_t size_) {
		if (this->mode == MODE_SUB_PACKAGE_2 &&  size_ > MAX_SIZE_TX_PACKET + 2){
			return ERR_E70_PACKET_TOO_BIG;
		}

		Status result = E70_SUCCESS;

		uint8_t len = this->serialDef.stream->write((uint8_t *) structureManaged, size_);
		if (len!=size_){
			DEBUG_PRINT(F("Send... len:"))
			DEBUG_PRINT(len);
			DEBUG_PRINT(F(" size:"))
			DEBUG_PRINT(size_);
			if (len==0){
				result = ERR_E70_NO_RESPONSE_FROM_DEVICE;
			}else{
				result = ERR_E70_DATA_SIZE_NOT_MATCH;
			}
		}
		if (result != E70_SUCCESS) return result;

		result = this->waitCompleteResponse(5000, 5000);
		if (result != E70_SUCCESS) return result;
        DEBUG_PRINT(F("Clear buffer..."))
        this->cleanUARTBuffer();

		DEBUG_PRINTLN(F("ok!"))

		return result;
}


/*

Method to get a chunk of data provided data is in a struct--my personal favorite as you
need not parse or worry about sprintf() inability to handle floats

TTP: put your structure definition into a .h file and include in both the sender and reciever
sketches

NOTE: of your sender and receiver MCU's are different (Teensy and Arduino) caution on the data
types each handle ints floats differently

*/


Status RF_E70::receiveStruct(void *structureManaged, uint16_t size_) {
	Status result = E70_SUCCESS;

	uint8_t len = this->serialDef.stream->readBytes((uint8_t *) structureManaged, size_);

	DEBUG_PRINT("Available buffer: ");
	DEBUG_PRINT(len);
	DEBUG_PRINT(" structure size: ");
	DEBUG_PRINTLN(size_);

	if (len!=size_){
		if (len==0){
			result = ERR_E70_NO_RESPONSE_FROM_DEVICE;
		}else{
			result = ERR_E70_DATA_SIZE_NOT_MATCH;
			#ifdef RF_E70_DEBUG
				DEBUG_PRINT(F("Configuration packet: "));
				byte* byteArray = (byte*)&structureManaged;  // Cast the address of config to a byte pointer
				for (int i = 0; i < sizeof(Configuration); i++) {
					if (byteArray[i] < 16) {
						DEBUG_PRINT('0');  // Print a leading zero for single-digit hex values
					}
					DEBUG_PRINT(byteArray[i], HEX);  // Print each byte of the struct in hexadecimal
					DEBUG_PRINT(" ");
				}
				DEBUG_PRINTLN(F(" "));

			#endif

		}
	}
	if (result != E70_SUCCESS) return result;

	result = this->waitCompleteResponse(1000);
	if (result != E70_SUCCESS) return result;

	return result;
}



/*

method to set the mode (program, normal, etc.)

*/

Status RF_E70::setMode(MODE_TYPE mode) {

	// data sheet claims module needs some extra time after mode setting (2ms)
	// most of my projects uses 10 ms, but 40ms is safer

	this->managedDelay(40);

	if (this->m0Pin == -1 && this->m1Pin == -1 && this->m2Pin == -1) {
		DEBUG_PRINTLN(F("The M0, M1 and M2 pins is not set, this mean that you are connect directly the pins as you need!"))
	}else{
		switch (mode)
		{

            case MODE_RSSI_0:
			// Mode 0 | normal operation
			digitalWrite(this->m0Pin, LOW);
			digitalWrite(this->m1Pin, LOW);
			digitalWrite(this->m2Pin, LOW);
			DEBUG_PRINTLN("MODE RSSI!");
			break;
		  case MODE_CONTINUOUS_1:
			digitalWrite(this->m0Pin, HIGH);
			digitalWrite(this->m1Pin, LOW);
			digitalWrite(this->m2Pin, LOW);
			DEBUG_PRINTLN("MODE CONTINUOUS!");
			break;
		  case MODE_SUB_PACKAGE_2:
			digitalWrite(this->m0Pin, LOW);
			digitalWrite(this->m1Pin, HIGH);
			digitalWrite(this->m2Pin, LOW);
			DEBUG_PRINTLN("MODE SUB PACKAGE!");
			break;
		  case MODE_CONFIGURATION_3:
			digitalWrite(this->m0Pin, HIGH);
			digitalWrite(this->m1Pin, HIGH);
			digitalWrite(this->m2Pin, LOW);
			DEBUG_PRINTLN("MODE CONFIGURATION!");
			break;
		  case MODE_CONFIGURATION_5:
//		  case MODE_PROGRAM_3:
			digitalWrite(this->m0Pin, HIGH);
			digitalWrite(this->m1Pin, LOW);
			digitalWrite(this->m2Pin, HIGH);
			DEBUG_PRINTLN("MODE CONFIGURATION!");
			break;
		  case MODE_WOR_4:
			digitalWrite(this->m0Pin, LOW);
			digitalWrite(this->m1Pin, LOW);
			digitalWrite(this->m2Pin, HIGH);
			DEBUG_PRINTLN("MODE WOR!");
			break;
		  case MODE_POWER_SAVING_6:
			digitalWrite(this->m0Pin, LOW);
			digitalWrite(this->m1Pin, HIGH);
			digitalWrite(this->m2Pin, HIGH);
			DEBUG_PRINTLN("MODE POWER SAVING!");
			break;
		  case MODE_SLEEP_7:
			digitalWrite(this->m0Pin, HIGH);
			digitalWrite(this->m1Pin, HIGH);
			digitalWrite(this->m2Pin, HIGH);
			DEBUG_PRINTLN("MODE SLEEP!");
			break;

		  default:
			return ERR_E70_INVALID_PARAM;
		}
	}
	// data sheet says 2ms later control is returned, let's give just a bit more time
	// these modules can take time to activate pins
	this->managedDelay(140);

	// wait until aux pin goes back low
	Status res = this->waitCompleteResponse(1000);

	if (res == E70_SUCCESS){
		this->mode = mode;
	}

	return res;
}

MODE_TYPE RF_E70::getMode(){
	return this->mode;
}

bool RF_E70::writeProgramCommand(PROGRAM_COMMAND cmd){
    uint8_t CMD[3] = {cmd, cmd, cmd};
    uint8_t size = this->serialDef.stream->write(CMD, 3);
    this->managedDelay(50);  //need ti check

    return size!=3;
}


ResponseStructContainer RF_E70::getConfiguration(){
	ResponseStructContainer rc;

	rc.status.code = checkUARTConfiguration(MODE_PROGRAM);
	if (rc.status.code!=E70_SUCCESS) return rc;

	MODE_TYPE prevMode = this->mode;

//	this->serialDef.stream->flush();

	rc.status.code = this->setMode(MODE_PROGRAM);
	if (rc.status.code!=E70_SUCCESS) return rc;

	this->writeProgramCommand(READ_CONFIGURATION);

//	this->serialDef.stream->read();

	rc.data = malloc(sizeof(Configuration));
	rc.status.code = this->receiveStruct((uint8_t *)rc.data, sizeof(Configuration));

//#ifdef RF_E70_DEBUG
//	 this->printParameters((Configuration *)rc.data);
//#endif

	if (rc.status.code!=E70_SUCCESS) {
		this->setMode(prevMode);
		return rc;
	}

	rc.status.code = this->setMode(prevMode);
	if (rc.status.code!=E70_SUCCESS) return rc;

	if (WRONG_FORMAT == ((Configuration *)rc.data)->COMMAND){
		rc.status.code = ERR_E70_WRONG_FORMAT;
	}
	if (RETURNED_COMMAND != ((Configuration *)rc.data)->COMMAND){
		rc.status.code = ERR_E70_HEAD_NOT_RECOGNIZED;
	}

	return rc;
}

RESPONSE_STATUS RF_E70::checkUARTConfiguration(MODE_TYPE mode){
	if ((mode==MODE_CONFIGURATION_3 || mode==MODE_CONFIGURATION_5 )  && this->bpsRate!=UART_BPS_RATE_9600){
		return ERR_E70_WRONG_UART_CONFIG;
	}
	return E70_SUCCESS;
}

ResponseStatus RF_E70::setConfiguration(Configuration configuration, PROGRAM_COMMAND saveType){
	ResponseStatus rc;

	rc.code = checkUARTConfiguration(MODE_PROGRAM);
	if (rc.code!=E70_SUCCESS) return rc;

	MODE_TYPE prevMode = this->mode;

	rc.code = this->setMode(MODE_PROGRAM);
	if (rc.code!=E70_SUCCESS) return rc;

//	this->writeProgramCommand(saveType, REG_ADDRESS_CFG);

//	configuration.HEAD = saveType;
	configuration.COMMAND = saveType;
//	configuration.STARTING_ADDRESS = REG_ADDRESS_CFG;
//	configuration.LENGHT = PL_CONFIGURATION;

		#ifdef RF_E70_DEBUG
			DEBUG_PRINT(F("Configuration packet: "));
			byte* byteArray = (byte*)&configuration;  // Cast the address of config to a byte pointer
			for (int i = 0; i < sizeof(Configuration); i++) {
				if (byteArray[i] < 16) {
					DEBUG_PRINT('0');  // Print a leading zero for single-digit hex values
				}
				DEBUG_PRINT(byteArray[i], HEX);  // Print each byte of the struct in hexadecimal
				DEBUG_PRINT(" ");
			}
			DEBUG_PRINTLN(F(" "));

		#endif



	rc.code = this->sendStruct((uint8_t *)&configuration, sizeof(Configuration));
	if (rc.code!=E70_SUCCESS) {
		this->setMode(prevMode);
		return rc;
	}

	rc.code = this->receiveStruct((uint8_t *)&configuration, sizeof(Configuration));
	// Return 5bytes leng structure that It's strange
//	if (rc.code!=E70_SUCCESS) {
//		this->setMode(prevMode);
//		return rc;
//	}

//	#ifdef RF_E70_DEBUG
//		 this->printParameters((Configuration *)&configuration);
//	#endif

#ifdef RF_E70_DEBUG
	DEBUG_PRINT(F("Configuration packet: "));
	byte* byteArray2 = (byte*)&configuration;  // Cast the address of config to a byte pointer
	for (int i = 0; i < sizeof(Configuration); i++) {
		if (byteArray2[i] < 16) {
			DEBUG_PRINT('0');  // Print a leading zero for single-digit hex values
		}
		DEBUG_PRINT(byteArray2[i], HEX);  // Print each byte of the struct in hexadecimal
		DEBUG_PRINT(" ");
	}
	DEBUG_PRINTLN(F(" "));

#endif

	rc.code = this->setMode(prevMode);
	if (rc.code!=E70_SUCCESS) return rc;

//	if (WRONG_FORMAT == ((Configuration *)&configuration)->COMMAND){
//		rc.code = ERR_E70_WRONG_FORMAT;
//	}
//	if (saveType != ((Configuration *)&configuration)->COMMAND){
//		rc.code = ERR_E70_HEAD_NOT_RECOGNIZED;
//	}

	return rc;
}

ResponseStructContainer RF_E70::getModuleInformation(){
	ResponseStructContainer rc;

	rc.status.code = checkUARTConfiguration(MODE_PROGRAM);
	if (rc.status.code!=E70_SUCCESS) return rc;

	MODE_TYPE prevMode = this->mode;

	rc.status.code = this->setMode(MODE_PROGRAM);
	if (rc.status.code!=E70_SUCCESS) return rc;

	this->writeProgramCommand(READ_VERSION);

	rc.data = malloc(sizeof(ModuleInformation));

//	struct ModuleInformation *moduleInformation = (ModuleInformation *)malloc(sizeof(ModuleInformation));
	rc.status.code = this->receiveStruct((uint8_t *)rc.data, sizeof(ModuleInformation));
	if (rc.status.code!=E70_SUCCESS) {
		this->setMode(prevMode);
		return rc;
	}

	rc.status.code = this->setMode(prevMode);
	if (rc.status.code!=E70_SUCCESS) return rc;

//	this->printParameters(*configuration);

	if (WRONG_FORMAT == ((ModuleInformation *)rc.data)->COMMAND){
		rc.status.code = ERR_E70_WRONG_FORMAT;
	}
	if (READ_VERSION != ((ModuleInformation *)rc.data)->COMMAND){
		rc.status.code = ERR_E70_HEAD_NOT_RECOGNIZED;
	}

	DEBUG_PRINTLN("----------------------------------------");
	DEBUG_PRINT(F("HEAD: "));  DEBUG_PRINT(((ModuleInformation *)rc.data)->COMMAND, BIN);DEBUG_PRINT(" ");

	DEBUG_PRINT(F("Model no.: "));  DEBUG_PRINTLN(((ModuleInformation *)rc.data)->model, HEX);
	DEBUG_PRINT(F("Version  : "));  DEBUG_PRINTLN(((ModuleInformation *)rc.data)->version, HEX);
	DEBUG_PRINT(F("Features : "));  DEBUG_PRINTLN(((ModuleInformation *)rc.data)->features1, HEX);
	DEBUG_PRINT(F("Features : "));  DEBUG_PRINTLN(((ModuleInformation *)rc.data)->features2, HEX);
	DEBUG_PRINT(F("Features : "));  DEBUG_PRINTLN(((ModuleInformation *)rc.data)->features3, HEX);
	DEBUG_PRINT(F("Features : "));  DEBUG_PRINTLN(((ModuleInformation *)rc.data)->features4, HEX);
	DEBUG_PRINT(F("Status : "));  DEBUG_PRINTLN(rc.status.getResponseDescription());
	DEBUG_PRINTLN("----------------------------------------");

//	if (rc.status.code!=E70_SUCCESS) return rc;

//	rc.data = moduleInformation; // malloc(sizeof (moduleInformation));

	return rc;
}


ResponseStatus RF_E70::resetModule(){
	ResponseStatus status;

	status.code = checkUARTConfiguration(MODE_PROGRAM);
	if (status.code!=E70_SUCCESS) return status;

	MODE_TYPE prevMode = this->mode;

	status.code = this->setMode(MODE_PROGRAM);
	if (status.code!=E70_SUCCESS) return status;

	this->writeProgramCommand(RESET_DEVICE);

	status.code = this->waitCompleteResponse(1000);
	if (status.code!=E70_SUCCESS)  {
		this->setMode(prevMode);
		return status;
	}


	status.code = this->setMode(prevMode);
	if (status.code!=E70_SUCCESS) return status;

	return status;
}

ResponseContainer RF_E70::receiveMessage(){
	return RF_E70::receiveMessageComplete();
}
//ResponseContainer RF_E70::receiveMessageRSSI(){
//	return RF_E70::receiveMessageComplete(true);
//}

ResponseContainer RF_E70::receiveMessageComplete(){
	ResponseContainer rc;
	rc.status.code = E70_SUCCESS;
	String tmpData = this->serialDef.stream->readString();

	DEBUG_PRINTLN(tmpData);

    rc.data = tmpData;

	this->cleanUARTBuffer();
	if (rc.status.code!=E70_SUCCESS) {
		return rc;
	}

//	rc.data = message; // malloc(sizeof (moduleInformation));

	return rc;
}

//Stream RF_E70::getStream(){
//	return this->serialDef.stream;
//}

ResponseContainer RF_E70::receiveMessageUntil(char delimiter){
	ResponseContainer rc;
	rc.status.code = E70_SUCCESS;
	rc.data = this->serialDef.stream->readStringUntil(delimiter);
//	this->cleanUARTBuffer();
	if (rc.status.code!=E70_SUCCESS) {
		return rc;
	}

//	rc.data = message; // malloc(sizeof (moduleInformation));

	return rc;
}
ResponseContainer RF_E70::receiveInitialMessage(uint8_t size){
	ResponseContainer rc;
	rc.status.code = E70_SUCCESS;
	char buff[size];
	uint8_t len = this->serialDef.stream->readBytes(buff, size);
	if (len!=size) {
		if (len==0){
			rc.status.code = ERR_E70_NO_RESPONSE_FROM_DEVICE;
		}else{
			rc.status.code = ERR_E70_DATA_SIZE_NOT_MATCH;
		}
		return rc;
	}

	rc.data = buff; // malloc(sizeof (moduleInformation));

	return rc;
}


ResponseStructContainer RF_E70::receiveMessage(const uint8_t size){
	return RF_E70::receiveMessageComplete(size);
}
//ResponseStructContainer RF_E70::receiveMessageRSSI(const uint8_t size){
//	return RF_E70::receiveMessageComplete(size, true);
//}

ResponseStructContainer RF_E70::receiveMessageComplete(const uint8_t size){
	ResponseStructContainer rc;

	rc.data = malloc(size);
	rc.status.code = this->receiveStruct((uint8_t *)rc.data, size);
	if (rc.status.code!=E70_SUCCESS) {
		return rc;
	}

	 this->cleanUARTBuffer();

	return rc;
}

ResponseStructContainer RF_E70::receiveStreamMessage(const uint8_t size){
	return RF_E70::receiveStreamMessageComplete(size);
}

ResponseStructContainer RF_E70::receiveStreamMessageComplete(const uint8_t size){
	ResponseStructContainer rc;

	rc.data = malloc(size);
	rc.status.code = this->receiveStreamStruct((uint8_t *)rc.data, size);
	if (rc.status.code!=E70_SUCCESS) {
		return rc;
	}

	return rc;
}

Status RF_E70::receiveStreamStruct(void *structureManaged, uint16_t size_) {
	Status result = E70_SUCCESS;

	uint8_t len = this->serialDef.stream->readBytes((uint8_t *) structureManaged, size_);

	DEBUG_PRINT("Available buffer: ");
	DEBUG_PRINT(len);
	DEBUG_PRINT(" structure size: ");
	DEBUG_PRINTLN(size_);

	if (len!=size_){
		if (len==0){
			result = ERR_E70_NO_RESPONSE_FROM_DEVICE;
		}else{
			result = ERR_E70_DATA_SIZE_NOT_MATCH;
		}
	}
	if (result != E70_SUCCESS) return result;

	return result;
}


ResponseStatus RF_E70::sendMessage(const void *message, const uint8_t size){
	ResponseStatus status;
	status.code = this->sendStruct((uint8_t *)message, size);
	if (status.code!=E70_SUCCESS) return status;

	return status;
}
ResponseStatus RF_E70::sendMessage(const String message){
	DEBUG_PRINT(F("Send message: "));
	DEBUG_PRINT(message);
	byte size = message.length(); // sizeof(message.c_str())+1;
	DEBUG_PRINT(F(" size: "));
	DEBUG_PRINTLN(size);
	char messageFixed[size];
	memcpy(messageFixed,message.c_str(),size);
	DEBUG_PRINTLN(F(" memcpy "));

	ResponseStatus status;
	status.code = this->sendStruct((uint8_t *)&messageFixed, size);
	if (status.code!=E70_SUCCESS) return status;

//	free(messageFixed);
	return status;
}

ResponseStatus RF_E70::sendFixedMessage(byte ADDH, byte ADDL, byte CHAN, const String message){
//	DEBUG_PRINT("String/size: ");
//	DEBUG_PRINT(message);
//	DEBUG_PRINT("/");
	byte size = message.length(); // sizeof(message.c_str())+1;
//	DEBUG_PRINTLN(size);
//
//	#pragma pack(push, 1)
//	struct FixedStransmissionString {
//		byte ADDH = 0;
//		byte ADDL = 0;
//		byte CHAN = 0;
//		char message[];
//	} fixedStransmission;
//	#pragma pack(pop)
//
//	fixedStransmission.ADDH = ADDH;
//	fixedStransmission.ADDL = ADDL;
//	fixedStransmission.CHAN = CHAN;
//	char* msg = (char*)message.c_str();
//	memcpy(fixedStransmission.message, (char*)msg, size);
////	fixedStransmission.message = message;
//
//	DEBUG_PRINT("Message: ");
//	DEBUG_PRINTLN(fixedStransmission.message);
//
//	ResponseStatus status;
//	status.code = this->sendStruct((uint8_t *)&fixedStransmission, sizeof(fixedStransmission));
//	if (status.code!=E70_SUCCESS) return status;
//
//	return status;
	char messageFixed[size];
	memcpy(messageFixed,message.c_str(),size);
	return this->sendFixedMessage(ADDH, ADDL, CHAN, (uint8_t *)messageFixed, size);
}
ResponseStatus RF_E70::sendBroadcastFixedMessage(byte CHAN, const String message){
	return this->sendFixedMessage(BROADCAST_ADDRESS, BROADCAST_ADDRESS, CHAN, message);
}

typedef struct fixedStransmission
{
	byte ADDH = 0;
	byte ADDL = 0;
	byte CHAN = 0;
	unsigned char message[];
}FixedStransmission;

FixedStransmission *init_stack(int m){
	FixedStransmission *st = (FixedStransmission *)malloc(sizeof(FixedStransmission)+m*sizeof(int));
    return st;
}

ResponseStatus RF_E70::sendFixedMessage( byte ADDH,byte ADDL, byte CHAN, const void *message, const uint8_t size){
//	#pragma pack(push, 1)
//	struct FixedStransmission {
//		byte ADDH = 0;
//		byte ADDL = 0;
//		byte CHAN = 0;
//		unsigned char message[];
//	} fixedStransmission;
//	#pragma pack(pop)


	DEBUG_PRINT(ADDH);


	FixedStransmission *fixedStransmission = init_stack(size);

//	STACK *resize_stack(STACK *st, int m){
//	    if (m<=st->max){
//	         return st; /* Take sure do not kill old values */
//	    }
//	    STACK *st = (STACK *)realloc(sizeof(STACK)+m*sizeof(int));
//	    st->max = m;
//	    return st;
//	}

	fixedStransmission->ADDH = ADDH;
	fixedStransmission->ADDL = ADDL;
	fixedStransmission->CHAN = CHAN;
//	fixedStransmission.message = &message;

	memcpy(fixedStransmission->message,(unsigned char*)message,size);

	ResponseStatus status;
	status.code = this->sendStruct((uint8_t *)fixedStransmission, size+3);

	free(fixedStransmission);

	if (status.code!=E70_SUCCESS) return status;

	return status;
}

//ResponseStatus RF_E70::sendFixedMessage( byte ADDH,byte ADDL, byte CHAN, Stream *streamLocal){
////	#pragma pack(push, 1)
////	struct FixedStransmission {
////		byte ADDH = 0;
////		byte ADDL = 0;
////		byte CHAN = 0;
////		unsigned char message[];
////	} fixedStransmission;
////	#pragma pack(pop)
//
//
//	DEBUG_PRINT(ADDH);
//
//
//	FixedStransmission *fixedStransmission = init_stack(3);
//
////	STACK *resize_stack(STACK *st, int m){
////	    if (m<=st->max){
////	         return st; /* Take sure do not kill old values */
////	    }
////	    STACK *st = (STACK *)realloc(sizeof(STACK)+m*sizeof(int));
////	    st->max = m;
////	    return st;
////	}
//	ResponseStatus status;
//
//	fixedStransmission->ADDH = ADDH;
//	fixedStransmission->ADDL = ADDL;
//	fixedStransmission->CHAN = CHAN;
////	fixedStransmission.message = &message;
//
////	memcpy(fixedStransmission->message,(unsigned char*)message,size);
//
//
//
//	Status result = E70_SUCCESS;
//
//	status.code = result;
//
////	uint8_t len =
//			this->serialDef.stream->write((uint8_t *) fixedStransmission, 3);
//
//    DEBUG_PRINT(F("File available..."));
//    DEBUG_PRINTLN(streamLocal->available());
//
//
//
//	while (streamLocal->available()>0) {
////			uint8_t len =
//					this->serialDef.stream->write(streamLocal->read());
//	}
////	if (len!=size_){
////		DEBUG_PRINT(F("Send... len:"))
////		DEBUG_PRINT(len);
////		DEBUG_PRINT(F(" size:"))
////		DEBUG_PRINT(size_);
////		if (len==0){
////			result = ERR_E70_NO_RESPONSE_FROM_DEVICE;
////		}else{
////			result = ERR_E70_DATA_SIZE_NOT_MATCH;
////		}
////	}
////	if (result != E70_SUCCESS) return result;
//
//	result = this->waitCompleteResponse(5000, 5000);
//
//	if (result != E70_SUCCESS)
//	{
//		status.code = result;
//		return status;
//	}
//    DEBUG_PRINT(F("Clear buffer..."))
//    this->cleanUARTBuffer();
//
//	DEBUG_PRINTLN(F("ok!"))
//
////	status.code = this->sendStruct((uint8_t *)fixedStransmission, size+3);
////
//	free(fixedStransmission);
//
////	if (status.code!=E70_SUCCESS) {
////		status.code = status;
////	}
//
//	return status;
//}
ResponseStatus RF_E70::streamStructMessage(const void *message, const uint8_t size, Stream *streamLocal){
	ResponseStatus status;
	Status result = E70_SUCCESS;

	status.code = result;

    if (streamLocal->available()==0) {
		status.code = ERR_E70_NO_STREAM_FOUND;
		return status;
    }

	uint8_t len = this->serialDef.stream->write((uint8_t *) message, size);
	if (len!=size){
		DEBUG_PRINT(F("Send... len:"))
		DEBUG_PRINT(len);
		DEBUG_PRINT(F(" size:"))
		DEBUG_PRINT(size);
		if (len==0){
			result = ERR_E70_NO_RESPONSE_FROM_DEVICE;
		}else{
			result = ERR_E70_DATA_SIZE_NOT_MATCH;
		}
	}
	if (result != E70_SUCCESS) {
		status.code = result;
		return status;
	}


	DEBUG_PRINT(F("File available... "));
    DEBUG_PRINTLN(streamLocal->available());

    if (streamLocal->available()>0) {
		while (streamLocal->available()>0) {
	//			uint8_t len =
						this->serialDef.stream->write(streamLocal->read());
		}
//    } else {
//		status.code = ERR_E70_NO_STREAM_FOUND;
//		return status;
	}

	result = this->waitCompleteResponse(5000, 5000);

	if (result != E70_SUCCESS)
	{
		status.code = result;
		return status;
	}
    DEBUG_PRINT(F("Clear buffer..."))
    this->cleanUARTBuffer();

	DEBUG_PRINTLN(F("ok!"))

	return status;
}


ResponseStatus RF_E70::streamMessage(Stream *streamLocal){
	ResponseStatus status;
	Status result = E70_SUCCESS;

	status.code = result;

	DEBUG_PRINT(F("File available..."));
    DEBUG_PRINTLN(streamLocal->available());

	while (streamLocal->available()>0) {
//			uint8_t len =
					this->serialDef.stream->write(streamLocal->read());
	}

	result = this->waitCompleteResponse(5000, 5000);

	if (result != E70_SUCCESS)
	{
		status.code = result;
		return status;
	}
    DEBUG_PRINT(F("Clear buffer..."))
    this->cleanUARTBuffer();

	DEBUG_PRINTLN(F("ok!"))

	return status;
}


ConfigurationMessage *init_stack_conf(int m){
	ConfigurationMessage *st = (ConfigurationMessage *)malloc(sizeof(ConfigurationMessage)+m*sizeof(int));
    return st;
}


ResponseStatus RF_E70::sendBroadcastFixedMessage(byte CHAN, const void *message, const uint8_t size){
	return this->sendFixedMessage(0xFF, 0xFF, CHAN, message, size);
}

#define KeeLoq_NLF		0x3A5C742E

unsigned long RF_E70::encrypt(unsigned long data)
{
  unsigned long x = data;
  unsigned long r;
  int keyBitNo, index;
  unsigned long keyBitVal,bitVal;

  for (r = 0; r < 528; r++)
  {
    keyBitNo = r & 63;
    if(keyBitNo < 32)
      keyBitVal = bitRead(this->halfKeyloqKey,keyBitNo); // key low
    else
      keyBitVal = bitRead(this->halfKeyloqKey, keyBitNo - 32);// key hight
    index = 1 * bitRead(x,1) + 2 * bitRead(x,9) + 4 * bitRead(x,20) + 8 * bitRead(x,26) + 16 * bitRead(x,31);
    bitVal = bitRead(x,0) ^ bitRead(x, 16) ^ bitRead(KeeLoq_NLF,index) ^ keyBitVal;
    x = (x>>1) ^ bitVal<<31;
  }
  return x;
}

unsigned long RF_E70::decrypt(unsigned long data)
{
  unsigned long x = data;
  unsigned long r;
  int keyBitNo, index;
  unsigned long keyBitVal,bitVal;

  for (r = 0; r < 528; r++)
  {
    keyBitNo = (15-r) & 63;
    if(keyBitNo < 32)
      keyBitVal = bitRead(this->halfKeyloqKey,keyBitNo); // key low
    else
      keyBitVal = bitRead(this->halfKeyloqKey, keyBitNo - 32); // key hight
    index = 1 * bitRead(x,0) + 2 * bitRead(x,8) + 4 * bitRead(x,19) + 8 * bitRead(x,25) + 16 * bitRead(x,30);
    bitVal = bitRead(x,31) ^ bitRead(x, 15) ^ bitRead(KeeLoq_NLF,index) ^ keyBitVal;
    x = (x<<1) ^ bitVal;
  }
  return x;
 }
#ifdef RF_E70_DEBUG
void RF_E70::printParameters(struct Configuration *configuration) {
	DEBUG_PRINTLN("----------------------------------------");

	DEBUG_PRINT(F("HEAD : "));  DEBUG_PRINT(configuration->COMMAND, HEX);DEBUG_PRINT(" ");
	DEBUG_PRINTLN(F(" "));
	DEBUG_PRINT(F("AddH : "));  DEBUG_PRINTLN(configuration->ADDH, HEX);
	DEBUG_PRINT(F("AddL : "));  DEBUG_PRINTLN(configuration->ADDL, HEX);
	DEBUG_PRINTLN(F(" "));
	DEBUG_PRINT(F("Chan : "));  DEBUG_PRINT(configuration->CHAN.CHAN, DEC); DEBUG_PRINT(" -> "); DEBUG_PRINTLN(configuration->CHAN.getChannelDescription());
	DEBUG_PRINTLN(F(" "));
	DEBUG_PRINT(F("SpeedParityBit     : "));  DEBUG_PRINT(configuration->SPED.uartParity, BIN);DEBUG_PRINT(" -> "); DEBUG_PRINTLN(configuration->SPED.getUARTParityDescription());
	DEBUG_PRINT(F("SpeedUARTDatte     : "));  DEBUG_PRINT(configuration->SPED.uartBaudRate, BIN);DEBUG_PRINT(" -> "); DEBUG_PRINTLN(configuration->SPED.getUARTBaudRateDescription());
	DEBUG_PRINT(F("SpeedAirDataRate   : "));  DEBUG_PRINT(configuration->SPED.airDataRate, BIN);DEBUG_PRINT(" -> "); DEBUG_PRINTLN(configuration->SPED.getAirDataRateDescription());
	DEBUG_PRINTLN(F(" "));
	DEBUG_PRINT(F("OptionFECPacketSett: "));  DEBUG_PRINT(configuration->OPTION.fec, BIN);DEBUG_PRINT(" -> "); DEBUG_PRINTLN(configuration->OPTION.getFECDescription());
	DEBUG_PRINT(F("OptionTranPower    : "));  DEBUG_PRINT(configuration->OPTION.transmissionPower, BIN);DEBUG_PRINT(" -> "); DEBUG_PRINTLN(configuration->OPTION.getTransmissionPowerDescription());
	DEBUG_PRINT(F("OptionIODrive: "));  DEBUG_PRINT(configuration->OPTION.ioDriveMode, BIN);DEBUG_PRINT(" -> "); DEBUG_PRINTLN(configuration->OPTION.getIODroveModeDescription());
	DEBUG_PRINT(F("OptionFixedTransmission: "));  DEBUG_PRINT(configuration->OPTION.fixedTransmission, BIN);DEBUG_PRINT(" -> "); DEBUG_PRINTLN(configuration->OPTION.getFixedTransmissionDescription());
	DEBUG_PRINT(F("OptionWirelessWakeUPTime: "));  DEBUG_PRINT(configuration->OPTION.wirelessWakeupTime, BIN);DEBUG_PRINT(" -> "); DEBUG_PRINTLN(configuration->OPTION.getWirelessWakeUPTimeDescription());


	DEBUG_PRINTLN("----------------------------------------");
}
#endif
