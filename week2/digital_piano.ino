int btnDo = 2;
int btnRe = 3;
int btnMi = 4;
int btnFa = 5;
int btnMode = 6;

int buzzer = 9;

bool minorMode = false;

void setup() {
  pinMode(btnDo, INPUT_PULLUP);
  pinMode(btnRe, INPUT_PULLUP);
  pinMode(btnMi, INPUT_PULLUP);
  pinMode(btnFa, INPUT_PULLUP);
  pinMode(btnMode, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
  Serial.println("Digital Piano Started");
}

void loop() {

  // Mode toggle button
  if (digitalRead(btnMode) == LOW) {
    minorMode = !minorMode;
    Serial.print("Mode changed: ");
    Serial.println(minorMode ? "Minor" : "Major");
    delay(300);
  }

  bool d = !digitalRead(btnDo);
  bool r = !digitalRead(btnRe);
  bool m = !digitalRead(btnMi);
  bool f = !digitalRead(btnFa);

  // Two buttons pressed → SOL chord
  if ((d + r + m + f) >= 2) {
    tone(buzzer, 392);
    Serial.println("Chord: SOL");
  }
  else if (d) {
    tone(buzzer, minorMode ? 247 : 262);
    Serial.println("Do");
  }
  else if (r) {
    tone(buzzer, minorMode ? 277 : 294);
    Serial.println("Re");
  }
  else if (m) {
    tone(buzzer, minorMode ? 311 : 330);
    Serial.println("Mi");
  }
  else if (f) {
    tone(buzzer, minorMode ? 329 : 349);
    Serial.println("Fa");
  }
  else {
    noTone(buzzer);
  }
}
