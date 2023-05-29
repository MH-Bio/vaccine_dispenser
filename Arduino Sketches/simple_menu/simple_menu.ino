#include <LiquidCrystal.h> // LIBRARY TO ACCESS THE LCD DISPLAY

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Sets up which pins go to the LCD display
int menuCount = 0;

const int SW_pin = 7; // digital pin connected to SW
const int X_pin = 0; // analog pin connected to VRx
const int Y_pin = 1; // analog pin connected to VRy
float joystickX = 0.0;
float joystickY = 0.0;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  lcd.begin(16, 2); // set up the LCD's number of columns and rows

  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
  joystickX = analogRead(X_pin);
  joystickY = analogRead(Y_pin);

  if (joystickX > 1000) {
    menuCount = menuCount + 1;
    if (menuCount > 3) {
      menuCount = 3;
    }
  }
  else if (joystickX < 50) {
    menuCount = menuCount - 1;
    if (menuCount < 0) {
      menuCount = 0;
    }
  }

  else {
    menuCount = menuCount;
  }

  switch (menuCount) {
    case 0:
      lcd.setCursor(0, 0);
      lcd.print("Screen A ");
      break;

    case 1:
      lcd.setCursor(0, 0);
      lcd.print("Screen B ");
      break;

    case 2:
      lcd.setCursor(0, 0);
      lcd.print("Screen C ");
      break;

    case 3:
      lcd.setCursor(0, 0);
      lcd.print("Screen D ");
      break;
  }

  delay(200);

}
