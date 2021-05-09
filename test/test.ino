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

int tictac[10];
boolean s2_flag,s3_flag ,s4_flag ,s5_flag ,s6_flag ,s7_flag ,s8_flag ,s9_flag ,s10_flag,winner_flag ;

int count = 0 ;
int winner = 0 ;
int P1_points =0 , P2_points = 0 ;
char sx,control ;
int nof=0;

int led[9][2]={};
int buzz=1;
int result;
int temp,c=22;
void setup() 
{
  
s2_flag = s3_flag = s4_flag = s5_flag = s6_flag = s7_flag = s8_flag = s9_flag = s10_flag = winner_flag = false ; 

for(int i =0 ; i < 9 ; i++) //clearing the array on reset
tictac[i] = 0 ;

Serial.begin(9600);
for(int temp=0;temp<=8;temp++)
{
  led[temp][0]=c++;
  led[temp][1]=c++;
  pinMode(led[temp][0],OUTPUT);
  pinMode(led[temp][1],OUTPUT);
}
 for(int set=0;set<9;set++)
{
  digitalWrite(led[set][0],HIGH);
  digitalWrite(led[set][1],HIGH);
}
digitalWrite(22,1);
digitalWrite(23,1);

}
//void loop()
//{
//  
//}

void loop()
{
  

key=keypad.getKey();



if(key =='1' && s2_flag == false ) 
{ Serial.println(key);
  s2_flag = true ;
  count ++;
  if(count % 2 == 0 )
  {
  tictac[0] = 5 ; // O
  digitalWrite(led[0][0],LOW);
  digitalWrite(led[0][1],HIGH);

  }
  else
  {
  tictac[0] = 1 ;
  digitalWrite(led[0][0],HIGH);
  digitalWrite(led[0][1],LOW);
   
  }
}

else if(key == '2' && s3_flag == false ) 
{  Serial.println(key);
  s3_flag = true ;
  count ++ ;
  if(count % 2 ==0 )
  {
  tictac[1] = 5 ; // O
  digitalWrite(led[1][0],LOW);
  digitalWrite(led[1][1],HIGH);

  }
  else
  { 
  tictac[1] = 1 ; // X
  digitalWrite(led[1][0],HIGH);
  digitalWrite(led[1][1],LOW);

  }
}

else if(key =='3' && s4_flag == false ) 
{  Serial.println(key);
  s4_flag = true ;
  count ++ ;
  if(count % 2 == 0 )
  {
  tictac[2] = 5 ; // O
  digitalWrite(led[2][0],LOW);
  digitalWrite(led[2][1],HIGH);

  }
  else
  {
  tictac[2] = 1 ; // X
  digitalWrite(led[2][0],HIGH);
  digitalWrite(led[2][1],LOW);

  }
}

else if(key == '4' && s5_flag == false ) 
{  Serial.println(key);
  s5_flag = true ;
  count ++ ;
  if(count % 2 == 0 )
  {
  tictac[3] = 5 ; // O
  digitalWrite(led[3][0],LOW);
  digitalWrite(led[3][1],HIGH);

  }
  else
  {
  tictac[3] = 1 ; // X
  digitalWrite(led[3][0],HIGH);
  digitalWrite(led[3][1],LOW);

  }
}

else if(key =='5' && s6_flag == false ) 
{  Serial.println(key);
  s6_flag = true ;
  count ++ ;
  if(count % 2 == 0 )
  {
  tictac[4] = 5 ; // O
  digitalWrite(led[4][0],LOW);
  digitalWrite(led[4][1],HIGH);

  }
  else
  {  
  tictac[4] = 1 ; // X
  digitalWrite(led[4][0],HIGH);
  digitalWrite(led[4][1],LOW);

  }
}

else if(key =='6' && s7_flag == false ) 
{  Serial.println(key);
  s7_flag = true ;
  count ++ ;
  if(count % 2 ==0 )
  {
  tictac[5] = 5 ; // O
  digitalWrite(led[5][0],LOW);
  digitalWrite(led[5][1],HIGH);

  }
  else
  {
  tictac[5] = 1 ; // X
  digitalWrite(led[5][0],HIGH);
  digitalWrite(led[5][1],LOW);

  }
}

else if(key =='7' && s8_flag == false ) 
{ Serial.println(key);
  s8_flag = true ;
  count ++ ;
  if(count % 2 == 0 )
  {
  tictac[6] = 5 ; // O
  digitalWrite(led[6][0],LOW);
  digitalWrite(led[6][1],HIGH);

  }
  else
  {
  tictac[6] = 1 ; // X
  digitalWrite(led[6][0],HIGH);
  digitalWrite(led[6][1],LOW);

  }
}

else if(key =='8' && s9_flag == false ) 
{Serial.println(key);
  s9_flag = true ;
  count ++ ;
  if(count % 2 == 0 )
  {
  tictac[7] = 5 ; // O
  digitalWrite(led[7][0],LOW);
  digitalWrite(led[7][1],HIGH);

  }
  else
  {
  tictac[7] = 1 ; // X
  digitalWrite(led[7][0],HIGH);
  digitalWrite(led[7][1],LOW);

  }
}

else if(key =='9' && s10_flag == false ) 
{Serial.println(key);
  s10_flag = true ;
  count ++ ;
  if(count % 2 == 0 )
  {
  tictac[8] = 5 ; // O
  digitalWrite(led[8][0],LOW);
  digitalWrite(led[8][1],HIGH);

  }
  else
  {
  tictac[8] = 1 ; // X
  digitalWrite(led[8][0],HIGH);
  digitalWrite(led[8][1],LOW);

  }
}



winner = check();
if(winner == 1)
{ 
  delay(1000);
  Serial.println("Player 1 wins ! "); 
  P1_points ++ ;
  delay(200);
  winner_flag = true  ;
  nof++;
}
else if(winner == 2)
{
  delay(1000);
  Serial.println("Player 2 wins ! ");
  P2_points ++ ;

  delay(2000);
  winner_flag = true ;
  nof++;
}
else if(winner == 0 && count == 9 )
{
  delay(1000);
  Serial.println(" Draw match !! ") ;

  delay(200);
  winner_flag = true ;
  nof++;
}

if(winner_flag == true )
{


  control = 'r' ;
  if(control == 'r' ) 
  {
  Serial.println("resetting..");

  //resett();

  }
}

if(nof==5)
{
  if(P1_points>P2_points)
  {
  digitalWrite(buzz,HIGH);
  delay(1000);
  }
  else
  {
     digitalWrite(buzz,HIGH);
     delay(1000);
     digitalWrite(buzz,LOW);
     delay(500);
     digitalWrite(buzz,HIGH);
  }
}

}//loop

