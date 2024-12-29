#include "DHT.h"
#include "BH1750.h"
#include "BMP180.h"
#include "config.h"

DHT dht(DHT_PIN, DHT22);
BH1750 lightSensor;
BMP180 pressureSensor;

float temperature, humidity, lightIntensity, pressure;

void initSensors() {
  dht.begin();
  lightSensor.begin();
  pressureSensor.begin();
}

void readSensors() {
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  lightIntensity = lightSensor.readLightLevel();
  pressure = pressureSensor.readPressure();
}

String getSensorData() {
  return "{ \"temperature\": " + String(temperature) + 
         ", \"humidity\": " + String(humidity) + 
         ", \"light\": " + String(lightIntensity) + 
         ", \"pressure\": " + String(pressure) + " }";
}
