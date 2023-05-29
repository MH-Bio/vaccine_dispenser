#include <temp_sensor.h>

#define ANALOG_PIN A0

float asdf *temp_sensor = new temp_sensor(analogRead(ANALOG_PIN));

void setup() {
  Serial.begin(115200);
  
}

void loop() {
  temp_sensor->update_internal_temp(analogRead(ANALOG_PIN));
  internal_temp(getInternalTemp);
  Serial.println(internal_temp);
}
