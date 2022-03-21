//#include<LiquidCrystal.h>
//const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int pin=2;
unsigned long duration;
volatile unsigned int revolution;

void setup() {
  Serial.begin(115200);
  pinMode(pin, INPUT);
}

void loop() {
  delay(1000);
  duration = pulseIn(pin, HIGH);
//  revolution=60000000.0/duration;
  Serial.println(duration);
}