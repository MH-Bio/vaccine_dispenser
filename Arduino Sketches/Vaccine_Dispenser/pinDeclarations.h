// This .h file is for my pin declarations

#ifndef PINDECLARATIONS_H
#define PINDECLARATIONS_H

//******************************************* H-Bridge Pins *****************************************
const int DIR_A = 5;  // forward direction
const int DIR_B = 6;  // reverse direcion
const int PWM = 7;    // pulse width modulation
//***************************************************************************************************

//****************************************** Joystick Stuff *****************************************
const int SW_pin = 23;     // digital pin that the joystick is plugged into
const int X_pin = A1;      // analog pin connected to VRx
const int Y_pin = A2;      // analog pin connected to VRy
//***************************************************************************************************

//************************************** keypadCharacterpad Stuff ***********************************
const byte ROWS = 4; // rows
const byte COLS = 3; // columns

char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {33, 34, 35, 36}; //connect to the row pinouts of the keypadCharacterpad
byte colPins[COLS] = {30, 31, 32};     //connect to the column pinouts of the keypadCharacterpad
//***************************************************************************************************

//******************************************** LCD Stuff ********************************************
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8; // declares which pins are plugged in where
//***************************************************************************************************

//******************************************** SDA Pins *********************************************
const int SDChipSelect = 22;          // SD card chip select pin
const int potentiometerCS = 29;       // chip select pin for the digital potentiometer (cooling module control)
const int lockPullupResistorPin = 4; // This sets the pin that will be used as the lock's pullup resistor
const int lockRelayPin = 28;          // Sets the pin that will be used to communicate with the lock
//***************************************************************************************************

//**************************************** Temperature Stuff ****************************************
int temperaturePin = A0;              // analog pin A0
const int temperatureOutputPin = 44;  // sets the pin which will be used to control the pletier module
//***************************************************************************************************

#endif
