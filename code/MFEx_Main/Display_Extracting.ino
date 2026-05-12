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
  lcd.print("Speed2: ");
}

void Display_Extracting() {
  if (!Display_Extracting_Init) {
    Display_Extracting_Setup();
  }

  lcd.setCursor(7, 2);
  lcd.print(ActualSpeed1);
  lcd.print("   ");

  lcd.setCursor(7, 3);
  lcd.print(ActualSpeed2);
}