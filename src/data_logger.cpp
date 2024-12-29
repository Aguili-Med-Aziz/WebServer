#include <SD.h>
#include "config.h"

File dataFile;

void initSDCard() {
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("SD card initialization failed!");
    return;
  }
  
  dataFile = SD.open("/data/sensor_data.csv", FILE_WRITE);
  if (dataFile) {
    dataFile.println("Time,Temperature,Humidity,Light,Pressure");
  }
}

void logDataToSD() {
  if (dataFile) {
    dataFile.print(millis());
    dataFile.print(",");
    dataFile.print(temperature);
    dataFile.print(",");
    dataFile.print(humidity);
    dataFile.print(",");
    dataFile.print(lightIntensity);
    dataFile.print(",");
    dataFile.println(pressure);
  }
}

