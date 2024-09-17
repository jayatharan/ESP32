#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display width and height
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Create an SSD1306 display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// PIR sensor pin
#define PIR_PIN 13  // GPIO 13

void setup() {
  Serial.begin(115200);

  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  // Clear the buffer
  display.clearDisplay();
  display.display();

  // Initialize the PIR sensor pin
  pinMode(PIR_PIN, INPUT);
}

void loop() {
  // Read the state of the PIR sensor
  int pirState = digitalRead(PIR_PIN);

  // Clear the display
  display.clearDisplay();
  
  // Set text size and color
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  // Check if motion is detected
  if (pirState == HIGH) {
    Serial.println("Motion detected!");
    display.setCursor(20, 24);  // Set cursor to the center
    display.print("MOTION!");
  } else {
    Serial.println("No motion");
    display.setCursor(20, 24);  // Set cursor to the center
    display.print("NO MOTION");
  }

  // Update the display
  display.display();

  // Delay for a short period to avoid multiple triggers
  delay(500);
}
