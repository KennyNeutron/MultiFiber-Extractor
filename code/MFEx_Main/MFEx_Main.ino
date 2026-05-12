/**
 * MultiFiber-Extractor Main Program
 * Description: Basic demonstration for a 20x4 I2C LCD displaying "Hello World".
 * Author: 
 * Date Started: Mar 5, 2026
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "variables.h"

#define RollerMotorPin 11
#define ReedSwitch1_Pin 8


// I2C address 0x27, 20 columns, 4 rows
LiquidCrystal_I2C lcd(0x27, 20, 4);

struct FiberData {
  const char* name;
  int speed;
  int gap;
};

const FiberData fibers[] = {
  { "Banana       ", 750, 4 },
  { "Abaca        ", 715, 5 },
  { "Pineapple    ", 150, 2 },
  { "Snake Plant  ", 150, 3 }
};

bool testVar = false;
volatile bool ReedSwitch1_Status = false;

void setup() {
  Serial.begin(9600);
  Serial.println("MultiFiber-Extractor \nSystem Booting...");

  buttons_Setup();

  pinMode(RollerMotorPin, OUTPUT);
  pinMode(ReedSwitch1_Pin, INPUT_PULLUP);
  digitalWrite(RollerMotorPin, LOW);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("SYSTEM STARTING...");
  delay(3000);
  CurrentScreen = 0x1000;

  ISR_Setup();

  Actuator_Setup();
  Actuator_Right_Down();
  delay(500);
  Actuator_OffAll();
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