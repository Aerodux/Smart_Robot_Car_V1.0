// define IO pin

#define ENA 5
#define IN1 6
#define IN2 7

#define ENB 10
#define IN3 8
#define IN4 9

void setup() {
  pinMode(IN1, OUTPUT); //set IO pin mode OUTPUT
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
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
void loop() {
  // put your main code here, to run repeatedly:
 right_forward(127);
 left_forward(127);
 delay(2000);
 right_forward(150);
 left_backward(150);
 delay(850);
 right_forward(127);
 left_forward(127);
 delay(2000);
 left_forward(150);
 right_backward(150);
 delay(850);
}
