const int ldrPin = A0;
const int pirPin = 2;
const int ledPin = 9;

const int ldrThreshold = 500;   // Adjust if needed

unsigned long motionStart = 0;
bool motionActive = false;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

  Serial.println("[00:00:00] EVENT: System Started");
}

void loop() {

  int ldrValue = analogRead(ldrPin);
  bool motion = digitalRead(pirPin);

  // DAY MODE
  if (ldrValue > ldrThreshold) {

    analogWrite(ledPin, 0);

    if (motionActive) {
      Serial.println("[00:00:00] EVENT: Daylight Detected");
      motionActive = false;
    }

    delay(500);
    return;
  }

  // NIGHT MODE

  if (motion) {

    analogWrite(ledPin, 255);

    if (!motionActive) {
      Serial.println("[00:00:00] EVENT: Motion Detected - LED Full Brightness");
    }

    motionStart = millis();
    motionActive = true;
  }

  if (motionActive) {

    if (millis() - motionStart < 30000) {

      analogWrite(ledPin, 255);

    } else {

      analogWrite(ledPin, 51);

      Serial.println("[00:00:30] EVENT: No Motion - LED Dimmed (20%)");

      motionActive = false;
    }

  } else {

    analogWrite(ledPin, 51);

  }

  delay(200);
}
