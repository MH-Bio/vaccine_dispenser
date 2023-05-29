//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ dispenseRoutine ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// This function will move the track acuator to dispense one unit
void dispenseRoutine() {
  if (dispensed == false) {

    writeDispenseUsage();
    usageTime(); // writes the time and user at which the lock was used to the SD card
    
    //drive forward at full speed by pulling DIR_A High
    //and DIR_B low, while writing a full 255 to PWM to
    //control speed
    digitalWrite(DIR_A, HIGH);
    digitalWrite(DIR_B, LOW);
    analogWrite(PWM, 255);

    //wait 1 second
    delay(25000);

    //Brake the motor by pulling both direction pins to
    //the same state (in this case LOW). PWM doesn't matter
    //in a brake situation, but set as 0.
    digitalWrite(DIR_A, LOW);
    digitalWrite(DIR_B, LOW);
    analogWrite(PWM, 0);

    //wait 1 second
    delay(500);

    //change direction to reverse by flipping the states
    //of the direction pins from their forward state
    digitalWrite(DIR_A, LOW);
    digitalWrite(DIR_B, HIGH);
    analogWrite(PWM, 255);

    //wait 1 second
    delay(25000);

    //Brake again
    digitalWrite(DIR_A, LOW);
    digitalWrite(DIR_B, LOW);
    analogWrite(PWM, 0);

    //wait 1 second
    delay(500);
    
    dispensed = true;  // prevents the routine from running a second time
    
  }
  else {
    
  }

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ setRTCC ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// This function will run once during the setup, and again if the user wants to change the timezone
// it will set the variables for the real time clock and calendar (RTCC)

void setRTCC() {
  myRTCC.setSec(RTCC_RTCC, 0x00);
  myRTCC.setMin(RTCC_RTCC, 0x28); // 25 in HEX
  myRTCC.setHour(RTCC_RTCC, 0x10); // 20 in HEX
  myRTCC.setDay(RTCC_RTCC, 0x07);
  myRTCC.setDate(RTCC_RTCC, 0x30);
  myRTCC.setMonth(RTCC_RTCC, 0x05);
  myRTCC.setYear(0x14);
  myRTCC.enableVbat(); // enables the use of the battery backup
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ temperature ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// this function reads and returns the temperature
// There are 10mV per degree Celcius, therefore 0 C = 0.48V, and 22 C = 0.7 V
int temperature() {

  float reading = analogRead(temperaturePin);
  float voltage = reading * 5.0;
  voltage = voltage / 1024.0;
  //Serial.println(voltage);
  float  temperature = (voltage - 0.5) * 100.0;
  temperature = temperature + 54; // offset correction

  return temperature;

} // closing brace for temperature

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ temperatureControl ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// this function reads and returns the temperature
void temperatureControl() {

  int currentTemp;
  currentTemp = analogRead(temperaturePin) - 2.5; // the -3.5 C is a correction (test showed 75 F, room temp is 71)

  int error = setTemperature - currentTemp; // calculates how far off in degrees the current temperature is

  if (error > 0) {
    digitalWrite(temperatureOutputPin, HIGH);
  }


}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ unlock ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// This function will unlock the lock one time and will not work again until the unlock variable is
// reset
void unlock() {

  if (lockActivated == false) {
    digitalWrite(lockRelayPin, HIGH);
    delay(3000);
    digitalWrite(lockRelayPin, LOW);
  }

  else {
    digitalWrite(lockRelayPin, LOW);
    writeLockUsage(); // writes lock usage to the SD card
    usageTime(); // writes the time and user at which the lock was used to the SD card
  }

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
