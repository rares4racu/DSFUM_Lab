#include <LiquidCrystal.h>
//            lcd(RS,  E, d4, d5, d6, d7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

String textul = "Bun venit la laboratorul 6";

String textnou2[26] = {"B","u","n"," ","v", "e", "n","i","t"," ","l","a"," ","l","a","b","o","r","a","t","o","r","u","l"," ", "6"};
String textnou[12] = {"B","u","n"," ","v", "e", "n","i","t"," ","l","a"};
void setup() {
  lcd.begin(16,2);
}

void loop() {
  lcd.setCursor(0,0);
  for(int i = 0;i<12;i++)
     lcd.print(textnou[i]);
    lcd.setCursor(0,0);
    for(int i=0;i<26;i++)
    {
     for(int j=0;j<15;j++)
        {
          lcd.print(textnou2[j+i]);
        }
      delay(500);
      lcd.clear();
    }
}
