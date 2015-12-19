/*
 * BLEConstants.h - Constants for BLESerial Library for communicating with BLE Serial devices
 * Created by Shrikant Patnaik, December 19, 2015
 * Released under MIT license
 */
#ifndef BLEConstants_h
#define BLEConstants_h

#define DEFAULT_BLE_BAUD 9600
#define DEFAULT_SERIAL_BAUD 9600

typedef enum
{
  BAUD_9600 = 0,
  BAUD_19200 = 1,
  BAUD_38400 = 2,
  BAUD_57600 = 3,
  BAUD_115200 = 4,
  BAUD_4800 = 5,
  BAUD_2400 = 6,
  BAUD_1200 = 7,
  BAUD_230400 = 8

} BaudRates;


static const char NAME_CMD[] = "AT+NAME";
static const char BAUD_CMD[] = "AT+BAUD";
static const char PIN_CMD[] = "AT+PASS";
static const char QUERY_CHAR[] = "?";
static const char WELCOME_MSG[] = "Serial Ports Opened";
static const char AT_RESPONSE_MSG[] = "AT Response Received: ";

#endif
