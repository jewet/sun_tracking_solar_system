

#include<Servo.h>     //   library for servo motor 

Servo rf; // define Vertival servo
 // define horizontal servo           
int start1 = 90; // initially starting from 90 degree
int start2 = 90; 
int buzzer=4;  //for read data from LDR1         
      
int a = 15;          

void setup() 
{ 
  s.attach(9); //connect vertical servo to pin 9 of arduino  
  sh.attach(10);  //connect horizontal servo to pin 10 of arduino 
  pinMode(buzzer, OUTPUT);  //define LDR as input
  
  rf.write(start1); //it will start servo from 90 when we reset system
   
  delay(2000);          
} 
void loop() 
{ 
  int LDR1 = analogRead(L1); //read value from LDR
  int LDR2 = analogRead(L2); 
  int LDR3 = analogRead(L3);
  int LDR4 = analogRead(L4);
  int plus14 =(LDR1+LDR4);  //average of two corner LDR
  int plus23 =(LDR2+LDR3);
  int plus12 =(LDR1+LDR2);
  int plus34 =(LDR3+LDR4);
  int diff1= abs(plus14 - plus23);  // difference to take proper value
  int diff2= abs(plus23 - plus14);
  int diff3= abs(plus12 - plus34);  
  int diff4= abs(plus34 - plus12);
  
  if((diff1 <= a) || (diff2 <= a))
 {
   //difference is less then 15 so do nothing
  } 
else 
{    
    if(plus14 > plus23) //move vertical servo in lessthen 90 degree
    {
     start2= --start2;   
    }
 if(plus14 < plus23) 
    {
      start2 = ++start2;  //move vertical servo in greaterthen 90 degree
    }
  }
       if(plus12 > plus34 )
  {
    start1= --start1;   // move horizontal servo in lessthen 90 degree
  }
  if(plus12 < plus34)
  {
   start1= ++start1;  //move horizontal servo in greaterthen 90 degree
   }
   s.write(start1);
  sh.write(start2);
   delay(100);
}
