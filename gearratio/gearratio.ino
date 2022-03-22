#define motor 2
#define rear 3

const float first = 0.1615, second = 0.1419, third = 0.1223, fourth = 0.1, fifth = 0.0851, sixth = 0.0748, seventh = 0.0644, eighth = 0.0527;

#define tire 0.482

volatile unsigned long OB1pretime = 0;
volatile unsigned long OB1time = 0;
volatile unsigned long OB1diff = 0;
volatile float OB1rpm = 0;

volatile unsigned long OB2pretime = 0;
volatile unsigned long OB2time = 0;
volatile unsigned long OB2diff = 0;
volatile float OB2rpm = 0;

float gearratio;
int speed;

void setup() {
  Serial.begin(115200);

  pinMode(motor,INPUT_PULLUP); //モーター側のピンの設定
  pinMode(rear,INPUT_PULLUP); //後輪側のピンの設定

  attachInterrupt(0, generateOB1rev, FALLING); //motor入力に対する割り込みの設定
  attachInterrupt(1, generateOB2rev, FALLING); //rear入力に対する割り込みの設定
}

void loop() {
  gearratio = OB1diff / OB2diff;
  speed = OB1diff * OB1diff * tire / OB2diff;

  Serial.print(get_position(gearratio));
  Serial.print(",");
  Serial.println(speed);
}

void generateOB1rev(){
  OB1time = micros(); //現在の時刻を記録
  OB1diff = OB1time - OB1pretime; //pretimeとtimeの時差を計算
  OB1pretime = OB1time; //今の時刻をpretimeに代入する
  // OB1rpm = 60.0 / OB1diff; //回転数[rpm]を計算
}

void generateOB2rev(){
  OB2time = micros(); //現在の時刻を記録
  OB2diff = OB2time - OB2pretime; //pretimeとtimeの時差を計算
  OB2pretime = OB2time; //今の時刻をpretimeに代入する
  // OB2rpm = 60.0 / OB2diff; //回転数[rpm]を計算
}

int get_position(int x){ //判定もちっとガバガバにせないかん
  if(gearratio == first){
    return 1;
  }
  else if(gearratio == second){
    return 2;
  }
  else if(gearratio == third){
    return 3;
  }
  else if(gearratio == fourth){
    return 4;
  }
  else if(gearratio == fifth){
    return 5;
  }
  else if(gearratio == sixth){
    return 6;
  }
  else if(gearratio == seventh){
    return 7;
  }
  else{
    return 8;
  }
}