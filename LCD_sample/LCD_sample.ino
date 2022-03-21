//#include<KanaLiquidCrystal.h>
#include<LiquidCrystal.h>
KanaLiquidCrystal lcd(10,9,8,7,6,5,4);
void setup() {
  lcd.kanaOn();
  lcd.begin(16,2);
  lcd.print("ﾄﾆｰﾋﾞﾝ");
  lcd.setCursor(0,1);
  lcd.print("ﾆｼﾞﾝｽｷｰ");
}

void loop() {

}
