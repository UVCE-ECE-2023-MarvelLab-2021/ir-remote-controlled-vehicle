#include <IRremote.h>
#include "pinsUsed.h"

int decoded_val = 0;

IRrecv ir_recv(ir_recv_pin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ir_recv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (ir_recv.decode()) {
    ir_recv.resume();
    decoded_val = ir_recv.decodedIRData.command;
    Serial.println(decoded_val);

    if(decoded_val == 70){
      moveForward();
      delay(100);
      stopBot();
    }
    else if(decoded_val == 21){
      moveBackward();
      delay(100);
      stopBot();
    }
    else if(decoded_val == 67){
      goRight();
      delay(100);
      stopBot();
    }
    else if(decoded_val == 68){
      goLeft();
      delay(100);
      stopBot();
    }
    else{
      stopBot();
    }
  }
}

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
