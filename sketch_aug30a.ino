#include <Wire.h>
#include <EncButton.h>
#include <Arduino.h>
#include <GyverOLED.h>
#include <vector>
#include <EEPROM.h>


//tech vars

#define EEPROM_SIZE 11
int16_t data[7];  

//-------------SNAKE-------------------------------------------

const uint8_t bitmap_63x64[] PROGMEM = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0xC0,
  0xF0,
  0xF0,
  0xF0,
  0xE0,
  0x80,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x0E,
  0xFF,
  0xFF,
  0xFF,
  0xFF,
  0xFF,
  0x07,
  0x00,
  0x80,
  0x80,
  0x80,
  0x80,
  0x80,
  0x80,
  0x80,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x80,
  0xC0,
  0xC0,
  0xE0,
  0xE0,
  0xC3,
  0xC7,
  0xC7,
  0x8F,
  0x0F,
  0x0F,
  0x0F,
  0x07,
  0x07,
  0x07,
  0x87,
  0xCF,
  0xFF,
  0xFF,
  0xFE,
  0x78,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x7E,
  0xFF,
  0xFF,
  0xFF,
  0xE7,
  0xC3,
  0xC3,
  0xC3,
  0xC3,
  0xE7,
  0xFF,
  0xFF,
  0xFF,
  0x7E,
  0x7E,
  0x7E,
  0xFF,
  0xFF,
  0xE7,
  0xE7,
  0xC3,
  0x81,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0xC0,
  0xE1,
  0xE3,
  0xF3,
  0xF3,
  0xF7,
  0xF3,
  0xF3,
  0xE3,
  0xC1,
  0xC0,
  0x80,
  0x00,
  0x00,
  0x80,
  0xC0,
  0xC1,
  0xF3,
  0xFF,
  0xFF,
  0x7F,
  0x1E,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x1F,
  0x7F,
  0xFF,
  0xFF,
  0xF1,
  0xE0,
  0xE0,
  0xE0,
  0xF1,
  0xFB,
  0xFF,
  0x7F,
  0x3F,
  0x3F,
  0x1F,
  0x3F,
  0x7F,
  0x7F,
  0xFB,
  0xF1,
  0xE1,
  0xC0,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x01,
  0x01,
  0x01,
  0x01,
  0x81,
  0xC0,
  0xE0,
  0xE0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF8,
  0x78,
  0x7D,
  0x7F,
  0x3F,
  0x1F,
  0x0F,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x07,
  0x1F,
  0x3F,
  0x03,
  0x01,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
};

