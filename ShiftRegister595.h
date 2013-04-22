/*
 ShiftRegister595.h - Arduino Library for shift register 74HC595
 Version 1.0.0 March, 2013
 
 Copyright (c) 2013 Miroslav Božík. All right reserved.
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 */ 

#ifndef SHIFT_REGISTER_595_H
#define SHIFT_REGISTER_595_H

#include <Arduino.h>

class ShiftRegister595 
{

public:
	/* 
	 Constructor of class ShiftRegister595,
	 parameter serialDataPin - uint8_t type, is pin where is connected to DS (serial data) input on shift register IC (74HC595),
	 parameter shiftRegisterClockPin - uint8_t type, is pin of arduino that is connected to SHCP clock pin on shift register IC (74HC595),
	 parameter shiftRegisterClockPin - uint8_t type, is pin of arduino that is connected to STCP clock pin on shift register IC (74HC595)
	 */
	ShiftRegister595(uint8_t serialDataPin, uint8_t shiftRegisterClockPin, uint8_t storageRegisterClockPin);
	/*
	 Setup of class, set output pins and default values
	 parameter unsigned int numberOfRegisters - set number of connected registers (mutually)
	*/
	void setup(unsigned int numberOfRegisters);
	/*
	 Return number of connected registers
	*/
	unsigned int getNumberOfRegisters();
	/*
	 Return number of pins all connected registers
	*/
	unsigned int getNumberOfRegisterPins();
	/*
	 Clear all data - all pins are off
	*/
	void clear();
	/*
	 Write data to shift register
	*/
	void write();
	/*
	 Set pin value individually
	 parameter registerPin - number of pin (started by number 0)
	 parameter value - 1 or 0 (also HIGH or LOW constants of arduino)
	*/
	void setPin(unsigned int registerPin, unsigned int value);
	/*
	 Set value of all pins at once	
	 parameter pinsValue - value to be send via serial data pin
	*/
	void setPins(unsigned int pinsValue);

private:
	uint8_t _serialDataPin;
	uint8_t _shiftRegisterClockPin;
	uint8_t _storageRegisterClockPin;
	unsigned int _numberOfRegisters;
	unsigned int _numberOfRegisterPins;
	unsigned int _registerPinsValue;	

};

#endif