/***************************************************
//Web: http://www.buydisplay.com
EastRising Technology Co.,LTD
Libraries for ER-TFTM050-5(800x480 Pixels) with No Touch Panel
8080 16-bit Parallel Interface,5V Power Supply
***************************************************/

#ifndef UTFT_h
#define UTFT_h

#define UTFT_VERSION	279

#define LEFT 0
#define RIGHT 9999
#define CENTER 9998

#define PORTRAIT 0
#define LANDSCAPE 1

#define HX8347A			0
#define ILI9327			1
#define SSD1289			2
#define ILI9325C		3
#define ILI9325D_8		4
#define ILI9325D_16		5
#define HX8340B_8		6
#define HX8340B_S		7
#define HX8352A			8
#define ST7735			9
#define PCF8833			10
#define S1D19122		11
#define SSD1963_480		12
#define SSD1963_800		13
#define S6D1121_8		14
#define S6D1121_16		15
#define	SSD1289LATCHED	16
//#define NOT_IN_USE	17
//#define NOT_IN_USE	18
#define SSD1289_8		19
#define	SSD1963_800ALT	20
#define ILI9481			21
#define ILI9325D_16ALT	22
#define S6D0164			23
#define ST7735S			24
#define ILI9341_S5P		25
#define ILI9341_S4P		26
#define R61581			27
#define ILI9486			28
#define CPLD			29
#define HX8353C			30
#define ST7735_ALT		31
#define ILI9341_8		32
#define ILI9341_16		33
#define ILI9488_16		34
#define ILI9342_16		35
#define ILI9342_S5P		36
#define ILI9342_S4P		37
#define ILI9163_S5P		38



#define ITDB32			0	// HX8347-A (16bit)
#define ITDB32WC		1	// ILI9327  (16bit)
#define TFT01_32W		1	// ILI9327	(16bit)
#define ITDB32S			2	// SSD1289  (16bit)
#define TFT01_32		2	// SSD1289  (16bit)
#define CTE32			2	// SSD1289  (16bit)
#define ITDB24			3	// ILI9325C (8bit)
#define ITDB24D			4	// ILI9325D (8bit)
#define ITDB24DWOT		4	// ILI9325D (8bit)
#define ITDB28			4	// ILI9325D (8bit)
#define TFT01_24_8		4	// ILI9325D (8bit)
#define DMTFT24104      4   // ILI9325D (8bit)
#define DMTFT28103      4   // ILI9325D (8bit)
#define TFT01_24_16		5	// ILI9325D (16bit)
#define ITDB22			6	// HX8340-B (8bit)
#define ITDB22SP		7	// HX8340-B (Serial 4Pin)
#define ITDB32WD		8	// HX8352-A (16bit)
#define TFT01_32WD		8	// HX8352-A	(16bit)
#define CTE32W			8	// HX8352-A	(16bit)
#define ITDB18SP		9	// ST7735   (Serial 5Pin)
#define LPH9135			10	// PCF8833	(Serial 5Pin)
#define ITDB25H			11	// S1D19122	(16bit)
#define ITDB43			12	// SSD1963	(16bit) 480x272
#define TFT01_43		12	// SSD1963	(16bit) 480x272
#define SSD1963_480272		12	// SSD1963	(16bit) 480x272
#define TFTM043_4_16		12	// SSD1963	(16bit) 480x272
#define TFTM050_4_16		12	// SSD1963	(16bit) 480x272

#define ITDB50			13	// SSD1963	(16bit) 800x480
#define TFT01_50		13	// SSD1963	(16bit) 800x480
#define CTE50			13	// SSD1963	(16bit) 800x480
#define EHOUSE50		13	// SSD1963	(16bit) 800x480
#define SSD1963_800480		13	// SSD1963	(16bit) 800x480
#define TFTM050_5_16		13	// SSD1963	(16bit) 800x480
#define TFTM070_4_16		13	// SSD1963	(16bit) 800x480
#define TFTM080_1_16		13	// SSD1963	(16bit) 800x480
#define TFTM090_1_16		13	// SSD1963	(16bit) 800x480


