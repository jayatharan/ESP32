#include <Adafruit_GFX.h>        // Core graphics library
#include <Adafruit_ST7789.h>     // Library for ST7789 display

// Define the display pins
#define TFT_CS     5   // Chip select pin
#define TFT_DC     2   // Data/command pin
#define TFT_RST    4   // Reset pin
#define TFT_BL     16  // Backlight pin (optional)

// Create an ST7789 display object
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);

  // Initialize the backlight pin (optional)
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);  // Turn on the backlight

  // Initialize the display
  tft.init(240, 320);  // Initialize ST7789 with 240x320 resolution
  tft.setRotation(1);  // Set the rotation if needed

  // Fill the screen with a solid color
  tft.fillScreen(ST77XX_BLACK);

  // Set text color and size
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);

  // Set cursor position and print text
  tft.setCursor(0, 0);  // Adjust the cursor position
  tft.print("Hello, ESP32!");
}

void loop() {
  // Nothing to do here
}
