void Display_Loop() {
  switch (CurrentScreen) {
    case 0x1000:
      Display_Main();
      break;
    case 0x2000:
      Display_Extracting();
      break;
    default:
      break;
  }
}