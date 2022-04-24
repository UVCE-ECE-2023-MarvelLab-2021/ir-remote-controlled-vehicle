#pragma once

// command to control the vehicle
void moveForward(){ // IR code is 70
  Serial.println("Forward...at "+String(botSpeed));
  analogWrite(rf_pin,botSpeed);
  analogWrite(rr_pin,0);
  analogWrite(lf_pin,botSpeed);
  analogWrite(lr_pin,0);
}
void moveBackward(){ // IR code is 21
  Serial.println("Reverse...at "+String(botSpeed));
  analogWrite(rf_pin,0);
  analogWrite(rr_pin,botSpeed);
  analogWrite(lf_pin,0);
  analogWrite(lr_pin,botSpeed);
}
void goRight(){ // IR code is 67
  Serial.println("Right...at "+String(botSpeed));
  analogWrite(rf_pin,0);
  analogWrite(rr_pin,botSpeed);
  analogWrite(lf_pin,botSpeed);
  analogWrite(lr_pin,0);
}
void goLeft(){ // IR code is 68
  Serial.println("Left...at "+String(botSpeed));
  analogWrite(rf_pin,botSpeed);
  analogWrite(rr_pin,0);
  analogWrite(lf_pin,0);
  analogWrite(lr_pin,botSpeed);
}
void stopBot(){ // IR code is 64
  Serial.println("Stopped");
  analogWrite(rf_pin,0);
  analogWrite(rr_pin,0);
  analogWrite(lf_pin,0);
  analogWrite(lr_pin,0);
}
