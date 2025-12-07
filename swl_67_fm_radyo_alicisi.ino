#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TEA5767Radio.h>

#define I2C_ADDR 0x27
LiquidCrystal_I2C lcd(I2C_ADDR, 16, 2);

TEA5767Radio radio = TEA5767Radio();

double frequencies[] = {91.50, 93.40, 102.40, 97.20, 104.9, 99.20, 106.90, 91.80};
String radioNames[] = {"Meteor FM", "TRT Turku", "TRT Turku", "TRT FM", "TRT FM", "TRT RADYO 3", "TRT RADYO 1","TRT HABER"};

double frequency = 87.0;
double frequency_pt = 87.0;
unsigned long lastMillis = 0;
unsigned long debounceDelay = 100;
bool flash = false;
bool initialDisplay = true;
unsigned long initialDisplayMillis = 0;
int lastPotValue = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.backlight();
  Serial.println("TA2CAY - SWL67 ");

  // Radyo modülünü otomatik olarak belirli bir frekansa ayarla
  radio.setFrequency(91.8);
}

void loop() {
  unsigned long currentMillis = millis();

  if (initialDisplay) {
    if (currentMillis - initialDisplayMillis < 3000) {
      lcd.setCursor((16 - 7) / 2, 0);
      lcd.print("TA2CAY");

      lcd.setCursor((16 - 6) / 2, 1);
      lcd.print("SWL67");
    } else {
      initialDisplay = false;
      lcd.clear();
    }
  } else {
    // Potansiyometre değerini okuma
    int value_pot = analogRead(A1);

    // Potansiyometre değeri değiştiğinde frekansı güncelle
    if (abs(value_pot - lastPotValue) > 5) {
      // Frekans hesaplaması
      frequency = ((double)value_pot * (108.0 - 87.0)) / 1024.0 + 87.0;
      frequency = round(frequency * 10) / 10.0;

      lcd.clear();

      for (int i = 0; i < sizeof(frequencies) / sizeof(frequencies[0]); i++) {
        if (abs(frequencies[i] - frequency) < 0.01) {
          lcd.setCursor((16 - radioNames[i].length()) / 2, 0);
          lcd.print(radioNames[i]);
          Serial.print("Radyo Adı: ");
          Serial.println(radioNames[i]);
          break;
        }
      }

      lcd.setCursor(0, 1);
      lcd.print("  FM");
      lcd.setCursor(6, 1);
      lcd.print("       MHz");
      lcd.setCursor(6, 1);
      lcd.print(frequency, 2);
      Serial.print("Frekans: ");
      Serial.println(frequency);
      radio.setFrequency(frequency);
      frequency_pt = frequency;
      lastPotValue = value_pot;

      delay(debounceDelay);
    }

    if (millis() - lastMillis > 500) {
      lastMillis = millis();
      flash = !flash;
      lcd.setCursor(0, 0);
      if (flash) {
        lcd.print("                ");
      } else {
        for (int i = 0; i < sizeof(frequencies) / sizeof(frequencies[0]); i++) {
          if (abs(frequencies[i] - frequency) < 0.01) {
            lcd.setCursor((16 - radioNames[i].length()) / 2, 0);
            lcd.print(radioNames[i]);
            break;
          }
        }
      }
    }
  }
}
