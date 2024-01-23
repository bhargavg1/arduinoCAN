
#include <Adafruit_MPU6050.h>
#include <Adafruit_sensor.h>
#include <Wire.h>

Adafruit_MPU6050 gyro;

void setup() {
  Serial.begin(9600);

  Serial.println("starting setting up\n");

  if (!mpu.begin()) {
    Serial.println("the initialization failed oh no");
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.println("finished setting up\n");

}

void loop() {
  sensors_event_t a; //acceleration
  sensors_event_t g; //gyroscope
  sensors_event_t t; //temperature
  mpu.getEvent(&a, &g, &t);

  char data[100];
  sprintf(data, "accelX: %d\t accely: %d\t accelZ: %d \t\ngyroX: %d\tgyroY: %d\tgyroZ: %d\t\n", 
  a.acceleration.x, a.acceleration.y, a.acceleration.z, g.gyro.x, g.gyro.y, g.gyro.z);
  Serial.print(data);

}
