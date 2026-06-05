#include <LiquidCrystal.h>
int led1 = 9;
int led2 = 10;
int led3 = 11;
int rs = 3, en = 4, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int sensor = A0;

void setup() {
  lcd.begin(16, 2);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  int val = analogRead(sensor);
  int valmap = map(val, 0, 1023, 0, 100);

  lcd.setCursor(0, 0);
  lcd.print("Sensor Value: ");
  lcd.print(val);

  if (valmap <= 15) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    lcd.setCursor(0, 1);
    lcd.print("SAFE ZONE");
    delay(2000);
    lcd.clear();
  } else if (valmap > 15 && valmap <= 50) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    lcd.setCursor(0, 1);
    lcd.print("MODERATE ZONE");
    delay(2000);
    lcd.clear();
  } else if (valmap > 50) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("DENGEROUS ZONE");
    delay(2000);
    lcd.clear();
  }
}