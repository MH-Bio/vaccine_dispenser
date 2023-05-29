#include <SPI.h>
#include <SD.h>

File userInfo;

const int SDChipSelect = 7; // SD card chip select pin
char testPassword [4] = {'1', '2', '3', '4'};
bool arrayCheck [5] = {false, false, false, false, false};
bool successfulMatch = false;
char checkCharacter = '%';

void setup() {
  Serial.begin(9600);
  pinMode(SDChipSelect, OUTPUT);
  SD.begin();

  // Pass 2, check every place in the file for matching info
  userInfo = SD.open("userinfo.txt");
  while (userInfo.available()) {

    // Part 1
    if (arrayCheck[0] == false && arrayCheck[1] == false && arrayCheck[2] == false && arrayCheck[3] == false && arrayCheck[4] == false && successfulMatch == false) {
      if (userInfo.read() == checkCharacter) { // checkCharacter is %
        arrayCheck[0] = true;
        Serial.println("Part 0 A");
      }
      else {
        arrayCheck[0] = false;
        Serial.println("Part 0 B");
      }
    }

    else if (arrayCheck[0] == true && arrayCheck[1] == false && arrayCheck[2] == false && arrayCheck[3] == false && arrayCheck[4] == false && successfulMatch == false) {
      if (userInfo.read() == testPassword[0]) {
        arrayCheck[1] = true;
        Serial.println("Part 1 A");
      }
      else {
        arrayCheck[0] = false;
        Serial.println("Part 1 B");
      }
    }

    // Part 2
    else if (arrayCheck[0] == true && arrayCheck[1] == true && arrayCheck[2] == false && arrayCheck[3] == false && arrayCheck[4] == false && successfulMatch == false) {
      if (userInfo.read() == testPassword[1]) {
        arrayCheck[2] = true;
        Serial.println("Part 2 A");
      }
      else {
        arrayCheck[0] = false;
        arrayCheck[1] = false;
        Serial.println("Part 2 B");
      }
    }

    // Part 3
    else if (arrayCheck[0] == true && arrayCheck[1] == true && arrayCheck[2] == true && arrayCheck[3] == false && arrayCheck[4] == false && successfulMatch == false) {
      if (testPassword[2] == userInfo.read()) {
        arrayCheck[3] = true;
        Serial.println("Part 3 A");
      }
      else {
        arrayCheck[0] = false;
        arrayCheck[1] = false;
        arrayCheck[2] = false;
        Serial.println("Part 3 B");
      }
    }

    // Part 4
    else if (arrayCheck[0] == true && arrayCheck[1] == true && arrayCheck[2] == true && arrayCheck[3] == true && arrayCheck[4] == false && successfulMatch == false) {
      if (testPassword[3] == userInfo.read()) {
        arrayCheck[4] = true;
        Serial.println("Part 4 A");
      }
      else {
        arrayCheck[0] = false;
        arrayCheck[1] = false;
        arrayCheck[2] = false;
        arrayCheck[3] = false;
        Serial.println("Part 4 B");
      }
    }

    // Part 5
    else if (arrayCheck[0] == true && arrayCheck[1] == true && arrayCheck[2] == true && arrayCheck[3] == true && arrayCheck[4] == true && successfulMatch == false) {
      successfulMatch = true;
      Serial.println("Part 5");
      break;
    }

    else {
      break;
    }

  }
  userInfo.close();


  Serial.println();
  Serial.println();
  Serial.print("The result for the successfulMatch variable is: ");
  Serial.println(successfulMatch);

  if (successfulMatch == true) {
    Serial.println("Success");
  }
  else {
    Serial.println("Failure");
  }

}

void loop() {

}
