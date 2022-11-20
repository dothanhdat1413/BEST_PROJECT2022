#include <Arduino.h>
#include <main.h>
 
 
#define BT Serial3
char cmd;
///--------------------Chuyển động của xe-------------
void Dung(){
   digitalWrite(M11,0);
   digitalWrite(M12,0);
   digitalWrite(M21,0);
   digitalWrite(M22,0);
 
   Serial.println("Dung");
}
void Tien(){
   analogWrite(ENA,230);
   analogWrite(ENB,230);
 
   digitalWrite(M11,1);
   digitalWrite(M12,0);
 
   digitalWrite(M21,1);
   digitalWrite(M22,0);
   
   Serial.println("Tien");
}
void Lui(){
   analogWrite(ENA,180);
   analogWrite(ENB,180);
 
   digitalWrite(M11,0);
   digitalWrite(M12,1);
 
   digitalWrite(M21,0);
   digitalWrite(M22,1);
   Serial.println("Lui");
}
void QuayTrai(){
   analogWrite(ENA,180);
   analogWrite(ENB,180);
 
   digitalWrite(M11,1);
   digitalWrite(M12,0);
 
   digitalWrite(M21,0);
   digitalWrite(M22,1);
 
   Serial.println("QuayTrai");
}
void QuayPhai(){
   analogWrite(ENA,180);
   analogWrite(ENB,180);
 
   digitalWrite(M11,0);
   digitalWrite(M12,1);
 
   digitalWrite(M21,1);
   digitalWrite(M22,0);
 
   Serial.println("QuayPhai");
}
void TienTrai(){
   analogWrite(ENA,230);
   analogWrite(ENB,192);
 
   digitalWrite(M11,1);
   digitalWrite(M12,0);
 
   digitalWrite(M21,1);
   digitalWrite(M22,0);
 
   Serial.println("TienTrai");
}
void TienPhai(){
   analogWrite(ENA,192);
   analogWrite(ENB,230);
 
   digitalWrite(M11,1);
   digitalWrite(M12,0);
 
   digitalWrite(M21,1);
   digitalWrite(M22,0);
 
   Serial.println("TienPhai");
}
void LuiTrai(){
   analogWrite(ENA,230);
   analogWrite(ENB,192);
 
   digitalWrite(M11,0);
   digitalWrite(M12,1);
 
   digitalWrite(M21,0);
   digitalWrite(M22,1);
 
   Serial.println("LuiTrai");
}
void LuiPhai(){
   analogWrite(ENA,192);
   analogWrite(ENB,230);
 
   digitalWrite(M11,0);
   digitalWrite(M12,1);
 
   digitalWrite(M21,0);
   digitalWrite(M22,1);
 
   Serial.println("LuiPhai");
}
//------------------------Chuyển động khi dò line--------------------
void TienLine(){
   analogWrite(ENA,120);
   analogWrite(ENB,120);
 
   digitalWrite(M11,1);
   digitalWrite(M12,0);
 
   digitalWrite(M21,1);
   digitalWrite(M22,0);
   
   Serial.println("TienLine");
}
void TraiLine(){
   analogWrite(ENA,180);
   analogWrite(ENB,180);
 
   digitalWrite(M11,1);
   digitalWrite(M12,0);
 
   digitalWrite(M21,0);
   digitalWrite(M22,1);
 
   Serial.println("TraiLine");
}
void PhaiLine(){
   analogWrite(ENA,180);
   analogWrite(ENB,180);
 
   digitalWrite(M11,0);
   digitalWrite(M12,1);
 
   digitalWrite(M21,1);
   digitalWrite(M22,0);
 
   Serial.println("PhaiLine");
}
//---------------------Doline2bongngungu---------------
void DolineDeu(){
   Serial.print("Trai:");
   Serial.println(digitalRead(left));
   Serial.print("Phai:");
   Serial.println(digitalRead(right));
 
  //line detected by both
  if(digitalRead(left)==digitalRead(right)){  //bị che 1, không che 0
    //Forward
    TienLine();
 
  }
 
  else if(digitalRead(left)==0 && digitalRead(right)==1){ //chạm line bên phải
    PhaiLine();
  }
 
  else if(digitalRead(left)==1 && digitalRead(right)==0){ //chạm line bên trái
    //turn right
    TraiLine();
   
  }
 
}
 
//------------------------------------------
void pinModeSetup(){
  pinMode(M11,OUTPUT);
  pinMode(M12,OUTPUT);
  pinMode(M21,OUTPUT);
  pinMode(M22,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
 
  pinMode(left,INPUT);
  pinMode(right,INPUT);
}
//-----------------Đọc lệnh từ cmd và điều khiển động cơ-----
void ButtonControl(){
if (BT.available()>0) {
   cmd=BT.read();
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
    case 'G':
      TienTrai();
      break;
    case 'I':
      TienPhai();
      break;
    case 'H':
      LuiTrai();
      break;
    case 'J':
      LuiPhai();
      break;
    case 'A':
      DolineDeu();
      break;
    }
 
}
else Dung();
}
   
//----------------------------------------------
void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  pinModeSetup();
}
 
void loop() {
ButtonControl();
}

