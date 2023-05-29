void keypadSetup() {
  keyPad[0].initButton(&tft,
                       195,               // x button offset
                       95,                // y button offset
                       75,                // size of button in x direction
                       60,                // size of button in y direction
                       WHITE,             // button outline color
                       LIGHTGREY,         // button fill color
                       BLUE,              // text color
                       keypadLabels[0],   // button text
                       BUTTON_TEXTSIZE    // size of button text
                      );                  // closing parenthesis and semicolon

  keyPad[1].initButton(&tft,
                       285,               // x button offset
                       95,                // y button offset
                       75,                // size of button in x direction
                       60,                // size of button in y direction
                       WHITE,             // button outline color
                       LIGHTGREY,         // button fill color
                       BLUE,              // text color
                       keypadLabels[1],   // button text
                       BUTTON_TEXTSIZE    // size of button text
                      );                  // closing parenthesis and semicolon

  keyPad[2].initButton(&tft,
                       375,               // x button offset
                       95,                // y button offset
                       75,                // size of button in x direction
                       60,                // size of button in y direction
                       WHITE,             // button outline color
                       LIGHTGREY,         // button fill color
                       BLUE,              // text color
                       keypadLabels[2],   // button text
                       BUTTON_TEXTSIZE    // size of button text
                      );                  // closing parenthesis and semicolon

  keyPad[3].initButton(&tft,
                       195,               // x button offset
                       160,               // y button offset
                       75,                // size of button in x direction
                       60,                // size of button in y direction
                       WHITE,             // button outline color
                       LIGHTGREY,         // button fill color
                       BLUE,              // text color
                       keypadLabels[3],   // button text
                       BUTTON_TEXTSIZE    // size of button text
                      );                  // closing parenthesis and semicolon

  keyPad[4].initButton(&tft,
                       285,               // x button offset
                       160,               // y button offset
                       75,                // size of button in x direction
                       60,                // size of button in y direction
                       WHITE,             // button outline color
                       LIGHTGREY,         // button fill color
                       BLUE,              // text color
                       keypadLabels[4],   // button text
                       BUTTON_TEXTSIZE    // size of button text
                      );                  // closing parenthesis and semicolon

  keyPad[5].initButton(&tft,
                       375,               // x button offset
                       160,               // y button offset
                       75,                // size of button in x direction
                       60,                // size of button in y direction
                       WHITE,             // button outline color
                       LIGHTGREY,         // button fill color
                       BLUE,              // text color
                       keypadLabels[5],   // button text
                       BUTTON_TEXTSIZE    // size of button text
                      );                  // closing parenthesis and semicolon

  keyPad[6].initButton(&tft,
                       195,               // x button offset
                       225,               // y button offset
                       75,                // size of button in x direction
                       60,                // size of button in y direction
                       WHITE,             // button outline color
                       LIGHTGREY,         // button fill color
                       BLUE,              // text color
                       keypadLabels[6],   // button text
                       BUTTON_TEXTSIZE    // size of button text
                      );                  // closing parenthesis and semicolon

  keyPad[7].initButton(&tft,
                       285,               // x button offset
                       225,               // y button offset
                       75,                // size of button in x direction
                       60,                // size of button in y direction
                       WHITE,             // button outline color
                       LIGHTGREY,         // button fill color
                       BLUE,              // text color
                       keypadLabels[7],   // button text
                       BUTTON_TEXTSIZE    // size of button text
                      );                  // closing parenthesis and semicolon

  keyPad[8].initButton(&tft,
                       375,               // x button offset
                       225,               // y button offset
                       75,                // size of button in x direction
                       60,                // size of button in y direction
                       WHITE,             // button outline color
                       LIGHTGREY,         // button fill color
                       BLUE,              // text color
                       keypadLabels[8],   // button text
                       BUTTON_TEXTSIZE    // size of button text
                      );                  // closing parenthesis and semicolon

  keyPad[9].initButton(&tft,
                       285,               // x button offset
                       290,               // y button offset
                       75,                // size of button in x direction
                       60,                // size of button in y direction
                       WHITE,             // button outline color
                       LIGHTGREY,         // button fill color
                       BLUE,              // text color
                       keypadLabels[9],   // button text
                       BUTTON_TEXTSIZE    // size of button text
                      );                  // closing parenthesis and semicolon

  for (int i = 0; i < 10; i++) {
    keyPad[i].drawButton(); // draws all 10 keypad buttons
  }
}

char keyMatrix(int16_t x, int16_t y) {
  // determine where on the Y axis you hit the keypad
  x=480-x;
  if (y > 60 && y < 120) {
    keypadY = 0;
    keypadX = xKeypad(x, y);
    tft.fillRect(x, y, 30, 30, GREEN);
  }
  else if (y > 125 && y < 185) {
    keypadY = 3;
    keypadX = xKeypad(x, y);
    tft.fillRect(x, y, 30, 30, CYAN);
  }
  else if (y > 190 && y < 250) {
    keypadY = 6;
    keypadX = xKeypad(x, y);
    tft.fillRect(x, y, 30, 30, MAGENTA);
  }
  else if (y > 420 && y < 480) {
    keypadY = -20;
    keypadX = xKeypad(x, y);
    tft.fillRect(x, y, 30, 30, DARKGREY);
  }
  else {
    keypadY = 9;
    tft.fillRect(x, y, 30, 30, ORANGE);
  }

  // determine where on the x axis you hit the keypad


  keypadSum = keypadX + keypadY;  // add the x and y values to determine which key was pressed

  return keypadSum;

}

char xKeypad(int16_t x, int16_t y) {
  
  //x = 480 - x; // Reverse correction
  
  if (x > 338 && x < 412) {      // x > 70 && x < 144 | x > 336 && x < 410 | 
    keypadX = 51;
    tft.fillRect(x, y, 30, 30, RED);
  }
  else if (x > 248 && x < 322) { // x > 159 && x < 233 | x > 247 && x < 321  | 
    keypadX = 50;
    tft.fillRect(x, y, 30, 30, BLUE);
  }
  else if (x > 158 && x < 232) { // x > 248 && x < 322 | x > 158 && x < 232  | x > 158 && x < 232
    keypadX = 49;
    tft.fillRect(x, y, 30, 30, YELLOW);
  }
  else {
    keypadX = 45;
    tft.fillRect(x, 150, 30, 30, WHITE);
  }

  return keypadX;
}
