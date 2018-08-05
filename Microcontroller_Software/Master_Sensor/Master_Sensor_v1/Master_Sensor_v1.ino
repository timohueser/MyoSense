#include <Wire.h>

int active_sensors[] = {0, 0, 0, 0, 0, 0, 0, 0};
unsigned long start;
void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  TWSR &= 0xFC;                                // set I2C frequency of 400K
  TWBR = 12;
  uint32_t i2c_prescaler = 4 ^ (TWSR & 0x03);
  uint32_t i2c_freq = 16000000L / (16 + 2 * TWBR * i2c_prescaler);
  Serial.begin(9600);
  Serial.println("Hallo");// start serial for output
  //delay(1000);
  for (int i = 0; i < 8; i++) {
    Wire.requestFrom(i, 2, true);
    Serial.println(Wire.available());
    unsigned long start = millis();
    while (millis() - start < 50) {
      if (Wire.available()) {
        active_sensors[i] = 1;
        while (Wire.available() && millis() - start < 50) {
          Wire.read();
        }
      }
    }
    Serial.println(active_sensors[i]);
  }
}

void loop() {
  start = micros();
  for (int i = 0; i < 8; i++) {
    if (active_sensors[i] == 1) {
      Wire.requestFrom(i, 2);    // request 6 bytes from slave device #2
      int c = Wire.read() * 256; // receive a byte as character
      c += Wire.read();
      Serial.print(i);
      Serial.print(" ");
      Serial.print(0);  // To freeze the lower limit
      Serial.print(" ");
      Serial.print(1023);  // To freeze the upper limit
      Serial.print(" ");
      Serial.print(String(c) + " ");
    }
  }
  Serial.println();
  while (micros() - start < 100000);
}
