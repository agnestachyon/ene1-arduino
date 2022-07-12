#include <Wire.h> //I2C取り扱うためのライブラリ
#define ADDR 64   //センサのアドレス

double sensdata; //センサから受け取ったデータを格納
double curr=0;
double volt=0;
unsigned int ADDR;
unsigned char reg;
unsigned char length;

double ina228_recv(ADDR,reg,length){
  double tmp;

  Wire.beginTransmission(ADDR);
  Wire.write(reg);
  Wire.endTransmission();
  Wire.requestFrom(ADDR, length);

  tmp = Wire.read();
  tmp = tmp << 12;
  tmp += Wire.read() << 4;
  tmp += Wire.read() >> 4;

  return (double)tmp;
}

void setup()
{
  Wire.begin();
  Serial.begin(115200);
}

// void loop(){ //通信・デバイスの固有ID確認用
//   Wire.beginTransmission(ADDR); //通信の開始。slave側のアドレスを定義する
//   Wire.write(63);
//   Wire.endTransmission(); //送信0の実行
//   Wire.requestFrom(ADDR, 2); //slaveアドレスを再定義。レジスタアドレスから2バイトのデータを読み込む
//   sensdata = Wire.read();
//   Serial.println(sensdata);
//   delay(500);
// }

void loop()
{
  curr = ina228_recv(ADDR, 4, 3);

  //  Wire.beginTransmission(ADDR); //電圧データ
  //  Wire.write(5);
  //  Wire.endTransmission();
  //  Wire.requestFrom(ADDR, 3);
  //  volt = Wire.read();

  Serial.println(curr);
  //  Serial.println(volt);

  delay(500);
}
