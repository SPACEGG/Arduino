int Trig_Pin = 14;      
int Echo_Pin = 15;
 
void setup(){
  Serial.begin(9600);       
  // 시리얼 통신을 9600 의 통신속도로 시작한다.      
  pinMode(Echo_Pin, INPUT);  
  // Echo_Pin 은 수신부이므로 입력핀으로 설정
  pinMode(Trig_Pin, OUTPUT);  
  // Trig_Pin 은 송신부이므로 출력핀으로 설정  
}
 
void loop(){
 
  long duration, distance;
  // 송신후 수신할때까지의 시간을 duration 이라는 변수라고 하자.
  // 물체까지의 거리를 distance 라는 변수라고 하자.
  
  digitalWrite(Trig_Pin, HIGH);        
  delayMicroseconds(10);
  digitalWrite(Trig_Pin, LOW);
  // Trig_Pin(송신부)에 HIGH 신호를 주면 당연히 초음파가 나가겠다.
  // 그 초음파는 delayMicroseconds() 라는 함수에 의해 10 마이크로 초만큼동안만 유지가 된다.
  // 10 마이크로 초 이후에는 송신부에 LOW 신호를 줘서 초음파를 끈다.
  
  duration = pulseIn(Echo_Pin, HIGH);
  // 수신부인 Echo_Pin 이 HIGH 상태를 유지했던 시간을 duration 이라는 변수에 저장한다.
  
  distance = ((float)(340 * duration) / 10000) / 2; 
  // duration 을 이용해 거리 distance 를 계산한다.
  // 이때 2로 나눠주는 이유는 초음파가 갔다가 다시 오는 왕복운동을 했기 때문에
  // 2 로 나눠주면 편도거리가 나온다.
 
  Serial.print("거리:");         
  Serial.print(distance);
  Serial.println("cm");
  // 시리얼모니터에 물체와 초음파 센서간 거리를 표시        
 
  delay(500);
  // 그 정보는 0.5초마다 출력이 된다.
 
} 


