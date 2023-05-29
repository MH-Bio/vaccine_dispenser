#include <SPI.h>

byte address = 0x00;
int CS = 10;

void setup() {
  pinMode (CS, OUTPUT);
  SPI.begin();

  digitalWrite(CS, LOW);
  
  SPI.transfer(address);
  SPI.transfer(128);
  digitalWrite(CS, HIGH);
}

void loop() {

}

//int digitalPotWrite(int value) {
//  digitalWrite(CS, LOW);
//  SPI.transfer(address);
//  SPI.transfer(value);
//  digitalWrite(CS, HIGH);
//}

// output from the digital potentiometer is 1.68 volts with a 30 M ohm resistor
