#define Actuator1_InA 6
#define Actuator1_InB 7
#define Actuator2_InA 9
#define Actuator2_InB 10

void Actuator_Setup() {
  pinMode(Actuator1_InA, OUTPUT);
  pinMode(Actuator1_InB, OUTPUT);
  pinMode(Actuator2_InA, OUTPUT);
  pinMode(Actuator2_InB, OUTPUT);
  Actuator_OffAll();
}


//Needs Calibration
void Actuator_Right_Down() {
  digitalWrite(Actuator1_InA, 0);
  digitalWrite(Actuator1_InB, 1);
}
void Actuator_Right_Up() {
  digitalWrite(Actuator1_InA, 1);
  digitalWrite(Actuator1_InB, 0);
}

void Actuator_Left_Down() {
  digitalWrite(Actuator2_InA, 0);
  digitalWrite(Actuator2_InB, 1);
}

void Actuator_Left_Up() {
  digitalWrite(Actuator2_InA, 1);
  digitalWrite(Actuator2_InB, 0);
}

void Actuator_OffAll() {
  digitalWrite(Actuator1_InA, 0);
  digitalWrite(Actuator1_InB, 0);
  digitalWrite(Actuator2_InA, 0);
  digitalWrite(Actuator2_InB, 0);
}