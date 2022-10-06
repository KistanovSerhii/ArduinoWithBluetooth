#include <SoftwareSerial.h>

SoftwareSerial HC_05(10, 11); // RX | TX

void setup()
 {
 
  Serial.begin(9600);
  HC_05.begin(9600);  //Default Baud for comm, it may be different for your Module. 
  Serial.println("The bluetooth gates are open.\n Connect to HC-05 from any other bluetooth device with 1234 as pairing key!.");
 
}
 
void loop()
{
 
  // Feed any data from bluetooth to Terminal.
  if (HC_05.available())
    Serial.write(HC_05.read());
 
  // Feed all data from termial to bluetooth
  if (Serial.available())
    HC_05.write(Serial.read());
}
