#include <DHT.h>

DHT dht(26, DHT11);

void setup() {
  dht.begin();
  delay(2000);

  Serial.begin(115200);
}

void loop() {

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" C, ");
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" % ");
  Serial.println("");

  delay(2000);
}
