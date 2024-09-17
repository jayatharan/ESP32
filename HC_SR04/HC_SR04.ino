#include <NewPing.h>

#define TRIGGER_PIN 32
#define ECHO_PIN 33
#define MAX_DISTANCE 100

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  delay(500); // Wait for a moment
  unsigned int distance = sonar.ping_cm(); // Measure distance in centimeters
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(1000);
}