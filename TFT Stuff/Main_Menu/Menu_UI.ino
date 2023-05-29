void tftSetup() {
  tft.reset();

  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.setRotation(1);
  tft.fillScreen(BLACK);
}

void mainMenuDesign() {
  // button 1, top left
  buttons[0].initButton(&tft,
                        120,               // x button offset 120 = 480 / 4
                        80,                // y button offset 80 = 320 / 4
                        230,               // size of button in x direction 230 = (480 / 2) - 5
                        150,               // size of button in y direction 150 = (320 / 2) - 5
                        BLUE,              // button outline color
                        BLUE,              // button fill color
                        WHITE,             // text color
                        buttonlabels[0],   // button text
                        BUTTON_TEXTSIZE    // size of button text
                       );                  // closing parenthesis and semicolon

  tft.fillRect(5,      // x origin
               5,      // y origin
               230,    // x size
               150,    // y size
               BLUE    // color
              );       // closing parenthesis and semicolon


  // button 2
  buttons[1].initButton(&tft,
                        360,               // x button offset 120 = (480 / 2) + (480 / 4)
                        80,                // y button offset 80 = 320 / 4
                        220,               // size of button in x direction 230 = (480 / 2) - 5
                        150,               // size of button in y direction 150 = (320 / 2) - 5
                        BLUE,              // button outline color
                        BLUE,              // button fill color
                        WHITE,             // text color
                        buttonlabels[1],   // button text
                        BUTTON_TEXTSIZE    // size of button text
                       );                  // closing parenthesis and semicolon

  tft.fillRect(250,      // x origin
               5,        // y origin
               230,      // x size
               150,      // y size
               BLUE      // color
              );         // closing parenthesis and semicolon


  // button 3
  buttons[2].initButton(&tft,
                        120,               // x button offset 120 = 480 / 4
                        240,               // y button offset 80 = (320 / 2) + (320 / 4)
                        220,               // size of button in x direction 230 = (480 / 2) - 5
                        150,               // size of button in y direction 150 = (320 / 2) - 5
                        BLUE,              // button outline color
                        BLUE,              // button fill color
                        WHITE,             // text color
                        buttonlabels[2],   // button text
                        BUTTON_TEXTSIZE    // size of button text
                       );                  // closing parenthesis and semicolon

  tft.fillRect(5,        // x origin
               165,      // y origin
               230,      // x size
               150,      // y size
               BLUE      // color
              );         // closing parenthesis and semicolon

  // not a button, but placeholder 4
  tft.fillRect(250,      // x origin
               165,      // y origin
               230,      // x size
               150,      // y size
               WHITE     // color  0x03EF
              );         // closing parenthesis and semicolon

}

void drawMainMenu() {
  // Draw buttons
  buttons[0].drawButton();
  buttons[1].drawButton();
  buttons[2].drawButton();

  // White text block properties
  tft.setCursor(285, 220);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.print("Copyright 2020");

  tft.setCursor(265, 240);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.print("Michael Hernandez");
}
