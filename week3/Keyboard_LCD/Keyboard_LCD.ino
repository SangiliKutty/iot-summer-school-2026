#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// System variables
String inputPIN = "";
String correctPIN = "1234";

int greenLED = 10;
int redLED = 11;
int buzzer = 12;

int wrongCount = 0;
bool locked = false;

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.setCursor(0,0);
  lcd.print("ENTER PIN:");

  Serial.println("SYSTEM STARTED");
  Serial.println("ENTER PIN:");
}

void loop() {

  if (locked) {
    lcd.clear();
    lcd.print("SYSTEM LOCKED");

    Serial.println("SYSTEM LOCKED - WAIT 10 SEC");

    delay(10000);

    locked = false;
    wrongCount = 0;

    lcd.clear();
    lcd.print("ENTER PIN:");
    Serial.println("SYSTEM UNLOCKED");
    return;
  }

  char key = keypad.getKey();

  if (key) {

    Serial.print("KEY PRESSED: ");
    Serial.println(key);

    if (key == '#') {

      Serial.print("FINAL INPUT PIN: ");
      Serial.println(inputPIN);

      if (inputPIN == correctPIN) {

        lcd.clear();
        lcd.print("ACCESS GRANTED");

        digitalWrite(greenLED, HIGH);
        digitalWrite(redLED, LOW);
        noTone(buzzer);

        Serial.println("ACCESS GRANTED");
      }
      else {

        lcd.clear();
        lcd.print("ACCESS DENIED");

        digitalWrite(redLED, HIGH);
        digitalWrite(greenLED, LOW);
        tone(buzzer, 1000);

        wrongCount++;

        Serial.println("ACCESS DENIED");
        Serial.print("WRONG ATTEMPTS: ");
        Serial.println(wrongCount);
      }

      inputPIN = "";
      delay(2000);

      lcd.clear();
      lcd.print("ENTER PIN:");

      Serial.println("ENTER PIN:");

      if (wrongCount >= 3) {
        locked = true;
      }

    } else {
      inputPIN += key;

      lcd.setCursor(0,1);
      lcd.print(inputPIN);

      Serial.print("CURRENT INPUT: ");
      Serial.println(inputPIN);
    }
  }
}
