// Found 0x9486 LCD driver
// TFT size is 320x480

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include <TouchScreen.h>
#include <MCUFRIEND_kbv.h>
#include "definations.h"

// Global variables
bool dontDraw = false;
double touchPoint;
char textfield[TEXT_LEN + 1] = "";
uint8_t textfield_i = 0;

// Create 3 buttons to be used on the main screen
Adafruit_GFX_Button buttons[3];
Adafruit_GFX_Button keyPad[10];

char buttonlabels[22][10] = {"Dispense", "Unlock", "Settings"};
char keypadLabels[10][2] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
uint16_t buttoncolors[3] = {BLUE, BLUE, BLUE};
char usernameDispalyInput[4][2] = {"-", "-", "-", "-"};
int username[4] = {0, 0, 0, 0};
char keypadY = 0;
char keypadX = 0;
char keypadSum = 0;

// Create a new instance of the touchscreen
MCUFRIEND_kbv tft;
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);


void setup() {
  Serial.begin(9600);
  Serial.println(F("TFT LCD test"));

  tftSetup();

  mainMenuDesign(); // calls the design for the main menu
  drawMainMenu(); // draws the design called in the previous line

}


void loop(void) {
  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();
  digitalWrite(13, LOW);

  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  if (p.z > MINPRESSURE/* && p.z < MAXPRESSURE*/) {
    p.x = map(p.x, TS_MINX, TS_MAXX, tft.width(), 0);
    p.y = tft.height() - (map(p.y, TS_MINY, TS_MAXY, tft.height(), 0));
  }

  // take note that the x axis is inverted, but the y axis is normal
  // button mapping

  if (p.x > 240 && p.x < 480 && p.y > 0 && p.y < 150) {//40 70
    buttons[0].press(true);
    buttons[1].press(false);
    buttons[2].press(false);
  }
  else if (p.x > 0 && p.x < 230 && p.y > 0 && p.y < 150) {
    buttons[0].press(false);
    buttons[1].press(true);
    buttons[2].press(false);
  }
  else if (p.x > 240 && p.x < 480 && p.y > 160 && p.y < 320) {
    buttons[0].press(false);
    buttons[1].press(false);
    buttons[2].press(true);
  }
  else if (dontDraw == false) {
    buttons[0].press(false);
    buttons[1].press(false);
    buttons[2].press(false);
  }
  else {
    buttons[0].press(false);
    buttons[1].press(false);
    buttons[2].press(false);
  }

  // now we can ask the buttons if their state has changed

  for (uint8_t b = 0; b < 3; b++) {

    if (buttons[b].justReleased()) {

      Serial.print("Released: ");
      Serial.println(b);

      if (dontDraw == false) {
        buttons[b].drawButton();  // draw normal
      }
      else {

      }
    }

    if (buttons[b].justPressed()) {

      if (dontDraw == false) { // DO draw the main menu
        buttons[b].drawButton(true);  // draw invert!
      }

      else {

      }

      // Dispense Button
      if (b == 0) {
        if (p.z > MINPRESSURE/* && p.z < MAXPRESSURE*/) {
          p.x = map(p.x, TS_MINX, TS_MAXX, tft.width(), 0);
          p.y = tft.height() - (map(p.y, TS_MINY, TS_MAXY, tft.height(), 0));
        }
        dontDraw = true; // don't draw the main menu

        drawDispenseMenu(); // draw the dispense menu

        keypadSetup();
        for (int i = 0; i < 4; i++) {
          tft.setCursor(235 + (i * 30), 13);
          tft.setTextColor(WHITE);
          tft.print(usernameDispalyInput[i]);
        }


        //tft.fillRect(480-p.x, p.y, 30, 30, WHITE);
        //        if (p.y > 60 && p.y < 120 && p.x > 338 && p.x < 412) { // button 1
        //          usernameDispalyInput[0][0] = 49;
        //        }
        if (p.y > 200 && p.y < 320 && p.x > 248 && p.x < 322) { // button 2
          usernameDispalyInput[0][0] = 50;
        }
        //        if (keyPad[1].contains(p.x + 60, p.y)) {
        //          keyPad[1].press(true);
        //        }
        //        else {
        //          keyPad[1].press(false);
        //        }
        //
        //        if (keyPad[1].justReleased()) {
        //          keyPad[b].drawButton();  // draw normal
        //        }
        //
        //        if (keyPad[1].justPressed()) {
        //          keyPad[1].drawButton(true);  // draw invert!
        //        }

        //        else if (p.y > 60 && p.y < 120 && p.x > 0 && p.x < 200) { // button 3
        //          usernameDispalyInput[0][0] = 51;
        //        }
        //
        //        else if (p.y > 125 && p.y < 185 && p.x > 338 && p.x < 412) { // button 4
        //          usernameDispalyInput[1][0] = 52;
        //        }
        //
        //        else if (p.y > 125 && p.y < 185 && p.x > 200 && p.x < 320) { // button 5
        //          usernameDispalyInput[1][0] = 53;
        //        }
        //
        //        else if (p.y > 125&& p.y < 185 && p.x > 0 && p.x < 200) { // button 6
        //          usernameDispalyInput[1][0] = 54;
        //        }
        //
        //        else if (p.y > 190 && p.y < 250 && p.x > 338 && p.x < 412) { // button 7
        //          usernameDispalyInput[2][0] = 55;
        //        }
        //
        //        else if (p.y > 190 && p.y < 250 && p.x > 200 && p.x < 320) { // button 8
        //          usernameDispalyInput[2][0] = 56;
        //        }
        //
        //        else if (p.y > 190 && p.y < 250 && p.x > 0 && p.x < 200) { // button 9
        //          usernameDispalyInput[2][0] = 57;
        //        }
        //
        //        else if (p.y > 240 && p.y < 480 && p.x > 420 && p.x < 480) { // button 0
        //          usernameDispalyInput[3][0] = 30;
        //        }


        if (p.x > 365 && p.x < 480 && p.y > 0 && p.y < 75) { // if we touch the back button
          backButtonAction(); // go back to the main menu
        }

      }

      // Unlock Button
      if (b == 1) {

      }

      //Settings Button
      if (b == 2) {

      }

      delay(100); // UI debouncing

    }

  }

}
