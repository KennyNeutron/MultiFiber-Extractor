/**
 * MultiFiber-Extractor Main Program
 * Description: Basic demonstration for a 20x4 I2C LCD displaying "Hello World".
 * Author: KennyNeutron
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// I2C address 0x27, 20 columns, 4 rows
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello World");
}

void loop() {
}