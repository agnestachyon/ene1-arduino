#include<Wire.h>

#define ADDR 64
#define REG 7
#define LENGTH 3

double data;

void setup(){
  Serial.begin(115200);
}
void loop(){
  Wire.beginTransmission(ADDR); //通信の開始。slave側のアドレスを定義する
  Wire.write(REG);
  Wire.endTransmission(); //送信0の実行
  Wire.requestFrom(ADDR, LENGTH); //slaveアドレスを再定義。レジスタアドレスから2バイトのデータを読み込む
  data = Wire.read();
  Serial.println(data);
  delay(1000);

  
}
