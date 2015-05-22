//Controlador PID discreto
//Implementado sin punto flotante

const byte PWM1 = 3;
const byte PWM2 = 4;
const byte MAX_PWM = 255;
const byte POT  = A7;
const byte POT2 = A6;


signed int Kp, Ki, Kd, minInt, maxInt;
signed int setPoint;
signed int derivator, integrator;
signed int error;

void pidInit(int p, int i, int d, int minI, int maxI){
   Kp = p; Ki = i; Kd = d; //Coeficientes del controlador PID
   minInt = minI; maxInt = maxI; //Limites del integrador
   
   derivator = 0; integrator = 0; //Condiciones iniciales
   error = 0; //Condiciones iniciales
}

void pidSetPoint(signed int set){
  setPoint = set; //Establecer valor deseado
  derivator = 0; //Inicializar condiciones iniciales
  integrator = 0; //Eliminar todo error acumulado al reiniciar
}

signed int pidUpdate(signed int currentValue){
  signed int pValue, iValue, dValue, PID;
  error = setPoint - currentValue; 

  //Parte proporcional del controlador
  pValue = Kp*error;
  
  //Integral discreta
  integrator = integrator + error;
  if (integrator > maxInt){
    integrator = maxInt;
  }else if(integrator < minInt){
    integrator = minInt;
  }
  //Parte integral del controlador
  iValue = integrator*Ki;
  
  
  //Derivada discreta
  dValue = Kd*(error - derivator);
  derivator = error; //Diferencia del valor anterior con el valor actual
  
  PID = pValue + iValue + dValue;
  
  
  /*Normalmente esta condicion NO SE COLOCA
  Fue para compensar la limitacion que impone el 
  uso de un ventilador (el ventilador no puede "calentar"
  el ambiente cuando gira al reves)*/
  if(PID > MAX_PWM - 1){
    PID = MAX_PWM - 1;
  }else if(PID < (-1)*MAX_PWM){
    PID = (-1)*MAX_PWM;
  }
  
  return PID;
}


void setup()
{
  
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);  

  digitalWrite(PWM1, 0);
  digitalWrite(PWM2, 0);
 
  Serial.begin(115200);
  pinMode(POT, INPUT); //PID Feedback
  pinMode(POT2, INPUT); //Set point
  
  
  //Extremadamente importante calibrar adecuadamente los coeficiente
  pidInit(1, 0, 1, -5, 5); //Coeficientes y limites de integrador
  pidSetPoint(analogRead(A6)); //Posicion deseada
}

uint16_t leePosicion(){
  return analogRead(POT);
}

void loop()
{
  uint16_t pos;
  int16_t pwmOut;
  pos = leePosicion();
  Serial.print("Posicion: ");
  Serial.println(pos);

  uint16_t sp;
  sp = analogRead(A6);
  pidSetPoint(sp); //Actualizar set point  
  
  Serial.print("Set point: ");
  Serial.println(sp);
  
  pwmOut = pidUpdate(pos); //Actualizar el sistema de control
                            //y obtener nuevo valor

  if(pwmOut > 0){
    analogWrite(PWM1, pwmOut);
    digitalWrite(PWM2, 0);
    analogWrite(GREEN_LED, pwmOut);
    digitalWrite(RED_LED, 0);
  }else{
    analogWrite(PWM1, MAX_PWM - 1 - pwmOut);
    digitalWrite(PWM2, 1);
    analogWrite(RED_LED, pwmOut);
    digitalWrite(GREEN_LED, 0);
  }
  Serial.println(" ");  
  Serial.print("PIDval: ");
  Serial.println(pwmOut);
  
  delay(100);
  
}  

