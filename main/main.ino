//lcd
#include<LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//temp
#include <OneWire.h>
#include <DallasTemperature.h>
#define temp_pin 7
OneWire oneWire(temp_pin);
DallasTemperature sensors(&oneWire);

//rev
#define rev_pin 2
volatile unsigned long pastres = 0;	//sensor's previous response time
volatile unsigned long nowres = 0;	//sensor's latest responce time
volatile unsigned long diff = 0;	//nowres-lastres 1rev
volatile unsigned long revolution = 0.0;

void setup(){
//lcd
	lcd.begin(16,2);
//temp
    sensors.begin();
//rev
	pinMode(rev_pin,INPUT_PULLUP);
	attachInterrupt(0,revmeter,FALLING);
//debug
	Serial.begin(115200);	
}

void loop(){
//volt
    double value=analogRead(A0);
    value*=5;
    value/=1024;
    value/=1000;
    value*=1000;
    value*=1.103471;
    lcd.setCursor(0,1);	//displayposition
    lcd.print(value); lcd.print("V");
//temp
	sensors.requestTemperatures();
	float tempC = sensors.getTempCByIndex(0);
	if(tempC != DEVICE_DISCONNECTED_C){
		lcd.setCursor(7,1);	//displayposition
		lcd.print(sensors.getTempCByIndex(0));
	} 
	else{
		lcd.print("ERR");
	}
	lcd.print("C");

	lcd.setCursor(0,0);	//dsiplayposition
	lcd.print(revolution);

//debug
	Serial.print(value);	Serial.print(",");	Serial.print(sensors.getTempCByIndex(0));	Serial.print(",");	Serial.print(revolution);	Serial.println();
} 

void revmeter(){
  	nowres = micros();	//時間記録
	diff = nowres - pastres;
	pastres = nowres;
  	revolution = 60000000.0 / diff;
}