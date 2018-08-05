
#include <TinyWireS.h>
#include <EEPROM.h>

// The default buffer size, Can't recall the scope of defines right now
#ifndef TWI_RX_BUFFER_SIZE
#define TWI_RX_BUFFER_SIZE ( 16 )
#endif
volatile uint8_t i2c_regs[] =
{
  0xDE,
  0xAD,
  0xBE,
  0xEF,
};
// Tracks the current register pointer position
volatile byte reg_position;
byte I2C_address;

void setup() {
  pinMode(1, OUTPUT);
  pinMode(4, INPUT);
  delay(100);
  for (int j = 0; j < 24; j++) {
    digitalWrite(1, HIGH);
    delay(25);
    digitalWrite(1, LOW);
    delay(25);
  }
  I2C_address = EEPROM.read(10);
  if (I2C_address > 8) {
    I2C_address = 0;
    EEPROM.write(10, I2C_address);
  }
  for (int j = 0; j < I2C_address; j++) {
    digitalWrite(1, HIGH);
    delay(25);
    digitalWrite(1, LOW);
    delay(25);
  }
  TinyWireS.begin(I2C_address);
  TinyWireS.onRequest(requestEvent);
}


void requestEvent() {
  int res = analogRead(A3);
  TinyWireS.send(res >> 8); // respond with message of 6 bytes
  TinyWireS.send(res);
  // as expected by master
}
void loop() {
  while (digitalRead(4) == LOW);
  I2C_address = (I2C_address + 1) % 8;
  EEPROM.write(10, I2C_address);
  TinyWireS.begin(I2C_address);
  digitalWrite(1, HIGH);
  delay(10);
  digitalWrite(1, LOW);
  while (digitalRead(4) == HIGH);

}

