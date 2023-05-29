#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

#ifndef Parse_User_Info_h
#define Parse_User_Info_h

class Parse_User_Info {
  public:
    Parse_User_Info(unsigned int CSpin, bool userOrPassword);
    setArray();
    
  private:
    bool _arrayCheck [5];
    bool _successfulMatch;
    bool _userOrPassword; // use 0 for looking for user, 1 for looking for a password
    char _checkCharacter; // This is the character that we are comparing against, will either be a % for userID or $ for password
    char _inputPassword; // the password that is input by the user
    unsigned int _CSpin;

};

#endif
