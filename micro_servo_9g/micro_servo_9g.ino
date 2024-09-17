#include<ESP32Servo.h>

Servo servo;

const int servoPin = 18;

int angle = 90;

void setup() {
  servo.attach(18);
  servo.write(angle);

  Serial.begin(115200);
}

void loop() {
  if(Serial.available()){
    angle = Serial.parseInt();
    servo.write(angle);
  }

  delay(1000);
}
