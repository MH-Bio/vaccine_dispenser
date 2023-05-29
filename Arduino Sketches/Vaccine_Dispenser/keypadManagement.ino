//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ keyInput ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// This function allows the program to accept an input from the keypad for all four entries
void keyInput(bool isPassword) { // enter a 0 for not a password, and 1 for password.

  bool successCheck; // local variable used to move on to next menu if necessary

  if (iDFlag[0] == false && iDFlag[1] == false && iDFlag[2] == false && iDFlag[3] == false) {
    key0 = keypad.getKey();
  }
  else if (iDFlag[0] == true && iDFlag[1] == false && iDFlag[2] == false && iDFlag[3] == false) {
    key1 = keypad.getKey();
  }
  else if (iDFlag[0] == true && iDFlag[1] == true && iDFlag[2] == false && iDFlag[3] == false) {
    key2 = keypad.getKey();
  }
  else if (iDFlag[0] == true && iDFlag[1] == true && iDFlag[2] == true && iDFlag[3] == false) {
    key3 = keypad.getKey();
  }


  // check to see if the input userID matches a stored userID
  else if (isPassword == false) { // if we are not working with the password array
    successCheck = arrayCheck(userID, userIDCheck); // compares userID against the predefined "password"
    if (successCheck == true) {
      currentMenu = 20;
      flagReset(); // calls the function flagReset to change all values of iDFlag to false
      keyReset(); // This function resets the keys to be NO_KEY
      arrayReset(passwordMask);
      arrayReset(userID);
    }
    else {
      arrayReset(userID);
    }
  }

  // If we are inputting the password for the DISPENSING MECHANISM
  else if (isPassword == true && unlockFlag == false) { // if we are working with the password array
    successCheck = arrayCheck(passwordInput, userIDCheck); // compares userID against the predefined "password"
    if (successCheck == true) {
      writeDispenseUsage();
      usageTime();
      lcd.clear();
      lcd.setCursor(0, 0); // sets cursor at column 0, row 0
      lcd.print("Success!");
      dispenseRoutine();
      arrayReset(passwordMask);  // clears the password mask values
      arrayReset(passwordInput); // clears out the values for the password
      isPassword = false; // resets the screen to go back to the user id input
    }
    else {
      arrayReset(passwordInput);
    }
  }


  // if we are inputting the password for the ELECTRONIC LOCK
  else if (isPassword == true && unlockFlag == true) { // if we are working with the password array & unlock
    successCheck = arrayCheck(passwordInput, userIDCheck); // compares userID against the predefined "password"
    if (successCheck == true) {
      writeLockUsage();
      usageTime();
      lcd.clear();
      lcd.setCursor(0, 0); // sets cursor at column 0, row 0
      lcd.print("Success!");
      unlock();
      unlockFlag = false;
      dispensed = true; // prevents the dispense motor from running
    }
    else {
      arrayReset(passwordMask);
      arrayReset(passwordInput);
    }
  }

  else { // if all else fails, reset everything
    flagReset(); // calls the function flagReset to change all values of iDFlag to false
    keyReset(); // This function resets the keys to be NO_KEY
    arrayReset(passwordInput);
    arrayReset(passwordMask);
  }

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ keyReset ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// This void type function will reset the keypad inputs, key0-4 back to NO_KEY
void keyReset() {
  key0 = NO_KEY;
  key1 = NO_KEY;
  key2 = NO_KEY;
  key3 = NO_KEY;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
