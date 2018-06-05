# ShiftRegister595 #

Arduino library for shift registers 595

## Install ##

Copy folder to your libraries

## Example ##

- Set current pin to HIGH / LOW

```cpp
// file ShiftRegisterSetPin.ino

#include <ShiftRegister595.h>

#define PIN_DS 3
#define PIN_SHCP 4
#define PIN_STCP 5

ShiftRegister595 shiftRegister595(PIN_DS, PIN_SHCP, PIN_STCP);

void setup()
{
  shiftRegister595.setup(1);// setup register library
}

void loop()
{	
  shiftRegister595.setPin(0, HIGH);// set first pin to HIGH
  shiftRegister595.write();// write to register(s)
  delay(1000);
  shiftRegister595.setPin(0, LOW);// set first pin to LOW
  shiftRegister595.write();// write to register(s)
  delay(1000);
}

```

- Set All pings to HIGH or LOW

```cpp
#include <ShiftRegister595.h>

#define PIN_DS 3
#define PIN_SHCP 4
#define PIN_STCP 5

ShiftRegister595 shiftRegister595(PIN_DS, PIN_SHCP, PIN_STCP);

void setup()
{
  shiftRegister595.setup(1);// setup register library
}

void loop()
{	
  shiftRegister595.setPins(255);// set all pins to HIGH
  shiftRegister595.write();// write to register(s)
  delay(1000);
  shiftRegister595.setPins(0);// set all pins to LOW
  shiftRegister595.write();// write to register(s)
  delay(1000);
}

```