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
  lcd.setCursor(0, 3);
  lcd.print("GAP: ");

  if ((fibers[FiberSelect].name) == "Banana       ") {
    //2mm gap
    Actuator_Right_Down();
    Actuator_Left_Down();
    delay(1400);
    Actuator_OffAll();

    digitalWrite(ExtractorMotorPin, 1);
    delay(3000);

    //750rpm
    analogWrite(RollerMotorPin, 250);
  }

  if ((fibers[FiberSelect].name) == "Abaca        ") {
    //3mm gap
    Actuator_Right_Down();
    Actuator_Left_Down();
    delay(1300);
    Actuator_OffAll();

    digitalWrite(ExtractorMotorPin, 1);
    delay(5000);

    //715rpm
    analogWrite(RollerMotorPin, 230);
  }

  if ((fibers[FiberSelect].name) == "Pineapple    ") {
    //3mm gap
    Actuator_Right_Down();
    Actuator_Left_Down();
    delay(1300);
    Actuator_OffAll();
    digitalWrite(ExtractorMotorPin, 1);
    delay(3000);

    // 150 rpm
    analogWrite(RollerMotorPin, 150);
  }


  if ((fibers[FiberSelect].name) == "Snake Plant  ") {
    //5mm gap
    Actuator_Right_Down();
    Actuator_Left_Down();
    delay(1100);
    Actuator_OffAll();
    digitalWrite(ExtractorMotorPin, 1);
    delay(3000);

    //150 rpm
    analogWrite(RollerMotorPin, 150);
  }
}

void Display_Extracting() {
  if (!Display_Extracting_Init) {
    Display_Extracting_Setup();
  }

  lcd.setCursor(7, 2);
  lcd.print(ActualSpeed1);
  lcd.print("rpm");


  lcd.setCursor(6, 3);
  lcd.print(fibers[FiberSelect].gap);
  lcd.print("mm");

  Display_Extracting_ButtonFunctions();
}

void Display_Extracting_ButtonFunctions() {

  if (Status_btn_Select()) {
    delay(100);
    while (Status_btn_Select())
      ;
    CurrentScreen = 0x1000;
    digitalWrite(ExtractorMotorPin, 0);
    analogWrite(RollerMotorPin, 0);
    delay(100);
    Actuator_Reset();

    Display_Extracting_Init = false;
    FiberSelect = false;
  }
}