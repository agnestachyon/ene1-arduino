#include <Wire.h> //I2C取り扱うためのライブラリ
#define address 64//センサのアドレス

int sensdata; //センサから受け取ったデータを格納
int current;
int voltage;

void setup(){
  Wire.begin();
  Serial.begin(115200);
}

// void loop(){ //通信・デバイスの固有ID確認用
//   Wire.beginTransmission(address); //通信の開始。slave側のアドレスを定義する
//   Wire.endTransmission(); //送信0の実行
//   Wire.requestFrom(address, 1); //slaveアドレスを再定義。レジスタアドレスから1バイトのデータを読み込む
//   sensdata = Wire.read();
//   Serial.println(sensdata);
//   delay(500);
//}

void loop(){
  Wire.beginTransmission(address); //電流データの焼き鳥
  Wire.write(7);
  Wire.endTransmission();
  Wire.requestFrom(address, 1);
  current = Wire.read();

  Wire.beginTransmission(address); //電圧データの焼き鳥
  Wire.write(4);
  Wire.endTransmission();
  Wire.requestFrom(address, 1);
  voltage = Wire.read();

//  Serial.print(current);
  Serial.println(voltage);
  
  delay(500);
}
