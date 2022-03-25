#include <Wire.h> //I2C取り扱うためのライブラリ

#define address //センサのアドレス

int sensdata; //センサから受け取ったデータを格納

void setup(){
  Wire.begin();
  Serial.begin(115200);
}

void loop(){ //通信・デバイスの固有ID確認用
  Wire.beginTransmission(address); //通信の開始。slave側のアドレスを定義する
  Wire.write(0x00); //固有IDの格納場所のアドレス
  Wire.endTransmittion(); //送信の実行
  Wire.requestFrom(address, 1); //slaveアドレスを再定義。レジスタアドレスから1アドレスのデータを読み込む
  sensdata = Wire.read();
  Serial.println(sensdata);
  delay(500)
}