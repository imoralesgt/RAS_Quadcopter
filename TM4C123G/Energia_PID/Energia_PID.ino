//Controlador PID discreto
//Implementado sin punto flotante

const byte PWM_PIN = 37; //Ventilador
const byte POTENCIOMETRO = A3; //LM35

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
  if(PID > 255){
    PID = 255;
  }else if(PID < 0){
    PID = 0;
  }
  
  return PID;
}


void setup()
{
  
  pinMode(PWM_PIN, OUTPUT);
  
  Serial.begin(115200);
  pinMode(POTENCIOMETRO, INPUT);
  
  //Extremadamente importante calibrar adecuadamente los coeficiente
  pidInit(30, 8, 0, -100, 100); //Coeficientes y limites de integrador
  pidSetPoint(100); //Temperatura deseada
}

void loop()
{
  uint16_t temp;
  int16_t pwmOut;
  temp = analogRead(POTENCIOMETRO) / 16;
  
  pwmOut = pidUpdate(temp); //Actualizar el sistema de control
                            //y obtener nuevo valor

  analogWrite(PWM_PIN, pwmOut);
  
  Serial.print("CurrentValue: ");
  Serial.println(temp);
  Serial.print("PWMValue: ");
  Serial.println(pwmOut);
  Serial.println("");
  
  delay(100);
  
}  

