#include <Wire.h>              // include Arduino wire library (required for I2C devices)
#include <Adafruit_GFX.h>      // include Adafruit graphics library
#include <Adafruit_SSD1306.h>  // include Adafruit SSD1306 OLED display driver

#define OLED_RESET  4    // define display reset pin
Adafruit_SSD1306 display(OLED_RESET);

// define LM35 data pin connection
#define  LM35_pin  A0

void setup(void)
{
  delay(1000);  // wait a second
  analogReference(INTERNAL);  // set positive reference voltage to 1.1V

  // initialize the SSD1306 OLED display with I2C address = 0x3D
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);

  // clear the display buffer.
  display.clearDisplay();

  display.setTextSize(1);   // text size = 1
  display.setTextColor(WHITE, BLACK);  // set text color to white and black background
  display.setCursor(15, 0);            // move cursor to position (15, 0) pixel
  display.print("LM35 TEMPERATURE:");
  display.display();        // update the display
  display.setTextSize(2);   // text size = 2
}

int tKelvin, tCelsius, tFahrenheit;
char _buffer[8];

void loop()
{
  // read analog voltage ( = tenths degree Celsius)
  //   9.3 = 1023/(1.1*100)
  tCelsius = 10 * analogRead(LM35_pin) / 9.3;

  tKelvin     = tCelsius + 2732;       // convert tenths °C to tenths Kelvin
  tFahrenheit = tCelsius * 9 / 5 + 320 ; // convert tenths °C to tenths °Fahrenheit

  // print temperature in degree Celsius
  if (tCelsius >= 1000)    // if temperature >= 100.0 °C
    sprintf(_buffer, "%03u.%1u C", tCelsius / 10, tCelsius % 10);
  else
    sprintf(_buffer, " %02u.%1u C", tCelsius / 10, tCelsius % 10);
  display.setCursor(23, 10);
  display.print(_buffer);

  // print temperature in degree Fahrenheit
  if (tFahrenheit >= 1000)     // if temperature >= 100.0 °F
    sprintf(_buffer, "%03u.%1u F", tFahrenheit / 10, tFahrenheit % 10);
  else
    sprintf(_buffer, " %02u.%1u F", tFahrenheit / 10, tFahrenheit % 10);
  display.setCursor(23, 30);
  display.print(_buffer);

  // print temperature in Kelvin
  sprintf(_buffer, "%03u.%1u K", tKelvin / 10, tKelvin % 10);
  display.setCursor(23, 50);
  display.print(_buffer);

  // print degree symbols ( ° )
  display.drawCircle(88, 12, 2, WHITE);
  display.drawCircle(88, 32, 2, WHITE);

  // update the display
  display.display();

  delay(1000);  // wait a second

}
