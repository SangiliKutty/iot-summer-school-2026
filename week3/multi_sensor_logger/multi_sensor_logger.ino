#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// HC-SR04 Pins
const int trigPin = 9;
const int echoPin = 10;

// LDR Pin
const int ldrPin = A0;

void setup() {

  Serial.begin(9600);

  dht.begin();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.println("Multi Sensor Data Logger Started");
}

void loop() {

  // -------- DHT11/DHT22 --------
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // -------- LDR --------
  int ldrRaw = analogRead(ldrPin);

  int lightPercent = map(ldrRaw, 0, 1023, 100, 0);

  String lightStatus;

  if (lightPercent >= 70)
    lightStatus = "Bright";
  else if (lightPercent >= 30)
    lightStatus = "Normal";
  else
    lightStatus = "Dark";

  // -------- Ultrasonic --------
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  float distance = duration * 0.0343 / 2;

  // -------- Output --------

  Serial.println("=======================");
  Serial.println("=== SENSOR LOG ===");

  Serial.print("Time      : ");
  Serial.print(millis());
  Serial.println(" ms");

  Serial.print("Temp      : ");
  Serial.print(temperature);
  Serial.print(" C | Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  Serial.print("Light     : ");
  Serial.print(lightPercent);
  Serial.print("% (");
  Serial.print(lightStatus);
  Serial.println(")");

  Serial.print("Distance  : ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.println("=======================");
  Serial.println();

  delay(5000);
}
