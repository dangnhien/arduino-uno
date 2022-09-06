#include <Arduino.h>
#include "main.h"
#include "rfid_rc522.h"

void setup()
{
  Serial.begin(9600);

  init_MFRC522();
}

void loop()
{
  handle_RC522_1();
}

