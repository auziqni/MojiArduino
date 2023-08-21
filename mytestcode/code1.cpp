#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <ErriezDHT22.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // 0x27 merupakan adress dari iic lcd, cari nilai pake scanner
DHT22 dht22 = DHT22(A0);
static const int RXPin = A1, TXPin = A2;
static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);

float lat = 0, lng = 0;
float temp = 0, humid = 0;
bool gpsReady = false, dhtReady = false;
unsigned long lastMillis = 0, currentMillis = millis();

void readData()
{
    while (ss.available() > 0) // normal .3-.6s
    {
        gps.encode(ss.read());
        if (gps.location.isUpdated())
        {
            lat = gps.location.lat();
            lng = gps.location.lng();
            gpsReady = true;
        }
    }
    delay(100);
    while (dht22.available()) // normal 1-2s
    {
        temp = dht22.readTemperature() / 10;
        humid = dht22.readHumidity() / 10;
        dhtReady = true;
    }
    delay(100);
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
    dht22.begin();

    lcd.init();      // initialize the lcd
    lcd.backlight(); // menghidupkan backlight

    //       ("1234567890123456")
    lcd.setCursor(0, 0);
    lcd.print("    WELCOME     ");
    lcd.setCursor(0, 1);
    lcd.print("      MOJI      ");

    currentMillis = millis();
    lastMillis = currentMillis;
    while (currentMillis - lastMillis < 10000)
    {
        readData();
        currentMillis = millis();
    }

    currentMillis = millis();
    lastMillis = currentMillis;
    lcd.clear();

    do
    {
        lastMillis = currentMillis;
        while (currentMillis - lastMillis < 2000)
        {
            lcd.setCursor(0, 0);
            lcd.print("LOADING          ");
            lcd.setCursor(0, 1);
            lcd.print("GETTING DATA.    ");
            readData();
            currentMillis = millis();
        }

    } while (!gpsReady || !dhtReady);
}

void loop()
{
    currentMillis = millis();

    if ((currentMillis - lastMillis) % 5000 > 2500)
    {
        lcd.setCursor(0, 0);
        // lcd.print("    WELCOME     ");
        lcd.print("temp  :     ");
        lcd.setCursor(12, 0);
        lcd.print(temp);
        lcd.setCursor(0, 1);
        lcd.print("humid :     ");
        lcd.setCursor(12, 1);
        lcd.print(humid);
    }
    else
    {
        lcd.setCursor(0, 0);
        lcd.print("lat:   ");
        lcd.setCursor(7, 0);
        lcd.print(lat, 6);
        lcd.setCursor(0, 1);
        lcd.print("lng:  ");
        lcd.setCursor(6, 1);
        lcd.print(lng, 6);
    }

    if (currentMillis - lastMillis > 10000)
    {
        serialPrint();
        readData();
        lastMillis = currentMillis;
    }
}