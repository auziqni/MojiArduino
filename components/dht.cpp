#include <Arduino.h>
#include <ErriezDHT22.h>

// Create DHT22 sensor object
DHT22 dht22 = DHT22(A0);
int temperature;
int humidity;
void setup()
{
    Serial.begin(9600);
    dht22.begin();
}

void loop()
{
    if (dht22.available())
    {
        temperature = dht22.readTemperature();
        humidity = dht22.readHumidity();
        Serial.print(temperature);
        Serial.print(" : ");
        Serial.print(humidity);
        Serial.println();
    }
}