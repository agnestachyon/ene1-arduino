void setup() {
  Serial.begin(115200UL);
}

void loop() {
  double value=analogRead(A0);
  value*=5;
  value/=1024;
  value/=1000;
  value*=10000;
  value*=1.103471;
  Serial.println(value);
  delay(1000);
}
