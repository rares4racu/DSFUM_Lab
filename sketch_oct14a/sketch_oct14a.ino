void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
char s[1000];
int idx = 0;
char c;
int ledPin = 9;
int ledPin2 = 11;
void blink(int ledPin) {
  digitalWrite(ledPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                 // wait for a second
  digitalWrite(ledPin, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);
}

void fadein(int ledPin) {
  for (int fadeValue = 0; fadeValue <= 255; fadeValue += 5) {
    analogWrite(ledPin, fadeValue);
    delay(30);
  }
}
void fadeout(int ledPin) {
  for (int fadeValue = 255; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(ledPin, fadeValue);
    delay(30);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {
    c = Serial.read();
    s[idx++] = c;
  }
  if (idx > 0 && c == '\n') {
    s[idx] = 0;
    Serial.println("Am receptionat: ");
    Serial.println(s);
    ls = idx;
    idx = 0;
  }
  int v1 = 0;
  int v2 = 0;
  int lt = 0;
  int pl = 0;
  for (int i = 0; i < ls; i++) {
    if (s[i] == "-") {
      lt = 1;
      pl = i;
    }
    if (s[i] == "," && v1 == 0) v1 = i;
    if (s[i] == "," && v1 != 0) v2 = i;
  }
  int nr = 0;
  int ni = 0;
  int nf = 0;
  int nrv[6];
  char com[7];
  int time = 0;
  if (lt == 0) {
    char cn[2];
    for (int j = 0; j < v1; j++)
      cn[j] = s[j];
    nr = atoi(cn);
  } else {
    char n1[2];
    char n2[2];
    for (int j = 0; j < pl; j++)
      n1[j] = s[j];
    for (int j = pl + 1; j < v1; j++)
      n2[j - pl + 1] = s[j];
    ni = atoi(n1);
    nf = atoi(n2);
    nr = ni;
    for (int j = 0; j < nf - ni + 1; j++) {
      nrv[j] = nr;
      nr++;
    }
  }
  /* 
  blink(ledPin);
  blink(ledPin2);
  fadein(ledPin);
  fadeout(ledPin);
  fadein(ledPin2);
  fadeout(ledPin2);
  */
}
