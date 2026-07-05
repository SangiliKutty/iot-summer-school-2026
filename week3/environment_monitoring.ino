#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define RED_LED 8
#define GREEN_LED 9

DHT dht(DHTPIN, DHTTYPE);

unsigned long startTime;

void setup() {
  Serial.begin(9600);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  dht.begin();

  startTime = millis();

  Serial.println("timestamp,temp_C,temp_F,humidity");
}

void loop() {

  float tempC = dht.readTemperature();
  float humidity = dht.readHumidity();
  float tempF = dht.readTemperature(true);

  if (isnan(tempC) || isnan(humidity) || isnan(tempF)) {
    Serial.println("Failed to read DHT sensor!");
    delay(2000);
    return;
  }

  unsigned long timeStamp = millis() / 1000;

  Serial.print(timeStamp);
  Serial.print(",");
  Serial.print(tempC);
  Serial.print(",");
  Serial.print(tempF);
  Serial.print(",");
  Serial.println(humidity);

  if (tempC > 35 || humidity > 80) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  }
  else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  }

  delay(2000);
}