int check ()
{
    

result=row_check(tictac);
if(result==1)
return 1;
else if(result==2)
return 2;
//else if(count==9&&result==0) return 0;
result=col_check(tictac);
if(result==1)
return 1;
else if(result==2)
return 2;
//else if(count==9&&result==0) return 0;
result=cross_check(tictac);
if(result==1)
return 1;
else if(result==2)
return 2;
//else if(count==9&&result==0) return 0;      
if(count==9)
return 0;
}
int row_check(int t[])
{
  int i=0;
  for(i=0;i<=6;i=i+3)
  {
    if((t[i]+t[i+1]+t[i+2])==3)
    {
      //blinker(i,i+1,i+3,1);
      Serial.println("row");
      return 1;
    }
    else if((t[i]+t[i+1]+t[i+2])==15)
    {
      //blinker(i,i+1,i+2,2);
      Serial.println("row1");
      return 2;
    }
    
  }
}
int col_check(int t[])
{
  int i=0;
  for(i=0;i<=2;i=i++)
  {
    if((t[i]+t[i+3]+t[i+6])==3)
    {
      //blinker(i,i+3,i+6,1);
      Serial.println("col");
      return 1;
    }
    else if((t[i]+t[i+3]+t[i+6])==15)
    {
      //blinker(i,i+3,i+6,2);
      Serial.println("col1");
      return 2;
    }
  }
}

int cross_check(int tictac[])
{
  if(((tictac[0]+tictac[4]+tictac[8]) == 3 ))
   {
    //blinker(0,4,8,1);
    Serial.println("cross");
    return 1;
   }
  else if((tictac[0]+tictac[4]+tictac[8]) == 15 )  
   {
    //blinker(0,4,8,2);
    Serial.println("cross1");
    return 2;
   }
  else if((tictac[2]+tictac[4]+tictac[6]) == 3 )
  {
    //blinker(2,4,6,1);
    Serial.println("cross2");
    return 1;
  }
  else if((tictac[2]+tictac[4]+tictac[6]) == 15 )
  {
    // blinker(2,4,6,2);
    Serial.println("cross3");
     return 2;
  }
 
   
  }

//void blinker(int h,int j,int k,int win)
//{ if(win!=0)
//  {
//  digitalWrite(led[h][win],LOW);
//  digitalWrite(led[j][win],LOW);
//  digitalWrite(led[k][win],LOW);
//  delay(1000);
//  digitalWrite(led[h][win],HIGH);
//  digitalWrite(led[j][win],HIGH);
//  digitalWrite(led[k][win],HIGH);
//  }
//  else
//  { int i=0;
//    for(i=0;i<9;i++)
//    {
//      digitalWrite(led[i][0],LOW);
//    }
//    delay(1000);
//    for(i=0;i<9;i++)
//    {
//      digitalWrite(led[i][0],HIGH);
//      
//    }    
//  }
//}


void resett()
{
for(int set=0;set<9;set++)
{
  digitalWrite(led[set][0],HIGH);
  digitalWrite(led[set][1],HIGH);
}
s2_flag = s3_flag = s4_flag = s5_flag = s6_flag = s7_flag = s8_flag = s9_flag = s10_flag = winner_flag = false ; 
for(int i = 0 ; i < 9 ; i++) //clearing the array on reset
tictac[i] = 0 ; 
count = 0 ;
winner = 0 ;


}
