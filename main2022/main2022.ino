#define UD 2
#define CS 11
#define GAIN 200

void setup(){
  pinMode(UD, OUTPUT);
  pinMode(CS, OUTPUT);

  Serial.begin(115200);
}
void loop(){
  double curr;
  int ltc = analogRead(A0);

  curr = ltc * 5.0 / 1023.0 / GAIN / 0.002;

  Serial.print("curr:"); Serial.println(curr);

  if(curr < 4.50){
    upvol();
  }
  else if(curr > 5.00){
    dnvol();
  }
  else{
    lkvol();
  }
}
void upvol(){
  digitalWrite(UD, LOW);
  digitalWrite(CS, LOW);
}
void dnvol(){
  digitalWrite(UD, HIGH);
  digitalWrite(CS, LOW);
}
void lkvol(){
  digitalWrite(CS, HIGH);
}