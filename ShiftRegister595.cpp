/*
 ShiftRegister595.cpp - Arduino Library for shift register 74HC595
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

#include "ShiftRegister595.h"

ShiftRegister595::ShiftRegister595(uint8_t serialDataPin, uint8_t shiftRegisterClockPin, uint8_t storageRegisterClockPin)
{
	this->_serialDataPin = serialDataPin;
	this->_shiftRegisterClockPin = shiftRegisterClockPin;
	this->_storageRegisterClockPin = storageRegisterClockPin;
}

/* 
 Setup shift register class
 parameter numberOfRegisters - number of registers in circuite
 */
void ShiftRegister595::setup(unsigned int numberOfRegisters)
{
	_numberOfRegisters = numberOfRegisters;
	_numberOfRegisterPins = 8*_numberOfRegisters;
	// Initialize pin status for registers, set LOW value	
	_registerPinsValue = 0;

	pinMode(this->_serialDataPin, OUTPUT);
	pinMode(this->_shiftRegisterClockPin, OUTPUT);
	pinMode(this->_storageRegisterClockPin, OUTPUT);

	write();
}

/* 
 Clear all pins on registers (set 0 on all output pins)
 */
void ShiftRegister595::clear()
{	
	_registerPinsValue = 0;
}

/*
 Write data to shift registers
 */
void ShiftRegister595::write()
{
	digitalWrite(_storageRegisterClockPin, LOW);
	for(int i = _numberOfRegisterPins - 1; i >=  0; i--)
	{
		digitalWrite(_shiftRegisterClockPin, LOW);

		unsigned int pinValue = !!(_registerPinsValue & (1 << i));

		digitalWrite(_serialDataPin, pinValue);
		digitalWrite(_shiftRegisterClockPin, HIGH);
	}
	digitalWrite(_storageRegisterClockPin, HIGH);
}

/*
 Set pin value individually
 parameter registerPin - number of pin (started by number 0)
 parameter value - 1 or 0 (also HIGH or LOW constants of arduino)
 */
void ShiftRegister595::setPin(unsigned int registerPin, unsigned int value)
{		
	if(value==HIGH)
	{
		_registerPinsValue |= (1 << registerPin);
	}
	else
	{
		_registerPinsValue &= ~(1 << registerPin);
	}
}

/*
Set value of all pins at once
parameter pinsValue - value to be send via serial data pin
*/
void ShiftRegister595::setPins(unsigned int pinsValue)
{
	_registerPinsValue = pinsValue;
}

unsigned int ShiftRegister595::getNumberOfRegisters()
{
	return _numberOfRegisters;
}

unsigned int ShiftRegister595::getNumberOfRegisterPins()
{
	return _numberOfRegisterPins;
}
