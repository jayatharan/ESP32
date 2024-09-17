#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  
  display.clearDisplay();
  display.setTextSize(10);      
  display.setTextColor(SSD1306_WHITE); 
  display.setCursor(0, 0);
  display.println(F("Hello World! Hello World! Hello World!"));
  display.display();  
}

void loop() {  
  display.clearDisplay();
  display.setTextSize(10);      
  display.setTextColor(SSD1306_WHITE); 
  display.setCursor(0, 0);
  display.println(F("Hello World! Hello World! Hello World!"));
  display.display(); 
  
  delay(200); 
}
