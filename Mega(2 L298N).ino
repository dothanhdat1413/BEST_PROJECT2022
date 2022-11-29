#include "main.h"
#include <Arduino.h>
 
#define BT Serial2

// TCCR0B = TCCR0B & B11111000 | B00000010;
char cmd;
///--------------------Chuyển động của xe-------------
void Dung(){
   analogWrite(LeftENA,0);
   analogWrite(LeftENB,0);
   analogWrite(RightENA,0);
   analogWrite(RightENB,0);
   digitalWrite(FL1,1);
   digitalWrite(FL2,1);
   digitalWrite(FR1,1);
   digitalWrite(FR2,1);
   digitalWrite(BL1,1);
   digitalWrite(BL2,1);
   digitalWrite(BR1,1);
   digitalWrite(BR2,1);
 
   Serial.println('S');
}
void Tien(){
   analogWrite(LeftENA,pwmTien);
   analogWrite(LeftENB,pwmTien);
   analogWrite(RightENA,pwmTien-saiso);
   analogWrite(RightENB,pwmTien-saiso);
 
   digitalWrite(FL1,1);
   digitalWrite(FL2,0);
 
   digitalWrite(FR1,1);
   digitalWrite(FR2,0);

   digitalWrite(BL1,1);
   digitalWrite(BL2,0);
   
   digitalWrite(BR1,1);
   digitalWrite(BR2,0);

   Serial.println('F');
}
void Lui(){
   analogWrite(LeftENA,pwmLui);
   analogWrite(LeftENB,pwmLui);
   analogWrite(RightENA,pwmLui-saiso);
   analogWrite(RightENB,pwmLui-saiso);
 
 
   digitalWrite(FL1,0);
   digitalWrite(FL2,1);
 
   digitalWrite(FR1,0);
   digitalWrite(FR2,1);

   digitalWrite(BL1,0);
   digitalWrite(BL2,1);
   
   digitalWrite(BR1,0);
   digitalWrite(BR2,1);
   Serial.println('B');
}
void QuayTrai(){
    analogWrite(LeftENA,pwmQuay);
   analogWrite(LeftENB,pwmQuay);
   analogWrite(RightENA,pwmQuay);
   analogWrite(RightENB,pwmQuay);
 
 
   digitalWrite(FL1,0);
   digitalWrite(FL2,1);
 
   digitalWrite(FR1,1);
   digitalWrite(FR2,0);
   
   digitalWrite(BL1,0);
   digitalWrite(BL2,1);
   
   digitalWrite(BR1,1);
   digitalWrite(BR2,0);
   Serial.println('L');
}
void QuayPhai(){
   analogWrite(LeftENA,pwmQuay);
   analogWrite(LeftENB,pwmQuay);
   analogWrite(RightENA,pwmQuay);
   analogWrite(RightENB,pwmQuay);
 
 
   digitalWrite(FL1,1);
   digitalWrite(FL2,0);
 
   digitalWrite(FR1,0);
   digitalWrite(FR2,1);
   
   digitalWrite(BL1,1);
   digitalWrite(BL2,0);
   
   digitalWrite(BR1,0);
   digitalWrite(BR2,1);
   Serial.println('R');
}
void TienTrai(){
   analogWrite(LeftENA,pwmCheoCham);
   analogWrite(LeftENB,pwmCheoCham);
   analogWrite(RightENA,pwmCheoNhanh);
   analogWrite(RightENB,pwmCheoNhanh);

   digitalWrite(FL1,1);
   digitalWrite(FL2,0);
 
   digitalWrite(FR1,1);
   digitalWrite(FR2,0);
 
   digitalWrite(BL1,1);
   digitalWrite(BL2,0);
   
   digitalWrite(BR1,1);
   digitalWrite(BR2,0);

   Serial.println('1');
}
void TienPhai(){
   analogWrite(LeftENA,pwmCheoNhanh);
   analogWrite(LeftENB,pwmCheoNhanh);
   analogWrite(RightENA,pwmCheoCham-saiso);
   analogWrite(RightENB,pwmCheoCham-saiso);
 
   digitalWrite(FL1,1);
   digitalWrite(FL2,0);
 
   digitalWrite(FR1,1);
   digitalWrite(FR2,0);
 
   digitalWrite(BL1,1);
   digitalWrite(BL2,0);
   
   digitalWrite(BR1,1);
   digitalWrite(BR2,0);

   Serial.println('2');
}
void LuiTrai(){
   analogWrite(LeftENA,pwmCheoCham);
   analogWrite(LeftENB,pwmCheoCham);
   analogWrite(RightENA,pwmCheoNhanh);
   analogWrite(RightENB,pwmCheoNhanh);
 
   digitalWrite(FL1,0);
   digitalWrite(FL2,1);
 
   digitalWrite(FR1,0);
   digitalWrite(FR2,1);
 
   digitalWrite(BL1,0);
   digitalWrite(BL2,1);
   
   digitalWrite(BR1,0);
   digitalWrite(BR2,1);

   Serial.println('4');
}
void LuiPhai(){
   analogWrite(LeftENA,pwmCheoNhanh);
   analogWrite(LeftENB,pwmCheoNhanh);
   analogWrite(RightENA,pwmCheoCham);
   analogWrite(RightENB,pwmCheoCham);
 
   digitalWrite(FL1,0);
   digitalWrite(FL2,1);
 
   digitalWrite(FR1,0);
   digitalWrite(FR2,1);
 
   digitalWrite(BL1,0);
   digitalWrite(BL2,1);
   
   digitalWrite(BR1,0);
   digitalWrite(BR2,1);

   Serial.println('3');
}
//------------------------Chuyển động khi dò line--------------------
void TienLine(){
   analogWrite(LeftENA,pwmTienLine);
   analogWrite(LeftENB,pwmTienLine);
   analogWrite(RightENA,pwmTienLine);
   analogWrite(RightENB,pwmTienLine);
 
   digitalWrite(FL1,1);
   digitalWrite(FL2,0);
 
   digitalWrite(FR1,1);
   digitalWrite(FR2,0);

   digitalWrite(BL1,1);
   digitalWrite(BL2,0);
   
   digitalWrite(BR1,1);
   digitalWrite(BR2,0);
}

