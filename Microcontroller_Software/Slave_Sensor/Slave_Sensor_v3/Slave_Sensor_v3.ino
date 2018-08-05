#include <TinyWireS.h>
#include <EEPROM.h>

#define shift_pin 4
#define SHIFT_PIN PINB4
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
byte test = 0;

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
  if (digitalRead(button_pin) == LOW) {
  I2C_address = (I2C_address + 1) % 8;
  EEPROM.write(EEPROM_ADDRESS, I2C_address);
  TinyWireS.begin(I2C_address);
  shift_onewire(shift_pin, address_to_shift[I2C_address]);
  while (digitalRead(button_pin) == LOW);
  delay(200);
  }
  TinyWireS_stop_check();
}


void requestEvent() {
  int res = analogRead(A3);
  TinyWireS.send(res>>8);
  TinyWireS.send(res);
}


void shift_onewire(int pin, byte shift_data) {
  unsigned long start;
  for (int i = 7; i >= 0; i--) {
    if (shift_data & (1 << i))
    {
      PORTB &= ~(1<<PINB4);      
      PORTB |= (1<<PINB4);
    }
    else {
      PORTB &= ~(1<<PINB4); 
      start = micros();
      while (micros() - start < 15);
      PORTB |= (1<<PINB4);
    }
    start = micros();
    while (micros() - start < 15);
  }
  start = micros();

}


