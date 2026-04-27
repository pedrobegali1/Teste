#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

File myFile;

bool i = true;

void setup() {
  
    Serial.begin(115200);

    Serial.print(">-------------------------------<\n");
    Serial.print("Initializing SD Card...\n");

    if (!SD.begin(4)) {
        Serial.print("SD Card initialization failed!\n");
        return;
        
    }

    Serial.print("SD Card initialized.\n");

    myFile = SD.open("gpsData.txt", FILE_WRITE);
    myFile.close();

}

void writeToSD() {

    if (SD.exists("gpsData.txt")) {
        myFile = SD.open("gpsData.txt", FILE_WRITE);
        myFile.close();

        Serial.print("Wrote to GPSDATA.txt\n");

    }

    else {
        Serial.print("GPSDATA does not exist\n");

    }

}

void loop() {

    if (i) {
        writeToSD();
        i = false;
    }

}