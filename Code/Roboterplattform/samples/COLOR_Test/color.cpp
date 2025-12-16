#include "DFRobot_TCS34725.h"
#include <Wire.h>

#define SDA_PIN 16
#define SCL_PIN 15
#define SENSOR_ADDRESS 0x29

// Create the sensor object with address 0x29
DFRobot_TCS34725 tcs = DFRobot_TCS34725(&Wire, SENSOR_ADDRESS, TCS34725_INTEGRATIONTIME_24MS, TCS34725_GAIN_1X);

void setup() 
{
  Serial.begin(115200);
  Serial.println("\nColor View Test!");

  // 1. Start I2C manually with YOUR specific pins
  Wire.begin(SDA_PIN, SCL_PIN);

  // 2. Initialize Sensor
  // Note: If this gets stuck, ensure you commented out Wire.begin() in the library file!
  while(tcs.begin() == 0)
  {
    Serial.println("No TCS34725 found ... check connections (SDA=16, SCL=15)");
    delay(1000);
  }
  
  Serial.println("TCS34725 Found!");
}

void loop() {
  uint16_t clear, red, green, blue;
  
  // Get raw data
  tcs.getRGBC(&red, &green, &blue, &clear);
  
  // Locks the interrupt logic (standard practice for this lib)
  tcs.lock();  
  
  // Safety check: If sensor is covered/dark, don't divide by zero
  if (clear == 0) {
    return; 
  }

  // Print Raw Values
  Serial.print("C:\t"); Serial.print(clear);
  Serial.print("\tR:\t"); Serial.print(red);
  Serial.print("\tG:\t"); Serial.print(green);
  Serial.print("\tB:\t"); Serial.print(blue);

  // Calculate simple Hex visualization
  uint32_t sum = clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;
  
  Serial.print("\tHex: ");
  Serial.print((int)r, HEX); Serial.print((int)g, HEX); Serial.print((int)b, HEX);
  Serial.println();
}