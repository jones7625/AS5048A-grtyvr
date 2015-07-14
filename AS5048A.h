/*
AS5048.h - Library for interacting with the AS5048A magnetic angular position sensors
http://ams.com/eng/Products/Position-Sensors/Magnetic-Rotary-Position-Sensors/AS5048A
Created by Guy Thomas, July 2015

*/
#ifndef AS5048_h
#define AS5048_h
#define LIBRARY_VERSION 0.1

#define AS5048A_CMD_READ 0x4000                     // Flag for read attempt
#define AS5048A_CMD_WRITE 0x8000                    // Flag for write attempt
#define AS5048A_REGISTER_CLEAR_RERROR 0x0001        // Register to read to get error information
                                                    // bit 2 = parity error
                                                    // bit 1 = Command invalid
                                                    // bit 0 = Framing error
#define AS5048_NO_OPERATION 0x0                     // No Operation, dummy information
#define AS5048A_PROGRAMMING_CONTROL 0x0003          // Flag to enable programming mode
                                                    // bit 6 = verify
                                                    // bit 3 = Burn
                                                    // bit 0 = Programming Enable
#define AS5048A_OTP_REGISTER_ZERO_POS_HIGH 0x0016   // Register for Zero Position high byte
#define AS5048A_OTP_REGISTER_ZERO_POS_LOW 0x0017    // Register for Zero Position low byte
#define AS5048A_REGISTER_DIAGNOSTIC_AGC 0x3FFD      // Register for Diagnostics and Automatic Gain Controll
                                                    // bit 11 = Comp High 1 = high magnetic field
                                                    // bit 10 = Comp Low 1 = low magnetic field
                                                    // bit 9 = Cordic OverFlow 1 = out of range error
                                                    // if this bit is set the angle register has the last valid value
                                                    // bit 8 = Offset Compensation Finished 1 = finished
                                                    // Automatic Gain Control register 0 = high field, 255 = low field
#define AS5048A_REGISTER_MAGNITUDE 0x3FFE           // Magnitude register
#define AS5048A_REGISTER_ANGLE 0x3FFF               // Angle information after zero position adder (if any)

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "SPI.h"

class AS5048
{
  Public:
    // Constructors
    AS5048(int _arg_cs_pin);                        // single sensor on a seperate Cable Select pin
    AS5048(int _arg_cs_pin, int _arg_num_sensors);  // _arg_num_sensors daisy chained with Cable Select = _arg_cs_pin 
    // Initializer that will set up the SPI bus.
    void init();
    // close the SPI bus
    void close();
    // read a register
    word readAngle(word registerAddress);
  Private:
  byte _calc_even_parity(word value);
}
#endif
