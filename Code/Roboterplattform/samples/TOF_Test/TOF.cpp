#include "Arduino.h"
#include "Wire.h"
#include "DFRobot_VL53L0X.h"

DFRobot_VL53L0X sensor;

// Define your pins here so they are easy to change later
#define SDA_PIN 16 // Data
#define SCL_PIN 15 // Clock

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);
  
  // Sensor initialization Adress: 0x50
  sensor.begin(0x50);
  
  // Set mode
  sensor.setMode(DFRobot_VL53L0X::eContinuous, DFRobot_VL53L0X::eHigh);
  
  // Start measuring
  sensor.start();
}

void loop()
{
  Serial.print("Distance: ");
  Serial.println(sensor.getDistance());
  delay(500);
}