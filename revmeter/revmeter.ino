#include<LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

volatile unsigned long tachoBefore = 0;//クランクセンサーの前回の反応時の時間
volatile unsigned long tachoAfter = 0;//クランクセンサーの今回の反応時の時間
volatile unsigned long tachoWidth = 0;//クランク一回転の時間　tachoAfter - tachoBefore
volatile float tachoRpm = 0;//エンジンの回転数[rpm]

void setup(){
  Serial.begin(2000000);//シリアル通信を開始
  lcd.begin(16,2);
  pinMode(2, INPUT_PULLUP);//ピンモードの設定
  attachInterrupt(0, tachometer, FALLING);//外部割り込み（Pin2）
}

void loop(){

}

void tachometer(){
  lcd.clear();
  tachoAfter = micros();//現在の時刻を記録
  tachoWidth = tachoAfter - tachoBefore;//前回と今回の時間の差を計算
  tachoBefore = tachoAfter;//今回の値を前回の値に代入する
  tachoRpm = 60000000.0 / tachoWidth;//タイヤの回転数[rpm]を計算
  lcd.print(tachoRpm);
  Serial.print(tachoRpm);
  Serial.println("rpm");
}