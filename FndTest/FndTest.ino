const int fndled[8] = {5, 6, 9, 8, 7, 4, 3, 10};

const int fndArray[10][7] = {
  {1,1,1,1,1,1,0},    //0
  {0,1,1,0,0,0,0},    //1
  {1,1,0,1,1,0,1},    //2
  {1,1,1,1,0,0,1},    //3
  {0,1,1,0,0,1,1},    //4
  {1,0,1,1,0,1,1},    //5
  {1,0,1,1,1,1,1},    //6
  {1,1,1,0,0,1,0},    //7
  {1,1,1,1,1,1,1},     //8
  {1,1,1,1,0,1,1}     //9
};

void NumLight(int* farray){
  for(int i = 0; i < 7; i++){
    digitalWrite(fndled[i], Change(farray[i]));
  }
}

void Clear(){
  for(int i = 0; i < 8; i++){
    digitalWrite(fndled[i], LOW);
  }
}

int Change(int bol){
  return (bol == 0) ? LOW : HIGH;
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
  pinMode(fndled[7], OUTPUT);
}

void loop() {
  for(int i = 0; i < 10; i++){
    NumLight(fndArray[i]);
    delay(500);
    Clear();
  }
}
