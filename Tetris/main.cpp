#include <pieces.h>

#define CLK 13
#define DIN 11
#define CS  10
#define X_SEGMENTS   4
#define Y_SEGMENTS   2
#define NUM_SEGMENTS (X_SEGMENTS * Y_SEGMENTS)
#define Do  262 
#define Re  294
 
// a framebuffer to hold the state of the entire matrix of LEDs
// laid out in raster order, with (0, 0) at the top-left
byte fb[8 * NUM_SEGMENTS];
 
void shiftAll(byte send_to_address, byte send_this_data)
{
  digitalWrite(CS, LOW);
  for (int i = 0; i < NUM_SEGMENTS; i++) {
    shiftOut(DIN, CLK, MSBFIRST, send_to_address);
    shiftOut(DIN, CLK, MSBFIRST, send_this_data);
  }
  digitalWrite(CS, HIGH);
}

void move(byte fb[],int poz1,int poz2)
{
  byte x = fb[poz1] >> 1;
  fb[poz1] = x;
  byte y = fb[poz1+4] >> 1;
  fb[poz1+4]= y;
  byte z = fb[poz2] >> 1; 
  fb[poz2]=z;
}

const int buton1 = 41;
const int buton2 = 47;
const int buton3 = 43;
const int buton4 = 45;
long randomNumber;

void setup() {
  Serial.begin(115200);
  pinMode(CLK, OUTPUT);
  pinMode(DIN, OUTPUT);
  pinMode(CS, OUTPUT);
  pinMode(buton1, INPUT);
  pinMode(8,OUTPUT); //latch
  pinMode(7,OUTPUT); //clock
  pinMode(9,OUTPUT); //date
  // Setup each MAX7219
  shiftAll(0x0f, 0x00); //display test register - test mode off
  shiftAll(0x0b, 0x07); //scan limit register - display digits 0 thru 7
  shiftAll(0x0c, 0x01); //shutdown register - normal operation
  shiftAll(0x0a, 0x0f); //intensity register - max brightness
  shiftAll(0x09, 0x00); //decode mode register - No decode
  randomSeed(analogRead(0));
}

void afiseazaValoare(byte valoare, byte segment)
{
  digitalWrite(8,LOW);
  shiftOut(9, 7, MSBFIRST, valoare);
  shiftOut(9, 8, MSBFIRST, segment);
  digitalWrite(8,HIGH);
} 

void show() {
  for (byte row = 0; row < 8; row++) {
    digitalWrite(CS, LOW);
    byte segment = NUM_SEGMENTS;
    while (segment--) {
      byte x = segment % X_SEGMENTS;
      byte y = segment / X_SEGMENTS * 8;
      byte addr = (row + y) * X_SEGMENTS;
 
      if (segment & X_SEGMENTS) { // odd rows of segments
        shiftOut(DIN, CLK, MSBFIRST, 8 - row);
        shiftOut(DIN, CLK, LSBFIRST, fb[addr + x]);
      } else { // even rows of segments
        shiftOut(DIN, CLK, MSBFIRST, 1 + row);
        shiftOut(DIN, CLK, MSBFIRST, fb[addr - x + X_SEGMENTS - 1]);
      }
    }
    digitalWrite(CS, HIGH);
  }
}

void showPieces(byte fb[],int poz1,int poz2,long randomNumber)
{
  if(randomNumber == 0)
      pieceLine(fb,poz1,poz2);
   if(randomNumber == 1)
      pieceSquare(fb,poz1,poz2);
    if(randomNumber == 2)
      pieceLright(fb,poz1,poz2);
    if(randomNumber == 3)
      pieceLleft(fb,poz1,poz2);
    if(randomNumber == 4)
      pieceSkewright(fb,poz1,poz2);
    if(randomNumber == 5)
      pieceSkewleft(fb,poz1,poz2);
    if(randomNumber == 6)
      pieceT(fb,poz1,poz2);
    show();
    delay(1000);
    for(int i=0; i<64;i++) fb[i]=0;
}

void showButtonsSound(const int buton)
{
  if(digitalRead(buton)) {
     Serial.println("Am apasat butonul 1");
     tone(49,Do,800);
     delay(900);
     noTone(49);
     tone(49,Re,1200);
     delay(1300);
     noTone(49);
     digitalWrite(49,HIGH);
   }
}

void showButtonsNumber(const int buton)
{
  if(digitalRead(buton)) {
    Serial.println("Am apasat butonul 2");
    afiseazaValoare(0b11000000, 241);
    delay(1000);
  }
  else {
    afiseazaValoare(0b00000000, 241);
  }
}

void loop()
{
   int poz1=3;
   int poz2=63;
   randomNumber = random(0,7);
   showPieces(fb,poz1,poz2,randomNumber);
   showButtonsSound(buton1);
   showButtonsNumber(buton2);
}