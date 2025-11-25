#include <LiquidCrystal.h>
//            lcd(RS,  E, d4, d5, d6, d7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


byte c1[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
  0b00000
};

byte c2[8] = {
  0b11111,
  0b00001,
  0b11111,
  0b10000,
  0b11111,
  0b00001,
  0b11111,
  0b10000
};

byte o1[8] = {
  0b01110,
  0b01110,
  0b01110,
  0b00100,
  0b11111,
  0b00100,
  0b01010,
  0b10001
};

byte o2[8] = {
  0b00110,
  0b00110,
  0b00110,
  0b00100,
  0b00111,
  0b00100,
  0b00100,
  0b00110
};

byte o3[8] = {
  0b00110,
  0b00110,
  0b00110,
  0b00101,
  0b01110,
  0b10100,
  0b00110,
  0b01000
};

void setup()
{

  lcd.begin(16,2);               // initialize the lcd 
  lcd.createChar (0, c1);    // load character to the LCD
  lcd.createChar (1, c2);    // load character to the LCD
  lcd.createChar (2, o1);
  lcd.createChar (3, o2);
  lcd.createChar (4, o3);
}

void loop()
{
  lcd.setCursor ( 0, 0);
  lcd.print ( char(2));
  delay(1000);
  lcd.clear();
  lcd.print ( char(3));
  delay(1000);
  lcd.clear();
  for(int i=1;i<16;i++)
     {
      lcd.clear();
      lcd.setCursor(i,0);
      lcd.print ( char(4));
      delay(1000);
      lcd.print ( char(3));
      delay(1000);
     }
}
