int redLED = 8;
int yellowLED = 9;
int greenLED = 10;

int pedButton = 7;

unsigned long previousMillis = 0;
unsigned long pedStartTime = 0;

bool pedestrianMode = false;

enum State {
  RED,
  YELLOW,
  GREEN
};

State currentState = RED;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  pinMode(pedButton, INPUT_PULLUP);

  Serial.begin(9600);

  Serial.println("Traffic Light System Started");
}

void loop() {

  unsigned long currentMillis = millis();

  // Pedestrian button check
  if (digitalRead(pedButton) == LOW && !pedestrianMode) {
    pedestrianMode = true;
    pedStartTime = currentMillis;
    currentState = RED;

    Serial.print("[");
    Serial.print(currentMillis);
    Serial.println("] PEDESTRIAN MODE ACTIVATED");
  }

  // Pedestrian mode active
  if (pedestrianMode) {

    currentState = RED;
    setLights(1, 0, 0);

    Serial.print("[");
    Serial.print(currentMillis);
    Serial.println("] RED (PEDESTRIAN SAFE)");

    if (currentMillis - pedStartTime >= 8000) {
      pedestrianMode = false;
      previousMillis = currentMillis;
      Serial.println("Pedestrian mode ended");
    }

    delay(500);
    return;
  }

  // Normal traffic cycle
  if (currentState == RED && currentMillis - previousMillis >= 5000) {
    currentState = YELLOW;
    previousMillis = currentMillis;
    Serial.print("[");
    Serial.print(currentMillis);
    Serial.println("] YELLOW LIGHT");
  }

  else if (currentState == YELLOW && currentMillis - previousMillis >= 2000) {
    currentState = GREEN;
    previousMillis = currentMillis;
    Serial.print("[");
    Serial.print(currentMillis);
    Serial.println("] GREEN LIGHT");
  }

  else if (currentState == GREEN && currentMillis - previousMillis >= 4000) {
    currentState = RED;
    previousMillis = currentMillis;
    Serial.print("[");
    Serial.print(currentMillis);
    Serial.println("] RED LIGHT");
  }

  setLights(
    currentState == RED,
    currentState == YELLOW,
    currentState == GREEN
  );
}

void setLights(int r, int y, int g) {
  digitalWrite(redLED, r);
  digitalWrite(yellowLED, y);
  digitalWrite(greenLED, g);
}
