#include "SoftwareSerial_tiny.h"
#include "RF24.h"

RF24 radio(3, 3);
SoftwareSerial_tiny TinySerial(3, 4); // RX, TX

byte addresses[][6] = {"1Node", "2Node"};
byte instruction[2] = {0, 0};
byte handshake[2] = {0, 1};
uint16_t single_voltage;
byte active_sensors[8] = {1, 1, 0, 0, 0, 0, 0, 0};
int16_t voltages[8];
int num_active_channels = 2;
int16_t voltages_alt[8] = {0, 0, 0, 0, 0, 0, 0, 0};


void setup() {
  radio.begin();
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate( RF24_2MBPS );
  radio.enableDynamicPayloads();                // Ack payloads are dynamic payloads
  radio.openWritingPipe(addresses[0]);
  radio.openReadingPipe(1, addresses[1]);
  radio.setRetries(1, 1);
  radio.stopListening();
  TinySerial.begin(19200);


}

void loop() {
  if (TinySerial.available()) {
    unsigned long start = millis();
    while (TinySerial.available() < 2);
    if (TinySerial.available() == 2) {
      TinySerial.read(instruction, 2);
      TinySerial.flush();
      radio.write(instruction, 2);
      radio.startListening();
      if (instruction[0] == 0) {
        if (instruction[1] == 0) {
          radio.flush_rx();
          delay(10);
          if (radio.available()) {
            radio.read(active_sensors, 8);
            TinySerial.write(active_sensors, sizeof(active_sensors));
            num_active_channels = 0;
            for (int i = 0; i < 8; i++) {
              num_active_channels += active_sensors[i];
            }
          }
          else {
            TinySerial.write(active_sensors, sizeof(active_sensors));
          }
        }
        else if (instruction[1] == 1) {
          byte conn = 0;
          unsigned long start = millis();
          while (millis() - start < 2000 && !radio.available()) {
            radio.stopListening();
            radio.write(handshake, sizeof(handshake));
            radio.startListening();
            unsigned long start2 = millis();
            while (!radio.available() && millis() - start2 < 50);
          }
          if (radio.available()) conn = 1;
          radio.flush_rx();
          TinySerial.write(&conn, 1);
        }
      }
      else if (instruction[0] == 1) {
        if (instruction[1] == 0) {
          unsigned long start = millis();
          while (!radio.available() && millis() - start < 10);
          if (radio.available()) {
            radio.read(voltages, num_active_channels * 2);
            TinySerial.write(voltages, num_active_channels * 2);
          }
          else {
            voltages[0] = 127;
            TinySerial.write(voltages, num_active_channels * 2);
          }
        }
        else if (instruction[1] == 1) {
          while (!radio.available() && !TinySerial.available());
          if (!TinySerial.available()) {
            for (int i = 0; i < 75; i++) {
              unsigned long start = millis();
              while (!radio.available() && millis() - start < 10);
              if (radio.available()) {
                radio.read(voltages, num_active_channels * 2);
                TinySerial.write(voltages, num_active_channels * 2);
              }
              else TinySerial.write(voltages_alt, num_active_channels * 2);
            }
          }
        }
      }
    }
    else TinySerial.flush();
    radio.stopListening();

  }
}
