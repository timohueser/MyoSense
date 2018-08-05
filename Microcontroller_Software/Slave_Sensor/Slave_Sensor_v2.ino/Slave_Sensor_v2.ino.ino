#include <TinyWireS.h>
#include <EEPROM.h>

#define shift_pin 4
#define button_pin 1
#define data_pin 3
#define EEPROM_ADDRESS 1
#ifndef TWI_RX_BUFFER_SIZE
#define TWI_RX_BUFFER_SIZE ( 16 )
#endif
volatile uint8_t i2c_regs[] = { 0xDE, 0xAD, 0xBE, 0xEF};
volatile byte reg_position;
byte I2C_address;
byte address_to_shift[] = {1, 2, 4, 8, 16, 32, 64, 128};


void setup() {
  pinMode(button_pin, OUTPUT);
  pinMode(shift_pin, OUTPUT);
  pinMode(data_pin, INPUT);
  digitalWrite(shift_pin, HIGH);
  digitalWrite(button_pin, HIGH);
  delay(50);
  I2C_address = EEPROM.read(EEPROM_ADDRESS);
  if (I2C_address > 8) {
    I2C_address = 0;
    EEPROM.write(EEPROM_ADDRESS, I2C_address);
  }
  digitalWrite(button_pin, LOW);
  shift_onewire(shift_pin, address_to_shift[I2C_address]);
  digitalWrite(button_pin, HIGH);
  pinMode(button_pin, INPUT);
  TinyWireS.begin(I2C_address);
  TinyWireS.onRequest(requestEvent);
  delay(1000);
}


void loop() {
  while (digitalRead(button_pin) == LOW);
  while (digitalRead(button_pin) == HIGH);
  I2C_address = (I2C_address + 1) % 8;
  EEPROM.write(EEPROM_ADDRESS, I2C_address);
  TinyWireS.begin(I2C_address);
  shift_onewire(shift_pin, address_to_shift[I2C_address]);
  delay(200);
}


void requestEvent() {
  int res = analogRead(A3);
  TinyWireS.send(res >> 8); // respond with message of 6 bytes
  TinyWireS.send(res);
  // as expected by master
}


void shift_onewire(int pin, byte shift_data) {
  unsigned long start;
  for (int i = 7; i >= 0; i--) {
    if (shift_data & (1 << i))
    {
      digitalWrite(pin, LOW);
      digitalWrite(pin, HIGH);
    }
    else {
      digitalWrite(pin, LOW);
      start = micros();
      while (micros() - start < 15);
      digitalWrite(pin, HIGH);
    }
    start = micros();
    while (micros() - start < 15);
  }
  start = micros();

}


