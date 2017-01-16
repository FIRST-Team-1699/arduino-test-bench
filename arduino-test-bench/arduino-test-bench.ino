/*
 * arduino-test-bench.ino
 * 
 * A test bench that outputs PWM based on a potentiometer input. 
 * 
 * @author thatging3rkid, FIRST Team 1699
 */

const boolean debug = false;

void pot_to_pwm(byte pot_pin, byte pwm_pin) {
  /*
   * Currently, the pot_to_pwm function just outputs a 0% to 100% duty cycle.
   * 
   * So, not all motor controllers will work (if any). 
   */
  
  analogWrite(pwm_pin, analogRead(pot_pin) / 4);
  if (debug) {
    Serial.print(pot_pin);
    Serial.print(": ");
    Serial.print(analogRead(pot_pin));
    Serial.print("; PWM ");
    Serial.print(pwm_pin);
    Serial.print(": ");
    // need to add more debug info after a bit
    Serial.println(analogRead(pot_pin) / 4);
  }
}
 
void setup() {
  Serial.begin(19200);
  Serial.println("Arduino Test Bench for FRC v0.1");
  Serial.println("By Connor Henley, @thatging3rkid");
  if (debug) {
    Serial.println(F("----------DEBUG MODE------------"));
  }

  // complete
}



void loop() {
  /*
   * Note: not any pin can be used for PWM output. Only select pins are attached to the ATMEGA's PWM timer.  
   * 
   * Pins 5 and 6 are paired on timer0, with base frequency of 62500Hz
   * Pins 9 and 10 are paired on timer1, with base frequency of 31250Hz
   * Pins 3 and 11 are paired on timer2, with base frequency of 31250Hz
   * 
   * Pins 5 and 6 have prescaler values of 1, 8, 64, 256, and 1024
   * Pins 9 and 10 have prescaler values of 1, 8, 64, 256, and 1024
   * Pins 3 and 11 have prescaler values of 1, 8, 32, 64, 128, 256, and 1024
   * 
   * See: http://arduino.stackexchange.com/questions/210/why-do-some-pins-have-a-different-pwm-frequency/212#212
   */
  
  pot_to_pwm(A0, 3);
  //pot_to_pwm(A1, 5);
  //pot_to_pwm(A2, 6);
  //pot_to_pwm(A3, 9);
  //pot_to_pwm(A4, 10);
  //pot_to_pwm(A5, 11);
}

