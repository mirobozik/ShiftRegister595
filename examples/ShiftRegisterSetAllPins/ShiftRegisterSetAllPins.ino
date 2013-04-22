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
