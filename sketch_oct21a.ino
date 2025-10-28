void setup ()
{
  pinMode(4,OUTPUT); // pinul pentru latch (blocare)
  pinMode(7,OUTPUT); // pin pentru sincronizarea ceasului
  pinMode(8,OUTPUT); // pin pentru transmiterea datelor
}

 //hgfedcba
 //10010000 (numarul 9 pe segment)
 //10000000 (numarul 8 pe segment)
 //11111000 (numarul 7 pe segment)
 //10000010 (numarul 6 pe segment)
 //10010010 (numarul 5 pe segment)
 //10011001 (numarul 4 pe segment)
 //10110000 (numarul 3 pe segment)
 //10100100 (numarul 2 pe segment)
 //11111001 (numarul 1 pe segment)
 //11000000 (numarul 0 pe segment)
 
void loop()
{
  afiseazaValoare(0b11000000, 241);
  delay(1000);
  afiseazaValoare(0b11111001, 241); 
  delay(1000);
  afiseazaValoare(0b10100100, 241);
  delay(1000);
  afiseazaValoare(0b10110000, 241);
  delay(1000);
  afiseazaValoare(0b10011001, 241); 
  delay(1000);
  afiseazaValoare(0b10010010, 241); 
  delay(1000);
  afiseazaValoare(0b10000010, 241);
  delay(1000);
  afiseazaValoare(0b11111000, 241);
  delay(1000);
  afiseazaValoare(0b10000000, 241);
  delay(1000);
  afiseazaValoare(0b10010000, 241); 
  delay(1000);
  /*
  afiseazaValoareLSB(0b00000011, 241);
  delay(1000);
  afiseazaValoareLSB(0b00000011, 241);
  delay(1000);
  */
}
void afiseazaValoare(byte valoare, byte segment)
{
  digitalWrite(4,LOW);
  shiftOut(8, 7, MSBFIRST, valoare);
  shiftOut(8, 7, MSBFIRST, segment);
  digitalWrite(4,HIGH);
}

void afiseazaValoareLSB(byte valoare, byte segment)
{
  digitalWrite(4,LOW);
  shiftOut(8, 7, LSBFIRST, valoare);
  shiftOut(8, 7, LSBFIRST, segment);
  digitalWrite(4,HIGH);
}
