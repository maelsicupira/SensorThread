#include <AFMotor.h>
#include <SoftwareSerial.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

char state = 0;        
boolean stringComplete = false;  
int vel = 255;

boolean trs = false;
boolean frt = false;
boolean frl = false;

void setup() {
    Serial.begin(9600);
    motor1.run(RELEASE);         
    motor1.setSpeed(vel);
    motor2.run(RELEASE);
    motor2.setSpeed(vel);
    motor3.run(RELEASE);
    motor3.setSpeed(vel);
    motor4.run(RELEASE);
    motor4.setSpeed(vel);
}
void tras(){
    frt = false;  
    trs = true;  
    motor1.run(FORWARD);
    motor1.setSpeed(vel);
    motor2.run(FORWARD);
    motor2.setSpeed(vel);
    motor3.run(FORWARD);
    motor3.setSpeed(vel);
    motor4.run(FORWARD);
    motor4.setSpeed(vel);
}

void frente(){
    trs = false;
    frt = true;   
    motor1.run(BACKWARD);
    motor1.setSpeed(vel);
    motor2.run(BACKWARD);
    motor2.setSpeed(vel);
    motor3.run(BACKWARD);
    motor3.setSpeed(vel);
    motor4.run(BACKWARD);
    motor4.setSpeed(vel);  
}

void direita(){
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor2.run(FORWARD);
    motor2.setSpeed(vel);
    motor4.run(FORWARD);
    motor4.setSpeed(vel);
}

void esquerda(){
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);

    motor1.run(FORWARD);
    motor1.setSpeed(vel);
    motor4.run(FORWARD);
    motor4.setSpeed(vel);
}

void parar(){
   motor1.run(RELEASE);
   motor2.run(RELEASE);
   motor3.run(RELEASE);
   motor4.run(RELEASE);
}


void loop() {
  if(Serial.available()){
     state = (char)Serial.read();
     stringComplete = (state-'0' >0) && (state-'0')<=5;
  }
  if(stringComplete){
     switch(state){
         case '1':{
             Serial.println("OK -> FRENTE");
             frente();
             break;
         }
         case '2':{
             Serial.println("OK -> TRAS");
             tras();
             break;
         }
         case '3':{
            Serial.println("OK -> DIREITA");
            direita();
            break;
         }
         case '4':{
            Serial.println("OK -> ESQUERDA");
            esquerda();
            break;
         }
         case '5':{
             Serial.println("OK -> PARAR");
             parar();
             break;
     }  
             default:{
             Serial.println(state); 
             break;
             }
     }
    state = 0;
    stringComplete = false;
  }
}
   
