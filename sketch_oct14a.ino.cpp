#include <Arduino.h>
#line 1 "C:\\Users\\RRL\\AppData\\Local\\Temp\\.arduinoIDE-unsaved2025914-1108-1ifznts.p64ki\\sketch_oct14a\\sketch_oct14a.ino"
#line 1 "C:\\Users\\RRL\\AppData\\Local\\Temp\\.arduinoIDE-unsaved2025914-1108-1ifznts.p64ki\\sketch_oct14a\\sketch_oct14a.ino"
void setup();
#line 8 "C:\\Users\\RRL\\AppData\\Local\\Temp\\.arduinoIDE-unsaved2025914-1108-1ifznts.p64ki\\sketch_oct14a\\sketch_oct14a.ino"
void blink(int ledPin);
#line 15 "C:\\Users\\RRL\\AppData\\Local\\Temp\\.arduinoIDE-unsaved2025914-1108-1ifznts.p64ki\\sketch_oct14a\\sketch_oct14a.ino"
void fadein(int ledPin);
#line 21 "C:\\Users\\RRL\\AppData\\Local\\Temp\\.arduinoIDE-unsaved2025914-1108-1ifznts.p64ki\\sketch_oct14a\\sketch_oct14a.ino"
void fadeout(int ledPin);
#line 28 "C:\\Users\\RRL\\AppData\\Local\\Temp\\.arduinoIDE-unsaved2025914-1108-1ifznts.p64ki\\sketch_oct14a\\sketch_oct14a.ino"
void loop();
#line 1 "C:\\Users\\RRL\\AppData\\Local\\Temp\\.arduinoIDE-unsaved2025914-1108-1ifznts.p64ki\\sketch_oct14a\\sketch_oct14a.ino"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

 int ledPin = 9;
 int ledPin2 = 11;
 void blink(int ledPin) {
  digitalWrite(ledPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
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
  blink(ledPin);
  blink(ledPin2);
  fadein(ledPin);
  fadeout(ledPin);
  fadein(ledPin2);
  fadeout(ledPin2);
}

