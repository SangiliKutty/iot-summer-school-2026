// Q22 - Smart Parking Assistant
// HC-SR04 + 3 LEDs + Buzzer

const int trigPin = 9;
const int echoPin = 10;

const int greenLED = 2;
const int yellowLED = 3;
const int redLED = 4;

const int buzzer = 5;

long duration;
float distance;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

  Serial.println("=== Smart Parking Assistant ===");
}

void loop() {

  // Send Ultrasonic Pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Read Echo
  duration = pulseIn(echoPin, HIGH);

  // Calculate Distance
  distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Turn everything OFF first
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  noTone(buzzer);

  // SAFE
  if (distance > 20) {

    digitalWrite(greenLED, HIGH);

  }

  // WARNING
  else if (distance > 10 && distance <= 20) {

    digitalWrite(yellowLED, HIGH);

  }

  // DANGER
  else {

    digitalWrite(redLED, HIGH);

    tone(buzzer, 1000);

  }

  delay(500);
}
