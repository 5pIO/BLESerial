# BLESerial

A simple library to communicate with BLE Serial Modules using SoftwareSerial

## Usage Example
```c
//Init Library
BLESerial ble(10,11);

void setup() {
  ble.enableSerial(true); // Defaults to true but you can set it to false to disable any usage of the hardware serial

  ble.setSerialBaud(9600); // Set the Baud rate for Hardware serial console, defaults to 9600

  ble.setBLEBaud(9600); // Set the Baud rate for software serial to connect with module, defaults to 9600

  ble.begin(); // Initialize the serial ports

  ble.setName("SPBLE") // Set BLE Device Name

  Serial.println(ble.getName()); // Read BLE Name

  ble.setBaud(BAUD_9600) // Set Baudrate based on BLEConstants.h

  Serial.println(ble.getBaud()); // Read Baudrate

  ble.setPin("000000"); // Set pairing pin

  Serial.println(ble.getPin()) //Read Pin
}

void loop() {
  char dat; // Variable to store received byte
  if (ble.available()) {
    dat = ble.read();
    Serial.print(dat); // Print all received data to Serial Console
  }

  if (Serial.available()) {
    dat = Serial.read();
    ble.write(dat); // Send any data received from Serial to ble device.
  }
}
```

The `BLEConstants.h` File can be edited to match your module or language

## License
This code is released under the MIT License
