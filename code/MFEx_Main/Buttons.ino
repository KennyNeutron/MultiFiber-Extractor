#define btn_Prev 3
#define btn_Next 4
#define btn_Select 5

void buttons_Setup() {
  pinMode(btn_Prev, INPUT_PULLUP);
  pinMode(btn_Next, INPUT_PULLUP);
  pinMode(btn_Select, INPUT_PULLUP);
}


bool Status_btn_Prev() {
  return !digitalRead(btn_Prev);
}
bool Status_btn_Next() {
  return !digitalRead(btn_Next);
}
bool Status_btn_Select() {
  return !digitalRead(btn_Select);
}