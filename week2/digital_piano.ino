const int buzzer = 8;

const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;
const int modeButton = 6;

bool majorMode = true;

void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(modeButton, INPUT_PULLUP);
}

void loop() {

  if (digitalRead(modeButton) == LOW) {
    majorMode = !majorMode;
    delay(300);
  }

  if (
    (digitalRead(button1) == LOW && digitalRead(button2) == LOW) ||
    (digitalRead(button1) == LOW && digitalRead(button3) == LOW) ||
    (digitalRead(button1) == LOW && digitalRead(button4) == LOW) ||
    (digitalRead(button2) == LOW && digitalRead(button3) == LOW) ||
    (digitalRead(button2) == LOW && digitalRead(button4) == LOW) ||
    (digitalRead(button3) == LOW && digitalRead(button4) == LOW)
  ) {
    tone(buzzer, 392);
  }

  else if (digitalRead(button1) == LOW) {
    tone(buzzer, 262);
  }

  else if (digitalRead(button2) == LOW) {
    tone(buzzer, 294);
  }

  else if (digitalRead(button3) == LOW) {
    if (majorMode)
      tone(buzzer, 330);
    else
      tone(buzzer, 311);
  }

  else if (digitalRead(button4) == LOW) {
    if (majorMode)
      tone(buzzer, 349);
    else
      tone(buzzer, 330);
  }

  else {
    noTone(buzzer);
  }

}
