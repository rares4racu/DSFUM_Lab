#define do  131
#define do_diez 139
#define re  147
#define re 156
#define mi  165
#define fa  175
#define fa_diez 185
#define sol  196
#define sol_diez 208
#define la  220
#define la_diez 233
#define si  247
 
// aici incepe cheia Sol (octava lui C4):
#define Do  262 
#define Do_diez 277
#define Re  294
#define Re_diez 311
#define Mi  330
#define Fa  349
#define Fa_diez 370
#define Sol  392 
#define Sol_diez 415
#define La  440
#define La_diez 466
#define Si  494
 
// aici incepe cheia sol cu o octava mai sus (octava lui C5)
#define DO  523
#define DO_diez 554
#define RE  587
#define RE_diez 622
#define MI  659
#define FA  698
#define FA_diez 740
#define SOL  784
#define SOL_diez 831
#define LA  880
#define LA_diez 932
#define SI  988

int note[] = {
    Do,6,   Do,2,  Fa,12,  Fa,4, 
    Sol,6,  Do,2,  La,8,   Fa,8,
    Fa,6,   Mi,2,  Re,8,   Sol, 8,
    Fa,6,   Mi,2,  Fa,16,

    Do,6,   Do,2,  Fa,12,  Fa,4,
    Sol,6,  Do,2,  La,8,   Fa,8,
    Fa,6,   Mi,2,  Re,8,   La, 8,
    La,6,   Sol,2,La,16,

    La,6,   Si,2,  DO,12,  La,4,
    Si,6,   DO,2,  RE,8,   Si,4,  Sol,4,
    Fa,6,   Re,2,  Do,8,   Fa,8,
    La,6,   Sol,2, Fa,18                         
};
// 2,4,6,8,12,16
// 2 doua steaguri
// 4 un steag
// plin cu condita 8
// cerculet cu codita 16

int note2[] = {
   Do,8,  
   Mi,12,  Fa,4,  Sol,8,  La,8,
   Si,16,  Mi,8,  Mi,8,
   DO,12,  Si,4,  La,8,   La,8  
};  


void setup() {
    int octava=1; // puteti schimba cu 2,4,8 pentru a incerca alta octava - uneori se aude mai bine
    for (int nota_curenta = 0; nota_curenta < 12; nota_curenta++) 
    {
      tone(3, note2[nota_curenta*2] * octava, 100*note2[nota_curenta*2+1]); // 3 = pinul cu buzzer-ul, nota, delay
      delay(100*note2[nota_curenta*2+1] + 100);
      noTone(3);
    }  
    digitalWrite(3,HIGH);
}
void loop() {

}