const uint8_t cup[] PROGMEM = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0xC0,
  0xC0,
  0xC0,
  0xC0,
  0xC0,
  0xC0,
  0xC0,
  0xC0,
  0xF8,
  0xF8,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x00,
  0x00,
  0x18,
  0x18,
  0x18,
  0x38,
  0xB8,
  0xF8,
  0xF8,
  0xC0,
  0xC0,
  0xC0,
  0xC0,
  0xC0,
  0xC0,
  0xC0,
  0xC0,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x0F,
  0x3F,
  0xFD,
  0xE1,
  0x81,
  0x01,
  0x01,
  0x01,
  0x07,
  0x1F,
  0x3F,
  0x87,
  0x07,
  0x07,
  0x07,
  0x07,
  0x07,
  0x07,
  0x07,
  0x07,
  0x07,
  0x07,
  0x07,
  0x07,
  0x07,
  0x07,
  0x07,
  0x07,
  0x07,
  0x07,
  0x07,
  0x07,
  0x07,
  0x07,
  0x07,
  0x07,
  0x07,
  0xFF,
  0xFF,
  0x3F,
  0x07,
  0x01,
  0x01,
  0x01,
  0x81,
  0xE1,
  0xFD,
  0x3F,
  0x0F,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x03,
  0x07,
  0x0E,
  0x1C,
  0x38,
  0x30,
  0x70,
  0xE3,
  0xF3,
  0xF8,
  0xF0,
  0xC0,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x80,
  0xE0,
  0xF8,
  0xFF,
  0xFF,
  0xE3,
  0x70,
  0x30,
  0x38,
  0x1C,
  0x0E,
  0x07,
  0x03,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x01,
  0x03,
  0x07,
  0x0E,
  0x1C,
  0x38,
  0x70,
  0x60,
  0xE0,
  0xE0,
  0xE0,
  0xE0,
  0xE0,
  0xE0,
  0xE0,
  0x70,
  0x78,
  0x38,
  0x1C,
  0x0F,
  0x07,
  0x03,
  0x01,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x80,
  0x80,
  0x80,
  0xC0,
  0xC0,
  0xE0,
  0xF0,
  0xFC,
  0x9F,
  0x87,
  0x81,
  0x80,
  0x81,
  0xCF,
  0xFF,
  0xFC,
  0xF0,
  0xE0,
  0xC0,
  0xC0,
  0x80,
  0x80,
  0x80,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0xF0,
  0xF8,
  0x38,
  0x1F,
  0x3F,
  0x3F,
  0x39,
  0xB9,
  0xB9,
  0xB9,
  0xB9,
  0xB9,
  0xB9,
  0xB9,
  0xB9,
  0xB9,
  0xB9,
  0xB9,
  0xB9,
  0xB9,
  0xB9,
  0xB9,
  0x39,
  0x3F,
  0x3F,
  0xFF,
  0xF8,
  0xF8,
  0xF0,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0xFF,
  0xFF,
  0x00,
  0x00,
  0x00,
  0x00,
  0x3F,
  0x7F,
  0x7F,
  0x73,
  0x73,
  0x73,
  0x73,
  0x73,
  0x73,
  0x73,
  0x73,
  0x73,
  0x73,
  0x73,
  0x7F,
  0x7F,
  0x37,
  0x00,
  0x00,
  0xFF,
  0xFF,
  0xEF,
  0xEF,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x60,
  0x60,
  0x70,
  0x7E,
  0x7E,
  0x67,
  0x67,
  0x66,
  0x7E,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7F,
  0x7E,
  0x70,
  0x60,
  0x60,
  0x00,
  0x00,
  0x60,
  0x60,
  0x60,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
};

