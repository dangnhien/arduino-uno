#include <Arduino.h>
#include "SPI.h"
#include "MFRC522.h"
#include "rfid_rc522.h"

/*
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 *
*/
enum Pin_MFRC522
{
    RST_PIN = 9,
    SS_PIN
};

MFRC522 mfrc522(RST_PIN, SS_PIN);

void init_MFRC522()
{
    SPI.begin();

    mfrc522.PCD_Init();
}

void read_once()
{
    if(!mfrc522.PICC_IsNewCardPresent())
        return;
}

void read_All_Data()
{
    if( !mfrc522.PICC_ReadCardSerial() )
        return;
}

void print_Data_Readed()
{
    mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}

void handle_RC522_1()
{
    read_once();

    read_All_Data();

    print_Data_Readed();
}