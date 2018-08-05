#define   F_CPU   16000000UL

#include <avr/io.h>
#include <TinyWireS.h>
#include <util/delay.h>

#define BUTTON_1 0
#define BUTTON_2 2
#define CARRIER 1
#define TRAN_TOGGLE 3
#define SENSOR 4

unsigned int pulses[100];
unsigned long microseconds = 0;
unsigned long milliseconds = 0;
byte h  = 0;


void setup() {
  TCCR0A = 1 << COM0B0 | 2 << WGM00;
  TCCR0B = 1 << WGM02 | 1 << CS00;
  OCR0A = (16000000ul / 40000u / 2u) - 1u; //overflow twice per 40kHz period
  TIMSK |= (1 << OCIE0A);
  sei();
  memset(pulses, 0, sizeof(pulses));
  pinMode(BUTTON_1, INPUT);
  pinMode(BUTTON_2, INPUT);
  pinMode(SENSOR, INPUT);
  pinMode(CARRIER, OUTPUT);
  pinMode(TRAN_TOGGLE, OUTPUT);
}


void scan_signal() {
  memset(pulses, 0, sizeof(pulses));
  unsigned long start_pulse;
  unsigned int count = 0;
  unsigned long start_scan = microseconds;
  while (digitalRead(SENSOR) && microseconds - start_scan < 10000000) _delay_us(1);
  while (count < 100) {
    start_pulse = microseconds;
    int timeout = edge_detect();
    if (timeout == 0) return;
    pulses[count++] = (microseconds - start_pulse);
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


void send_signal() {
  digitalWrite(TRAN_TOGGLE, HIGH);
  byte state = 0;
  for (int i = 0; i < 100; i++) {
    if (pulses[i]) {
      digitalWrite(TRAN_TOGGLE, state = (state + 1) % 2);
      unsigned long start = microseconds;
      while (microseconds - start < pulses[i]) _delay_us(1);
    }
    else {
      digitalWrite(TRAN_TOGGLE, LOW);
      return;
    }
  }
  digitalWrite(TRAN_TOGGLE, LOW);
}




ISR (TIMER0_COMPA_vect)
{
  if (h == 0) microseconds += 25;
  h = (h + 1) % 2;
}


void loop() {
  while (digitalRead(BUTTON_1) && digitalRead(BUTTON_2));
  if (!digitalRead(BUTTON_2)) {
    scan_signal();
  }
  else {
    send_signal();
  }
}

