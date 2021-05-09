const int TrigPin = 9; //Trigger   
  const int EchoPin = 10; //Echo    
  int buz=3; //Buzzer  
  void setup() {   
  Serial.begin(9600);   
  pinMode(buz, OUTPUT);   
  }   
  void loop()   
  {   
  long duration, cm;   
  pinMode(TrigPin, OUTPUT);   
  digitalWrite(TrigPin, LOW);   
  delayMicroseconds(2);   
  digitalWrite(TrigPin, HIGH);   
  delayMicroseconds(5);   
  digitalWrite(TrigPin, LOW);   
  pinMode(EchoPin, INPUT);   
  duration = pulseIn(EchoPin, HIGH);   
  cm = microsecondsToCm(duration);   
  if(cm<=50 && cm>0)   
  {   
  int d= map(cm, 1, 100, 20, 2000);   
  digitalWrite(buz, HIGH);   
  delay(100);   
  digitalWrite(buz, LOW);   
  delay(d);  
  }   
  Serial.print(cm);    
  Serial.print("cm");   
  Serial.println();   
  delay(100);   
  }   
  long microsecondsToCm(long microseconds)   
  {   
  return microseconds / 29 / 2;   
  } 
