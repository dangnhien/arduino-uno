#include <Arduino.h>
//#include "main.h"
//#include "rfid_rc522.h"

#include "SPI.h"
#include "MFRC522.h"

#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc522_s(RST_PIN, SS_PIN);

void setup()
{
  Serial.begin(9600);
  Serial.println("RFID RC522");

  SPI.begin();

  mfrc522_s.PCD_Init();
}

void loop()
{
  if(!mfrc522_s.PICC_IsNewCardPresent())
        return;

  if( !mfrc522_s.PICC_ReadCardSerial() )
        return;

  mfrc522_s.PICC_DumpToSerial(&(mfrc522_s.uid));
}
