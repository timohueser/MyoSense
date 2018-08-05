
#include <TinyWireS.h>
// The default buffer size, Can't recall the scope of defines right now
#ifndef TWI_RX_BUFFER_SIZE
#define TWI_RX_BUFFER_SIZE ( 16 )
#endif
int I2C_SLAVE_ADDRESS = 0;

volatile uint8_t i2c_regs[] =
{
  0xDE,
  0xAD,
  0xBE,
  0xEF,
};
// Tracks the current register pointer position
volatile byte reg_position;


void setup() {
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  
  TinyWireS.begin(I2C_SLAVE_ADDRESS);
  TinyWireS.onRequest(requestEvent);
}

void requestEvent() {
  int res = analogRead(A3);
  TinyWireS.send(res >> 8); // respond with message of 6 bytes
  TinyWireS.send(res);
  // as expected by master
}
void loop() {
  delay(1000);
}

