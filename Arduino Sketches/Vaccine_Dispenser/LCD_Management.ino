//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ lcdDisplay ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// This function, when called will display any number of digits on the LCD display
void lcdDisplay(char Array[], int digits) {
  switch (digits) {
    case 1:
      lcd.print(Array[0]);
      break;

    case 2:
      lcd.print(Array[0]);
      lcd.print(Array[1]);
      break;

    case 3:
      lcd.print(Array[0]);
      lcd.print(Array[1]);
      lcd.print(Array[2]);
      break;

    case 4:
      lcd.print(Array[0]);
      lcd.print(Array[1]);
      lcd.print(Array[2]);
      lcd.print(Array[3]);
      break;
  }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
