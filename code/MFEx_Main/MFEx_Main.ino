/**
 * MultiFiber-Extractor Main Program
 * Description: Basic demonstration for a 20x4 I2C LCD displaying "Hello World".
 * Author: KennyNeutron
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "variables.h"


// I2C address 0x27, 20 columns, 4 rows
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  Serial.begin(9600);
  Serial.println("MultiFiber-Extractor \nSystem Booting...");

  buttons_Setup();

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello World");
  delay(3000);
  CurrentScreen = 0x1000;
}

void loop() {

  if (Status_btn_Prev()) {
    Serial.println("Previous Button Pressed");
  }
  if (Status_btn_Next()) {
    Serial.println("Next Button Pressed");
  }
  if (Status_btn_Select()) {
    Serial.println("Select Button Pressed");
  }

  Display_Loop();
}