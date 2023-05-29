#include <LiquidCrystal.h>
#include "Arduino.h"
#include <Keypad.h>

char key;
char key1;
char key2;
char key3;
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {45, 47, 49, 51}; //connect to the row pinouts of the keypadCharacterpad
byte colPins[COLS] = {46, 48, 50}; //connect to the column pinouts of the keypadCharacterpad

char testArray [4 ] {'1', '2', '3', '4'};
bool truthArray [3] = {false, false, false};
int counter = 0;

//******************************************** LCD Stuff ********************************************
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8; // declares which pins are plugged in where
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Sets up which pins go to the LCD display

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); // set up the LCD's number of columns and rows

  //  lcd.setCursor(0, 0); // sets cursor at column 0, row 0
  //  lcd.print("Welcome To");
  //  lcd.setCursor(0, 1); // sets cursor at column 0, row 1
  //  lcd.print("  Arduino   ");
}

void loop() {

  if (truthArray[0] == false) {
    key = keypad.getKey();
  }
  else if (truthArray[1] == false) {
    key1 = keypad.getKey();
  }
  else if (truthArray[2] == false) {
    key2 = keypad.getKey();
  }
  else {
    key3 = keypad.getKey();
  }


  if (key != NO_KEY) {
    Serial.println(key);
    testArray[0] = key;
    Serial.print("Test array[0]: ");
    Serial.println(testArray[0]);
    lcd.setCursor(0, 0); // sets cursor at column 0, row 0
    lcd.print(testArray[0]);
    truthArray[0] = true;
  }

  if (key1 != NO_KEY) {
    Serial.println(key1);
    testArray[1] = key1;
    Serial.print("Test array[1]: ");
    Serial.println(testArray[1]);
    lcd.setCursor(1, 0); // sets cursor at column 0, row 0
    lcd.print(testArray[1]);
    counter = 0;
    truthArray[1] = true;
  }

  if (key2 != NO_KEY) {
    Serial.println(key1);
    testArray[2] = key2;
    Serial.print("Test array[1]: ");
    Serial.println(testArray[1]);
    lcd.setCursor(2, 0); // sets cursor at column 0, row 0
    lcd.print(testArray[2]);
    counter = 0;
    truthArray[2] = true;
  }

  if (truthArray[0] == true && truthArray[1] == true && truthArray[1] == true && key3 == '#') {
    for (int i = 0; i < 4; i++) {
      truthArray[i] = false;
      lcd.setCursor(0, 0); // sets cursor at column 0, row 0
      lcd.clear();
      lcd.setCursor(1, 0); // sets cursor at column 0, row 0
      lcd.clear();
      lcd.setCursor(2, 0); // sets cursor at column 0, row 0
      lcd.clear();
    }
  }

}