#define ITDB24E_8		14	// S6D1121	(8bit)
#define TFT01_24R2		14	// S6D1121	(8bit)
#define ITDB24E_16		15	// S6D1121	(16bit)
#define INFINIT32		16	// SSD1289	(Latched 16bit) -- Legacy, will be removed later
#define ELEE32_REVA		16	// SSD1289	(Latched 16bit)
//#define NOT_IN_USE	17	
//#define NOT_IN_USE	18	
#define ELEE32_REVB		19	// SSD1289	(8bit)
#define TFT01_70		20	// SSD1963	(16bit) 800x480 Alternative Init
#define CTE70			20	// SSD1963	(16bit) 800x480 Alternative Init
#define EHOUSE70		20	// SSD1963	(16bit) 800x480 Alternative Init
#define CTE32HR			21	// ILI9481	(16bit)
#define CTE28			22	// ILI9325D (16bit) Alternative Init
#define TFT01_28		22	// ILI9325D (16bit) Alternative Init
#define CTE22			23	// S6D0164	(8bit)
#define TFT01_22		23	// S6D0164	(8bit)
#define DMTFT22102      23  // S6D0164  (8bit)
#define TFT01_18SP		24	// ST7735S  (Serial 5Pin)
#define TFT01_22SP		25	// ILI9341	(Serial 5Pin)
#define TFT01_24SP		25	// ILI9341	(Serial 5Pin)
#define TFT22SHLD		25	// ILI9341	(Serial 5Pin)

#define ILI9341_4L		25  // ILI9341	(Serial 5Pin)
#define TFTM022_1_4L		25  // ILI9341	(Serial 5Pin)
#define TFTM024_3_4L			25  // ILI9341	(Serial 5Pin)
#define TFTM026_1_4L			25  // ILI9341	(Serial 5Pin)
#define TFTM028_4_4L			25  // ILI9341	(Serial 5Pin)
#define TFTM032_3_4L			25  // ILI9341	(Serial 5Pin)

#define DMTFT28105      25  // ILI9341  (Serial 5Pin)

#define MI0283QT9		26  // ILI9341	(Serial 4Pin)

#define ILI9341_3L		26  // ILI9341	(Serial 4Pin)
#define TFTM022_1_3L		26  // ILI9341	(Serial 4Pin)
#define TFTM024_3_3L			26  // ILI9341	(Serial 4Pin)
#define TFTM026_1_3L			26  // ILI9341	(Serial 4Pin)
#define TFTM028_4_3L			26  // ILI9341	(Serial 4Pin)
#define TFTM032_3_3L			26  // ILI9341	(Serial 4Pin)

#define CTE35IPS		27	// R61581	(16bit)
#define CTE40			28	// ILI9486	(16bit)
#define EHOUSE50CPLD	29	// CPLD		(16bit)
#define CTE50CPLD		29	// CPLD		(16bit)
#define CTE70CPLD		29	// CPLD		(16bit)
#define DMTFT18101      30  // HX8353C  (Serial 5Pin)
#define TFT18SHLD		31	// ST7735	(Serial 5Pin) Alternative Init
#define ILI9341_8L		32  // ILI9341	(8bit)
#define ILI9341_16L	33  // ILI9341	(16bit)
#define TFTM022-1_16	33  // ILI9341	(16bit)
#define TFTM024-3_16	33  // ILI9341	(16bit)
#define TFTM026-1_16	33  // ILI9341	(16bit)
#define TFTM028-4_16	33  // ILI9341	(16bit)
#define TFTM032-3_16	33  // ILI9341	(16bit)

#define ILI9488_16L		34  // ILI9488	(16bit)
#define TFTM035_6_16		34  // ILI9488	(16bit)

#define ILI9342_16L		35  // ILI9342	(16bit)
#define TFTM023_1_16		35  // ILI9342	(16bit)
#define ILI9342_4L		36  // ILI9342	(Serial 5Pin)
#define TFTM023-1_4L		36  // ILI9342	(Serial 5Pin)
#define ILI9342_3L		37  // ILI9342	(Serial 4Pin)
#define TFTM023-1_3L		37  // ILI9342	(Serial 4Pin)

#define ILI9163_4L		38  // ILI9163	(Serial 5Pin)
#define TFTM018-2_4L		38  // ILI9163	(Serial 5Pin)

#define SERIAL_4PIN		4
#define SERIAL_5PIN		5
#define LATCHED_16		17

#define NOTINUSE		255

