/*Các chân của RF như sau
1. GND (có ô vuông), đọc từ trên xuống, từ trái sang phải
2. VCC     <3.3V>
3. CE      <Cắm đâu cũng được, chỉ cần lúc dùng hàm RF24 radio( ,  ) cần viết đúng>
4. CSN      10
5. SCK      13
6. MOSI     11
7. MISO     12
8. IRQ <không cần dùng>
*/
 #define RXpin 9
 #define TXpin 10
 
 #define VRY A0 //đổi ngược lại so với chân trên mạch để dễ nhớ
 #define VRX A1
 #define JoyMode 8
 
 #define Tien A2
 #define Lui A3
 
 #define QuayPhai A4
 #define QuayTrai A5
 
 #define TienCheoPhai 2
 #define TienCheoTrai 3
 
 #define LuiCheoPhai 4
 #define LuiCheoTrai 5
 
 #define AutoMode 6
 #define StopAutoMode 7
 

