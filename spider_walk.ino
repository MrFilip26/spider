#include "Arduino.h"
#include "Servo.h"

#define SPEED 10
#define VM 35
#define HM 50
#define STEPDEG 10


char cNEW;
//35
int vL1val = 130, vR1val = 120,
    vL2val = 130, vR2val = 120,
    vL3val = 120, vR3val = 120,

    hL1val = 95, hR1val = 85,
    hL2val = 90, hR2val = 90,
    hL3val = 70, hR3val = 115;


Servo //vertical
    vL1, vR1,
    vL2, vR2,
    vL3, vR3,

    //horizontal
    hL1, hR1,
    hL2, hR2,
    hL3, hR3;

void setup() {

  Serial.begin(9600); // init serial port
  
    vL1.attach(4);
    vR1.attach(28);
    vL2.attach(6);
    vR2.attach(32);
    vL3.attach(8);
    vR3.attach(36);

    hL1.attach(5);
    hR1.attach(30);
    hL2.attach(7);
    hR2.attach(26);
    hL3.attach(9);
    hR3.attach(34);

    initPosition();
}
void handleBluetooth()
{
    cNEW = 0;
    if (Serial.available() > 0)
    {
        cNEW = Serial.read();
        switch (cNEW)
        {
            case 'I': { initPosition(); break; }
            case 'W': { stepF(); break; }
            case 'S': { stepBack(); break; }
            case 'A': { stepL(); break; }
            case 'D': { stepR(); break; }
        }
    }
}
//da nohy do zaciatocnej polohy
void initPosition()
{
  //Serial.println("init");
  vL1.write(vL1val);
  vR1.write(vR1val);
  vL2.write(vL2val);
  vR2.write(vR2val);
  vL3.write(vL3val);
  vR3.write(vR3val);

  hL1.write(hL1val);
  hR1.write(hR1val);
  hL2.write(hL2val);
  hR2.write(hR2val);
  hL3.write(hL3val);
  hR3.write(hR3val);
}
//inicializuje nohy do polohy na chodenie -- treba len ak nohy mozu byt v inej ako inicializovanej polohe
void initStepF()
{
    vL1val = 120, vR1val = 120,
    vL2val = 120, vR2val = 120,
    vL3val = 120, vR3val = 120,

    hL1val = 110, hR1val = 70,
    hL2val = 90, hR2val = 90,
    hL3val = 70, hR3val = 115;
    
    vL1.write(vL1val);
    vL2.write(vL2val);
    vL3.write(vL3val);
    vR1.write(vR1val);
    vR2.write(vR2val);
    vR3.write(vR3val);
    
    hL1.write(hL1val);
    hL2.write(hL2val);
    hL3.write(hL3val);
    hR1.write(hR1val);
    hR2.write(hR2val);
    hR3.write(hR3val);
    
    delay(100);
}
//posunie sa o jeden krok vpred
void stepF()
{
  //Serial.println("StepF");
  for(int i = 0; i < HM; i++){
    hL1.write(++hL1val);
    hL2.write(++hL2val);
    hL3.write(++hL3val);
    hR1.write(--hR1val);
    hR2.write(--hR2val);
    hR3.write(--hR3val);
    delay(SPEED);
  }
  for(int i = 0; i < VM; i++){
    vL2.write(--vL2val);
    vR1.write(--vR1val);
    vR3.write(--vR3val);
    delay(SPEED);
  }
  for(int i = 0; i < HM; i++){
    hL2.write(--hL2val);
    hR1.write(++hR1val);
    hR3.write(++hR3val);
    delay(SPEED);
  }
  for(int i = 0; i < VM; i++){
    vL2.write(++vL2val);
    vR1.write(++vR1val);
    vR3.write(++vR3val);
  }
  for(int i = 0; i < VM; i++){
    vR2.write(--vR2val);
    vL1.write(--vL1val);
    vL3.write(--vL3val);
    delay(SPEED);
  }
  for(int i = 0; i < HM; i++){
    hR2.write(++hR2val);
    hL1.write(--hL1val);
    hL3.write(--hL3val);
    delay(SPEED);
  }
  for(int i = 0; i < VM; i++){
    vR2.write(++vR2val);
    vL1.write(++vL1val);
    vL3.write(++vL3val);
    delay(SPEED);
  }
}
//posunie sa o jeden krok s5
void stepBack()
{
  //Serial.println("StepBack");
  for(int i = 0; i < HM; i++){
    hL1.write(--hL1val);
    hL2.write(--hL2val);
    hL3.write(--hL3val);
    hR1.write(++hR1val);
    hR2.write(++hR2val);
    hR3.write(++hR3val);
    delay(SPEED);
  }
  for(int i = 0; i < VM; i++){
    vL2.write(--vL2val);
    vR1.write(--vR1val);
    vR3.write(--vR3val);
    delay(SPEED);
  }
  for(int i = 0; i < HM; i++){
    hL2.write(++hL2val);
    hR1.write(--hR1val);
    hR3.write(--hR3val);
    delay(SPEED);
  }
  for(int i = 0; i < VM; i++){
    vL2.write(++vL2val);
    vR1.write(++vR1val);
    vR3.write(++vR3val);
    delay(SPEED);
  }
  for(int i = 0; i < VM; i++){
    vR2.write(--vR2val);
    vL1.write(--vL1val);
    vL3.write(--vL3val);
    delay(SPEED);
  }
  for(int i = 0; i < HM; i++){
    hR2.write(--hR2val);
    hL1.write(++hL1val);
    hL3.write(++hL3val);
    delay(SPEED);
  }
  for(int i = 0; i < VM; i++){
    vR2.write(++vR2val);
    vL1.write(++vL1val);
    vL3.write(++vL3val);
    delay(SPEED);
  }
}
//natoci sa o jeden krok vpravo
void stepR()
{
  //Serial.println("TurnRight");
  for(int i = 0; i < HM; i++){
    hL1.write(++hL1val);
    hL2.write(++hL2val);
    hL3.write(++hL3val);
    hR1.write(++hR1val);
    hR2.write(++hR2val);
    hR3.write(++hR3val);
    delay(SPEED);
  }
  for(int i = 0; i < VM; i++){
    vL2.write(--vL2val);
    vR1.write(--vR1val);
    vR3.write(--vR3val);
    delay(SPEED);
  }
  for(int i = 0; i < HM; i++){
    hL2.write(--hL2val);
    hR1.write(--hR1val);
    hR3.write(--hR3val);
    delay(SPEED);
  }
  for(int i = 0; i < VM; i++){
    vL2.write(++vL2val);
    vR1.write(++vR1val);
    vR3.write(++vR3val);
    delay(SPEED);
  }
  for(int i = 0; i < VM; i++){
    vR2.write(--vR2val);
    vL1.write(--vL1val);
    vL3.write(--vL3val);
    delay(SPEED);
  }
  for(int i = 0; i < HM; i++){
    hR2.write(--hR2val);
    hL1.write(--hL1val);
    hL3.write(--hL3val);
    delay(SPEED);
  }
  for(int i = 0; i < VM; i++){
    vR2.write(++vR2val);
    vL1.write(++vL1val);
    vL3.write(++vL3val);
    delay(SPEED);
  }
}
//natoci sa o jeden krok vlavo
void stepL()
{
  //Serial.println("TurnLeft");
  for(int i = 0; i < HM; i++){
    hL1.write(--hL1val);
    hL2.write(--hL2val);
    hL3.write(--hL3val);
    hR1.write(--hR1val);
    hR2.write(--hR2val);
    hR3.write(--hR3val);
    delay(SPEED);
  }
  for(int i = 0; i < VM; i++){
    vL2.write(--vL2val);
    vR1.write(--vR1val);
    vR3.write(--vR3val);
    delay(SPEED);
  }
  for(int i = 0; i < HM; i++){
    hL2.write(++hL2val);
    hR1.write(++hR1val);
    hR3.write(++hR3val);
    delay(SPEED);
  }
  for(int i = 0; i < VM; i++){
    vL2.write(++vL2val);
    vR1.write(++vR1val);
    vR3.write(++vR3val);
    delay(SPEED);
  }
  for(int i = 0; i < VM; i++){
    vR2.write(--vR2val);
    vL1.write(--vL1val);
    vL3.write(--vL3val);
    delay(SPEED);
  }
  for(int i = 0; i < HM; i++){
    hR2.write(++hR2val);
    hL1.write(++hL1val);
    hL3.write(++hL3val);
    delay(SPEED);
  }
  for(int i = 0; i < VM; i++){
    vR2.write(++vR2val);
    vL1.write(++vL1val);
    vL3.write(++vL3val);
    delay(SPEED);
  }
}
//zatoci o "deg" stupnov vpravo
void turnR(int deg)
{
    for(int i = 0; i < deg; i+= STEPDEG)
    {
      stepR;  
    }
}
//zatoci o "deg" stupnov vlavo
void turnL(int deg)
{
    for(int i = 0; i < deg; i+= STEPDEG)
    {
      stepL;  
    }
}
void loop() {
  handleBluetooth();
  //initPosition();
  //stepR();
  //stepL();
  //stepF();
  //stepBack()
}
