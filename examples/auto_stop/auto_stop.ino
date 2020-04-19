// define IO pin
#include <Servo.h>

#define ENA 5
#define IN1 6
#define IN2 7

#define ENB 10
#define IN3 8
#define IN4 9

Servo myservo;

int Echo = A4;  
int Trig = A5; 

int Distance_test() {
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);   
  float Fdistance = pulseIn(Echo, HIGH);  
  Fdistance= Fdistance / 58;       
  return (int)Fdistance;
}  

void stop() {

  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
}

void right_forward(int speed) {

  if (speed >=0 && speed<=255) {

     analogWrite(ENA, speed);
  }
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void left_forward(int speed) {

  if (speed >=0 && speed<=255) {

     analogWrite(ENB, speed);
  }
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void right_backward(int speed) {
  
  if (speed >=0 && speed<=255) {

     analogWrite(ENB, speed);
  }
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void left_backward(int speed) {

  if (speed >=0 && speed<=255) {

     analogWrite(ENB, speed);
  }
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void setup() {
  pinMode(IN1, OUTPUT); //set IO pin mode OUTPUT
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  myservo.attach(3,700,2400);  // attach servo on pin 3 to servo object
  myservo.write(90);  //setservo position according to scaled value 
  
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT); 
  
  Serial.begin(9600); // open the serial port at 9600 bps:
}

void loop() {
  // put your main code here, to run repeatedly:
 while (Distance_test() > 10){
  left_forward(127);
  right_forward(127);
 }
 stop();
}
