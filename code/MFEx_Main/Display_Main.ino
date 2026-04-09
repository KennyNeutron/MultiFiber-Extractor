bool Display_Main_Init = false;

void Display_Main_Setup() {
  Serial.println("Display Main Setup");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("MultiFiber Extractor");
  lcd.setCursor(0, 1);
  lcd.print("Fiber:");
  lcd.setCursor(0, 2);
  lcd.print("Speed:");
  lcd.setCursor(0, 3);
  lcd.print("Gap:");
  Display_Main_Init = true;
}


void Display_Main() {
  if (!Display_Main_Init) {
    Display_Main_Setup();
  }
}