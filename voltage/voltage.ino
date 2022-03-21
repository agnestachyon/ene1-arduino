#include <OneWire.h>
#include <DallasTemperature.h>

void setup() {
  Serial.begin(115200UL);
}
void loop() {
  int sensorValue=analogRead(A0);
  float voltage=sensorValue*(5.0/1023.0);
  Serial.println(voltage*100);
  delay(1000);
}