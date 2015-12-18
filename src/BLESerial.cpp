/*
 * BLESerial.h - Library for communicating with BLE Serial devices
 * Created by Shrikant Patnaik, December 19, 2015
 * Released under MIT license
 */
 
#include "BLESerial.h"

BLESerial::BLESerial(int RX_Pin, int TX_Pin): bleSerial(RX_Pin, TX_Pin)
{
  _RX_pin = RX_Pin;
  _TX_pin = TX_Pin;
  _enableSerial = true;
  _bleBaud = DEFAULT_BLE_BAUD;
  _serialBaud = DEFAULT_SERIAL_BAUD;
}

void BLESerial::enableSerial(bool enable)
{
  _enableSerial = enable;
}

void BLESerial::setSerialBaud(int baud)
{
  _serialBaud = baud;
}

void BLESerial::setBLEBaud(int baud)
{
  _bleBaud = baud;
}

void BLESerial::begin()
{
  bleSerial.begin(_bleBaud);
  if (_enableSerial) {
    Serial.begin(_serialBaud);
    Serial.println(WELCOME_MSG);
  }
}

int BLESerial::available()
{
  return bleSerial.available();
}

int BLESerial::read() {
  return bleSerial.read();
}

int BLESerial::write(uint8_t toWrite)
{
  return bleSerial.write(toWrite);
}

void BLESerial::setName(String name)
{
  sendAT(NAME_CMD, name);
}

void BLESerial::getName()
{
  sendAT(NAME_CMD, QUERY_CHAR);
}

void BLESerial::setBaud(BaudRates baud)
{
  sendAT(BAUD_CMD, String(baud));
}

void BLESerial::getBaud()
{
  sendAT(BAUD_CMD, QUERY_CHAR);
}

void BLESerial::getPin()
{
  sendAT(PIN_CMD, QUERY_CHAR);
}

void BLESerial::setPin(String pin)
{
  sendAT(PIN_CMD, pin);
}

String BLESerial::sendAT(String cmd, String param)
{
  cmd += param;
  int cmdLen = cmd.length();
  for (int i = 0; i < cmdLen; i++) {
    write(cmd[i]);
  }
  delay(200);
  int len = 0;
  char recvChar;
  String recvBuf;
  if (len = available()) {
    for (int i = 0; i < len; i++) {
      recvChar = read();
      recvBuf += recvChar;
    }
    if(_enableSerial) {
      Serial.print(AT_RESPONSE_MSG);
      Serial.println(recvBuf);  
    }
  }
  return recvBuf;
}
