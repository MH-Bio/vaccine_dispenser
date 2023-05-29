// https://www.instructables.com/id/How-to-use-the-TMP36-temp-sensor-Arduino-Tutorial/

double external_temp;
double internal_temp;
double internal_temp_celcius;
double voltage;

void setup() {
  Serial.begin (115200);  // sets the baud rate
  pinMode(8, OUTPUT);
}

void loop() {


  ADMUX = B11001000;    // This will set ADC8 internal sensor Room temperature
  delay (20);           // Will wait for voltages to be stable
  ADCSRA |= B01000000;  // This will start the ADC conversion for measurement
  while (bit_is_set (ADCSRA, ADSC));  // This will wait for conversion to complete
  internal_temp_celcius =  100 * (1.1 * ADC / 1023) + (25 - 31.4); // This records the internal_temp
  internal_temp = (internal_temp_celcius * 9) / (5) + 32; //converts celcius to faranheight

  ADMUX = B01000000;    // This will set ADC0
  delay (20);           // Will wait for voltages to be stable
  ADCSRA |= B01000000;  // This will start the ADC conversion for measurement
  while (bit_is_set (ADCSRA, ADSC));  // This will wait for conversion to complete
  voltage = ((ADC * 5.0) / 1023); // dividing by 1023 bits
  external_temp = 100 * (voltage); // This records the external_temp in degrees ferenheight

  if (external_temp > 75.5){
    digitalWrite(8,HIGH);
  }
  else{
    digitalWrite(8,LOW);
  }

  delay (1000);   //This will only print after every second
  Serial.print("External Temperature: ");  // prints "External Temperature" to the serial monitor
  Serial.println(external_temp);            // This will print external temperature
  Serial.print("Internal Temperature: ");  // prints "Internal temperature" to the serial monitor
  Serial.println(internal_temp);            // This will print internal temperature
  Serial.println();
  return (internal_temp);



}
