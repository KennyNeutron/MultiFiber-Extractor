bool Display_Extracting_Init = false;

void Display_Extracting_Setup() {
  Serial.println("Display Extracting Setup");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Extracting...");
  Display_Extracting_Init = true;

  lcd.setCursor(0, 1);
  lcd.print(fibers[FiberSelect].name);

  lcd.setCursor(0, 2);
  lcd.print("Speed1: ");

  if ((fibers[FiberSelect].name) == "Banana       ") {
    //4mm gap
    Actuator_Right_Down();
    Actuator_Left_Down();
    delay(1200);
    Actuator_OffAll();

    analogWrite(RollerMotorPin, 240);
  }

  if ((fibers[FiberSelect].name) == "Abaca        ") {
    //5mm gap
    Actuator_Right_Down();
    Actuator_Left_Down();
    delay(1100);
    Actuator_OffAll();

    analogWrite(RollerMotorPin, 230);
  }
}

void Display_Extracting() {
  if (!Display_Extracting_Init) {
    Display_Extracting_Setup();
  }

  lcd.setCursor(7, 2);
  lcd.print(ActualSpeed1);
  lcd.print("   ");

  Display_Extracting_ButtonFunctions();
}

void Display_Extracting_ButtonFunctions() {

  if (Status_btn_Select()) {
    delay(100);
    while (Status_btn_Select())
      ;
    CurrentScreen = 0x1000;

    analogWrite(RollerMotorPin, 0);
    delay(100);
    Actuator_Reset();

    Display_Extracting_Init = false;
  }
}