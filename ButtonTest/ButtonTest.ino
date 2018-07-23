const int button = 12;

void setup() {
    Serial.begin(9600);
    pinMode(button, INPUT);
}

void loop() {
  if(digitalRead(button) == LOW){
    Serial.println("LOW");
  }
  else if(digitalRead(button) == HIGH){
      Serial.println("HIGH");
    }
    delay(500);
}
