#include <Wire.h> //I2C取り扱うためのライブラリ
#define addr 64//センサのアドレス

double sensdata; //センサから受け取ったデータを格納
double curr, volt;

void setup() {
  Wire.begin();
  Serial.begin(115200);
}

//void loop(){ //通信・デバイスの固有ID確認用
//  Wire.beginTransmission(addr); //通信の開始。slave側のアドレスを定義する
//  Wire.write(63);
//  Wire.endTransmission(); //送信0の実行
//  Wire.requestFrom(addr, 2); //slaveアドレスを再定義。レジスタアドレスから2バイトのデータを読み込む
//  sensdata = Wire.read();
//  Serial.println(sensdata);
//  delay(500);
//}

void loop() {
  curr = ina228_recv(addr, 4, 3);

//  Wire.beginTransmission(addr); //電圧データ
//  Wire.write(5);
//  Wire.endTransmission();
//  Wire.requestFrom(addr, 3);
//  volt = Wire.read();

  Serial.println(curr);
//  Serial.println(volt);

  delay(500);
}

double ina228_recv(unsigned int addr, unsigned char reg, unsigned char length){
  long tmp;

  Wire.beginTransmission(addr);
  Wire.write(reg);
  Wire.endTransmission();
  Wire.requestFrom(addr, length);

  tmp = Wire.read();
  tmp = tmp << 12;
  tmp += Wire.read() << 4;
  tmp += Wire.read() >> 4;

  return (double)tmp
}