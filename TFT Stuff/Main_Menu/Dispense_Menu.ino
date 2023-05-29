void drawDispenseMenu() {
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.setRotation(1);
  tft.fillScreen(BLACK);
  tft.fillRect(0,      // x origin
               0,      // y origin
               115,    // x size
               75,     // y size
               BLUE    // color
              );       // closing parenthesis and semicolon

  tft.fillRect(0,      // x origin
               100,    // y origin
               115,    // x size
               75,     // y size
               BLUE    // color
              );       // closing parenthesis and semicolon

  tft.setCursor(23, 25);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Back");
  
  tft.setCursor(23, 125);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Del.");
  
  tft.drawRoundRect(165,    // x pos
                    0,      // y pos
                    240,    // width
                    50,     // height
                    5,      // radius
                    WHITE   // color
                   );

}

void backButtonAction() {
  tftSetup();
  mainMenuDesign();
  drawMainMenu();
}
