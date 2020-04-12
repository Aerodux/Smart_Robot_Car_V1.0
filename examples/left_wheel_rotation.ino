
//     Left motor truth table
//Here are some handy tables to show the various modes of operation.
//  ENB         IN3             IN4         Description  
//  LOW   Not Applicable   Not Applicable   Motor is off
//  HIGH        LOW             LOW         Motor is stopped (brakes)
//  HIGH        LOW             HIGH        Motor is on and turning forwards
//  HIGH        HIGH            LOW         Motor is on and turning backwards
//  HIGH        HIGH            HIGH        Motor is stopped (brakes)      

// define IO pin
#define ENB 10
#define IN3 8
#define IN4 9

//init the car
void setup() {
  pinMode(IN3, OUTPUT); //set IO pin mode OUTPUT
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  digitalWrite(ENB, HIGH);  //Enable right motor       
}

//main loop
void loop() {
  digitalWrite(IN3, LOW);      
  digitalWrite(IN4, HIGH);//Left wheel turning forwards
  delay(500);             //delay 500ms
  digitalWrite(IN3, LOW);      
  digitalWrite(IN4, LOW); //Left wheel stoped
  delay(500);
  digitalWrite(IN3, HIGH);      
  digitalWrite(IN4, LOW); //Left wheel turning backwards
  delay(500);
  digitalWrite(IN3, HIGH);      
  digitalWrite(IN4, HIGH); //Left wheel stoped
  delay(500);
}
