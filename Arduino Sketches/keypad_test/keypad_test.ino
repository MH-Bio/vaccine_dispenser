#include <Adafruit_Keypad.h>
#include <Adafruit_Keypad_Ringbuffer.h>

// For this device the row pins are 3, 5, 7
// The column pins are 2, 4, 6, 8
// Column 1 = Pin 4
// Column 2 = Pin 2
// Column 3 = Pin 6
// Row 1 = Pin 3
// Row 2 = Pin 8
// Row 3 = Pin 7
// Row 4 = Pin 5

//#include <Adafruit_Keypad.h>
//#include <EventBuffer.h>

const byte ROWS = 4; // rows
const byte COLS = 3; // columns

char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
//  {'#', '0', '*'},
//  {'9', '8', '7'},
//  {'6', '5', '4'},
//  {'3', '2', '1'}
};

byte rowPins[ROWS] = {45, 47, 49, 43}; //connect to the row pinouts of the keypadCharacterpad
byte colPins[COLS] = {46, 48, 42}; //connect to the column pinouts of the keypadCharacterpad
//initialize an instance of class NewKeypad
Adafruit_Keypad customKeypad = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  customKeypad.begin();
}

void loop() {
  customKeypad.tick();

  while (customKeypad.available()) {
    keypadEvent e = customKeypad.read();
    Serial.print((char)e.bit.KEY);
    if (e.bit.EVENT == KEY_JUST_PRESSED) Serial.println(" pressed");
    else if (e.bit.EVENT == KEY_JUST_RELEASED) Serial.println(" released");
  }

  delay(10);
}
