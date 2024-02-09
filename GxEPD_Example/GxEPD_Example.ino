 // TECHATRONIC.COM   
  // SimpleDHT LIBRARY LINK   
  // https://github.com/winlinvip/SimpleDHT   
  // Library SPI.h  
  // https://github.com/PaulStoffregen/SPI   
  // Library Adafruit_GFX.h  
  // https://github.com/adafruit/Adafruit-GFX-Library  
  // Library Adafruit_SSD1306.h  
  // https://github.com/adafruit/Adafruit_SSD1306  
 #include <SPI.h>  
 #include <Wire.h>  
 #include <Adafruit_GFX.h>  
 #include <Adafruit_SSD1306.h>  
 #include <SimpleDHT.h>  
 //   for DHT11,    
 //   VCC: 5V or 3V  
 //   GND: GND  
 //   DATA: 2  
 int pinDHT11 = 3;  
 SimpleDHT11 dht11(pinDHT11);  
 #define screen_width 128 // OLED display width, in pixels  
 #define screen_height 64 // OLED display height, in pixels  
 #define OLED_RESET -1
 Adafruit_SSD1306 display(screen_width, screen_height);  
 void setup ()  
 {  
   Serial.begin(9600);  
   Serial.println("TEMPERATURE AND HUMIDITY");  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  display.clearDisplay();  
 }  
 void loop ()  
 {  
  byte temperature = 0;  
  byte humidity = 0;  
  int err = SimpleDHTErrSuccess;  
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {  
   Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);  
   return;  
  }  
  Serial.print((int)temperature); Serial.print(" *C, ");   
  Serial.print((int)humidity); Serial.println(" H");  
  // DHT11 sampling rate is 1HZ.  
   display.clearDisplay();  
   display.setTextSize(1);  
   display.setTextColor(SSD1306_WHITE);  
   display.setCursor(0, 0);  
   display.print("  TEMP. & HUMIDITY");  
   display.setCursor(0, 25);  
   display.print(" TEMPERATURE : ");  
   display.setCursor(90, 25);  
   display.print((int)temperature);  
   display.setCursor(0, 50);  
   display.print(" HUMIDITY  : ");  
   display.setCursor(90, 50);  
   display.print((int)humidity);  
   display.display();  
 }  