const uint8_t epd_bitmap_ping [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 
	0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xfc, 0xfe, 0x1f, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x0f, 0x1f, 
	0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x0f, 0x0f, 0x1f, 0x7e, 0xfc, 0xf8, 0xe0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xc0, 0xfc, 0xff, 0xff, 0xff, 0x70, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x0e, 0xee, 0xe0, 
	0xf0, 0xe0, 0xe4, 0x4e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xf0, 
	0xf8, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xc3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xfc, 0xf0, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x01, 0x00, 0x00, 0x07, 0x1f, 0x3f, 0x7f, 0xfe, 0xf8, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 
	0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0xf8, 0xfc, 0x7f, 0x3f, 0x1f, 0x07, 0x01, 0x00, 
	0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x05, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 
	0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x03, 0x05, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t race [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xa0, 0xc0, 0xd0, 0x00, 0x08, 0x08, 0x08, 0x00, 0x00, 0x04, 
	0x00, 0x00, 0x00, 0x08, 0x08, 0x08, 0x00, 0xd0, 0xc0, 0xa0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x03, 0x01, 0x00, 0x80, 0x80, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 
	0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x00, 0x01, 0x03, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xc0, 0xa0, 0x9f, 0xe0, 0x84, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x84, 0xe0, 0x9f, 0xa0, 0xc0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0xff, 0x7f, 0xff, 0xf8, 0x07, 0x0f, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 
	0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x0f, 0x07, 0xf0, 0xff, 0x7f, 0xff, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 0xfe, 0xfd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfd, 0xfe, 0xfe, 0xff, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0x7f, 0xff, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 
	0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0xff, 0x7f, 0x07, 0xff, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x01, 0x1c, 0x3f, 0x3f, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 
	0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x3f, 0x1c, 0x01, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0c, 0x10, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x10, 0x08, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00
};

void get_mpu_data() {
  int16_t data_1[7], data_2[7];

  Serial.println(0);
    Wire1.beginTransmission(0x68);
    Serial.println(1);
    Wire1.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
    Serial.println(2);
    byte err = Wire1.endTransmission();
    Serial.println(3);

    if (err == 0) {
        Wire1.requestFrom(0x68, 14, true); // request a total of 14 registers
    for (byte i = 0; i < 7; i++) {
      data_1[i] = Wire1.read() << 8 | Wire1.read();
      //Serial.print(Wire1.read() << 8 | Wire1.read());
      Serial.print(data[i]);
      Serial.print(' ');
    }
    } else {
      Serial.println("error");
    }

    Serial.println(' ');
    Serial.print("acc Y_f: ");
    Serial.println(data[1] / 32768 * 2);

    ////////////////////////

    Serial.println(0);
    Wire1.beginTransmission(0x69);
    Serial.println(1);
    Wire1.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
    Serial.println(2);
    byte err1 = Wire1.endTransmission();
    Serial.println(3);

    if (err1 == 0) {
        Wire1.requestFrom(0x69, 14, true); // request a total of 14 registers
    for (byte i = 0; i < 7; i++) {
      data_2[i] = Wire1.read() << 8 | Wire1.read();
      //Serial.print(Wire1.read() << 8 | Wire1.read());
      Serial.print(data[i]);
      Serial.print(' ');
    }
    } else {
      Serial.println("error");
    }

    if ((data_1[0] == 0 || data_1[1] == 0 || data_1[2] == 0 || data_1[3] == 0 || data_1[4] == 0 || data_1[5] == 0 || data_1[6] == 0) ||
        (data_1[0] == -1 || data_1[1] == -1 || data_1[2] == -1 || data_1[3] == -1 || data_1[4] == -1 || data_1[5] == -1 || data_1[6] == -1)) {

          if ((data_2[0] == 0 || data_2[1] == 0 || data_2[2] == 0 || data_2[3] == 0 || data_2[4] == 0 || data_2[5] == 0 || data_2[6] == 0) ||
        (data_2[0] == -1 || data_2[1] == -1 || data_2[2] == -1 || data_2[3] == -1 || data_2[4] == -1 || data_2[5] == -1 || data_2[6] == -1)) {
          for (int i = 0; i < 7; i++) {
            data[i] = 0;
          }
        } else {
          for (int i = 0; i < 7; i++) {
            data[i] = data_2[i];
          }
        }

          
    } else {
      for (int i = 0; i < 7; i++) {
            data[i] = data_1[i];
      }
    }
}

//-------------SNAKE-------------------------------------------


TaskHandle_t Task1, Task2;

GyverOLED<SSH1106_128x64> display;

enum console_state { main_menu,
                     snake,
                     racing };
console_state main_state = console_state::main_menu;

int main_menu_opt = 1;

int btn_pin1 = 4;   //left
int btn_pin2 = 32;  //up
int btn_pin3 = 2;   //down
int btn_pin4 = 17;  //right
int btn_pin5 = 23;  //ok

uint8_t score;
uint8_t best_score;
uint8_t race_score;
uint8_t race_best_score = 0;

Button btn1(btn_pin1);
Button btn2(btn_pin2);
Button btn3(btn_pin3);
Button btn4(btn_pin4);
Button btn5(btn_pin5);

//games vars
namespace snake_ns {
  //-------------SNAKE-------------------------------------------
  /**/ enum game_state { start,
                        game,
                        death,
                        score_menu };
  /**/ game_state cur_state = start;
  /**/
  /**/ String disp("                                                                                                                                                                        ");
  /**/ int diff_x = 1;
  /**/ int diff_y = 0;
  /**/
  /**/ int cur_death_option = 1;
  /**/ int cur_start_option = 1;
  /**/
  /**/ std::vector<int> points;
  /**/ std::vector<int> no_snake;
  /**/ std::vector<char> snake_chars;
  /**/ int apple_pos;
  //-------------SNAKE-------------------------------------------

  void print_score_screen() {
    display.clear();
    display.drawBitmap(0, 0, cup, 63, 64);
    display.setCursorXY(64, 0);
    display.setScale(2);
    display.print("BEST");
    display.setCursorXY(64, 16);
    display.print("SCORE");
    display.setScale(2);
    display.setCursorXY(64, 32);
    display.print(best_score);
    display.setCursorXY(64, 56);
    display.setScale(1);
    display.print(" > Exit");
    display.update();
  }

  void print_start_screen(int opt) {
    display.clear();
    display.drawBitmap(0, 0, bitmap_63x64, 63, 64);
    display.setCursorXY(64, 0);
    display.setScale(2);
    display.println("SNAKE");
    display.setScale(1);
    display.setCursorXY(54, 16);

    if (opt == 1)
      display.println("> Play");
    else
      display.println("  Play");

    display.setCursorXY(54, 24);

    if (opt == 2)
      display.println("> Best score");
    else
      display.println("  Best score");

    display.setCursorXY(54, 32);

    if (opt == 3)
      display.println("> Exit");
    else
      display.println("  Exit");
    //display.println("jopa");
    display.update();
  }

  void print_death_screen(int opt) {
    display.clear();
    display.home();
    display.setScale(2);
    display.println("Game Over");
    display.setScale(2);
    display.print("Score: ");
    display.println(score);
    display.setScale(1);

    if (opt == 1)
      display.println("  > Restart");
    else {
      display.println("    Restart");
    }

    if (opt == 2)
      display.println("  > Main menu");
    else
      display.println("    Main menu");

    display.update();
  }

  void restart_game() {
    int diff_x = 1;
    int diff_y = 0;

    Serial.print(diff_x);
    Serial.print(" 1-1 ");
    Serial.println(diff_y);

    cur_state = game_state::game;

    Serial.print(diff_x);
    Serial.print(" 2-2 ");
    Serial.println(diff_y);
  }

  void game_over() {
    cur_state = game_state::death;

    int diff_x = 1;
    int diff_y = 0;

    score = points.size();

    if (score > best_score) {
      best_score = score;
      EEPROM.write(0, best_score);
      //EEPROM.commit();
    }

    cur_death_option = 1;
    print_death_screen(1);

    points.clear();
    no_snake.clear();
    snake_chars.clear();

    points.push_back(0);
    points.push_back(1);
    points.push_back(2);
    points.push_back(3);

    snake_chars.push_back('>');
    snake_chars.push_back('>');
    snake_chars.push_back('>');
    snake_chars.push_back('>');

    apple_pos = random(4, disp.length() - 1);

    disp = "                                                                                                                                                                        ";
  }

  bool update_points() {
    if ((points[points.size() - 1] / 21 == 0 && diff_y == -1) || (points[points.size() - 1] / 21 == 7 && diff_y == 1) || (points[points.size() - 1] % 21 == 20 && diff_x == 1) || (points[points.size() - 1] % 21 == 0 && diff_x == -1) || (disp[points.back() + diff_y * 21 + diff_x] == '.')) {
      game_over();
      return false;
    }



    if (points.back() + diff_y * 21 + diff_x == apple_pos) {
      points.push_back(apple_pos);

      if (diff_x == 1) {
        snake_chars.push_back('>');
      } else if (diff_x == -1) {
        snake_chars.push_back('<');
      } else if (diff_y == 1) {
        snake_chars.push_back('V');
      } else {
        snake_chars.push_back('^');
      }

      int old_pos = apple_pos;

      while (old_pos == apple_pos) {
        apple_pos = no_snake[random(0, no_snake.size())];
      }

      return true;
    }

    for (int i = 0; i < points.size() - 1; i++) {
      points[i] = points[i + 1];
      snake_chars[i] = snake_chars[i + 1];
    }

    if (diff_x == 1) {
      snake_chars.back() = '>';
    } else if (diff_x == -1) {
      snake_chars.back() = '<';
    } else if (diff_y == 1) {
      snake_chars.back() = 'V';
    } else {
      snake_chars.back() = '^';
    }

    points[points.size() - 1] = points[points.size() - 1] + diff_y * 21 + diff_x;

    return true;
  }

  void update_map(void* pvParameters) {

    for (;;) {
      delay(100);

      if (cur_state == game_state::game) {
        if (!snake_ns::update_points())
          continue;

        disp = "                                                                                                                                                                        ";

        for (int i = 0; i < points.size(); i++) {
          disp[points[i]] = snake_chars[i];
        }

        no_snake.clear();

        for (int i = 0; i < disp.length(); i++) {
          if (disp[i] == ' ')
            no_snake.push_back(i);
        }

        disp[apple_pos] = '@';

        display.clear();
        display.home();
        display.setScale(1);
        display.print(disp);
        display.update();
      }
    }
  }

}

namespace racing_ns {
  struct car_coord {
    int lx;
    int rx;
    int by;
  };

  std::vector<car_coord> cars;

  enum game_state {start, game, score, death};
  game_state cur_state = start;
  String fake_disp("                                                                                                                                                                                                                                                            ");
  String disp("                                                                                                                                                                        ");
  int left_x = 9, right_x = 11; //starts from 0
  int y = 10; //start from 0

  int main_car_change = 0;

  int start_opt = 1;
  int death_opt = 1;

  void print_start_screen(int change) {
    start_opt = start_opt + change <= 3 && start_opt >= 1 ? start_opt + change : start_opt;

    display.clear();
    display.drawBitmap(11, 0, race, 32, 64);
    display.setCursorXY(64, 0);
    display.setScale(2);
    display.println("RACE");
    display.setScale(1);
    display.setCursorXY(54, 16);

    if (start_opt == 1)
      display.println("> Play");
    else
      display.println("  Play");

    display.setCursorXY(54, 24);

    if (start_opt == 2)
      display.println("> Best score");
    else
      display.println("  Best score");

    display.setCursorXY(54, 32);

    if (start_opt == 3)
      display.println("> Exit");
    else
      display.println("  Exit");
    
    display.update();
  }

  void print_death_screen(int change) {
    death_opt = death_opt + change == 1 || death_opt + change == 2 ? death_opt + change : death_opt;

    display.clear();
    display.home();
    display.setScale(2);
    display.println("Game Over");
    display.setScale(2);
    display.print("Score: ");
    display.println(race_score);
    display.setScale(1);

    if (death_opt == 1)
      display.println("  > Restart");
    else {
      display.println("    Restart");
    }

    if (death_opt == 2)
      display.println("  > Main menu");
    else
      display.println("    Main menu");

    display.update();
  }

  void print_car(String& disp, int left_x, int y) {
    disp[21*(y-1)+left_x] = '<';
    disp[21*(y-1)+left_x + 1] = '_';
    disp[21*(y-1)+left_x + 2] = '>';
    disp[21*(y-2)+left_x + 1] = '^';
  }

  void generate_cars() {
    
    int car_num = random(1, 3);

    std::vector<int> triplets{0, 1, 2, 3, 4, 5, 6};

    for (int i = 0; i < car_num; i++) {
      int pos = triplets[random(0, triplets.size())];
      cars.push_back({pos*3, pos*3 + 2, 1});

      int indx;

      for (int i = 0; i < triplets.size(); i++) {
        if (triplets[i] == pos) {
          indx = i;
          break;
        }
      }

      triplets.erase(triplets.begin() + indx);
    }
  }

  void game_over() {
    cur_state = game_state::death;

    left_x = 9, right_x = 11; //starts from 0
    y = 10; //start from 0

    //score = points.size();

    if (race_score > race_best_score) {
      race_best_score = race_score;
      Serial.println(race_best_score);
      EEPROM.write(10, race_best_score);
      EEPROM.commit();
    }

    death_opt = 1;
    print_death_screen(0);

    /*points.clear();
    no_snake.clear();
    snake_chars.clear();

    points.push_back(0);
    points.push_back(1);
    points.push_back(2);
    points.push_back(3);

    snake_chars.push_back('>');
    snake_chars.push_back('>');
    snake_chars.push_back('>');
    snake_chars.push_back('>');

    apple_pos = random(4, disp.length() - 1);*/
  }

  void restart_game() {
    race_score = 0;
    left_x = 9;
    right_x = 11;
    y = 10;
    cars.clear();
    
    int main_car_change = 0;

    int start_opt = 1;
    int death_opt = 1;

    cur_state = game_state::game;
  }

  bool update_points() {
    for (auto x:cars) {
      if ((x.by + 2 == y || x.by + 1 == y) && x.lx == left_x) {
        game_over();
        return false;
      }
    }

    for (auto &x:cars) {
      x.by++;
    }

    return true;
  }

  void clear_cars() {
    int dl = cars.size();

    for (int i = 0; i < dl; i++) {
      if (cars[i].by == 11) {
        cars.erase(cars.begin() + i);
        i--;
        dl--;
      }
    }
  }

  void print_score_screen() {
    display.clear();
    display.drawBitmap(0, 0, cup, 63, 64);
    display.setCursorXY(64, 0);
    display.setScale(2);
    display.print("BEST");
    display.setCursorXY(64, 16);
    display.print("SCORE");
    display.setScale(2);
    display.setCursorXY(64, 32);
    display.print(race_best_score);
    display.setCursorXY(64, 56);
    display.setScale(1);
    display.print(" > Exit");
    display.update();
  }

  void update_map(void* pvParameters) {
    bool is_gen = true;
    race_score = -1;
    cars.clear();
    //randomSeed(analogRead(0));

    while (true) {
      delay(100);

      if (cur_state == game_state::game) {
          /*sensors_event_t a, g, temp;
          sensors_event_t a2, g2, temp2;

          mpu.getEvent(&a, &g, &temp);
          mpu2.getEvent(&a2, &g2, &temp2);

          if (a2.acceleration.y > 3 && left_x > 0) {
            left_x -=3;
            right_x -= 3; 
          }

          if (a2.acceleration.y < -3 && right_x < 20) {
            left_x +=3;
            right_x += 3; 
          }*/

          get_mpu_data();

          if (data[1] > 6000 && left_x > 0) {
            left_x -=3;
            right_x -= 3; 
          }

          if (data[1] < -6000 && right_x < 20) {
            left_x +=3;
            right_x += 3; 
          }


          if (!update_points())
            continue;

          if (is_gen) {
            race_score++;
            generate_cars();
          }

          is_gen = !is_gen;

          String tmp(fake_disp);
          //print_main_car
          print_car(tmp, left_x, y);

          for (auto x:cars) {
            print_car(tmp, x.lx, x.by);
          }

          tmp = tmp.substring(42, 42+168);

          display.clear();
          display.home();
          display.setScale(1);
          display.print(tmp);
          display.update();

          clear_cars();
      }
    }
    
  }
}

void print_main_menu(int change) {
  main_menu_opt = main_menu_opt + change == 1 || main_menu_opt + change == 2 ? main_menu_opt + change : main_menu_opt;

  display.clear();
  display.drawBitmap(0, 0, epd_bitmap_ping, 64, 64);
  display.setCursorXY(64, 0);
  display.setScale(2);
  display.println("MAIN");
  display.setCursorXY(64, 16);
  display.println("MENU");
  display.setScale(1);
  display.setCursorXY(54, 32);

  if (main_menu_opt == 1)
    display.println("> Snake");
  else
    display.println("  Snake");

  display.setCursorXY(54, 40);

  if (main_menu_opt == 2)
    display.println("> Racing");
  else
    display.println("  Racing");

  display.update();
}

void setup() {
  Serial.begin(115200);

  display.init(26, 27);
  Wire1.begin(21, 22);  
  display.autoPrintln(true);
  display.home();
  display.setScale(1);
  
  Wire1.beginTransmission(0x68);
    byte error1;
    Wire1.write(0x6B);  // PWR_MGMT_1 register
    Wire1.write(0); 
    error1 = Wire1.endTransmission(true);
    Serial.print("error11111111111111111111111: ");
    Serial.println(error1);

    if (error1 == 0) {
      Serial.println("OK");
    }

  Wire1.beginTransmission(0x69);
    byte error2;
    Wire1.write(0x6B);  // PWR_MGMT_1 register
    Wire1.write(0); 
    error2 = Wire1.endTransmission(true);
    Serial.print("error22222222222222222222: ");
    Serial.println(error1);

    if (error2 == 0) {
      Serial.println("OK");
    }




  unsigned long seed = 0;
  for (int i=0; i<32; i++)
  {
    seed = seed | ((analogRead(A0) & 0x01) << i);
  }
  randomSeed(analogRead(21));

  EEPROM.begin(EEPROM_SIZE);
  

  main_state = console_state::main_menu;

  snake_ns::points.push_back(0);
  snake_ns::points.push_back(1);
  snake_ns::points.push_back(2);
  snake_ns::points.push_back(3);

  snake_ns::snake_chars.push_back('>');
  snake_ns::snake_chars.push_back('>');
  snake_ns::snake_chars.push_back('>');
  snake_ns::snake_chars.push_back('>');

  best_score = EEPROM.read(0);
  race_best_score = EEPROM.read(10);

  Serial.println(EEPROM.read(10));

  if (best_score == 255) {
    best_score = 0;
  }

  if (race_best_score == 255) {
    race_best_score = 0;
  }

  Serial.print(best_score);
  Serial.println("  best score");

  delay(6000);

  

  xTaskCreatePinnedToCore(
    snake_ns::update_map,
    "Task1",
    10000,
    NULL,
    0,
    &Task1,
    0);

  vTaskSuspend(Task1);

  xTaskCreatePinnedToCore(
    racing_ns::update_map,
    "Task2",
    10000,
    NULL,
    1,
    &Task2,
    0);

  vTaskSuspend(Task2);

  Serial.println(snake_ns::points.size());

  Serial.println("qweqwe");

  display.init(12, 14);
  display.autoPrintln(true);
  display.home();
  display.setScale(1);
  display.print(snake_ns::disp);
  display.update();

  print_main_menu(0);

  delay(2000);
}

void loop() {

  btn1.tick();
  btn2.tick();
  btn3.tick();
  btn4.tick();
  btn5.tick();

  if (main_state == console_state::main_menu) {
    if (btn2.press()) {
      print_main_menu(-1);
    } else if (btn3.press()) {
      print_main_menu(1);
    } else if (btn5.press()) {
      if (main_menu_opt == 1) {
        vTaskResume(Task1);
        main_state = console_state::snake;
        main_menu_opt = 1;
        snake_ns::cur_state = snake_ns::game_state::start;
        snake_ns::print_start_screen(snake_ns::cur_start_option);
      } else {
        vTaskResume(Task2);
        main_state = console_state::racing;
        main_menu_opt;
        racing_ns::cur_state = racing_ns::game_state::start;
        racing_ns::start_opt = 1;
        racing_ns::left_x = 9;
        racing_ns::right_x = 11; //starts from 0
        racing_ns::y = 10; //start from 0
        racing_ns::print_start_screen(0);
      }
    }
  } else if (main_state == console_state::snake){

    /*if (snake_ns::cur_state == snake_ns::game_state::game)
      vTaskResume(Task1);*/

    if (btn1.press()) {  //left
      if (snake_ns::cur_state == snake_ns::game_state::game && snake_ns::diff_x == 0) {
        snake_ns::diff_x = -1;
        snake_ns::diff_y = 0;
      }

      Serial.println("btn1");
    }
    if (btn2.press()) {  //up
      if (snake_ns::cur_state == snake_ns::game_state::game) {
        if (snake_ns::diff_y == 0) {
          snake_ns::diff_x = 0;
          snake_ns::diff_y = -1;
        }
      } else if (snake_ns::cur_state == snake_ns::game_state::death) {
        if (snake_ns::cur_death_option == 2) {
          snake_ns::cur_death_option = 1;

          snake_ns::print_death_screen(snake_ns::cur_death_option);
        }
      } else if (snake_ns::cur_state == snake_ns::game_state::start) {
        if (snake_ns::cur_start_option == 2 || snake_ns::cur_start_option == 3) {
          snake_ns::cur_start_option--;

          snake_ns::print_start_screen(snake_ns::cur_start_option);
        }
      } else {
      }

      Serial.println("btn2");
    }
    if (btn3.press()) {  //down
      if (snake_ns::cur_state == snake_ns::game_state::game) {
        if (snake_ns::diff_y == 0) {
          snake_ns::diff_x = 0;
          snake_ns::diff_y = 1;
        }
      } else if (snake_ns::cur_state == snake_ns::game_state::death) {
        if (snake_ns::cur_death_option == 1) {
          snake_ns::cur_death_option = 2;

          snake_ns::print_death_screen(snake_ns::cur_death_option);
        }
      } else if (snake_ns::cur_state == snake_ns::game_state::start) {
        if (snake_ns::cur_start_option == 2 || snake_ns::cur_start_option == 1) {
          snake_ns::cur_start_option++;

          snake_ns::print_start_screen(snake_ns::cur_start_option);
        }
      } else {
      }

      Serial.println("btn3");
    }
    if (btn4.press()) {  //right
      if (snake_ns::cur_state == snake_ns::game_state::game) {
        if (snake_ns::diff_x == 0) {
          snake_ns::diff_x = 1;
          snake_ns::diff_y = 0;
        }
      }

      Serial.println("btn4");
    }

    if (btn5.press()) {

      if (snake_ns::cur_state == snake_ns::game_state::death) {
        if (snake_ns::cur_death_option == 1) {
          Serial.println("rs");
          snake_ns::restart_game();
          snake_ns::diff_x = 1;
          snake_ns::diff_y = 0;
        } else {
          vTaskSuspend(Task1);
          snake_ns::print_start_screen(1);
          snake_ns::cur_state = snake_ns::game_state::start;
          snake_ns::cur_start_option = 1;
          snake_ns::cur_death_option = 1;
        }
      } else if (snake_ns::cur_state == snake_ns::game_state::start) {
        if (snake_ns::cur_start_option == 1) {
          snake_ns::cur_state = snake_ns::game_state::game;
          snake_ns::restart_game();
          snake_ns::diff_x = 1;
          snake_ns::diff_y = 0;
        } else if (snake_ns::cur_start_option == 2) {
          snake_ns::print_score_screen();
          snake_ns::cur_state = snake_ns::game_state::score_menu;
        } else {
          main_state = console_state::main_menu;
          snake_ns::cur_start_option = 1;
          main_menu_opt = 1;
          vTaskSuspend(Task1);
          print_main_menu(0);
        }
      } else if (snake_ns::cur_state == snake_ns::game_state::score_menu) {
        snake_ns::print_start_screen(1);
        snake_ns::cur_state = snake_ns::game_state::start;
        snake_ns::cur_start_option = 1;
        snake_ns::cur_death_option = 1;
      }
    }
  } else if (main_state == console_state::racing) {
    if (btn1.press()) { // left only in game
      if (racing_ns::cur_state == racing_ns::game_state::game) {
        if (racing_ns::left_x > 0) {
          racing_ns::left_x -=3;
          racing_ns::right_x -= 3; //starts from 0
        }
      }
    } else if (btn2.press()) { //up only in menus
      if (racing_ns::cur_state == racing_ns::game_state::start) {
        racing_ns::print_start_screen(-1);
      } else if (racing_ns::cur_state == racing_ns::game_state::death) {
        racing_ns::print_death_screen(-1);
      } else if (racing_ns::cur_state == racing_ns::game_state::score) {

      }
    } else if (btn3.press()) { //down only in menus
      if (racing_ns::cur_state == racing_ns::game_state::start) {
        racing_ns::print_start_screen(1);
      } else if (racing_ns::cur_state == racing_ns::game_state::death) {
        racing_ns::print_death_screen(1);
      } else if (racing_ns::cur_state == racing_ns::game_state::score) {

      }
    } else if (btn4.press()) { //right only in game
      if (racing_ns::cur_state == racing_ns::game_state::game) {
        
        if (racing_ns::right_x < 20) {
          racing_ns::left_x +=3;
          racing_ns::right_x += 3; //starts from 0
        }
      }
    } else if (btn5.press()) {
      if (racing_ns::cur_state == racing_ns::game_state::start) {
        if (racing_ns::start_opt == 1) {
          racing_ns::cur_state = racing_ns::game_state::game;
          //snake_ns::cur_state = snake_ns::game_state::game;
          //snake_ns::restart_game();
          //snake_ns::diff_x = 1;
          //snake_ns::diff_y = 0;
        } else if (racing_ns::start_opt == 2) {
          racing_ns::print_score_screen();
          racing_ns::cur_state = racing_ns::game_state::score;
        } else if (racing_ns::start_opt == 3) {
          main_state = console_state::main_menu;
          racing_ns::start_opt = 1;
          main_menu_opt = 1;
          //vTaskSuspend(Task);
          print_main_menu(0);
        }
      } else if (racing_ns::cur_state == racing_ns::game_state::score) {
        racing_ns::cur_state = racing_ns::game_state::start;
        racing_ns::start_opt = 1;
        racing_ns::death_opt = 1;
        racing_ns::print_start_screen(0);
      } else if (racing_ns::cur_state == racing_ns::game_state::death) {
        if (racing_ns::death_opt == 1) {
          racing_ns::restart_game();
          racing_ns::left_x = 9;
          racing_ns::right_x = 11;
          racing_ns::y = 10;
        } else {
          vTaskSuspend(Task2);
          racing_ns::start_opt = 1;
          racing_ns::death_opt = 1;
          racing_ns::print_start_screen(0);
          racing_ns::cur_state = racing_ns::game_state::start;
          racing_ns::start_opt = 1;
          racing_ns::death_opt = 1;
        }
      }
    }
  }
}
