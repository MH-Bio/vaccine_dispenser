#include "temp_sensor.h"

temp_sensor::temp_sensor(int analog_pin) {
	internal_temp = 0.0
	external_temp = 0.0
}

void temp_sensor::update_internal_temp(double internal_temp_celcius){
  ADMUX = B11001000;    // This will set ADC8 internal sensor Room temperature
  delay (20);           // Will wait for voltages to be stable
  ADCSRA |= B01000000;  // This will start the ADC conversion for measurement
  while (bit_is_set (ADCSRA,ADSC));   // This will wait for conversion to complete
  internal_temp_celcius =  100*(1.1*ADC/1023)+(25-31.4);   // This records the internal_temp
  internal_temp = (internal_temp_celcius * 9)/(5) + 32; //converts celcius to faranheight
}

void temp_sensor::update_external_temp(double external_temp, double voltage){
  ADMUX = B01000000;    // This will set ADC0
  delay (20);           // Will wait for voltages to be stable
  ADCSRA |= B01000000;  // This will start the ADC conversion for measurement
  while (bit_is_set (ADCSRA,ADSC));   // This will wait for conversion to complete
  voltage = ((ADC*5.0)/1023);  // dividing by 1023 bits
  external_temp = 100*(voltage)+7;   // This records the external_temp in degrees ferenheight
}

double temp_sensor::getInternalTemperature(){
	return(internal_temp);
}

double temp_sensor::getExternalTemperature(){
	return(external_temp);
}