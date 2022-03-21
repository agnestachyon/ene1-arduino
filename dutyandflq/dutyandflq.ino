#include <avr/io.h>

#define PWMPin 10

unsigned int frq = 250; // 周波数
float duty = 0.5; //指定したいデューティ比

void setup() {
  pinMode(PWMPin, OUTPUT);
    // モード指定
  TCCR1A = 0b00100001;
  TCCR1B = 0b00010010;
}

void loop() {



  // TOP値指定
  OCR1A = (unsigned int)(1000000 / frq);

  // Duty比指定
  OCR1B = (unsigned int)(1000000 / frq * duty);
}
