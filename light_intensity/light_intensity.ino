#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display width and height
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Create an SSD1306 display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Define the analog pin connected to the photosensitive module
int lightSensorPin = 34;  // GPIO 34

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
}

void loop() {
  // Read the analog value from the photosensitive module
  int sensorValue = analogRead(lightSensorPin);

  // Convert the sensor value to a range of 0 to 100 (as a percentage of light intensity)
  int lightIntensity = map(sensorValue, 0, 4095, 0, 100);

  // Print the sensor value and light intensity to the Serial Monitor
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(" | Light Intensity: ");
  Serial.print(lightIntensity);
  Serial.println("%");

  // Display the light intensity on the OLED
  display.clearDisplay();  // Clear the display

  // Set text size and color
  display.setTextSize(2);  // Increase text size for better visibility
  display.setTextColor(SSD1306_WHITE);  // Set text color to white
  
  // Calculate the width of the text and center it
  int16_t x = (SCREEN_WIDTH - (12 * 6)) / 2;  // Adjust based on the text size and character width
  int16_t y = (SCREEN_HEIGHT - 16) / 2;       // Adjust based on the text height

  // Set cursor to the calculated position
  display.setCursor(x, y);

  // Display the light intensity percentage
  display.print(lightIntensity);
  display.print(F("%"));

  // Update the display
  display.display();

  delay(500);  // Delay to update the display every 500 ms
}
