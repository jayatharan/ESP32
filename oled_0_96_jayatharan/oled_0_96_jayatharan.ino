#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display width and height
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Create an SSD1306 display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  // Clear the buffer
  display.clearDisplay();

  // Set text size and color
  display.setTextSize(2);          // Increase text size for better visibility
  display.setTextColor(SSD1306_WHITE);  // Set text color to white
  
  // Calculate the width of the text in pixels and center it on the screen
  int16_t x = (SCREEN_WIDTH - 10 * 12) / 2;  // 10 characters, each approximately 12 pixels wide at text size 2
  int16_t y = (SCREEN_HEIGHT - 16) / 2;  // Text height of approximately 16 pixels at text size 2

  // Set cursor position for the text
  display.setCursor(x, y);

  // Display the text
  display.print(F("JAYATHARAN"));
  display.display();  // Update the display
}

void loop() {
  // Do nothing in the loop
}
