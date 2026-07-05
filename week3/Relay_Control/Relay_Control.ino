#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int relayPin = 8;
int buttonPin = 3;

bool manualMode = false;
bool relayState = false;

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
  dht.begin();
}

void loop() {

  float temp = dht.readTemperature();

  // Manual override button
  if (digitalRead(buttonPin) == LOW) {
    manualMode = !manualMode;
    delay(300);
    Serial.println("Manual mode toggled");
  }

  // Automatic control with hysteresis
  if (!manualMode) {

    if (temp > 32) {
      relayState = true;
    }
    else if (temp < 28) {
      relayState = false;
    }

  }

  digitalWrite(relayPin, relayState);

  // Logging
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" °C | Relay: ");
  Serial.print(relayState ? "ON (AC ON)" : "OFF (AC OFF)");
  Serial.print(" | Mode: ");
  Serial.println(manualMode ? "MANUAL" : "AUTO");

  delay(1000);
}
