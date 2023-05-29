// Vaccine dispenser
// Designer: Michael Hernandez
// https://michael-hernandez.info/

#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <SD.h>
#include <SPI.h>
#include <RTCCI2C.h>
#include <Wire.h>
#include "byteAddress.h"
#include "globalVariables.h"
#include "pinDeclarations.h"

File myFile;  // the file used for SD card manipulation
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Sets up which pins go to the LCD display
RTCCI2C myRTCC;   // real time clock and calendar (RTCC)

//***************************************************************************************************
//********************************************** Setup **********************************************
//***************************************************************************************************
void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  // set up the real time clock and calendar (RTCC)
  myRTCC.begin();
//  setRTCC();          // calls the function setRTCC to set the day, time, etc.
  myRTCC.startClock();

  // setup the SD card
  if (!SD.begin(SDChipSelect)) {
    Serial.println("SD initialization failed!");
    return;
  }
  Serial.println("SD card initialized.");


  // Set up the cooling module potentiometer
  pinMode (potentiometerCS, OUTPUT);
  SPI.begin();
  digitalWrite(potentiometerCS, LOW);
  SPI.transfer(coolingPotentiometerAddress);
  SPI.transfer(setTemperature);
  digitalWrite(potentiometerCS, HIGH);

  //H bridge setup
  pinMode(DIR_A, OUTPUT);
  pinMode(DIR_B, OUTPUT);
  pinMode(PWM, OUTPUT);

  // Joystick startup routine
  pinMode(SW_pin, INPUT); // Joystick pin
  digitalWrite(SW_pin, HIGH); // joystick pin

  // Digital lock startup routine
  pinMode(lockPullupResistorPin, INPUT_PULLUP);  // sets up the pullup resistor
  pinMode(lockRelayPin, OUTPUT); // sets the pin connected to the lock relay as an output

  // LCD stuff title
  lcd.begin(16, 2); // set up the LCD's number of columns and rows
  lcd.setCursor(0, 0); // sets cursor at column 0, row 0
  lcd.print("Vaccine");
  lcd.setCursor(0, 1); // sets cursor at column 0, row 1
  lcd.print("Dispenser");
  //  delay(5000);
  lcd.clear();

  // LCD stuff copyright info
  lcd.begin(16, 2); // set up the LCD's number of columns and rows
  lcd.setCursor(0, 0); // sets cursor at column 0, row 0
  lcd.print("Copyright 2020");
  lcd.setCursor(0, 1); // sets cursor at column 0, row 1
  lcd.print("Michael H.");
  //  delay(5000);
  lcd.clear();
}

//***************************************************************************************************
//*********************************************** Loop **********************************************
//***************************************************************************************************

