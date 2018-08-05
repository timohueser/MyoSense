#define SENSOR 8
#define TRAN_TOGGLE 9
#include <util/delay.h>


void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT);
  pinMode(9, OUTPUT);
}

unsigned int pulse_len[8] = {0, 0, 0, 0, 0, 0, 0, 0};
byte pulses[200];


void scan_signal() {
  memset(pulse_len, 0, sizeof(pulse_len));
  memset(pulses, 0, sizeof(pulses));
  unsigned long start_pulse;
  unsigned int count = 0;
  unsigned long start_scan = micros();
  while (digitalRead(SENSOR) && micros() - start_scan < 10000000) _delay_us(1);
  while (count < 100) {
    start_pulse = micros();
    int timeout = edge_detect();
    if (timeout == 0) return;
    add_pulse(count++, micros() - start_pulse);
  }
}

int edge_detect() {
  int prev_val = digitalRead(SENSOR);
  int new_val;
  unsigned long start = micros();
  while (prev_val - (new_val = digitalRead(SENSOR)) == 0) {
    if (micros() - start > 100000) return 0;
    prev_val = new_val;
    _delay_us(1);
  }
  return 1;
}

void add_pulse(int counter, int dur) {
  byte pulse_num = 0;
  for (int i = 0; i  < 8; i++) {
    if (((dur - 100) <= pulse_len[i] && (dur + 100) >= pulse_len[i]) || pulse_len[i] == 0)  {
      pulse_num = i + 1;
      if (pulse_len[i] == 0) pulse_len[i] = dur;
      i= 8;
    }
  }
  pulses[counter] = pulse_num;
}


void send_signal() {
  digitalWrite(TRAN_TOGGLE, HIGH);
  byte state = 0;
  for (int i = 0; i < 200; i++) {
    if (pulses[i]) {
      digitalWrite(TRAN_TOGGLE, state = (state + 1) % 2);
      unsigned long start = micros();
      while (micros() - start < pulse_len[pulses[i]-1]) _delay_us(1);
    }
    else {
      digitalWrite(TRAN_TOGGLE, LOW);
      return;
    }
  }
  digitalWrite(TRAN_TOGGLE, LOW);
}

void loop() {
  while (!Serial.available());
  int cmd = Serial.read()-48;
  Serial.println(cmd);
  if (cmd == 0) {
  scan_signal();
  for (int i = 0; i < 8; i++) Serial.println(pulse_len[i]);
  for (int i = 0; i < 200; i++) {
    Serial.print(pulses[i]);
    Serial.print(", ");
  }
  Serial.println();
  }
  else if (cmd == 1) send_signal();
}





