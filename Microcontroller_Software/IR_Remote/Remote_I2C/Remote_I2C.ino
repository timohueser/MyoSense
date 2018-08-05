#define   F_CPU   16000000UL

#include <avr/io.h>
#include <TinyWireS.h>
#include <util/delay.h>
#include <EEPROM.h>

#ifndef TWI_RX_BUFFER_SIZE
#define TWI_RX_BUFFER_SIZE ( 16 )
#endif
#define DEVICEADDRESS 0b1010000
#define P_LEN 130
#define P_AM 10


#define BUTTON_1 0
#define BUTTON_2 2
#define CARRIER 1
#define TRAN_TOGGLE 3
#define SENSOR 4

unsigned int pulse_len[P_AM];
byte pulses[P_LEN];
unsigned long microseconds = 0;
byte h  = 0;
byte mode = 0;
byte cmd = 0;


void setup() {
  TCCR0A = 1 << COM0B0 | 2 << WGM00;
  TCCR0B = 1 << WGM02 | 1 << CS00;
  OCR0A = (16000000ul / 40000u / 2u) - 1u; //overflow twice per 40kHz period
  TIMSK |= (1 << OCIE0A);
  sei();
  memset(pulse_len, 0, sizeof(pulse_len));
  memset(pulses, 0, sizeof(pulses));
  pinMode(SENSOR, INPUT);
  pinMode(CARRIER, OUTPUT);
  pinMode(TRAN_TOGGLE, OUTPUT);
  TinyWireS.begin(1);
  TinyWireS.onReceive(receiveEvent);
}


void receiveEvent(uint8_t howMany) {
  mode = TinyWireS.receive();
  cmd = TinyWireS.receive();
  if (cmd > 5) cmd = 0;
}


void scan_signal() {
  memset(pulse_len, 0, sizeof(pulse_len));
  memset(pulses, 0, sizeof(pulses));
  unsigned long start_pulse;
  unsigned int count = 0;
  unsigned long start_scan = microseconds;
  while (digitalRead(SENSOR) && microseconds - start_scan < 10000000) _delay_us(1);
  while (count < P_LEN) {
    start_pulse = microseconds;
    int timeout = edge_detect();
    if (timeout == 0) return;
    add_pulse(count++, microseconds - start_pulse);
  }
}

int edge_detect() {
  int prev_val = digitalRead(SENSOR);
  int new_val;
  unsigned long start = microseconds;
  while (prev_val - (new_val = digitalRead(SENSOR)) == 0) {
    if (microseconds - start > 100000) return 0;
    prev_val = new_val;
    _delay_us(1);
  }
  return 1;
}

void add_pulse(int counter, int dur) {
  byte pulse_num = 0;
  for (int i = 0; i  < P_AM; i++) {
    if (((dur - 100) <= pulse_len[i] && (dur + 100) >= pulse_len[i]) || pulse_len[i] == 0)  {
      pulse_num = i + 1;
      if (pulse_len[i] == 0) pulse_len[i] = dur;
      i = P_AM;
    }
  }
  pulses[counter] = pulse_num;
}



ISR (TIMER0_COMPA_vect)
{
  if (h == 0) microseconds += 25;
  h = (h + 1) % 2;
}


void store_signal(int slot) {
  for (int i = 0; i < P_AM; i++) {
    EEPROM.write(2 * i + slot * (P_LEN / 2 + P_AM * 2), pulse_len[i] >> 8);
    EEPROM.write(2 * i + 1 + slot * (P_LEN / 2 + P_AM * 2), pulse_len[i]);
  }
  for (int i = 0; i  < P_LEN / 2; i++) {
    byte str_val = pulses[2 * i];
    str_val += pulses[2 * i + 1] << 4;
    EEPROM.write(i + P_AM * 2 + slot * (P_LEN / 2 + P_AM * 2), str_val);
  }
}

void load_signal(int slot) {
  for (int i = 0; i < P_AM; i++) {
    pulse_len[i] = EEPROM.read(2 * i + slot * (P_LEN / 2 + P_AM * 2)) * 256;
    pulse_len[i] += EEPROM.read(2 * i + 1 + slot * (P_LEN / 2 + P_AM * 2));
  }
  for (int i = 0; i < P_LEN / 2; i++) {
    int rd_val = EEPROM.read(i + P_AM * 2 + slot * (P_LEN / 2 + P_AM * 2));
    pulses[2 * i] = (rd_val & B00001111);
    pulses[2 * i + 1] = (rd_val & B11110000) >> 4;
  }

}

void send_signal() {
  digitalWrite(TRAN_TOGGLE, HIGH);
  byte state = 0;
  for (int i = 0; i < P_LEN; i++) {
    if (pulses[i]) {
      digitalWrite(TRAN_TOGGLE, state = (state + 1) % 2);
      unsigned long start = microseconds;
      while (microseconds - start < pulse_len[pulses[i] - 1]) _delay_us(1);
    }
    else {
      digitalWrite(TRAN_TOGGLE, LOW);
      return;
    }
  }
  digitalWrite(TRAN_TOGGLE, LOW);
}






void loop() {
  TinyWireS_stop_check();
  if (mode == 1) {
    scan_signal();
    store_signal(cmd);
    mode = 0;
    cmd = 0;
  }
  else if (mode == 2) {
    load_signal(cmd);
    send_signal();
    mode = 0;
    cmd = 0;
  }
  else if (mode == 3) {
    mode = 0;
    cmd = 0;
  }

}

