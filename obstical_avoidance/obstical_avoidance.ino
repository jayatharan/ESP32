const int irPin = 13;
const int ledPin = 2;

int irValue;

void setup() {
  pinMode(irPin, INPUT);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  irValue = digitalRead(irPin);

  if(irValue == HIGH){
    digitalWrite(ledPin, LOW);
  }else{
    digitalWrite(ledPin, HIGH);
  }

  delay(10);
}
