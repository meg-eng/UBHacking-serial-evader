int trigPin = 9;
int echoPin = 10;
int led = 7;
// set up the general pins for the motor 
int enRight = 3;
int rightA = 2;
int rightB = 4;
// setup left motors 
int enLeft = 11; 
int leftA = 12;
int leftB = 13;

void forward(int pinA,int pinB);
void stop(int pinA,int pinB);
//backward
void backward(int pinA,int pinB);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);// opens up serial port begins communication bt arduino and sensor, sets out data rate at 9600 bps
  pinMode(led,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
  // set up motor pins 
  pinMode(enRight,OUTPUT);
  pinMode(rightA,OUTPUT);
  pinMode(rightB,OUTPUT); 

  pinMode(enLeft,OUTPUT);
  pinMode(leftA,OUTPUT);
  pinMode(leftB,OUTPUT);

 //set the enable to HIGH and do not change it 
  digitalWrite(enRight,HIGH); 
  digitalWrite(enLeft,HIGH); 
  
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance; // declare variables 
  digitalWrite(trigPin,HIGH); // turns the trigger on i think 
  delayMicroseconds(1000); // delay for one seconds 
  digitalWrite(trigPin,LOW); // turns the trigger off
  duration = pulseIn(echoPin,HIGH); // sets the duration equal to how long the sound takes to return
  distance = (duration/2)/29.1; // converts the duration to a distance  
  Serial.print(distance); // prints the distance to a 'serial monitor' (what is this?)
  Serial.print("CM"); // prints the units (metric system babeyy)
  delay(10); // delays for 10 ms

  //logic to program the LED subject to change if/when we add speakers
   // if the distance is within 10cm, turn LED on, else turn it off
   if(distance <= 20){
      digitalWrite(led,HIGH);
      //stops
      stop(rightA,rightB);
      stop(leftA,leftB);
      delay(1000);
      //moves backward
      backward(rightA,rightB);
      backward(leftA,leftB);
      delay(1000);
      // turns right?
      forward(rightA,rightB);
      delay(1000);
      //moves forward
      forward(leftA,leftB);
      forward(rightA,rightB);
      
      
   }
   else if(distance > 20){
      digitalWrite(led,LOW);
      forward(rightA,rightB);
      forward(leftA,leftB);
   }

  
  
}
// api motor functions 
  //forward
   void forward( int pinA,int pinB){
    Serial.println("moving Forward");
    digitalWrite(pinA,HIGH);
    digitalWrite(pinB,LOW);
    //delay(1000);
  }

  
  //stop
  void stop(int pinA, int pinB){
    Serial.println("Stopping");
    digitalWrite(pinA,LOW);
    digitalWrite(pinB,LOW);
    //delay(1000);
  }
  

  
  //backward
  void backward(int pinA, int pinB){
    Serial.println("moving Backward");
    digitalWrite(pinA,LOW);
    digitalWrite(pinB,HIGH);
    //delay(1000);
  }

  
  /*
  // put your main code here, to run repeatedly:
  long duration, distance; // declare variables 
  digitalWrite(trigPin,HIGH); // turns the trigger on i think 
  delayMicroseconds(1000); // delay for one seconds 
  digitalWrite(trigPin,LOW); // turns the trigger off
  duration = pulseIn(echoPin,HIGH); // sets the duration equal to how long the sound takes to return
  distance = (duration/2)/29.1; // converts the duration to a distance  
  Serial.print(distance); // prints the distance to a 'serial monitor' (what is this?)
  Serial.print("CM"); // prints the units (metric system babeyy)
  delay(10); // delays for 10 ms
  */
  
  /* motor api*/
  
    /*
   //logic to program the LED subject to change if/when we add speakers
   // if the distance is within 10cm, turn LED on, else turn it off
   if(distance <= 20){
      digitalWrite(led,HIGH);
   }
   else if(distance > 20){
      digitalWrite(led,LOW);
   }
   */
