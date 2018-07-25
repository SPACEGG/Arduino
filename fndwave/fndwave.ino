#include <stdlib.h>
const int trig = 14;
const int echo = 15;
const int fndled[7] = {6, 8, 4, 3, 2, 7, 5};
const int number[4] = {9, 10, 11, 12};
const int fndArray[10][7] = {
  {1,1,1,1,1,1,0},    //0
  {0,1,1,0,0,0,0},    //1
  {1,1,0,1,1,0,1},    //2
  {1,1,1,1,0,0,1},    //3
  {0,1,1,0,0,1,1},    //4
  {1,0,1,1,0,1,1},    //5
  {1,0,1,1,1,1,1},    //6
  {1,1,1,0,0,1,0},    //7
  {1,1,1,1,1,1,1},    //8
  {1,1,1,1,0,1,1}     //9
};

int Change(int bol){ return (bol == 0) ? LOW : HIGH; }

void NumLight(int value){
  for(int i = 0; i < 7; i++){ digitalWrite(fndled[i], Change(fndArray[value][i])); }
}

void SetNumber(int num){
  for(int i  = 0; i < 4; i++){
    if(i == num){ digitalWrite(number[i],LOW); }
    else{ digitalWrite(number[i],HIGH); }
  }
}

void Light(int value){
  int a[4];
  for(int i = 3; i > -1; i--){
    a[i] = value % 10;
    value /= 10;
  }
  for(int i = 0; i < 4; i++){
    SetNumber(i);
    NumLight(a[i]);
    delay(3);
  }
}

void setup() {
  Serial.begin(9600); 
  pinMode(fndled[0], OUTPUT);
  pinMode(fndled[1], OUTPUT);
  pinMode(fndled[2], OUTPUT);
  pinMode(fndled[3], OUTPUT);
  pinMode(fndled[4], OUTPUT);
  pinMode(fndled[5], OUTPUT);
  pinMode(fndled[6], OUTPUT);
  pinMode(number[0], OUTPUT);
  pinMode(number[1], OUTPUT);
  pinMode(number[2], OUTPUT);
  pinMode(number[3], OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trig, HIGH);        
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = ((float)(340 * duration) / 10000) / 2;
  for(int i = 0; i < 30; i++){
    Light(distance);
    delay(5);
  }
}
