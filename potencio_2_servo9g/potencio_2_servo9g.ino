#include<ESP32Servo.h>

Servo servo;

const int servoPin = 18;
const int potPin = 34;

int potValue = 0;

void setup() {
  servo.attach(18);
}

void loop() {
  potValue = analogRead(potPin);

  int angle = map(potValue, 0, 4095, 0, 180);
  servo.write(angle);

  delay(10);
}
