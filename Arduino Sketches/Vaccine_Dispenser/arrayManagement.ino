//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ arrayCheck ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Compares two arrays against each other, used for user ID and password input

bool arrayCheck(char array1[], char array2[]) { // the two arrays to be compared against each other are entered as input arguments

  bool checkArrays [4] = {false, false, false, false}; // create a local array of bool values
  int counter = 0;
  bool finalCheck; // this is what the function will return

  for (int i = 0; i < 4; i++) {

    if (array1[i] == array2[i]) {
      checkArrays[i] = true;
    }

    else {
      checkArrays[i] = false;
    }

  }

  for (int i = 0; i < 4; i++) {
    counter = counter + checkArrays[i]; // counts the number of trues in the ID flag array, if true then we add a 1
  }

  if (counter == 4) {
    finalCheck = true;
  }

  else {
    finalCheck = false;
  }

  return finalCheck; // returns the final check variable as either true or false

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ arrayInput ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Inputs values into the arary, can be recycled for both username and password.  This function takes
// an array to be modified as an input value, and does not return a value.

void arrayInput(char inputArray[], bool password) {


  // This block of code deals with the FIRST value of the array of interest
  if (key0 != NO_KEY && iDFlag[0] == false) { // conditions for entering the FIRST value in the array
    inputArray[0] = key0; // enter the value stored in the key0 variable to the first value of the input array
    passwordMask[0] = 42;
    lcd.setCursor(0, 1); // sets cursor at column 0, row 0
    if (password == false) {
      lcdDisplay(inputArray, 1); // display the first value of the input array on the LCD screen
    }
    else { // if the boolean input value "password" is false
      lcdDisplay(passwordMask, 1); // display a * for the first value of the array on the LCD screen instead.
    }
    iDFlag[0] = true; // set the first value of iDFlag to be true
  }
  else { // if the conditions for entering the FIRST value in the array are not met
    lcd.setCursor(0, 1); // sets cursor at column 0, row 0

    if (password == false) { // if the boolean input value "password" is false
      lcdDisplay(inputArray, 1); // display 1 digit of the entered array
    }
    else { // if the boolean input value "password" is true
      lcdDisplay(passwordMask, 1); // display a * instead to mask the password
    }
  }


  // This block deals with the SECOND value of the array of interest
  if (key1 != NO_KEY && iDFlag[1] == false) { // conditions for entering the SECOND value in the array
    inputArray[1] = key1; // input the value stored in the variable key1 into the second value in the input array
    passwordMask[1] = 42;
    lcd.setCursor(0, 1); // sets the LCD cursor to row 2, column 1
    if (password == false) { // if the input variable "password" is set to false (input 0)
      lcdDisplay(inputArray, 2); // display two digits of the input array
    }
    else { // if the input variable "password" is set to true (input 1)
      lcdDisplay(passwordMask, 2); // display two digits of the passwordMask array
    }
    iDFlag[1] = true; // set the second value of the iDFlag array equal to true
  }
  else { // if the conditions for entering the SECOND value in the array are not met
    lcd.setCursor(0, 1); // sets cursor at column 1, row 2
    if (password == false) {  // if the value for the input variable "password" is set to 0
      lcdDisplay(inputArray, 2);  // display two values on the input arrray
    }
  }


  // This block deals with the THIRD value of the array of interest
  if (key2 != NO_KEY && iDFlag[2] == false) { // conditions for entering the THIRD value in the array
    inputArray[2] = key2; // input the value stored in the variable key2 into the third value in the input array
    passwordMask[2] = 42;
    lcd.setCursor(0, 1); // sets cursor at column 1, row 2
    if (password == false) {  // if the value for the input variable "password" is set to 0
      lcdDisplay(inputArray, 3); // display three values on the input arrray
    }
    else { // if the conditions for entering the THIRD value in the array are not met
      lcdDisplay(passwordMask, 3); // display three digits of the passwordMask array
    }
    iDFlag[2] = true; // set the third value of the iDFlag array equal to true
  }
  else { // if the conditions for entering the third value of the array are not met
    lcd.setCursor(0, 1); // sets cursor at column 0, row 1
    if (password == false) { // if the value for the input variable "password" is set to 0
      lcdDisplay(inputArray, 3); // display three values on the input arrray
    }
    else {
      lcdDisplay(passwordMask, 3); // display three digits of the passwordMask array
    }
  }


  // This block deals with the FOURTH value of the array of interest
  if (key3 != NO_KEY && iDFlag[3] == false) { // conditions for entering the FOURTH value in the array
    inputArray[3] = key3; // input the value stored in the variable key3 into the fourth value in the input array
    passwordMask[3] = 42;
    lcd.setCursor(0, 1); // sets cursor at column 0, row 1
    if (password == false) { // if the value for the input variable "password" is set to 0
      lcdDisplay(inputArray, 4);  // display four values on the input arrray
    }
    else {
      lcdDisplay(passwordMask, 4); // display four values on the passwordMask arrray
    }
    iDFlag[3] = true; // set the final value of the iDFlag array to be true
  }
  else { // if the input conditions are not met
    lcd.setCursor(0, 1); // sets cursor at column 0, row 1
    if (password == false) { // if the input variable "password" is set to 0
      lcdDisplay(inputArray, 4); // display four digits of the input array
    }
    else { // if the input variable "password" is set to 1
      lcdDisplay(passwordMask, 4);  // dispaly four variables of the array passwordMask (display four *'s)
    }
  }
} // closing curly brace for the function
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ arrayReset ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// resets all values in a username or password array back to _
void arrayReset(char inputArray[]) {
  for (int i = 0; i < 4; i++) {
    inputArray[i] = '_';
  }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ flagReset ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// This function does not return any value.
// This function resets the ID flags used to determine which place in an array you are to enter a
// value
void flagReset() {

  for (int i = 0; i < 4; i++) {
    iDFlag[i] = false; // changes the value of the iDFlag to false for cells 0-3 of the array.
  }

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ idFlagCount ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Counts the number of true variables in the iDFlag array.  For every true, we add a 1, for every
// false, we add a 0.  We then reutrn the total value of the count.
int idFlagCount() {

  int counter = 0; // Initialize a local variable of type int to keep a running total of each successful value.

  for (int i = 0; i < 4; i++) {
    counter = counter + iDFlag[i]; // counts the number of trues in the ID flag array, if true then we add a 1
  }

  return counter; // returns the value of the local variable

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
