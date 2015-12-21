/*
 * BLESerial.cpp - Library for communicating with BLE Serial devices
 * Created by Shrikant Patnaik, December 19, 2015
 * Released under MIT license
 */
#ifndef BLESerial_h
#define BLESerial_h

#include "Arduino.h"
#include <SoftwareSerial.h>
#include "utility/BLEConstants.h"


class BLESerial
{
  public:
    BLESerial(int RX_Pin, int TX_Pin);
    void enableSerial(bool enable);
    void begin();

    int available();
    void setSerialBaud(int baud);
    void setBLEBaud(int baud);
    int write(uint8_t toWrite);
    int read();

    void setName(String name);
    void getName();
    void setBaud(BaudRates baud);
    void getBaud();
    void setPin(String pin);
    void getPin();
    String sendAT(String cmd, String param);
  private:
    int _RX_pin;
    int _TX_pin;
    int _serialBaud;
    int _bleBaud;
    SoftwareSerial bleSerial;
    bool _enableSerial;
};

#endif
