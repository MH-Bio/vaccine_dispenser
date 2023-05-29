#include <LiquidCrystal.h> // LIBRARY TO ACCESS THE LCD DISPLAY
#include <Adafruit_Keypad.h>
#include <EventBuffer.h>

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Sets up which pins go to the LCD display
int menuCount = 0;
char keypadCharacter;
int keypadSelection = 0;
int combinedMenu = 0;
int keypadInput = 0;
int count = 0; // used for counting array values for iDFlag

// user ID and password stuff
int userID [4] = { };
int userIDCheck [4] = {1, 2, 3, 4};
boolean iDFlag [4] = {false, false, false, false};

char passwordInput [4] = {'_', '_', '_', '_'};
bool isWaiting = true;

// Declare rows and columns for keypad
const byte ROWS = 4; // rows
const byte COLS = 3; // columns

const int SW_pin = 53; // digital pin connected to SW
const int X_pin = 0; // analog pin connected to VRx
const int Y_pin = 1; // analog pin connected to VRy
float joystickX = 0.0;
float joystickY = 0.0;

char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {45, 47, 49, 51}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {46, 48, 50}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Adafruit_Keypad customKeypad = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  lcd.begin(16, 2); // set up the LCD's number of columns and rows

  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);

  customKeypad.begin(); // starts the keypad
}

void loop() {
  customKeypad.tick();

  while (customKeypad.available()) {
    keypadEvent e = customKeypad.read();
    keypadCharacter = (int)e.bit.KEY;

    switch (keypadCharacter) {

      case 48: // 51 is the ASCII character for 3
        keypadSelection = 0;
        break;

      case 49: // 49 is the ASCII character for 1
        keypadSelection = 1;
        break;

      case 50: // 50 is the ASCII character for 2
        keypadSelection = 2;
        break;

      case 51: // 51 is the ASCII character for 3
        keypadSelection = 3;
        break;

      case 52: // 51 is the ASCII character for 3
        keypadSelection = 4;
        break;

      case 53: // 51 is the ASCII character for 3
        keypadSelection = 5;
        break;

      case 54: // 51 is the ASCII character for 3
        keypadSelection = 6;
        break;

      case 55: // 51 is the ASCII character for 3
        keypadSelection = 7;
        break;

      case 56: // 51 is the ASCII character for 3
        keypadSelection = 8;
        break;

      case 57: // 51 is the ASCII character for 3
        keypadSelection = 9;
        break;

      default:
        keypadSelection = keypadSelection;
        break;
    }
  }

  if (isWaiting == true){
    userID[0] = keypadSelection;
    
    for ( int i = 0; i<4;i++){
      if (iDFlag[i] == true){
        count = count + 1;
      }
      else {
        count = count;
      }
    }
    iDFlag[0] = true;
  }
  

  joystickX = analogRead(X_pin);
  joystickY = analogRead(Y_pin);

  // This section of code determines allows the joystick to cycle through menu options.
  // It also prevents going to far in a menu, by capping out the menu count choice at 3 or 0.
  if (joystickX > 1000) {
    menuCount = menuCount + 1;
    keypadSelection = 0;
    if (menuCount > 3) {
      menuCount = 3;
    }
  }
  else if (joystickX < 50) {
    menuCount = menuCount - 1;
    keypadSelection = 0;
    if (menuCount < 0) {
      menuCount = 0;
    }
  }

  else {
    menuCount = menuCount;
  }

  // This portion of code choses the menu option
  switch (menuCount) {
    case 0:
      lcd.setCursor(0, 0);
      lcd.clear();
      lcd.print("Enter User ID:");

      // first digit of the user input menu
      lcd.setCursor(0, 1);
      lcd.print(userID[0]);

      // second digit of the user input menu
      lcd.setCursor(1, 1);
      lcd.print(userID[1]);

      // third digit of the user input menu
      lcd.setCursor(2, 1);
      lcd.print(userID[2]);

      // fourth digit of the user input menu
      lcd.setCursor(3, 1);
      lcd.print(userID[3]);

      break;

    case 1:
      lcd.setCursor(0, 0);
      lcd.clear();
      lcd.print("menu B");


      break;

    case 2:
      lcd.setCursor(0, 0);
      lcd.clear();
      lcd.print("menu C");


      break;

    case 3:
      lcd.setCursor(0, 0);
      lcd.clear();
      lcd.print("menu D");


      break;

  }

  delay(250);

}


///////////////////////// ASCII CHEAT SHEAT ///////////////////////////////////////
// # => 35
// * => 42
// 0 => 48
// 1 => 49
// 2 => 50
// 3 => 51
// 4 => 52
// 5 => 53
// 6 => 54
// 7 => 55
// 8 => 56
// 9 => 57
///////////////////////////////////////////////////////////////////////////////////
// Micro SD Card Tutorial: https://www.instructables.com/id/Micro-SD-Card-Tutorial/
