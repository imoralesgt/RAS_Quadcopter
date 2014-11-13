#include <wiring_private.h>

const int MOTOR = 30;
const int DELAY = 2;

void setup()
{
  pinMode(MOTOR, OUTPUT);
  digitalWrite(MOTOR, 0);
}

void loop()
{
  int i;
  for(i = 0; i < 4096; i++){
    //analogWrite(MOTOR, i);
    PWMWrite(MOTOR, 4095, i, 5000);
    delay(DELAY);
  }
  
  for(i = 4095; i >= 0; i--){
    //analogWrite(MOTOR, i);
    PWMWrite(MOTOR, 4095, i, 5000);
    delay(DELAY);
  }
  
  
}
