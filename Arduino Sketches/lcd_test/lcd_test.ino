#include <LiquidCrystal.h> // LIBRARY TO ACCESS THE LCD DISPLAY

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Sets up which pins go to the LCD display

int analogInPin = A0; // select the input pin for the potentiometer
float input_voltage = 0.0;
float voltage = 0.0; // voltage variable

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  lcd.begin(16, 2); // set up the LCD's number of columns and rows
  lcd.print("DC VOLTMETER"); // prints this message to the LCD screen
 // ADMUX = B01000000;
 // ADCSRA = B11110111;
}
void loop() {
//Conversion formula for voltage
   
   int analog_value = analogRead(A0);
   input_voltage = (analog_value * 5.0) / 1024.0; 

   
   if (input_voltage < 0.1) 
   {
     input_voltage=0.0;
   } 
    Serial.print("v= ");
    Serial.println(input_voltage);
    lcd.setCursor(0, 1);
    lcd.print("Voltage= ");
    lcd.print(input_voltage);
    delay(300);
}
