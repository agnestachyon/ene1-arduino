void setup() {
  Serial.begin(115200UL);
}

void loop() {
 double battery=analogRead(A0);
 battery*=5;
 battery/=1024;
 battery/=1000;
 battery*=10000; 
 battery*=1.103471;
 battery-=17;
 battery/=31;
 battery*=100;
 Serial.println(battery);
 delay(1000);
}
