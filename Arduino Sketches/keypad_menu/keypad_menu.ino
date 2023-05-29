#include <LiquidCrystal.h> // LIBRARY TO ACCESS THE LCD DISPLAY
#include <Adafruit_Keypad.h>
#include <EventBuffer.h>

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Sets up which pins go to the LCD display
int menuCount = 0;
char keypadCharacter;
int keypadSelection = 0;
int combinedMenu = 0;
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
  joystickX = analogRead(X_pin);
  joystickY = analogRead(Y_pin);

  while (customKeypad.available()) {
    keypadEvent e = customKeypad.read();
    keypadCharacter = (int)e.bit.KEY;

    switch (keypadCharacter) {
      case 49: // 49 is the ASCII character for 1
        keypadSelection = 1;
        break;

      case 50: // 50 is the ASCII character for 2
        keypadSelection = 2;
        break;

      case 51: // 51 is the ASCII character for 3
        keypadSelection = 3;
        break;

      default:
        keypadSelection = 0;
        break;
    }
  }

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
      if (keypadSelection == 3) {
        lcd.print("Blastoise ");
        lcd.setCursor(0, 1);
        lcd.print("<-[2]");
      }

      else if (keypadSelection == 2) {
        lcd.print("Wartortle ");
        lcd.setCursor(0, 1);
        lcd.print("<-[1]  [3]->");
      }

      else if (keypadSelection == 1) {
        lcd.print("Squirtle ");
        lcd.setCursor(0, 1);
        lcd.print("       [2]->");
      }

      else {
        lcd.print("Squirtle ");
        lcd.setCursor(0, 1);
        lcd.print("       [2]->");
      }

      break;

    case 1:
      lcd.setCursor(0, 0);
      lcd.clear();
      if (keypadSelection == 3) {
        lcd.print("Charzard ");
        lcd.setCursor(0, 1);
        lcd.print("<-[2]");
      }

      else if (keypadSelection == 2) {
        lcd.print("Charmeleon ");
        lcd.setCursor(0, 1);
        lcd.print("<-[1]  [3]->");
      }

      else if (keypadSelection == 1) {
        lcd.print("Charmander ");
        lcd.setCursor(0, 1);
        lcd.print("       [2]->");
      }

      else {
        lcd.print("Charmander ");
        lcd.setCursor(0, 1);
        lcd.print("       [2]->");
      }

      break;

    case 2:
      lcd.setCursor(0, 0);
      lcd.clear();
      if (keypadSelection == 3) {
        lcd.print("Venusaur ");
        lcd.setCursor(0, 1);
        lcd.print("<-[2]");
      }

      else if (keypadSelection == 2) {
        lcd.print("Ivysaur ");
        lcd.setCursor(0, 1);
        lcd.print("<-[1]  [3]->");
      }

      else if (keypadSelection == 1) {
        lcd.print("Bulbasaur ");
        lcd.setCursor(0, 1);
        lcd.print("       [2]->");
      }

      else {
        lcd.print("Bulbasaur ");
        lcd.setCursor(0, 1);
        lcd.print("       [2]->");
      }

      break;

    case 3:
      lcd.setCursor(0, 0);
      lcd.clear();
      if (keypadSelection == 2) {
        lcd.print("Raichu ");
        lcd.setCursor(0, 1);
        lcd.print("<-[1]");
      }

      else if (keypadSelection == 1) {
        lcd.print("Pikachu ");
        lcd.setCursor(0, 1);
        lcd.print("       [2]->");
      }

      else {
        lcd.print("Pikachu ");
        lcd.setCursor(0, 1);
        lcd.print("       [2]->");
      }

      break;

  }

  delay(250);

}


///////////////////////// ASCII CHEAT SHEAT /////////////////////////
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
/////////////////////////////////////////////////////////////////////
