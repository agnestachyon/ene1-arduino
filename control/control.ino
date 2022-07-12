#include <avr/io.h>

#define UD 2
#define CLOCK 10 //変えないで
#define GAIN 200

//unsigned int frq = 980; // 周波数
//float duty = 0.5; //指定したいデューティ比

void setup() {
//  pinMode(CLOCK, OUTPUT); //clock出力
//  pinMode(UD, OUTPUT); //ud出力
//  pinMode(11,OUTPUT);//cs出力
  Serial.begin(9600);
}
void loop() {
  float current;
  int icin = analogRead(A0);
//  Serial.print("icin:"); Serial.println(icin);
  current = icin *5.0 / 1023.0 / GAIN / 0.002;
  Serial.print("calc:"); Serial.println(current);

  // モード指定
//  TCCR1A = 0b00100001;
//  TCCR1B = 0b00010010;
//
//  OCR1A = (unsigned int)(1000000 / frq);//TOP値指定
//  OCR1B = (unsigned int)(1000000 / frq * duty);//Duty比指定
//
//  if (current < 4.50) { //5A以下
//    upVolume();
//  }
//  if (current > 4.50) { //5A以上
//    downVolume();
//  }
}
//void upVolume() {
//  digitalWrite(CLOCK, HIGH);
//  digitalWrite(UD, HIGH);
//  digitalWrite(CLOCK, LOW);
//}
//void downVolume() {
//  digitalWrite(CLOCK, HIGH);
//  digitalWrite(UD, LOW);
//  digitalWrite(CLOCK, LOW);
//}