void QuayTraiLine(){
    analogWrite(LeftENA,pwmQuayLine);
   analogWrite(LeftENB,pwmQuayLine);
   analogWrite(RightENA,pwmQuayLine);
   analogWrite(RightENB,pwmQuayLine);
 
   digitalWrite(FL1,0);
   digitalWrite(FL2,1);
 
   digitalWrite(FR1,1);
   digitalWrite(FR2,0);
   
   digitalWrite(BL1,0);
   digitalWrite(BL2,1);
   
   digitalWrite(BR1,1);
   digitalWrite(BR2,0);
}
void QuayPhaiLine(){
    analogWrite(LeftENA,pwmQuayLine);
   analogWrite(LeftENB,pwmQuayLine);
   analogWrite(RightENA,pwmQuayLine);
   analogWrite(RightENB,pwmQuayLine);
 
  digitalWrite(FL1,1);
   digitalWrite(FL2,0);
 
   digitalWrite(FR1,0);
   digitalWrite(FR2,1);
   
   digitalWrite(BL1,1);
   digitalWrite(BL2,0);
   
   digitalWrite(BR1,0);
   digitalWrite(BR2,1);
}
//---------------------Doline2bongngungu---------------
void Doline1Bong(){
  byte trai = digitalRead(trai1)+digitalRead(trai2);
  byte phai = digitalRead(phai1)+digitalRead(phai2);
  //line detected by both
  if(trai<phai){ //chạm line bên trái
    QuayTraiLine();
  }
  else if(trai>phai){ //chạm line bên trái
    QuayPhaiLine();
  }
  else TienLine();
}

void DungDoline(){
  digitalWrite(trai1,LOW);
  digitalWrite(trai2,LOW);
  digitalWrite(phai1,LOW);
  digitalWrite(phai2,LOW);
  Dung();
}
 
//------------------------------------------
void pinModeSetup(){
  pinMode(FL1,OUTPUT);
  pinMode(FL2,OUTPUT);
  pinMode(FR1,OUTPUT);
  pinMode(FR2,OUTPUT);
  pinMode(BL1,OUTPUT);
  pinMode(BL2,OUTPUT);
  pinMode(BR1,OUTPUT);
  pinMode(BR2,OUTPUT);
  pinMode(LeftENA,OUTPUT);
  pinMode(LeftENB,OUTPUT);
  pinMode(RightENA,OUTPUT);
  pinMode(RightENB,OUTPUT);
 
  pinMode(trai1,INPUT);
  pinMode(trai2,INPUT);
  pinMode(phai1,INPUT);
  pinMode(phai2,INPUT);
}
//-----------------Đọc lệnh từ cmd và điều khiển động cơ-----
void ButtonControl(char cmd){
    switch(cmd){
    case 'F':  
      Tien();
      break;
    case 'B':  
       Lui();
      break;
    case 'L':  
      QuayTrai();
      break;
    case 'R':
      QuayPhai();
      break;
    case '1':
      TienTrai();
      break;
    case '2':
      TienPhai();
      break;
    case '3':
      LuiPhai();
      break;
    case '4':
      LuiTrai();
      break;
    }
}

   
//----------------------------------------------
void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  pinModeSetup();
}
 
void loop() {
  if (BT.available()>0){
    cmd=BT.read();
    ButtonControl(cmd);
  } else Dung();
  bool autoMode=0;
  if(cmd=='A') autoMode=1;
  while(autoMode==1){
    cmd=BT.read();
    if(cmd=='X'){
      DungDoline();
      autoMode=0;
      break;
    }
    Doline1Bong();
  }
}