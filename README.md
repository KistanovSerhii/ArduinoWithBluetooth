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


Код Arduino:
 
#include <SoftwareSerial.h> // подключение библиотеки для эмуляции сериал-порта
 
SoftwareSerial HC_05(5, 6); // создание виртуального сериал соединения на выводах TX = 5, RX = 6
char appData; //
String inData = ""; // переменная для хранения полученных данных
 
void setup()
{
  Serial.begin(9600); // инициализация сериал соединения
  Serial.println("HC_05 serial started at 9600"); // вывод поясняющей надписи
  HC_05.begin(9600); // инициализация соединения блютус модуля со скоростью 9600 бод
  pinMode(13, OUTPUT); // конфигурация вывода светодиода
 
}
 
void loop()
{
  // Test
  if (HC_05.read() > 0) {
    Serial.print(HC_05.available());
  }
 
  HC_05.listen();  // "прослушивание" порта
  while (HC_05.available() > 0) {   // если пришла какая-то информация
    appData = HC_05.read(); // чтение полученных данных
    inData = String(appData);  // сохранение данных в строковом формате
    Serial.write(appData); //выведем полученные данные в монитор сериал порта
  }
 
 
  if (Serial.available()) { // если что-то пришло в сериал порт
    delay(3); // задержка в 3 мс
    HC_05.write(Serial.read()); //отправить это в порт блютус модуля
  }
 
 
  if (inData == "1") { // если пришла единица
    Serial.println("LED ON"); // поясняющая надпись в монитор порта
    HC_05.println("LED ON"); // поясняющая надпись в блютус модуль
    digitalWrite(13, HIGH); // включить светодиод
    delay(500); // задержка в полсекунды
    digitalWrite(13, LOW); // погасить светодиод
    HC_05.println("LED OFF"); // поясняющая надпись в блютус модуль
  }
}
