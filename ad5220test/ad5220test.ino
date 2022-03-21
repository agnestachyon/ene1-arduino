#define UD     2
#define Clock  3
#define ledPin 13
#define aInput 0

int buttonState1 = 0;
int buttonState2 = 0;

void setup() {
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);     
  pinMode(UD, OUTPUT);
  pinMode(Clock, OUTPUT);
  
  Serial.println("AD5220 Serian control.");
  Serial.println("Send 'u' or 'd'");
  
}
  
void loop(){

  if (Serial.available() > 0) {
    
    int incomingByte = Serial.read();
    
    if (incomingByte == 'd') {      
      digitalWrite(ledPin, HIGH); 
//      for(int i=0; i<100; i++)
      upVolume();
      Serial.println("==== DOWN ====");
      analogInPrint();
    }
    
    else if (incomingByte == 'u') {    
      digitalWrite(ledPin, HIGH); 
//      for(int i=0; i<100; i++)
      downVolume();
      Serial.println("===== UP =====");
      analogInPrint();
    }
  }
  
  delay(100);
  digitalWrite(ledPin, LOW); 
  
}

void analogInPrint(){
  int val = analogRead(aInput);
  Serial.println(val);
}
  
void upVolume(){
  digitalWrite(Clock, HIGH);
  digitalWrite(UD, HIGH);
  digitalWrite(Clock, LOW);
}
  
void downVolume(){
  digitalWrite(Clock, HIGH);
  digitalWrite(UD, LOW);
  digitalWrite(Clock, LOW);
}