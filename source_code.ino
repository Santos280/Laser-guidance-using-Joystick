//by Shubham Santosh

#include<Servo.h>
 Servo s1,s2;  
 
void setup() {
  s1.attach(10); //defining the pins for the servo's
  s2.attach(11);
  pinMode(12,OUTPUT); //Laser Output
  pinMode(2,INPUT);   //SW pin status
  digitalWrite(2,HIGH);
  Serial.begin(9600);  //Start Seria Monitor
 
  // put your setup code here, to run once:
}
int p1=90,p2=90;   // initial position of both servos in degree
void loop() 
{
  
  int t1=0,t2=0;  //rate of increment/decrement of angle
  int a=analogRead(A0); // reads analog x-y readings of joystick
  int b=analogRead(A1);

  //when joystick is moved away from the center
  if(a<=450 or a>=550)
  {
    t1=map(a,0,1023,10,-10);
    p1=change(p1,t1);  //change the servo's current position
   
  }
  if(b<=450 or b>=550)
  {
    t2=map(b,0,1023,-10,10);
    p2=change(p2,t2);  //change the servo's current position

  }
   s1.write(p1); // rotate the servo's if the joystick is moved
   s2.write(p2);
  if(digitalRead(2)==LOW)  //reads the status of joystick's SW pin
  digitalWrite(12,HIGH);
  else
  digitalWrite(12,LOW);
  
  //print the analog readings of joystick and servo degree(For Verification)
  Serial.print("s1:");
  Serial.print(a);
  Serial.print("\t");
  Serial.print("s2:");
  Serial.print(b);
  Serial.print("\t");
  Serial.print("t1:");
  Serial.print(t1);
  Serial.print("\t");
  Serial.print("t2:");
  Serial.print(t2);
  Serial.print("\t");
  Serial.print("pos1: ");
  Serial.print(p1);
  Serial.print("pos2: ");
  Serial.println(p2);
  
  delay(70);          // for Stability
}

int change(int pos,int t)
{
    pos=pos+t;                   // Increment/decrement the Servo angle
    if (pos>180)                //  maximum anlgle of servo is 180 degree
    pos=180;
    if(pos<0)                  // minimum angle of servo is 0 degree
    pos=0;
    return(pos);               //return the change of position
}