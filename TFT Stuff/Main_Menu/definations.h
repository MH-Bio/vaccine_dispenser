#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

// Colors
#define BLACK      0x0000
#define BLUE       0x001F
#define RED        0xF800
#define GREEN      0x07E0
#define CYAN       0x07FF
#define MAGENTA    0xF81F
#define YELLOW     0xFFE0
#define WHITE      0xFFFF
#define LIGHTGREY  0xC618
#define DARKGREY   0x7BEF
#define ORANGE     0xFD20

// UI Button Definations
#define BUTTON_X 240
#define BUTTON_Y 55
#define BUTTON_W 300
#define BUTTON_H 70
#define BUTTON_SPACING_X 60
#define BUTTON_SPACING_Y 28
#define BUTTON_TEXTSIZE 3

// text box where numbers go
#define TEXT_X 10
#define TEXT_Y 10
#define TEXT_W 300
#define TEXT_H 50
#define TEXT_TSIZE 3
#define TEXT_TCOLOR ILI9341_MAGENTA

// Touchscreen input pins
#define YP A2  // must be an analog pin, use "An" notation!
#define XM A3  // must be an analog pin, use "An" notation!
#define YM 8   // can be a digital pin
#define XP 9   // can be a digital pin

#define TS_MINX 130
#define TS_MAXX 905

#define TS_MINY 75
#define TS_MAXY 930

// We have a status line for like, is FONA working
#define STATUS_X 10
#define STATUS_Y 65

// Pressure definations for touchscreen
#define MINPRESSURE 10
#define MAXPRESSURE 1000

// for text boxes
#define TEXT_LEN 16
