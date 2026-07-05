const int ledIdle = 8;
const int ledCoin = 9;
const int ledItem = 10;

const int btnCoin = 2;
const int btnSelect = 3;
const int btnCancel = 4;

int state = 0;

// 0 = IDLE
// 1 = COIN_INSERTED
// 2 = ITEM_SELECTED
// 3 = DISPENSING

void setup()
{
  Serial.begin(9600);

  pinMode(ledIdle, OUTPUT);
  pinMode(ledCoin, OUTPUT);
  pinMode(ledItem, OUTPUT);

  pinMode(btnCoin, INPUT_PULLUP);
  pinMode(btnSelect, INPUT_PULLUP);
  pinMode(btnCancel, INPUT_PULLUP);

  Serial.println("State : IDLE");
}

void loop()
{
  updateLEDs();

  // IDLE
  if (state == 0)
  {
    if (digitalRead(btnCoin) == LOW)
    {
      state = 1;
      Serial.println("IDLE -> COIN_INSERTED");
      delay(300);
    }
  }

  // COIN_INSERTED
  else if (state == 1)
  {
    if (digitalRead(btnSelect) == LOW)
    {
      state = 2;
      Serial.println("COIN_INSERTED -> ITEM_SELECTED");
      delay(300);
    }

    else if (digitalRead(btnCancel) == LOW)
    {
      state = 0;
      Serial.println("COIN_INSERTED -> IDLE");
      delay(300);
    }
  }

  // ITEM_SELECTED
  else if (state == 2)
  {
    Serial.println("ITEM_SELECTED -> DISPENSING");
    state = 3;
    delay(1000);
  }

  // DISPENSING
  else if (state == 3)
  {
    updateLEDs();

    Serial.println("DISPENSING...");
    delay(2000);

    Serial.println("DISPENSING -> IDLE");

    state = 0;
  }
}

void updateLEDs()
{
  digitalWrite(ledIdle, LOW);
  digitalWrite(ledCoin, LOW);
  digitalWrite(ledItem, LOW);

  if (state == 0)
  {
    digitalWrite(ledIdle, HIGH);
  }

  else if (state == 1)
  {
    digitalWrite(ledCoin, HIGH);
  }

  else if (state == 2 || state == 3)
  {
    digitalWrite(ledItem, HIGH);
  }
}
