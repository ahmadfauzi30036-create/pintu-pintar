/*
  Pintu Pintar - kontrol sudut pintu 0-90 derajat
  Potensiometer -> Arduino -> Servo + LCD I2C
  Penulis: Ahmad Fauzi
*/

#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Servo pintu;
LiquidCrystal_I2C lcd(0x27, 16, 2);  // ganti ke 0x3F jika LCD tidak tampil

const int potPin   = A0;
const int servoPin = 9;

int sudutLama = -1;

void setup() {
  pintu.attach(servoPin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Pintu Pintar");
  delay(1000);
  lcd.clear();
}

void loop() {
  int nilaiADC = analogRead(potPin);             // 0 - 1023
  int sudut    = map(nilaiADC, 0, 1023, 0, 90);  // 0 - 90 derajat
  sudut = constrain(sudut, 0, 90);

  pintu.write(sudut);

  // Perbarui LCD hanya saat sudut berubah
  if (sudut != sudutLama) {
    lcd.setCursor(0, 0);
    lcd.print("Sudut: ");
    lcd.print(sudut);
    lcd.print((char)223);  // simbol derajat
    lcd.print("   ");

    lcd.setCursor(0, 1);
    if (sudut == 0)       lcd.print("Status: TERTUTUP");
    else if (sudut >= 90) lcd.print("Status: TERBUKA ");
    else                  lcd.print("Status: SEBAGIAN");

    sudutLama = sudut;
  }
  delay(15);
}
