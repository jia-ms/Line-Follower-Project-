#include <AFMotor.h>
#define Speed 50
// AF_DCMotor M1(1);
AF_DCMotor M2(2);
AF_DCMotor M3(3);
// AF_DCMotor M4(4);
int IR1 = A0;
int IR2 = A1;
int IR3 = A2;
int IR4 = A3;
void setup() 
{
  Serial.begin(9600);
  // M1.setSpeed(Speed);
  M2.setSpeed(Speed);
  M3.setSpeed(Speed);
  // M4.setSpeed(Speed);c:\Users\SantoshKumar\Documents
    pinMode(IR1, INPUT);
    pinMode(IR2, INPUT);
    pinMode(IR3, INPUT);
    pinMode(IR4, INPUT);
  
}
void loop() 
{
  int S1 = digitalRead(IR1);
  int S2 = digitalRead(IR2);
  int S3 = digitalRead(IR3);
  int S4 = digitalRead(IR4);

  if (S1==0 && S2==0 && S3==0 && S4==0)
  {
    forward();
  }
  else if(S1==1 && S2==1 && S3==0 && S4==0)
  {
     right();
  }
  else if(S1==0 && S2==0 && S3==1 && S4==1)
  {
     left();
  }
  else if(S1==1 && S2==1 && S3==1 && S4==1)
  {
     Stop();
  }
  else
  forward();
 }

//void backward() 
//{
  // M1.run(FORWARD);
  //M2.run(BACKWARD);
  //M3.run(BACKWARD);
  // M4.run(FORWARD);
//}
void forward() 
{
  // M1.run(BACKWARD);
  M2.run(FORWARD);
  M3.run(FORWARD);
  // M4.run(BACKWARD);
}
void right() 
{
  // M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(FORWARD);
  // M4.run(FORWARD);
}
void left() 
{
  // M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(BACKWARD);
  // M4.run(BACKWARD);
}
void Stop() 
{
  // M1.run(RELEASE);
  M2.run(RELEASE);
  M3.run(RELEASE);
  // M4.run(RELEASE);
}
