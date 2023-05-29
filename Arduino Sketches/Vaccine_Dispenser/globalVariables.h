// This .h file is for my global variables that I will be using in my project

#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H

//************************************* PASSWORD LOADING STUFF **************************************
char userStart [5] = {'u', 's', 'e', 'r', '<'};
char idStart [7] = {'u', 's', 'e', 'r', 'i', 'd', '<'};
char passwordStart [9] = {'p', 'a', 's', 's', 'w', 'o', 'r', 'd', '<'};
char terminal = '>';
int lengthCounter = 0;
String input;
char savedPassword [4] = {};
int y = 0;
char nameArray [50] = {};
bool nameArrayFlag = false;
char testCharacter;
int z = 0;
//***************************************************************************************************

//********************************************** ARRAYS *********************************************
boolean iDFlag [4] = {false, false, false, false}; // Used to check which place we are in the loop
char passwordInput [4] = {95, 95, 95, 95}; // stores the password values, 95 = *
char passwordMask [4] = {'_', '_', '_', '_'}; // what will be displayed for password values
char userID [4] = {'_', '_', '_', '_'}; // A blank array that will have four slots for a user input
char userIDCheck [4] = {'1', '2', '3', '4'}; // This is the "Correct" user ID that will be compared to the input
//***************************************************************************************************

//********************************************* BOOLEAN *********************************************
bool dispensed = false;        // runs the dispense routine one time
bool englishFlag = true;       // default, used for English language
bool japaneseFlag = false;     //日の丸です！
bool lockActivated = false;    // used in the unlock function to check if the lock has been unlocked
bool menuChangeFlag = false;   // used for the unlock refill compartment submenu
bool spanishFlag = false;      // used for Spanish language
bool successfulMatch = false;  // used in the SD card password array
bool unlockFlag = false;       // used to unlock the main compartment
//***************************************************************************************************

//*********************************************** CHAR **********************************************
char checkCharacter = '%';         // used in the password array to separate values
char key0;                         // used in the keypad entry
char key1;                         // used in the keypad entry
char key2;                         // used in the keypad entry
char key3;                         // used in the keypad entry
char keypadCharacterpadInput = 0;  // The last entered value on the keypad
char menuChoice;                   // used for menu selection
//***************************************************************************************************

//*********************************************** FLOAT *********************************************
float currentTemperature = 0;  // stores the current temperature
float joystickX = 0.0;         // joystick in the X direction
float joystickY = 0.0;         // joystick in the Y direction
//***************************************************************************************************

//************************************************ INT **********************************************
int currentMenu = 0;
int desiredTempMenu = 0;
int dispenseMenu = 0;
int iDEntry = 0;
int keypadCharacterpadSelection = 0;
int mainMenu = 0;
int menuCount = 0; // used to select which screen you are working in
int setTemperature = 43;  // set temperature point
int settingsMenu = 0;
int passwordMenu = 0;

int day;          // RTCC day of the week (Sun - Sat)
int hour;         // RTCC hour
int minute;       // RTCC minute
int second;       // RTCC second
//***************************************************************************************************

#endif
