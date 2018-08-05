#define CE_PIN 3
#define CSN_PIN 3

#include "RF24_tiny2.h"
#include <TinyWireM.h>

RF24 radio(CE_PIN, CSN_PIN);

byte addresses[][6] = {"1Node", "2Node"};
byte instruction[2];
uint16_t single_voltage;
byte active_sensors[8];
int16_t voltages[8];
int num_active_channels = 0;



void setup() {
  radio.begin(); // Start up the radio
  TinyWireM.begin();
  delay(100);
  get_active_sensors();
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate( RF24_2MBPS );
  radio.enableDynamicPayloads();                // Ack payloads are dynamic payloads
  radio.setAutoAck(1); // Ensure autoACK is enabled
  radio.setRetries(1,1);
  radio.openWritingPipe(addresses[1]); // Write to device address '2Node'
  radio.openReadingPipe(1, addresses[0]); // Read on pipe 1 for device address '1Node'
  radio.startListening(); // Start listening
}

void loop(void) {
  while (!radio.available()) {
    radio.stopListening();
    delay(1000);
    radio.startListening();
    delay(100);
  }
  byte cmd = 0;
  radio.stopListening();
  radio.write(&cmd,sizeof(cmd));
  radio.flush_rx();
  radio.startListening();
  unsigned long last_signal = millis();
  while (millis() - last_signal < 20000) {
    if (radio.available()) {
      last_signal = millis();
      radio.read(instruction, 2);
      radio.stopListening();
      if (instruction[0] == 0) {
        if (instruction[1] == 0) {
          radio.flush_tx();
          radio.write(active_sensors, 8);
        }
        else if (instruction[1] == 1) radio.write(instruction, sizeof(instruction));
      }
      else if (instruction[0] == 1) {
        if (instruction[1] == 0) {
          int j = 0;
          for (int i = 0; i < num_active_channels; i++) {
            while (!active_sensors[j]) j++;
            TinyWireM.requestFrom(j, 2);
            j++;
            voltages[i] = TinyWireM.read() * 256;
            voltages[i] += TinyWireM.read();
          }
        }
        radio.write(voltages, num_active_channels * 2);
      }
      radio.startListening();
    }
  }
}


void get_active_sensors() {
  for (int i = 0; i < 8; i++) {
    if (TinyWireM.requestFrom(i, 2)) active_sensors[i] = 0;
    else {
      active_sensors[i] = 1;
      num_active_channels++;
      TinyWireM.read();
      TinyWireM.read();
    }
  }
}





