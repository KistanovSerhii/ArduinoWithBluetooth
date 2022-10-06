# ArduinoWithBluetooth
Arduino with Bluetooth module

https://www.youtube.com/watch?v=Ofm1oyJZlmQ
https://github.com/husamhamu/mm_app



Важные моменты:
1.1 Прошивка АТ команд через приложение "Termit"
1.2 Прошивка АТ команд при постоянно нажатой кнопки на HC-05 модуле

![20221004_231945](https://user-images.githubusercontent.com/28355711/194031419-cbbb14bd-3319-4d73-bef4-69d7200b4fba.jpg)

![20221004_231508](https://user-images.githubusercontent.com/28355711/194030619-c69bb85b-3a73-46d6-8258-110492d69539.png)


2.1 Правильно подключить пины, иначе команды проходить не будут!
SoftwareSerial HC_05(5, 6); // создание виртуального сериал соединения на выводах TX = 5, RX = 6

![20221004_231506](https://user-images.githubusercontent.com/28355711/194031222-bc9ded63-bb84-4679-9eb2-fbc4c89bd45b.jpg)

С резисторами (делитель напряжения) по 10К
![20221004_231509](https://user-images.githubusercontent.com/28355711/194032432-f93b63e9-c294-4716-b077-ba7c58ecbc1b.png)

![image](https://user-images.githubusercontent.com/28355711/194367234-201b2115-dc5b-4041-b84e-069a055e791e.png)

# Код Arduino:
 
\#include <SoftwareSerial.h>

SoftwareSerial HC_05(11, 10); // RX | TX

void setup()\
 {
 
  Serial.begin(9600);\
  HC_05.begin(9600);  //Default Baud for comm, it may be different for your Module.\
  Serial.println("The bluetooth is ready to pairing!"); 
}
 
void loop()\
{
 
  // Feed any data from bluetooth to Terminal.\
  if (HC_05.available())\
    Serial.write(HC_05.read());
 
  // Feed all data from termial to bluetooth\
  if (Serial.available())\
    HC_05.write(Serial.read());\
}
