//import required libraries
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

static const uint8_t  PROGMEM logo1 [] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x07, 0xFC, 0x00, 0x1F, 0xF0, 0x00, 0x3F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x07, 0xFC, 0x00, 0x1F, 0xF0, 0x00, 0x7F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x07, 0xFC, 0x00, 0x1F, 0xF0, 0x00, 0x7F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x07, 0xFC, 0x00, 0x1F, 0xF0, 0x00, 0x7F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x07, 0xFC, 0x00, 0x1F, 0xF0, 0x00, 0x7F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x07, 0xFC, 0x00, 0x1F, 0xF0, 0x00, 0x7F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00,
  0x3F, 0xFE, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xFF, 0xFC, 0x00, 0x00,
  0x3F, 0xFE, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xFF, 0xFC, 0x00, 0x00,
  0x3F, 0xFE, 0x1F, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xF0, 0xFF, 0xFC, 0x00, 0x00,
  0x3F, 0xFE, 0x1F, 0xFF, 0xC3, 0xFF, 0xFF, 0xFF, 0xFF, 0x83, 0xFF, 0xF0, 0xFF, 0xFC, 0x00, 0x00,
  0x00, 0x00, 0x1F, 0xFF, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x1F, 0xFF, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x1F, 0xFF, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x1F, 0xFF, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x1F, 0xFF, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00,
  0x3F, 0xFE, 0x1F, 0xFF, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xFF, 0xF0, 0xFF, 0xFC, 0x00, 0x00,
  0x3F, 0xFE, 0x1F, 0xFF, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xFF, 0xF0, 0xFF, 0xFC, 0x00, 0x00,
  0x3F, 0xFE, 0x1F, 0xFF, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xFF, 0xF0, 0xFF, 0xFC, 0x00, 0x00,
  0x3F, 0xFE, 0x1F, 0xFF, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xFF, 0xF0, 0xFF, 0xFC, 0x00, 0x00,
  0x00, 0x00, 0x1F, 0xFF, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x1F, 0xFF, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x1F, 0xFF, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x1F, 0xFF, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x1F, 0xFF, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00,
  0x3F, 0xFE, 0x1F, 0xFF, 0xC1, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0xF0, 0xFF, 0xFC, 0x00, 0x00,
  0x3F, 0xFE, 0x1F, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xFF, 0xF0, 0xFF, 0xFC, 0x00, 0x00,
  0x3F, 0xFE, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xFF, 0xFC, 0x00, 0x00,
  0x3F, 0xFE, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xFF, 0xFC, 0x00, 0x00,
  0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x07, 0xFC, 0x00, 0x1F, 0xF0, 0x00, 0x7F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x07, 0xFC, 0x00, 0x1F, 0xF0, 0x00, 0x7F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x07, 0xFC, 0x00, 0x1F, 0xF0, 0x00, 0x7F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x07, 0xFC, 0x00, 0x1F, 0xF0, 0x00, 0x7F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x07, 0xFC, 0x00, 0x1F, 0xF0, 0x00, 0x7F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x07, 0xF8, 0x00, 0x0F, 0xF0, 0x00, 0x3F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x1C, 0x76, 0x7D, 0xF1, 0xF3, 0xFB, 0x3F, 0x6F, 0x3F, 0x3F, 0xF0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x1E, 0xF6, 0xE5, 0xBB, 0xBB, 0x3F, 0x7F, 0x7F, 0x73, 0xB0, 0xC0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x1F, 0xF6, 0xC1, 0xFB, 0x1B, 0x1F, 0x6F, 0x6F, 0xE3, 0xBE, 0xC0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x1B, 0xB6, 0xFD, 0x9B, 0xFB, 0xFB, 0x3F, 0x7F, 0x7F, 0x30, 0xC0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  delay(2000); // Pause for 2 seconds

  // Clear the buffer.
  display.clearDisplay();

  // Draw bitmap on the screen
  display.drawBitmap(0, 0, logo1, 128, 64, 1);
  display.display();
}

void loop() {

}
