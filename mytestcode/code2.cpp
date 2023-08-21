#include <Arduino.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = A1, TXPin = A2;
static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);

float lat = 0, lng = 0, temp = 0, humid = 0;
bool gpsReady = false, dhtReady = false;
unsigned long lastMillis = 0, currentMillis = millis();

void readData()
{
    while (ss.available() > 0)
    {
        gps.encode(ss.read());
        if (gps.location.isUpdated())
        {
            lat = gps.location.lat();
            lng = gps.location.lng();
            gpsReady = true;
        }
    }
}

void serialPrint()
{
    Serial.print("Latitude= ");
    Serial.print(lat, 6);
    Serial.print(" Longitude= ");
    Serial.print(lng, 6);
    Serial.print(" temperature= ");
    Serial.print(temp);
    Serial.print(" humidity= ");
    Serial.print(humid);
    Serial.println();
}

void setup()
{
    Serial.begin(9600);
    ss.begin(GPSBaud);
}

void loop()
{
    readData();
    serialPrint();
}