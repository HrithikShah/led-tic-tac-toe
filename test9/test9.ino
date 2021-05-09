#include<Keypad.h>
#include<LiquidCrystal.h>

const int rs = 42, en = 43, d4 = 13, d5 = 12, d6 = 11, d7 = 10;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


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

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


int tictac[10];
boolean s2_flag,s3_flag ,s4_flag ,s5_flag ,s6_flag ,s7_flag ,s8_flag ,s9_flag ,s10_flag,winner_flag ;
char key;
int count = 0 ;
int winner = 0 ;
int P1_points =0 , P2_points = 0 ;
char sx,control ;
int nof=0;

int led[9][2]={};
int buzz=20;
int result,cou=0;
int temp,c=22;
void setup() 
{
  
s2_flag = s3_flag = s4_flag = s5_flag = s6_flag = s7_flag = s8_flag = s9_flag = s10_flag = winner_flag = false ; 
lcd.begin(16, 2);
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
pinMode(buzz,OUTPUT);
}

void loop()
{
  

key=keypad.getKey();
Serial.println(key);


if(key =='1' && s2_flag == false ) 
{
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
{
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
{
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
{
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
  digitalWrite(led[3][0],1);
  digitalWrite(led[3][1],0);

  }
}

else if(key =='5' && s6_flag == false ) 
{
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
{
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
{
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
{
  s9_flag = true ;
  count ++ ;
  if(count % 2 == 0 )
  {
  tictac[7] = 5 ; // O
  digitalWrite(led[7][0],0);
  digitalWrite(led[7][1],1);

  }
  else
  {
  tictac[7] = 1 ; // X
  digitalWrite(led[7][0],1);
  digitalWrite(led[7][1],0);

  }
}

else if(key =='9' && s10_flag == false ) 
{
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
else if(winner ==0 && count == 9 )
{
  delay(1000);
  Serial.println(" Draw match !! ") ;

  delay(200);
  winner_flag = true ;
  nof++;
  }

if(winner_flag == true )
{ for(int i=22;i<=39;i++)
   {
    digitalWrite(i,1);
   }
  if(winner==1)
  {
    
    
    for(int i=23;i<=39;i=i+2)
    {
      digitalWrite(i,0);
    }
    delay(1000);
    for(int i=23;i<=39;i=i+2)
    {
      digitalWrite(i,1);
    }
    
  if(nof!=5)
  {
      digitalWrite(buzz,HIGH);
  delay(400);
  digitalWrite(buzz,LOW);   
  }
  }
  else  if(winner==2)
  {
  
   
    for(int i=22;i<=38;i=i+2)
    {
      digitalWrite(i,0);
    }
    delay(1000);
    for(int i=22;i<=38;i=i+2)
    {
      digitalWrite(i,1);
    } 
   
      digitalWrite(buzz,HIGH);
  delay(400);
  digitalWrite(buzz,LOW);   
  delay(300);
  digitalWrite(buzz,1); 
  delay(400);
  digitalWrite(buzz,0);
  }
//  digitalWrite(buzz,HIGH);
//  delay(1000);
//  digitalWrite(buzz,LOW);

  control = 'r' ;
  if(control == 'r' ) 
  {
  Serial.println("resetting..");

  resett();
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(P1_points);
  lcd.setCursor(2,1);
  lcd.print(P2_points);
  
  }
}

if(nof==5)
{ 
  
  if(P1_points>P2_points)
  {
  
  lcd.setCursor(0,1);
  lcd.print("player1 wins!");
  delay(1000);
 for(int j=0;j<4;j++)
 {
  for(int i=23;i<=27;i=i+2,cou++)
  {
    if(cou%2!=0)
    {
      digitalWrite(i,LOW);
            digitalWrite(i+6,LOW);
                  digitalWrite(i+12,LOW);
                  delay(400);
                  
      digitalWrite(i,HIGH);
            digitalWrite(i+6,HIGH);
                  digitalWrite(i+12,HIGH);
    }
    else
    {
      
      digitalWrite(i,LOW);
            digitalWrite(i+12,LOW);
                  digitalWrite(i+24,LOW);
                  delay(400);
                  
      digitalWrite(i,HIGH);
            digitalWrite(i+12,HIGH);
                  digitalWrite(i+24,HIGH);
    }
  }
 }
  }
  else if(P1_points<P2_points)
  { lcd.setCursor(0,1); 
    lcd.print("player2 wins!");
//     digitalWrite(buzz,HIGH);
//     delay(1000);
//     digitalWrite(buzz,LOW);
//     delay(500);
//     digitalWrite(buzz,HIGH);
//     delay(300);
//     digitalWrite

 for(int j=0;j<4;j++)
 {
 for(int i=22;i<=26;i=i+2,cou++)
  {
    if(cou%2!=0)
    {
      digitalWrite(i,LOW);
            digitalWrite(i+6,LOW);
                  digitalWrite(i+12,LOW);
                  delay(400);
                  
      digitalWrite(i,HIGH);
            digitalWrite(i+6,HIGH);
                  digitalWrite(i+12,HIGH);
    }
    else
    {
      
      digitalWrite(i,LOW);
            digitalWrite(i+12,LOW);
                  digitalWrite(i+24,LOW);
                  delay(400);
                  
      digitalWrite(i,HIGH);
            digitalWrite(i+12,HIGH);
                  digitalWrite(i+24,HIGH);
    }
  }
 }
  }
  else if(P1_points==P2_points)
  {
   lcd.setCursor(0,1); 
    lcd.print("draw!!"); 
  }
  
  P1_points=0;
  P2_points=0;
  nof=0;
  delay(3000);
  lcd.clear();
  
}

}//loop

int check ()
{
  if( ((tictac[0]+tictac[1]+tictac[2]) == 3 ) ||
      ((tictac[3]+tictac[4]+tictac[5]) == 3 ) ||
      ((tictac[6]+tictac[7]+tictac[8]) == 3 ) ||
      ((tictac[0]+tictac[3]+tictac[6]) == 3 ) ||
      ((tictac[1]+tictac[4]+tictac[7]) == 3 ) ||
      ((tictac[2]+tictac[5]+tictac[8]) == 3 ) ||
      ((tictac[0]+tictac[4]+tictac[8]) == 3 ) ||
      ((tictac[2]+tictac[4]+tictac[6]) == 3 ) )
      return 1 ;
  else if( ((tictac[0]+tictac[1]+tictac[2]) == 15 ) ||
      ((tictac[3]+tictac[4]+tictac[5]) == 15 ) ||
      ((tictac[6]+tictac[7]+tictac[8]) == 15 ) ||
      ((tictac[0]+tictac[3]+tictac[6]) == 15 ) ||
      ((tictac[1]+tictac[4]+tictac[7]) == 15 ) ||
      ((tictac[2]+tictac[5]+tictac[8]) == 15 ) ||
      ((tictac[0]+tictac[4]+tictac[8]) == 15 ) ||
      ((tictac[2]+tictac[4]+tictac[6]) == 15 ) )
      return 2 ;
  else
      return 0 ;     
//result=row_check(tictac);
//if(result==1)
//return 1;
//else if(result==2)
//return 2;
//else return 0;
//result=col_check(tictac);
//if(result==1)
//return 1;
//else if(result==2)
//return 2;
//else return 0;
//result=cross_check(tictac);
//if(result==1)
//return 1;
//else if(result==2)
//return 2;
//else return 0;      

}
int row_check(int t[])
{
  int i=0;
  for(i=0;i<=6;i=i+3)
  {
    if((t[i]+t[i+1]+t[i+2])==3)
    {
      //blinker(i,i+1,i+3,1);
      return 1;
    }
    else if((t[i]+t[i+1]+t[i+2])==15)
    {
      //blinker(i,i+1,i+2,2);
      return 2;
    }
    else
    {
      //blinker(0,0,0,0);
      return 0;
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
      return 1;
    }
    else if((t[i]+t[i+3]+t[i+6])==15)
    {
      //blinker(i,i+3,i+6,2);
      return 2;
    }
    else
    {
      //blinker(0,0,0,0);
      return 0;
    }
  }
}

int cross_check(int tictac[])
{
  if(((tictac[0]+tictac[4]+tictac[8]) == 3 ))
   {
    //blinker(0,4,8,1);
    return 1;
   }
  else if((tictac[0]+tictac[4]+tictac[8]) == 15 )  
   {
    //blinker(0,4,8,2);
    return 2;
   }
  else if((tictac[2]+tictac[4]+tictac[6]) == 3 )
  {
   // blinker(2,4,6,1);
    return 1;
  }
  else if((tictac[2]+tictac[4]+tictac[6]) == 15 )
  {
     //blinker(2,4,6,2);
     return 2;
  }
  else return 0;
   
  }

void blinker(int h,int j,int k,int win)
{ if(win!=0)
  {
  digitalWrite(led[h][win],LOW);
  digitalWrite(led[j][win],LOW);
  digitalWrite(led[k][win],LOW);
  delay(1000);
  digitalWrite(led[h][win],HIGH);
  digitalWrite(led[j][win],HIGH);
  digitalWrite(led[k][win],HIGH);
  }
  else
  { int i=0;
    for(i=0;i<9;i++)
    {
      digitalWrite(led[i][0],LOW);
    }
    delay(1000);
    for(i=0;i<9;i++)
    {
      digitalWrite(led[i][0],HIGH);
      
    }    
  }
}

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

void displayboard()
{ 
  lcd.setCursor(0, 1);
  lcd.print(P1_points );
  lcd.setCursor(2, 1);
  lcd.print(P2_points );
  lcd.clear();
}
