#include <Arduino.h>
#include <main.h>
#include <SoftwareSerial.h>
  void buttonSetup(){
    pinMode(Tien, INPUT_PULLUP);
    pinMode(Lui, INPUT_PULLUP);
 
    pinMode(QuayPhai, INPUT_PULLUP);
    pinMode(QuayTrai, INPUT_PULLUP);
 
    pinMode(TienCheoPhai, INPUT_PULLUP);
    pinMode(TienCheoTrai, INPUT_PULLUP);
 
    pinMode(LuiCheoPhai, INPUT_PULLUP);
    pinMode(LuiCheoTrai, INPUT_PULLUP);
 
    pinMode(VRX,INPUT);
    pinMode(VRY,INPUT);
 
    pinMode(AutoMode,INPUT_PULLUP);
    pinMode(StopAutoMode,INPUT_PULLUP);
 
    pinMode(VRX, INPUT);
    pinMode(VRX, INPUT);
  }
 
SoftwareSerial SerialBT(RXpin,TXpin);
char cmd;
void setup() {
  Serial.begin(9600);
  SerialBT.begin(9600);
  buttonSetup();
 
}
void ButtonRead(){
if (digitalRead(Tien)==0){
      cmd = 'F';
      Serial.println("Tien");
      SerialBT.write(cmd);
    }
 
    if (digitalRead(Lui)==0){
      cmd = 'B';
      Serial.println("Lui");
      SerialBT.write(cmd);
    }
 
    if (digitalRead(QuayPhai)==0){
      cmd = 'R';
      Serial.println("Quay phai");
      SerialBT.write(cmd);
    }
 
    if (digitalRead(QuayTrai)==0){
      cmd = 'L';
      Serial.println("Quay trai");
      SerialBT.write(cmd);
    }
 
    if (digitalRead(TienCheoPhai)==0){
      cmd = 'I';
      Serial.println("Tien phai");
      SerialBT.write(cmd);
    }
 
    if (digitalRead(TienCheoTrai)==0){
      cmd = 'G';
      Serial.println("Tien trai");                                                        
      SerialBT.write(cmd);
    }
 
    if (digitalRead(LuiCheoPhai)==0){
      cmd = 'J';
      Serial.println("Lui phai");
      SerialBT.write(cmd);
    }
 
    if (digitalRead(LuiCheoTrai)==0){
      cmd = 'H';
      Serial.println("Lui trai");
      SerialBT.write(cmd);
    }
    if(digitalRead(AutoMode)==0){
      cmd= 'A';
      Serial.println("AutoMode ON!");
      SerialBT.write(cmd);
    }
    if(digitalRead(StopAutoMode)==0){
      cmd= 'X';
      Serial.println("AutoMode OFF!");
      SerialBT.write(cmd);
    }
}

void loop(){
  ButtonRead();
}



 
