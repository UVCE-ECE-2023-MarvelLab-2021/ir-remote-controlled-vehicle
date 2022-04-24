#include <IRremote.h>
#include "pins.h"

int decoded_val = 0;

IRrecv ir_recv(ir_recv_pin);

void setup() {
  Serial.begin(9600);
  ir_recv.enableIRIn();
}

#include "vehicleCommands.h"

void loop() {
  if (ir_recv.decode()) {
    ir_recv.resume();
    decoded_val = ir_recv.decodedIRData.command;
    Serial.println(decoded_val); // for debugging

    if(decoded_val == 70){
      moveForward(); // move vehicle forward
    }
    else if(decoded_val == 21){
      moveBackward(); // move vehicle backward
    }
    else if(decoded_val == 67){
      goRight(); // turn vehicle to the right
    }
    else if(decoded_val == 68){
      goLeft(); // turn vehicle to the left
    }
    else{
      stopBot(); // stop the vehicle
    }
    delay(100);
    stopBot();
  }
}
