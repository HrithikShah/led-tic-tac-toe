void setup() {
  // put your setup code here, to run once:
pinMode(53,OUTPUT);

pinMode(47,OUTPUT);


}

void loop() {
  // put your main code here, to run repeated
 digitalWrite(53,LOW);
  digitalWrite(47,HIGH);
  delay(2000);
 digitalWrite(47,LOW);
 digitalWrite(53,HIGH);
 delay(2000);
  digitalWrite(47,HIGH);
  delay(2000);
 // digitalWrite(47,LOW);
   //digitalWrite(53,LOW);
   //delay(2000);
  
  
  
}
