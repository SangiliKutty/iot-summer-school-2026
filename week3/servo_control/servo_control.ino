#include <Servo.h>

Servo myServo;

const int potPin = A0;
const int buttonPin = 2;
const int servoPin = 9;

bool lastButtonState = LOW;

void setup() {
  myServo.attach(servoPin);

  pinMode(buttonPin, INPUT);

  Serial.begin(9600);

  Serial.println("=== Servo Motor Control ===");
}

void loop() {

  // Read Potentiometer
  int potValue = analogRead(potPin);

  // Map to Servo Angle
  int angle = map(potValue, 0, 1023, 0, 180);

  // Move Servo
  myServo.write(angle);

  // Display Angle
  Serial.print("Servo Angle: ");
  Serial.print(angle);
  Serial.println(" degrees");

  // Read Button
  bool buttonState = digitalRead(buttonPin);

  // Button Pressed
  if (buttonState == HIGH && lastButtonState == LOW) {

    Serial.println("Button Pressed!");
    Serial.println("Servo Sweep Started");

    // 0 -> 180
    for (int i = 0; i <= 180; i++) {
      myServo.write(i);
      delay(10);
    }

    // 180 -> 0
    for (int i = 180; i >= 0; i--) {
      myServo.write(i);
      delay(10);
    }

    Serial.println("Servo Sweep Completed");
  }

  lastButtonState = buttonState;

  delay(200);
}
