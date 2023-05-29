void usageTime() {
  // this function writes the date and time of the user to the SD card when used.
  myFile = SD.open("history.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.print("Used by user: ");
    myFile.print(userIDCheck[0]);
    myFile.print(userIDCheck[1]);
    myFile.print(userIDCheck[2]);
    myFile.println(userIDCheck[3]);
    myFile.print("Used at time: ");
    myFile.print(myRTCC.getHour(RTCC_RTCC));
    myFile.print(":");
    myFile.println(myRTCC.getMin(RTCC_RTCC));
    myFile.print("Used on this date: ");
    myFile.print(myRTCC.getMonth(RTCC_RTCC), HEX);
    myFile.print("/");
    myFile.print(myRTCC.getDate(RTCC_RTCC), HEX);
    myFile.print("/");
    myFile.print("20");
    myFile.println(myRTCC.getYear());
    myFile.println(" ");
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

  // re-open the file for reading:
  myFile = SD.open("history.txt");
  if (myFile) {
    Serial.println("history.txt:");


    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void writeLockUsage() {
  myFile = SD.open("history.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to history.txt...");
    myFile.println("LOCK USAGE");
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening usagehistory.txt");
  }

  // re-open the file for reading:
  myFile = SD.open("history.txt");
  if (myFile) {
    Serial.println("history.txt");

    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void writeDispenseUsage() {
myFile = SD.open("history.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to history.txt...");
    myFile.println("DISPENSER USAGE");
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening history.txt");
  }

  // re-open the file for reading:
  myFile = SD.open("history.txt");
  if (myFile) {
    Serial.println("history.txt");

    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}