void loop() {
  delay(200);  // delays the loop so that the LCD screen can actually be read
  currentTemperature = temperature();
  Serial.println(" ");
  Serial.print("Current temperature: ");
  Serial.println(currentTemperature);
  Serial.print("Current voltage on the temperature pin (mV): ");
  Serial.println(analogRead(temperaturePin));
  Serial.println(" ");
  Serial.print("Current date: ");
  Serial.print(myRTCC.getMonth(RTCC_RTCC), HEX);
  Serial.print("/");
  Serial.print(myRTCC.getDate(RTCC_RTCC), HEX);
  Serial.print("/");
  Serial.print("20");
  Serial.println(myRTCC.getYear());
  Serial.print("Current Time: ");
  Serial.print(myRTCC.getHour(RTCC_RTCC));
  Serial.print(":");
  Serial.print(myRTCC.getMin(RTCC_RTCC));
  Serial.println(" ");

  joystickX = analogRead(X_pin);  // Allows the joystick to work in the X direction

  if (currentMenu < 10) {

    mainMenu = menuSelect(joystickX, 2); // the number of menus is menu + 1, so 2 creates 3 menus

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Main Menu ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    switch (mainMenu) {

      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "to dispense" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      case 0:
        menuChoice = keypad.getKey();
        dispensed = false;
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("To dispense");
        lcd.setCursor(1, 1);
        lcd.print("press #");
        currentMenu = 1;
        if (menuChoice == '#') { // if the entered character is #
          currentMenu = 10;  // Change the variable 'currentMenu', in order to select a dispense menu (between 10 & 20)
          key0 = 95; // resets keypadCharacterpad character.
        }
        else {
          currentMenu = currentMenu; // if # isn't entered, do nothing.
        }
        break; // break for case zero, ends 'to dispense' menu

      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "settings" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      case 1:
        menuChangeFlag = false;
        menuChoice = keypad.getKey();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Settings");
        lcd.setCursor(1, 1);
        lcd.print("press #");
        if (menuChoice == '#') { // if the entered character is #
          currentMenu = 30;  // Change the variable 'currentMenu', in order to select a new menu
        }
        else {
          currentMenu = currentMenu; // if # isn't entered, do nothing.
        }
        break;

      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "unlock" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      case 2:

        char keyInput; // creates a local variable to read the keypad


        if (menuChangeFlag == true && currentMenu < 10) {
          mainMenu = 1; // change the global variable "mainMenu" to be 1, and force it to go to the previous screen
          break;
        }

        else if (menuChangeFlag == true && currentMenu >= 10) {
          dispenseMenu = 0;
          joystickX = 0.0;
          break;
        }

        else {
          for (int i = 0; i < 25; i++) {

            joystickX = analogRead(X_pin);  // Allows the joystick to work in the X direction

            if (joystickX < 50) {
              mainMenu = 1; // force the mainMenu variable to be 1
              menuChangeFlag = true; // change the menu flag to be true
              i = 26; // overloads the counter variable in the loop
              mainMenu = menuSelect(joystickX, 1); // changes the number of menus to 2 to force the program to the next screen
              break; // break the loop
            }

            lcd.clear();
            lcd.setCursor(-i, 0); // as the counter counts up, changes the position to be the inverse of that, forcing the display left
            lcd.print("Open refill compartment         "); // spaces added so that the last few letters don't "get stuck" above "press #"
            lcd.setCursor(1, 1);
            lcd.print("press #");

            if (i == 0) {
              delay(1500); // delay 1.5 seconds
            }
            else {
              delay(300); // delay 3/10 of a second
            }

            keyInput = keypad.getKey();

            if (keyInput == '#') { // if the entered character is #
              menuChangeFlag = true;
              unlockFlag = true;
              currentMenu = 11;  // Change the variable 'currentMenu', in order to select a dispense menu (between 10 & 20)
              dispenseMenu = 0;
              i = 26; // overloads the counter in the loop
              dispenseMenu = menuSelect(joystickX, 0); // changes the number of menus to 1 to force the program to the correct screen
              joystickX = 0.0;
              break;
            }

            else {
              currentMenu = currentMenu; // if # isn't entered, do nothing.
            }

          }
        }
    } // closing brace for mainMenu
  } // closing brace for if (currentMenu < 10)

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Dispense Menu ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  else if (currentMenu >= 10 && currentMenu < 20) { // Dispense submenu

    dispenseMenu = menuSelect(joystickX, 1);

    switch (dispenseMenu) { // this block starts the dispense submenu

      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ username input ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      case 0:
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("Enter user ID:");

        keyInput(0); // calls the function keyInput, the 0 indicates that we are not working with a password array.

        arrayInput(userID, 0);  // calls on the function arrayInput in order to input values into the username array

        break;  // this is the break for case 0, ends 'username input' menu

      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ go back ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      case 1:

        flagReset(); // calls the function flagReset to change all values of iDFlag to false
        arrayReset(userID); // calls the function arrayReset to reset the userID array
        keyReset(); // This function resets the keys to be NO_KEY

        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("To go back");
        lcd.setCursor(1, 1);
        lcd.print("press *");

        int previousSelect = keypad.getKey();

        if (previousSelect == 42) {
          currentMenu = 1;
        }

        else {
          currentMenu = currentMenu;
        }

        break; // break for case 1, ends 'go back' menu

    } // switch(dispenseMenu) closing curly brace

  } // closing curly brace for (currentMenu >= 10 && currentMenu < 20) (username input)

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Password Menu ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  else if (currentMenu >= 20 && currentMenu < 30) { // this is for the password input

    passwordMenu = menuSelect(joystickX, 1);

    switch (passwordMenu) { // this block starts the password submenu

      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ password input ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      case 0:
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("Enter password: ");

        keyInput(1); // calls the function keyInput, the 1 denotes that we are working with a password array.

        arrayInput(passwordInput, 1);  // calls on the function arrayInput in order to input values into the username array

        usageTime();
        //        myFile = SD.open("history.txt", FILE_WRITE);
        //        if (myFile) {
        //          myFile.println("This is some text");
        //          myFile.close();
        //        }

        break;  // this is the break for case 0, ends 'password input' menu

      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ go back ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      case 1:

        flagReset(); // calls the function flagReset to change all values of iDFlag to false
        arrayReset(passwordInput); // calls the function arrayReset to reset the passwordInput array
        keyReset(); // This function resets the keys to be NO_KEY

        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("To go back");
        lcd.setCursor(1, 1);
        lcd.print("press *");

        int previousSelect = keypad.getKey();

        if (previousSelect == 42) {
          currentMenu = 1;
        }

        else {
          currentMenu = currentMenu;
        }

        break; // break for case 1, ends 'go back' menu

    } // closing brace for the switch statement

  } // closing curly brace for (currentMenu >= 20 && currentMenu < 30) (password input)


  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Settings Menu ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  else if (currentMenu >= 30 && currentMenu < 40) { // this is the settings menu

    settingsMenu = menuSelect(joystickX, 2);

    switch (settingsMenu) {

      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ current Temp ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      case 0:

        currentTemperature = temperature();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Current Temp.");
        lcd.setCursor(0, 1);
        lcd.print(currentTemperature);
        lcd.print(" C");
        delay(150);
        break;

      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ go back ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      case 1: // go back

        keyReset(); // This function resets the keys to be NO_KEY

        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("To go back");
        lcd.setCursor(1, 1);
        lcd.print("press *");

        int previousSelect = keypad.getKey();

        if (previousSelect == 42) {
          currentMenu = 1;
        }

        else {
          currentMenu = currentMenu;
        }

        break; // break for case 1, ends 'go back' menu

      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ current time ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      case 2:
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("Current time is:");
        lcd.setCursor(1, 1);
        lcd.print(myRTCC.getHour(RTCC_RTCC));
        lcd.print(":");
        lcd.print(myRTCC.getMin(RTCC_RTCC));

//        int changeTemp = keypad.getKey();
//
//        if (previousSelect == 42) {
//          desiredTempMenu = menuSelect(joystickY, 14);
//          int selectionConfirm;
//
//          switch (desiredTempMenu) {
//            case 0:
//              lcd.clear();
//              lcd.setCursor(0, 0);
//              lcd.print("Scroll to select");
//              lcd.setCursor(0, 1);
//              lcd.print("desired temp.");
//
//            case 1:
//              lcd.clear();
//              lcd.setCursor(0, 0);
//              lcd.print("-4 C");
//              lcd.setCursor(0, 1);
//              lcd.print("press *");
//              selectionConfirm = keypad.getKey();
//
//              if (selectionConfirm == 42) {
//                setTemperature = 43; // we want a voltage from the TMP36 = 0.44 V for -4C; 0.01015625 x 43 ~ 0.437
//                lcd.clear();
//                lcd.setCursor(0, 0);
//                lcd.print("Set temperature");
//                lcd.setCursor(0, 1);
//                lcd.print("changed to -4 C");
//              }
//
//            case 2:
//              lcd.clear();
//              lcd.setCursor(0, 0);
//              lcd.print("-3 C");
//              lcd.setCursor(0, 1);
//              lcd.print("press *");
//              selectionConfirm = keypad.getKey();
//
//              if (selectionConfirm == 42) {
//                setTemperature = 44; // we want a voltage from the TMP36 = 0.44 V for -4C; 0.01015625 x 43 ~ 0.437
//                lcd.clear();
//                lcd.setCursor(0, 0);
//                lcd.print("Set temperature");
//                lcd.setCursor(0, 1);
//                lcd.print("changed to -3 C");
//              }
//
//            case 3:
//              lcd.clear();
//              lcd.setCursor(0, 0);
//              lcd.print("-2 C");
//              lcd.setCursor(0, 1);
//              lcd.print("press *");
//              selectionConfirm = keypad.getKey();
//
//              if (selectionConfirm == 42) {
//                setTemperature = 44; // we want a voltage from the TMP36 = 0.44 V for -4C; 0.01015625 x 43 ~ 0.437
//                lcd.clear();
//                lcd.setCursor(0, 0);
//                lcd.print("Set temperature");
//                lcd.setCursor(0, 1);
//                lcd.print("changed to -2 C");
//              }
//          }
//        }
//
//        else {
//          currentMenu = currentMenu;
//        }
//
//        digitalWrite(potentiometerCS, LOW);
//        SPI.transfer(coolingPotentiometerAddress);
//        SPI.transfer(setTemperature);
//        digitalWrite(potentiometerCS, HIGH);

    }

  } // closing curly brace for (currentMenu >= 30 && currentMenu < 40) (settings)

}
