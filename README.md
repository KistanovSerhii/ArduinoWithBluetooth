# ArduinoWithBluetooth
Arduino with Bluetooth module

https://www.youtube.com/watch?v=Ofm1oyJZlmQ
https://github.com/husamhamu/mm_app



Важные моменты:
1.1 Прошивка АТ команд через приложение "Termit"
1.2 Прошивка АТ команд при постоянно нажатой кнопки на HC-05 модуле

![20221004_231506](https://user-images.githubusercontent.com/28355711/194029133-f7094cc8-172c-4cda-a446-4ce4ec32ba83.jpg)

![20221004_231945](https://user-images.githubusercontent.com/28355711/194029147-a28d0848-c929-485b-85d9-ba1adb805e95.jpg)

2.1 Правильно подключить пины, иначе команды проходить не будут!
SoftwareSerial HC_05(5, 6); // создание виртуального сериал соединения на выводах TX = 5, RX = 6

![image](https://user-images.githubusercontent.com/28355711/194028660-2f9b0d14-d227-4b15-9a22-7028275a27c3.png)

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
