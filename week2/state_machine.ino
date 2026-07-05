enum State {
  IDLE,
  COIN_INSERTED,
  ITEM_SELECTED,
  DISPENSING
};

State currentState = IDLE;

// Buttons
int coinBtn = 2;
int selectBtn = 3;
int cancelBtn = 4;

// LEDs
int ledIdle = 8;
int ledSelect = 9;
int ledDispense = 10;

void setup() {
  pinMode(coinBtn, INPUT_PULLUP);
  pinMode(selectBtn, INPUT_PULLUP);
  pinMode(cancelBtn, INPUT_PULLUP);

  pinMode(ledIdle, OUTPUT);
  pinMode(ledSelect, OUTPUT);
  pinMode(ledDispense, OUTPUT);

  Serial.begin(9600);

  Serial.println("Vending Machine Started");
  setState(IDLE);
}

void loop() {

  if (digitalRead(coinBtn) == LOW) {
    if (currentState == IDLE) {
      setState(COIN_INSERTED);
      delay(300);
    }
  }

  if (digitalRead(selectBtn) == LOW) {
    if (currentState == COIN_INSERTED) {
      setState(ITEM_SELECTED);
      delay(500);

      setState(DISPENSING);
      delay(1000);

      setState(IDLE);
    }
  }

  if (digitalRead(cancelBtn) == LOW) {
    setState(IDLE);
    delay(300);
  }
}

void setState(State newState) {

  currentState = newState;

  // reset LEDs
  digitalWrite(ledIdle, LOW);
  digitalWrite(ledSelect, LOW);
  digitalWrite(ledDispense, LOW);

  switch (currentState) {

    case IDLE:
      digitalWrite(ledIdle, HIGH);
      Serial.println("STATE: IDLE");
      break;

    case COIN_INSERTED:
      Serial.println("STATE: COIN INSERTED");
      break;

    case ITEM_SELECTED:
      digitalWrite(ledSelect, HIGH);
      Serial.println("STATE: ITEM SELECTED");
      break;

    case DISPENSING:
      digitalWrite(ledDispense, HIGH);
      Serial.println("STATE: DISPENSING ITEM...");
      break;
  }
}
