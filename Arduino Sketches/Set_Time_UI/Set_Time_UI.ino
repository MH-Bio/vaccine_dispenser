/* This program is the UI for the time configuration
 * this program contains no buttons and does not accept or return input.
 * This program is just to have a layout to work with to accept further changes.
 * This program is designed to work with my smaller 3.5 inch screen.
 */

#include <SPI.h>          // f.k. for Arduino-1.5.2
#include "Adafruit_GFX.h"// Hardware-specific library
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;

// Assign human-readable names to some common 16-bit color values:
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GRAY    0x6B4D

#ifndef min
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif

#define ADJ_BASELINE 11            //new fonts setCursor to bottom of letter

void setup(void);
void loop(void);
unsigned long testFillScreen();
unsigned long testText();
unsigned long testLines(uint16_t color);
unsigned long testFastLines(uint16_t color1, uint16_t color2);
unsigned long testRects(uint16_t color);
unsigned long testFilledRects(uint16_t color1, uint16_t color2);
unsigned long testFilledCircles(uint8_t radius, uint16_t color);
unsigned long testCircles(uint8_t radius, uint16_t color);
unsigned long testTriangles();
unsigned long testFilledTriangles();
unsigned long testRoundRects();
unsigned long testFilledRoundRects();
void progmemPrint(const char *str);
void progmemPrintln(const char *str);

void runtests(void);

uint16_t g_identifier;

uint16_t ID;
uint8_t hh, mm, ss; //containers for current time

uint8_t conv2d(const char* p) {
  uint8_t v = 0;
  if ('0' <= *p && *p <= '9') v = *p - '0';
  return 10 * v + *++p - '0';
}

void setup() {
  tft.reset();
  uint16_t id = tft.readID();
  tft.begin(id);
  tft.setRotation(1);     //Landscape
  tft.fillScreen(BLACK);

  // Sets the time from the computer
  hh = conv2d(__TIME__);
  mm = conv2d(__TIME__ + 3);
  ss = conv2d(__TIME__ + 6);

}

void loop() {
  tft.setTextSize(5);
  tft.fillRect(140, 120, 200, 56, BLACK); // X, Y, Width, Height, Color
  /* Here are the triangles for the selectors, the first triangle will be for the hour increase
      the next triangle is the hour decrease
      Then minute increase
      Then minute decrease
  */
  tft.setCursor(125, 15); // set cursor for "set time"
  tft.print("Set Time");
  tft.fillTriangle(195, 75, 170, 115, 220, 115, GRAY); // x apex, y apex, x left, y left, x right, y right, color
  tft.fillTriangle(195, 221, 170, 181, 220, 181, GRAY); // x apex, y apex, x left, y left, x right, y right, color
  tft.fillTriangle(282, 75, 257, 115, 307, 115, GRAY); // x apex, y apex, x left, y left, x right, y right, color
  tft.fillTriangle(282, 221, 257, 181, 307, 181, GRAY); // x apex, y apex, x left, y left, x right, y right, color
  
  tft.fillRect(0, 250, 235, 70, 0x0520); // X coord, Y coord, Width, Height, Color
  tft.setTextSize(4);
  tft.setCursor(37, 270);
  tft.print("Confirm");
  
  tft.fillRect(245, 250, 235, 70, RED); // X coord, Y coord, Width, Height, Color
  tft.setCursor(140, 120); // Original: 128, 187 + ADJ_BASELINE
  tft.setCursor(300, 270);
  tft.print("Cancel");
  
  tft.setTextSize(5);
  while (1) {
    if (++ss > 59) {
      ss = 0;
      mm++;
      if (mm > 59) {
        mm = 0;
        hh++;
        if (hh > 23) hh = 0;
      }
    }
    char buf[20];
    sprintf(buf, "%02d:%02d", hh, mm);
    tft.fillRect(140, 120, 200, 56, BLACK); // X, Y, Width, Height, Color
    tft.setCursor(165, 130);
    tft.print(buf);
    delay(1000);
  }
}
