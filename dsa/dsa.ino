

#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,7,8}; //connect to the column pinouts of the keypad
char key;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int count=0;


void setup(){
  // Robojax 4x3 keypad test
  Serial.begin(9600);
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(24,OUTPUT);
  
  digitalWrite(23,1);
  digitalWrite(22,1);
  digitalWrite(24,1);
  digitalWrite(25,1);
 }
  
void loop(){
  // Robojax 4x3 keypad test
  
  Serial.print("key= ");Serial.println(key);
  key = keypad.getKey();
    // just print the pressed key
   if (key){
    Serial.println(key);
  } 
   if(key=='1'){
  count++;
  if(count%2!=0)
  {
   digitalWrite(23,1);
  digitalWrite(22,0);
  }
  else
  {
       digitalWrite(23,0);
  digitalWrite(22,1);
  }
  key=0;
 
   }
   else if(key=='2')
   {
    count++;
 if(count%2!=0)
  {
   digitalWrite(24,0);
  digitalWrite(25,1);
  }
  else
  {
       digitalWrite(24,1);
  digitalWrite(25,0);
  }
  key=0;
   }
   

}
