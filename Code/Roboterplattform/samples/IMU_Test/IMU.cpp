#include "Wire.h"

#define SDA_PIN 16
#define SCL_PIN 15
#define ADDR    0x6A

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);
  delay(10);

  // 1. Setup Accelerometer: 0x60 = 416Hz, +/- 2g range
  Wire.beginTransmission(ADDR);
  Wire.write(0x10); 
  Wire.write(0x60);
  Wire.endTransmission();

  // 2. Setup Gyroscope: 0x60 = 416Hz, 250dps
  Wire.beginTransmission(ADDR);
  Wire.write(0x11);
  Wire.write(0x60);
  Wire.endTransmission();
}

void loop() {
  Wire.beginTransmission(ADDR);
  Wire.write(0x28);
  Wire.endTransmission();
  
  Wire.requestFrom(ADDR, 6);
  int16_t rawX = Wire.read() | (Wire.read() << 8);
  int16_t rawY = Wire.read() | (Wire.read() << 8);
  int16_t rawZ = Wire.read() | (Wire.read() << 8);

  // --- Calculate g (0.061 mg/LSB) ---
  float gX = rawX * 0.061 / 1000.0;
  float gY = rawY * 0.061 / 1000.0;
  float gZ = rawZ * 0.061 / 1000.0;

  Serial.print("AccX:"); Serial.print(gX); Serial.print("\t");
  Serial.print("AccY:"); Serial.print(gY); Serial.print("\t");
  Serial.print("AccZ:"); Serial.println(gZ);

  delay(50);
}