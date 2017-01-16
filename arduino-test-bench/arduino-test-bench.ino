/*
 * arduino-test-bench
 * 
 * A test bench that outputs PWM based on a potentiometer input. 
 * 
 * @author thatging3rkid, FIRST Team 1699
 */

const boolean debug = true;

void pot_to_pwm(byte pot_pin, byte pwm_pin) {
  analogWrite(pwm_pin, analogRead(pot_pin) / 4);
  if (debug) {
    Serial.print(pot_pin);
    Serial.print(": ");
    Serial.print(analogRead(pot_pin));
    Serial.print("; PWM ");
    Serial.print(pwm_pin);
    Serial.print(": ");
    // need to add more debug info after a bit
    Serial.println();
  }
}
 
void setup() {
  Serial.begin(19200);
  Serial.println("Arduino Test Bench for FRC v0.1");
  Serial.println("By Connor Henley, @thatging3rkid");
  if (debug) {
    Serial.println(F("----------DEBUG MODE------------"));
  }
  

}



void loop() {
  pot_to_pwm(A0, 3);  
}

