#include <SPI.h>
#include <MFRC522.h> 

#define RST_PIN 9
#define SS_PIN  10

//Made object RFID 
MFRC522 rfid(SS_PIN, RST_PIN); 

void setup() 
{
  //BUZZER
  pinMode(8 , OUTPUT);

  //RFID
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  Serial.println("Ready to scan");
}

void loop() 
{
  if(!rfid.PICC_IsNewCardPresent()) return;
  if(!rfid.PICC_ReadCardSerial()) return;

  String uid = "";
  for(byte i = 0 ; i < rfid.uid.size ; i++)
  {
    if(rfid.uid.uidByte[i] < 0x10) uid += "0"; 
    uid += String(rfid.uid.uidByte[i] , HEX);
  }

  Serial.println(uid);
  
  //makes sound
  digitalWrite(8 , HIGH);
  delay(2000);
  digitalWrite(8 , LOW);
 
  rfid.PICC_HaltA();
}