//*********************************
// COLORS
//*********************************
// VGA color palette
#define VGA_BLACK		0x0000
#define VGA_WHITE		0xFFFF
#define VGA_RED			0xF800
#define VGA_GREEN		0x0400
#define VGA_BLUE		0x001F
#define VGA_SILVER		0xC618
#define VGA_GRAY		0x8410
#define VGA_MAROON		0x8000
#define VGA_YELLOW		0xFFE0
#define VGA_OLIVE		0x8400
#define VGA_LIME		0x07E0
#define VGA_AQUA		0x07FF
#define VGA_TEAL		0x0410
#define VGA_NAVY		0x0010
#define VGA_FUCHSIA		0xF81F
#define VGA_PURPLE		0x8010
#define VGA_TRANSPARENT	0xFFFFFFFF

#if defined(__AVR__)
	#include "Arduino.h"
	#include "hardware/avr/HW_AVR_defines.h"
#elif defined(__PIC32MX__)
	#include "WProgram.h"
	#include "hardware/pic32/HW_PIC32_defines.h"
#elif defined(__arm__)
	#include "Arduino.h"
	#include "hardware/arm/HW_ARM_defines.h"
#endif

struct _current_font
{
	uint8_t* font;
	uint8_t x_size;
	uint8_t y_size;
	uint8_t offset;
	uint8_t numchars;
};

class UTFT
{
	public:
		UTFT();
		UTFT(byte model, int RS, int WR, int CS, int RST, int SER=0);
		void	InitLCD(byte orientation=LANDSCAPE);
		void	clrScr();
		void	drawPixel(int x, int y);
		void	drawLine(int x1, int y1, int x2, int y2);
		void	fillScr(byte r, byte g, byte b);
		void	fillScr(word color);
		void	drawRect(int x1, int y1, int x2, int y2);
		void	drawRoundRect(int x1, int y1, int x2, int y2);
		void	fillRect(int x1, int y1, int x2, int y2);
		void	fillRoundRect(int x1, int y1, int x2, int y2);
		void	drawCircle(int x, int y, int radius);
		void	fillCircle(int x, int y, int radius);
		void	setColor(byte r, byte g, byte b);
		void	setColor(word color);
		word	getColor();
		void	setBackColor(byte r, byte g, byte b);
		void	setBackColor(uint32_t color);
		word	getBackColor();
		void	print(char *st, int x, int y, int deg=0);
		void	print(String st, int x, int y, int deg=0);
		void	printNumI(long num, int x, int y, int length=0, char filler=' ');
		void	printNumF(double num, byte dec, int x, int y, char divider='.', int length=0, char filler=' ');
		void	setFont(uint8_t* font);
		uint8_t* getFont();
		uint8_t	getFontXsize();
		uint8_t	getFontYsize();
		void	drawBitmap(int x, int y, int sx, int sy, bitmapdatatype data, int scale=1);
		void	drawBitmap(int x, int y, int sx, int sy, bitmapdatatype data, int deg, int rox, int roy);
		void	lcdOff();
		void	lcdOn();
		void	setContrast(char c);
		int		getDisplayXSize();
		int		getDisplayYSize();
		void	setBrightness(byte br);
		void	setDisplayPage(byte page);
		void	setWritePage(byte page);

/*
	The functions and variables below should not normally be used.
	They have been left publicly available for use in add-on libraries
	that might need access to the lower level functions of UTFT.

	Please note that these functions and variables are not documented
	and I do not provide support on how to use them.
*/
		byte			fch, fcl, bch, bcl;
		byte			orient;
		long			disp_x_size, disp_y_size;
		byte			display_model, display_transfer_mode, display_serial_mode;
		regtype			*P_RS, *P_WR, *P_CS, *P_RST, *P_SDA, *P_SCL, *P_ALE;
		regsize			B_RS, B_WR, B_CS, B_RST, B_SDA, B_SCL, B_ALE;
		byte			__p1, __p2, __p3, __p4, __p5;
		_current_font	cfont;
		boolean			_transparent;

		void LCD_Writ_Bus(char VH,char VL, byte mode);
		void LCD_Write_COM(char VL);
		void LCD_Write_DATA(char VH,char VL);
		void LCD_Write_DATA(char VL);
		void LCD_Write_COM_DATA(char com1,int dat1);
		void _hw_special_init();
		void setPixel(word color);
		void drawHLine(int x, int y, int l);
		void drawVLine(int x, int y, int l);
		void printChar(byte c, int x, int y);
		void setXY(word x1, word y1, word x2, word y2);
		void clrXY();
		void rotateChar(byte c, int x, int y, int pos, int deg);
		void _set_direction_registers(byte mode);
		void _fast_fill_16(int ch, int cl, long pix);
		void _fast_fill_8(int ch, long pix);
		void _convert_float(char *buf, double num, int width, byte prec);
};

#endif