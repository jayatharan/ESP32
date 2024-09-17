// Define the pin where the LED is connected
int ledPin = 4; // On most ESP32 boards, the onboard LED is connected to GPIO 2

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Turn the LED on (HIGH is the voltage level)
  digitalWrite(ledPin, HIGH);
  delay(100); // Wait for 1000 milliseconds (1 second)

  // Turn the LED off by making the voltage LOW
  digitalWrite(ledPin, LOW);
  delay(100); // Wait for 1000 milliseconds (1 second)
}
