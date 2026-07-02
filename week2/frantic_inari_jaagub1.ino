String command = "";
int blinkCounter = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(9600);
  Serial.println("Serial Command Interface Ready");
}

void loop() {
  if (Serial.available()) {

    command = Serial.readStringUntil('\n');
    command.trim();
    command.toUpperCase();

    if (command == "LED_ON") {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("LED ON");
    }

    else if (command == "LED_OFF") {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("LED OFF");
    }

    else if (command.startsWith("BLINK_")) {

      int times = command.substring(6).toInt();

      if (times >= 1 && times <= 9) {

        blinkCounter += times;

        for (int i = 0; i < times; i++) {

          digitalWrite(LED_BUILTIN, HIGH);
          delay(300);
          digitalWrite(LED_BUILTIN, LOW);
          delay(300);

        }

        Serial.print("Blink Completed: ");
        Serial.println(times);

      }

      else {

        Serial.println("ERROR: Invalid Blink Value");

      }

    }

    else if (command == "STATUS") {

      Serial.print("LED State: ");

      if (digitalRead(LED_BUILTIN))
        Serial.println("ON");
      else
        Serial.println("OFF");

      Serial.print("Blink Counter: ");
      Serial.println(blinkCounter);

    }

    else if (command == "RESET") {

      blinkCounter = 0;
      Serial.println("Blink Counter Reset");

    }

    else {

      Serial.println("ERROR: Unknown command");

    }

  }
}