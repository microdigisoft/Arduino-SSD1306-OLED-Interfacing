#include <wire.h>// Include Wire library (required for I2C devices)
#include <adafruit_gfx.h>// Include Adafruit graphics library
#include <adafruit_ssd1306.h>            // Include Adafruit SSD1306 OLED driver
 
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
 
#define button1    9 // Button B1 is connected to Arduino pin 9
#define button2    8 // Button B2 is connected to Arduino pin 8
 
void setup(void) {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  delay(1000);
 
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
 
  // Clear the display buffer.
  display.clearDisplay();
  display.display();
 
  display.setTextColor(WHITE, BLACK);
}
 
char Time[]     = "  :  :  ";
char Calendar[] = "  /  /20  ";
byte i, second, minute, hour, day, date, month, year;
 
void display_day(){
  switch(day){
    case 1:  draw_text(40, 0, " SUNDAY  ", 1); break;
    case 2:  draw_text(40, 0, " MONDAY  ", 1); break;
    case 3:  draw_text(40, 0, " TUESDAY ", 1); break;
    case 4:  draw_text(40, 0, "WEDNESDAY", 1); break;
    case 5:  draw_text(40, 0, "THURSDAY ", 1); break;
    case 6:  draw_text(40, 0, " FRIDAY  ", 1); break;
    default: draw_text(40, 0, "SATURDAY ", 1);
  }
}
 
void DS1307_display(){
  // Convert BCD to decimal
  second = (second &gt;&gt; 4) * 10 + (second &amp; 0x0F);
  minute = (minute &gt;&gt; 4) * 10 + (minute &amp; 0x0F);
  hour   = (hour &gt;&gt; 4)   * 10 + (hour &amp; 0x0F);
  date   = (date &gt;&gt; 4)   * 10 + (date &amp; 0x0F);
  month  = (month &gt;&gt; 4)  * 10 + (month &amp; 0x0F);
  year   = (year &gt;&gt; 4)   * 10 + (year &amp; 0x0F);
  // End conversion
 
  Time[7]     = second % 10 + 48;
  Time[6]     = second / 10 + 48;
  Time[4]     = minute % 10 + 48;
  Time[3]     = minute / 10 + 48;
  Time[1]     = hour   % 10 + 48;
  Time[0]     = hour   / 10 + 48;
  Calendar[9] = year   % 10 + 48;
  Calendar[8] = year   / 10 + 48;
  Calendar[4] = month  % 10 + 48;
  Calendar[3] = month  / 10 + 48;
  Calendar[1] = date   % 10 + 48;
  Calendar[0] = date   / 10 + 48;
 
  draw_text(4,  18, Calendar, 2);
  draw_text(16, 42, Time, 2);
}
 
void blink_parameter(){
  byte j = 0;
  while(j &lt; 10 &amp;&amp; digitalRead(button1) &amp;&amp; digitalRead(button2)){
    j++;
    delay(25);
  }
}
 
byte edit(byte x_pos, byte y_pos, byte parameter){
  char text[3];
  sprintf(text,"%02u", parameter);
  while(!digitalRead(button1));// Wait until button B1 released
  while(true){
    while(!digitalRead(button2)){ // If button B2 is pressed
      parameter++;
      if(i == 0 &amp;&amp; parameter &gt; 31) // If date &gt; 31 ==&gt; date = 1
        parameter = 1;
      if(i == 1 &amp;&amp; parameter &gt; 12) // If month &gt; 12 ==&gt; month = 1
        parameter = 1;
      if(i == 2 &amp;&amp; parameter &gt; 99) // If year &gt; 99 ==&gt; year = 0
        parameter = 0;
      if(i == 3 &amp;&amp; parameter &gt; 23) // If hours &gt; 23 ==&gt; hours = 0
        parameter = 0;
      if(i == 4 &amp;&amp; parameter &gt; 59) // If minutes &gt; 59 ==&gt; minutes = 0
        parameter = 0;
      sprintf(text,"%02u", parameter);
      draw_text(x_pos, y_pos, text, 2);
      delay(200);// Wait 200ms
    }
    draw_text(x_pos, y_pos, "  ", 2);
    blink_parameter();
    draw_text(x_pos, y_pos, text, 2);
    blink_parameter();
    if(!digitalRead(button1)){// If button B1 is pressed
      i++; // Increament 'i' for the next parameter
      return parameter; // Return parameter value and exit
    }
  }
}
 
void draw_text(byte x_pos, byte y_pos, char *text, byte text_size) {
  display.setCursor(x_pos, y_pos);
  display.setTextSize(text_size);
  display.print(text);
  display.display();
}
 
void loop() {
 
  if(!digitalRead(button1)){// If button B1 is pressed
    i = 0;
    while(!digitalRead(button1));// Wait for button B1 release
    while(true){
      while(!digitalRead(button2)){ // While button B2 pressed
        day++;                                       // Increment day
        if(day &gt; 7) day = 1;
        display_day(); // Call display_day function
        delay(200);  // Wait 200 ms
      }
      draw_text(40, 0, "         ", 1);
      blink_parameter();  // Call blink_parameter function
      display_day();      // Call display_day function
      blink_parameter();  // Call blink_parameter function
      if(!digitalRead(button1))// If button B1 is pressed
        break;
    }
 
    date   = edit(4, 18, date);  // Edit date
    month  = edit(40, 18, month);// Edit month
    year   = edit(100, 18, year);// Edit year
    hour   = edit(16, 42, hour); // Edit hours
    minute = edit(52, 42, minute); // Edit minutes
 
    // Convert decimal to BCD
    minute = ((minute / 10) &lt;&lt; 4) + (minute % 10);
    hour = ((hour / 10) &lt;&lt; 4) + (hour % 10);
    date = ((date / 10) &lt;&lt; 4) + (date % 10);
    month = ((month / 10) &lt;&lt; 4) + (month % 10);
    year = ((year / 10) &lt;&lt; 4) + (year % 10);
    // End conversion
 
    // Write data to DS1307 RTC
    Wire.beginTransmission(0x68);// Start I2C protocol with DS1307 address
    Wire.write(0); // Send register address
    Wire.write(0); // Reset sesonds and start oscillator
    Wire.write(minute);// Write minute
    Wire.write(hour); // Write hour
    Wire.write(day);  // Write day
    Wire.write(date);  // Write date
    Wire.write(month); // Write month
    Wire.write(year);   // Write year
    Wire.endTransmission(); // Stop transmission and release the I2C bus
    delay(200);                                 // Wait 200ms
  }
 
  Wire.beginTransmission(0x68);// Start I2C protocol with DS1307 address
  Wire.write(0); // Send register address
  Wire.endTransmission(false); // I2C restart
  Wire.requestFrom(0x68, 7);// Request 7 bytes from DS1307 and release I2C bus at end of reading
  second = Wire.read(); // Read seconds from register 0
  minute = Wire.read(); // Read minuts from register 1
  hour   = Wire.read(); // Read hour from register 2
  day    = Wire.read(); // Read day from register 3
  date   = Wire.read(); // Read date from register 4
  month  = Wire.read();  // Read month from register 5
  year   = Wire.read();  // Read year from register 6
 
  display_day();
  DS1307_display(); // Diaplay time &amp; calendar
 
  delay(50); // Wait 50ms 
}
