/*


*/
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "AS5048.h"
#include "SPI.h"

//#define AS5048_DEBUG

/*
  Constructor for single sensor SPI
*/
AS5048::AS5048(byte arg_cableSelect_pin){
  _cableSelect = arg_cableSelect_pin);
  errorFlag = false;
  position = 0;
  pinMode(_cableSelect, OUTPUT);
}

AS5048::AS5048(byte arg_cableSelect_pin, byte arg_num_sensors){
  _cableSelect = arg_cableSelect_pin;
  _numSensors = arg_num_sensors;
  errorFlag = false;
  position = 0;
  pinMode(_cableSelect, OUTPUT);
}
