#include <Ps3Controller.h>

int enaMotor=27;
int in1Motor=32;
int in2Motor=33;
bool speed;

void setup() {
  Serial.begin(115200);
  Ps3.begin();
  Serial.println("Ready.");
  pinMode(in1Motor, OUTPUT);
  pinMode(in2Motor, OUTPUT);
  pinMode(enaMotor,OUTPUT);
  digitalWrite(in1Motor, LOW);
  digitalWrite(in2Motor, LOW);
}

void loop() {
  if( abs(Ps3.event.analog_changed.button.l2) ){
       Serial.print("Pressing the left trigger button: ");
       Serial.println(Ps3.data.analog.button.l2, DEC);
   }

   if( abs(Ps3.event.analog_changed.button.r2) ){
       Serial.print("Pressing the right trigger button: ");
       Serial.println(Ps3.data.analog.button.r2, DEC);
   }

    int fMOVE_p = Ps3.event.button_down.r2;
    int fMOVE_r = Ps3.event.button_up.r2;
    int bMOVE_p = Ps3.event.button_down.l2;
    int bMOVE_r = Ps3.event.button_up.l2;
    int steer_p = Ps3.event.button_down.r1;
    int steer_r = Ps3.event.button_up.r1;


    if(fMOVE_p){
      digitalWrite(in1Motor, HIGH);
      digitalWrite(in2Motor, LOW);
    }

    if(fMOVE_r){
      digitalWrite(in1Motor, LOW);
      digitalWrite(in2Motor, LOW);
    }

    if(bMOVE_p){
      digitalWrite(in2Motor, HIGH);
      digitalWrite(in1Motor, LOW);
    }

    if(bMOVE_r){
      digitalWrite(in1Motor, LOW);
      digitalWrite(in2Motor, LOW);
    }

    if(fMOVE_p && bMOVE_p){
      digitalWrite(in1Motor, LOW);
      digitalWrite(in2Motor, LOW);
    }

    if(steer_p){
      speed = 1;
    }

    if(steer_r){
      speed = 0;
    }

    switch(speed){
      case 1:
        analogWrite(enaMotor, 255);
        break;
      case 0:
        analogWrite(enaMotor, 110);
        break;
    }
}
