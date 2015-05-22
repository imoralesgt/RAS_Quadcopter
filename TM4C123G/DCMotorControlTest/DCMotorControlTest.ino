const byte PWM1 = 3;
const byte PWM2 = 4;

byte pwm;

void setup()
{
  // put your setup code here, to run once:
  pinMode(PWM1, OUTPUT);
  digitalWrite(PWM1, 0);
  pinMode(PWM2, OUTPUT);
  digitalWrite(PWM2, 0);
  pinMode(BLUE_LED, OUTPUT);
  digitalWrite(BLUE_LED, 0);
  pinMode(PUSH1, INPUT_PULLUP);
  pinMode(PUSH2, INPUT_PULLUP);
  pwm = 0;
  
}

void loop()
{
  if(!digitalRead(PUSH1)){
    if(pwm < 255){
      pwm += 1;
    }
    delay(5);
    analogWrite(PWM1, pwm);
    analogWrite(BLUE_LED, pwm);
  }else if(!digitalRead(PUSH2)){
    if(pwm > 0){
      pwm -= 1;
    }
    delay(5);
    analogWrite(PWM1, pwm);
    analogWrite(BLUE_LED, pwm);
  }
  
}
