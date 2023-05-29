
// this function
void readUsername() {
  nameArrayFlag = false;

  myFile = SD.open("userinfo.txt");
  while (myFile.available()) {
    if (myFile.read() == '<') {
      nameArrayFlag = true;
      testCharacter = '%';
      for (int j = 0; j < 50; j++) {
        if (myFile.read() == '>') {
          nameArrayFlag = false;
        }
        else if (nameArrayFlag == true) {
          nameArray[j] = myFile.read();
        }
        else {
          nameArray[j] = ' ';
        }
      }
    }
  }
  myFile.close();

}

void readPassword() {
  char completeArray [lengthCounter] = {}; // creates an array the size of the text file

  // the following block of code copies the information from the SD card to an array in the arduino
  myFile = SD.open("userinfo.txt");
  while (myFile.available()) {
    for (int i = 0; i < lengthCounter; i++) {
      completeArray[i] = myFile.read();
    }
  }
  myFile.close();
  Serial.println();
  Serial.println();

  int flagCheck = 0;
  int y = 0;

  for (int i = 0; i < lengthCounter; i++) {
    Serial.print(completeArray[i]);

    if (completeArray[i] == '<') {
      if (completeArray[i - 1] == 'd' && completeArray[i - 2] == 'i') {
        savedPassword[0] = completeArray[i + 1];
        savedPassword[1] = completeArray[i + 2];
        savedPassword[2] = completeArray[i + 3];
        savedPassword[3] = completeArray[i + 4];
      }
    }

  }
}


void fileLengthCounter() {
  myFile = SD.open("userinfo.txt");
  if (myFile) {
    Serial.println("Read:");
    // Reading the whole file
    while (myFile.available()) {
      Serial.write(myFile.read());

      lengthCounter = lengthCounter + 1;
    }
    myFile.close();
  }
  else {
    Serial.println("error opening WRITE.TXT");
  }
}
