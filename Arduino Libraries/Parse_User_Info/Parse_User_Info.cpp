// This is for the SD card

#include <SPI.h>
#include <SD.h>
#include "Parse_User_Info.h"

Parse_User_Info :: Parse_User_Info(unsigned int CSpin, bool userOrPassword) {
  pinMode(CSpin, OUTPUT);

  if (userOrPassword == 0) {
    _checkCharacter = '%';
  }
  else {
    _checkCharacter = '$';
  }

  bool _arrayCheck [] = {false, false, false, false, false};

  _CSpin = CSpin;
  _userOrPassword = userOrPassword;
}

Parse_User_Info :: setArray() {

}
