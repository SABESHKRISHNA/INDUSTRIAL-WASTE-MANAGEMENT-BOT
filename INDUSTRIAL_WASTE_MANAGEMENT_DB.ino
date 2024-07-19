#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int gasSensorPin = A0;

void setup() {
  Serial.begin(9600); // Use the native USB port for serial communication
  Serial1.begin(9600); // Use Serial1 for Bluetooth communication
  pinMode(gasSensorPin, INPUT);
  dht.begin();
}

void loop() {
  delay(2000);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int gasValue = analogRead(gasSensorPin);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);

  Serial1.print("Temperature: ");
  Serial1.print(temperature);
  Serial1.println(" °C");

  Serial1.print("Humidity: ");
  Serial1.print(humidity);
  Serial1.println(" %");

  Serial1.print("Gas Sensor Value: ");
  Serial1.println(gasValue);
}