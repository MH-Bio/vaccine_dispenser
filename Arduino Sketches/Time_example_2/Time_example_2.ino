#include <RTCCI2C.h>
#include <Wire.h>
#include <SPI.h>

RTCCI2C myRTCC;

int day;
int hour;
int minute;
int second;

void setup() {
  Serial.begin(9600);
  myRTCC.begin();

  myRTCC.setSec(RTCC_RTCC, 0x00);
  myRTCC.setMin(RTCC_RTCC, 0x19);    // 19 in HEX = 25 in decimal
  myRTCC.setHour(RTCC_RTCC, 0x14);   // 14 in HEX = 20 in decimal
  myRTCC.setDay(RTCC_RTCC, 0x06);
  myRTCC.setDate(RTCC_RTCC, 0x29);   // 29 in HEX = 41 in decimal
  myRTCC.setMonth(RTCC_RTCC, 0x05);
  myRTCC.setYear(0x14);
  myRTCC.enableVbat();               // enables the use of the battery backup

  myRTCC.startClock();

  Serial.print("Today is: ");
  day = myRTCC.getDay(RTCC_RTCC);

  switch (day) {
    case 0x01:
      Serial.print("Sunday");
      break;
    case 0x02:
      Serial.print("Monday");
      break;
    case 0x03:
      Serial.print("Tuesday");
      break;
    case 0x04:
      Serial.print("Wednesday");
      break;
    case 0x05:
      Serial.print("Thursday");
      break;
    case 0x06:
      Serial.print("Friday");
      break;
    case 0x07:
      Serial.print("Saturday");
      break;
    default:
      Serial.print("Error");
      break;
  }
  Serial.print(" ");
  Serial.print(myRTCC.getMonth(RTCC_RTCC), HEX);
  Serial.print("/");
  Serial.print(myRTCC.getDate(RTCC_RTCC), HEX);
  Serial.print("/");
  Serial.print("20");
  Serial.println(myRTCC.getYear());
}

void loop() {
  second = myRTCC.getSec(RTCC_RTCC);
  minute = myRTCC.getMin(RTCC_RTCC);
  hour = myRTCC.getHour(RTCC_RTCC);

  Serial.print(hour, HEX);
  Serial.print(':');
  Serial.print(minute, HEX);
  Serial.print(':');
  Serial.println(second, HEX);
  
  delay(1000);
}
