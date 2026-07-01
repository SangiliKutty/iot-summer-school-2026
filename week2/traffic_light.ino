const int RED_PIN = 8;
const int YELLOW_PIN = 9;
const int GREEN_PIN = 10;
const int BUTTON_PIN = 7;

const unsigned long RED_TIME = 5000;
const unsigned long YELLOW_TIME = 2000;
const unsigned long GREEN_TIME = 4000;
const unsigned long PED_TIME = 8000;

enum State { RED, YELLOW, GREEN, PED_RED };
State currentState = RED;

unsigned long stateStartTime = 0;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial.begin(9600);

  setState(RED);
}

void loop() {

  if (digitalRead(BUTTON_PIN) == LOW && currentState != PED_RED) {
    setState(PED_RED);
  }

  unsigned long elapsed = millis() - stateStartTime;

  switch (currentState) {
    case RED:
      if (elapsed >= RED_TIME) setState(YELLOW);
      break;

    case YELLOW:
      if (elapsed >= YELLOW_TIME) setState(GREEN);
      break;

    case GREEN:
      if (elapsed >= GREEN_TIME) setState(RED);
      break;

    case PED_RED:
      if (elapsed >= PED_TIME) setState(RED);
      break;
  }
}

void setState(State newState) {
  currentState = newState;
  stateStartTime = millis();

  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);

  String msg;

  if (newState == RED) {
    digitalWrite(RED_PIN, HIGH);
    msg = "RED ON";
  }
  else if (newState == YELLOW) {
    digitalWrite(YELLOW_PIN, HIGH);
    msg = "YELLOW ON";
  }
  else if (newState == GREEN) {
    digitalWrite(GREEN_PIN, HIGH);
    msg = "GREEN ON";
  }
  else {
    digitalWrite(RED_PIN, HIGH);
    msg = "PEDESTRIAN MODE - RED ON";
  }

  Serial.print(millis());
  Serial.print(" ms -> ");
  Serial.println(msg);
}
