const int trig = 9;
const int echo = 10;
const int buz = 3;
void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buz,OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
int dur,dist;

digitalWrite(trig,HIGH);
delay(1);
digitalWrite(trig,LOW);

dur = pulseIn(echo,HIGH);
dist = (dur/2)/29.1;

if(dist <= 50 && dist >=0){
  digitalWrite(buz,HIGH);
  }
else{
  digitalWrite(buz,LOW);
}
Serial.println(dist);
delay(60);
}
