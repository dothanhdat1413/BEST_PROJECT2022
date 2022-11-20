/*Các chân của RF như sau
1. GND (có ô vuông), đọc từ trên xuống, từ trái sang phải
2. VCC  <3.3V>
3. CE   <Cắm đâu cũng được, chỉ cần lúc dùng hàm RF24 radio( ,  ) cần viết đúng>
4. CSN     53
5. SCK     52
6. MOSI    51
7. MISO    50
8. IRQ <không cần dùng>
*/
 
const int CE = 49;
const int CSN = 53;
 
#define M12 5//Phai
#define M11 4//Phai
#define M21 3//Trai
#define M22 2//Trai
 
#define ENA 9//Phai
#define ENB 8//Trai
 
#define left A0//DolineTrai
#define right A1//DolinePhai
 
 

