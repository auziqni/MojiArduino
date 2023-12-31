#include <Arduino.h>

#include <SoftwareSerial.h>

// The serial connection to the GPS module
SoftwareSerial ss(A1, A2);

void setup()
{
    Serial.begin(115200);
    ss.begin(9600);
}

void loop()
{
    while (ss.available() > 0)
    {
        // get the byte data from the GPS
        byte gpsData = ss.read();
        Serial.write(gpsData);
    }
}