#include<LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#include<Metro.h> // タイマー処理のために Metro ライブラリをインクルード
Metro metro1 = Metro(250); // metro1 タイマーを 250ms にセット
 
//#define DATAPIN (5) // 74LC595の(14)SIへ
//#define LATCHPIN (6) // 74LC595の(12)RCKへ
//#define CLOCKPIN (7) // 74LC595の(11)SCKへ
 
#define FREQPIN (3) // 周波数測定用の入力ピン
 
// パルスの幅を測定する変数
 
/*volatile unsigned long t_time=0;
volatile unsigned long h_time=0;
volatile unsigned long l_time=0;*/

volatile unsigned long pastres = 0;	//sensor's previous response time
volatile unsigned long nowres = 0;	//sensor's latest responce time
volatile unsigned long diff = 0;	//nowres-lastres 1rev
volatile int revolution = 0;
 
/*struct PTN{
int nOut;
};*/
/*struct PTN ptn[11] // 7seg LED のパターンを設定
{
B00111111, // 0
B00000110, // 1
B01011011, // 2
B01001111, // 3
B01100110, // 4
B01101101, // 5
B01111101, // 6
B00000111, // 7
B01111111, // 8
B01100111, // 9
B00000000  // Space
};*/
 
void setup() {
    lcd.begin(16,2);
//pinMode(DATAPIN, OUTPUT); // 7seg LED 制御用(1)
//pinMode(LATCHPIN, OUTPUT); // 7seg LED 制御用(2)
//pinMode(CLOCKPIN, OUTPUT); // 7seg LED 制御用(3)
 
pinMode(FREQPIN, INPUT_PULLUP); // 周波数測定用のピンを入力用に設定
 
Serial.begin(115200);
}
 
long FREQ1 = 0;
 
void loop() {
    nowres = micros();	//時間記録
	diff = nowres - pastres;
	pastres = nowres;
  	revolution = 60000000.0 / diff;
    Serial.println(revolution);
	lcd.setCursor(0,0);	//displayposition
	lcd.print(revolution);

    /*if (metro1.check() == 1) { // Metro を使って 250ms 毎に下記を実行し、周波数を求める
        h_time = pulseIn( FREQPIN, HIGH ); // まずは3番ピンが High 状態になっている時間を p_time に格納
        l_time = pulseIn( FREQPIN, LOW); // 次に3番ピンが Low になっている状態を l_time に格納
        t_time = h_time + l_time ; // 足し算してパルスの幅（周期）にする
        
        Serial.println( (1.0 / t_time)  , DEC ); // シリアルポートに周波数に換算して10進数で出力する
        //Serial.println( "Hz");        
        FREQ1 = (1.0 / t_time) * 1000000;
        
    //Out5Digit(FREQ1); // 7seg LED に出力 値を 250ms ごとに更新
    
    }*/
 
//Out5Digit(FREQ1); // 7seg LED に出力 こっちは同じ値を出しておくため（チラついちゃうから）
 
}
 
/*void Out5Digit(long nValue)
{
for(int i=0;i<5;i++){
int amari = nValue %10;
Out(i, amari);
nValue = nValue / 10;
}
}
 
void Out(int nKeta, int nValue)
{
if(nKeta==4 and nValue==0) { // 最上位の桁を0（ゼロ）の時、どうしても消したいから
nValue=10; // カブのアイドリングは1700RPMだから最上位桁だけでよいの
} // （時間があるときにもう少し書けば、頭に 0 出さなくできる)
digitalWrite(LATCHPIN, LOW);
ShiftOut8( DATAPIN, CLOCKPIN, ~(B00000001 << nKeta));
ShiftOut8( DATAPIN, CLOCKPIN, ptn[nValue].nOut);
digitalWrite(LATCHPIN, HIGH);
delay(1);
}
 
void ShiftOut8( int dataPin, int clockPin, unsigned long val )
{
for( int i = 7; i >= 0; i-- ){
digitalWrite(dataPin, !!(val & (1L << i)));
digitalWrite(clockPin, HIGH);
digitalWrite(clockPin, LOW);
}
}*/