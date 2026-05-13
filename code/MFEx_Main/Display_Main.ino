bool Display_Main_Init = false;

void Display_Main_Setup() {
  Serial.println("Display Main Setup");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("MultiFiber Extractor");
  lcd.setCursor(0, 1);
  lcd.print("Fiber: ");
  lcd.setCursor(0, 2);
  lcd.print("Speed: ");
  lcd.setCursor(0, 3);
  lcd.print("Gap:   ");
  Display_Main_Init = true;
}

void Display_Main() {
  if (!Display_Main_Init) {
    Display_Main_Setup();
  }

  static uint8_t lastFiberSelect = 255;

  if (FiberSelect != lastFiberSelect) {
    if (FiberSelect >= (sizeof(fibers) / sizeof(fibers[0]))) {
      FiberSelect = 0;
    }

    lcd.setCursor(7, 1);
    lcd.print(fibers[FiberSelect].name);

    lcd.setCursor(7, 2);
    lcd.print(fibers[FiberSelect].speed);

    lcd.setCursor(7, 3);
    lcd.print(fibers[FiberSelect].gap);

    lastFiberSelect = FiberSelect;
  }

  Display_Main_ButtonFunctions();
}

void Display_Main_ButtonFunctions() {
  if (Status_btn_Next()) {
    delay(100);
    while (Status_btn_Next())
      ;
    FiberSelect++;
    if (FiberSelect > 3) {
      FiberSelect = 0;
    }
  }

  if (Status_btn_Prev()) {
    delay(100);
    while (Status_btn_Prev())
      ;
    FiberSelect--;
    if (FiberSelect == 255) {
      FiberSelect = 3;
    }
  }

  if (Status_btn_Select()) {
    delay(100);
    while (Status_btn_Select())
      ;
    CurrentScreen = 0x2000;
    Display_Main_Init = false;
  }
}