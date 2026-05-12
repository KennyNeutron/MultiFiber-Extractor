void ISR_Setup() {

  cli();  // Disable global interrupts

  //############# SET TIMER2 to 8kHz ############
  //Reset Timer2 registers
  TCCR2A = 0;
  TCCR2B = 0;
  TCNT2 = 0;
  OCR2A = 249;
  TCCR2A |= (1 << WGM21);
  TCCR2B |= (1 << CS21);
  TIMSK2 |= (1 << OCIE2A);
  //############### END TIMER2 ##################

  sei();  // enable interrupts
}



volatile uint32_t timer_ticks = 0;
volatile uint32_t last_trigger_ticks = 0;
volatile bool prev_reed_status = true;

// Interrput for Time
ISR(TIMER2_COMPA_vect) {
  // timer2 interrupt 8kHz
  cli();
  
  timer_ticks++;
  ReedSwitch1_Status = digitalRead(ReedSwitch1_Pin);
  
  // Detect falling edge (High to Low)
  if (prev_reed_status == true && ReedSwitch1_Status == false) {
    uint32_t tick_diff = timer_ticks - last_trigger_ticks;
    
    // Debounce: Only process if at least 48 ticks (6ms) have passed since the last valid trigger
    if (tick_diff > 48) {
      last_trigger_ticks = timer_ticks;
      ActualSpeed1 = 480000UL / tick_diff;
    }
  }
  
  prev_reed_status = ReedSwitch1_Status;
  
  // Timeout for 0 RPM (no pulse for 2 seconds = 16000 ticks)
  if ((timer_ticks - last_trigger_ticks) > 16000) {
    ActualSpeed1 = 0;
  }

  sei();  //enable all interrupts
}