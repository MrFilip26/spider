#include "Arduino.h"
#include "Servo.h"

#define SPEED 30
#define VM 10
#define HM 40
#define STEPDEG 15

char cNEW;
int vL1val = 130, vR1val = 120,
    vL2val = 130, vR2val = 120,
    vL3val = 120, vR3val = 120,

    hL1val = 95, hR1val = 85,
    hL2val = 70, hR2val = 110;

Servo //vertical
    vL1, vR1,
    vL2, vR2,
    vL3, vR3,

    //horizontal
    hL1, hR1,
    hL2, hR2;

void setup() {
  Serial.begin(9600); // init serial port
  
    vL1.attach(4);
    vR1.attach(28);
    vL2.attach(6);
    vR2.attach(32);
    vL3.attach(8);
    vR3.attach(36);

    hL1.attach(34);
    hR1.attach(30);
    hL2.attach(7);
    hR2.attach(26);

    initPosition();
}
void loop() {
  initPosition();
  handleBluetooth();
  delay(350);
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
            case 'W': { stepF(10); break; }
            case 'S': { stepBack(20); break; }
            case 'A': { stepL(15); break; }
            case 'D': { stepR(15); break; }
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
}
//inicializuje nohy do polohy na chodenie -- treba len ak nohy mozu byt v inej ako inicializovanej polohe
void initStepF()
{
    vL1val = 130, vR1val = 120,
    vL2val = 130, vR2val = 120,
    vL3val = 120, vR3val = 120,

    hL1val = 95, hR1val = 85,
    hL2val = 60, hR2val = 120;
    
    vL1.write(vL1val);
    vL2.write(vL2val);
    vL3.write(vL3val);
    vR1.write(vR1val);
    vR2.write(vR2val);
    vR3.write(vR3val);
    
    hL1.write(hL1val);
    hL2.write(hL2val);
    hR1.write(hR1val);
    hR2.write(hR2val);
    
    delay(100);
}
//posunie sa o jeden krok vpred
void stepF(int speedStep)
{
  //Serial.println("StepF");
  for(int i = 0; i < HM; i++){
    hL1.write(++hL1val);
    hL2.write(++hL2val);
    
    hR1.write(--hR1val);
    hR2.write(--hR2val);
    delay(3*speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL2.write(--vL2val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR1.write(--vR1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR3.write(--vR3val);
    delay(speedStep);
  }
  for(int i = 0; i < HM; i++){
    hL2.write(--hL2val);
    hR1.write(++hR1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL2.write(++vL2val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR1.write(++vR1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR3.write(++vR3val);
    delay(speedStep);
  }

  for(int i = 0; i < VM; i++){
    vR2.write(--vR2val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL1.write(--vL1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL3.write(--vL3val);
    delay(speedStep);
  }
  for(int i = 0; i < HM; i++){
    hR2.write(++hR2val);
    hL1.write(--hL1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR2.write(++vR2val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL1.write(++vL1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL3.write(++vL3val);
    delay(speedStep);
  }
}
//posunie sa o jeden krok s5
void stepBack(int speedStep)
{
  //Serial.println("StepBack");
  for(int i = 0; i < HM; i++){
    hL1.write(--hL1val);
    hL2.write(--hL2val);
    hR1.write(++hR1val);
    hR2.write(++hR2val);
    delay(3*speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL2.write(--vL2val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR1.write(--vR1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR3.write(--vR3val);
    delay(speedStep);
  }
  for(int i = 0; i < HM; i++){
    hL2.write(++hL2val);
    hR1.write(--hR1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL2.write(++vL2val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR1.write(++vR1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR3.write(++vR3val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR2.write(--vR2val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL1.write(--vL1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL3.write(--vL3val);
    delay(speedStep);
  }
  for(int i = 0; i < HM; i++){
    hR2.write(--hR2val);
    hL1.write(++hL1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR2.write(++vR2val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL1.write(++vL1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL3.write(++vL3val);
    delay(speedStep);
  }
}
//natoci sa o jeden krok vpravo
void stepR(int speedStep)
{
  //Serial.println("TurnRight");
  for(int i = 0; i < HM; i++){
    hL1.write(++hL1val);
    hL2.write(++hL2val);
    hR1.write(++hR1val);
    hR2.write(++hR2val);
    delay(3*speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL2.write(--vL2val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR1.write(--vR1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR3.write(--vR3val);
    delay(speedStep);
  }
  for(int i = 0; i < HM; i++){
    hL2.write(--hL2val);
    hR1.write(--hR1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL2.write(++vL2val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR1.write(++vR1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR3.write(++vR3val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR2.write(--vR2val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL1.write(--vL1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL3.write(--vL3val);
    delay(speedStep);
  }
  for(int i = 0; i < HM; i++){
    hR2.write(--hR2val);
    hL1.write(--hL1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR2.write(++vR2val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL1.write(++vL1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL3.write(++vL3val);
    delay(speedStep);
  }
}
//natoci sa o jeden krok vlavo
void stepL(int speedStep)
{
  //Serial.println("TurnLeft");
  for(int i = 0; i < HM; i++){
    hL1.write(--hL1val);
    hL2.write(--hL2val);
    hR1.write(--hR1val);
    hR2.write(--hR2val);
    delay(3*speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL2.write(--vL2val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR1.write(--vR1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR3.write(--vR3val);
    delay(speedStep);
  }
  for(int i = 0; i < HM; i++){
    hL2.write(++hL2val);
    hR1.write(++hR1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL2.write(++vL2val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR1.write(++vR1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR3.write(++vR3val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR2.write(--vR2val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL1.write(--vL1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL3.write(--vL3val);
    delay(speedStep);
  }
  for(int i = 0; i < HM; i++){
    hR2.write(++hR2val);
    hL1.write(++hL1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vR2.write(++vR2val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL1.write(++vL1val);
    delay(speedStep);
  }
  for(int i = 0; i < VM; i++){
    vL3.write(++vL3val);
    delay(speedStep);
  }
}
//zatoci o "deg" stupnov vpravo
void turnR(int deg)
{
    for(int i = 0; i < deg; i+= STEPDEG)
    {
      stepR(20);  
    }
}
//zatoci o "deg" stupnov vlavo
void turnL(int deg)
{
    for(int i = 0; i < deg; i+= STEPDEG)
    {
      stepL(30);  
    }
}
