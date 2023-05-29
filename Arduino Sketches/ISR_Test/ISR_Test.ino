int setTemperature = 0;

void setup() {
  // put your setup code here, to run once:
  attachInterrupt(digitalPinToInterrupt(22), temperatureControl, FALLING );
  pinMode(2, INPUT);
  pinMode(22, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  delay(500);
  
}

void temperatureControl() {

  int currentTemp;
  currentTemp = analogRead(2) - 2.5; // the -3.5 C is a correction (test showed 75 F, room temp is 71)

  int error = setTemperature - currentTemp; // calculates how far off in degrees the current temperature is

  if (1 > setTemperature) {
  digitalWrite(22, HIGH);
  }
}
