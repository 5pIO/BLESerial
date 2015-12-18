#include "BLESerial.h"
#include <SoftwareSerial.h>

BLESerial ble(10, 11);

void setup() {
  ble.begin();
  ble.setName("5PBLE");
  ble.getName();
  ble.setBaud(BAUD_9600);
}

void loop() {
  char dat;
  if (ble.available()) {
    dat = ble.read();
    Serial.print(dat);
  }

  if (Serial.available()) {
    dat = Serial.read();
    ble.write(dat);
  }
}
