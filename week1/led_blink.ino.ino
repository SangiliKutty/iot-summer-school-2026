int count = 0;
int sensorValue = 0;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(A0);

  digitalWrite(13, HIGH);
  delay(sensorValue);

  digitalWrite(13, LOW);
  delay(sensorValue);

  count++;

  Serial.print("Blink Count: ");
  Serial.println(count);
}
