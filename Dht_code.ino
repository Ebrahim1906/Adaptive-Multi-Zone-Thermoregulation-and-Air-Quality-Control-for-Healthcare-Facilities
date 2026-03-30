#include <LiquidCrystal.h>
const int rs= 12, en= 11, d4= 5, d5= 4, d6= 3, d7= 2;
LiquidCrystal lcd(rs, en,d4, d5, d6, d7);
const int trigPin = 6;
const int echoPin = 8;

float duration_us, distance_cm;
void setup() {
lcd.begin(16,2);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
}
void loop() {
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
duration_us = pulseIn(echoPin, HIGH);

distance_cm = 0.0348* duration_us/2; //Find out how

lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Distance: ");
lcd.print(distance_cm);
Serial.print("Distance: ");
Serial.println(distance_cm);
delay(1000);
}