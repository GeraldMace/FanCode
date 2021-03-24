//variables such as the period of the servo, the initial duty cycle of the servo, and the pins that are reading and sending information
int tperiod = 20000;
int dcspeed = 9;
int dc1 = 6;
int dc2 = 7;
int tcontrol = 1300;
int servo = 10;



void setup() {
  // Setting baud rate
Serial.begin(9600);

//defining dc control for the L298

pinMode(servo, OUTPUT);
pinMode(dcspeed, OUTPUT);
pinMode(dc1, OUTPUT);
pinMode(dc2, OUTPUT);
//setting direction
digitalWrite(dc1, LOW);
digitalWrite(dc2, HIGH);


}

void loop() {
  // two if loops with nesting while loops are running here. They accomplish the same thing but in different directions for the oscillation effect. 


// when the angle is at -30 degrees
 if (tcontrol = 1300){

//runs until angle is at 30 degrees
 while(tcontrol <1800){

  //sets the integer for the raw signal and maps it for the pwm of the dc motor
  int raw = analogRead(0);
  int pwm  = map(raw,0,1023,0,255);
  analogWrite(dcspeed, pwm);

  //maps the duty cycle of servo into an angle. 0-60 is used here for simpler calculations later in processing
  int angle = map(tcontrol,1300,1800,0,60);

  //printing values for processing to read and use
  Serial.print(pwm);
  Serial.print("  ");
  Serial.println(angle);
  

  //the actual control of the servo via manipulating the duty cycle.
  digitalWrite(servo, HIGH);
  delayMicroseconds(tcontrol);
  digitalWrite(servo, LOW);
  delayMicroseconds(tperiod-tcontrol);


  //increments to change the angle
  tcontrol = tcontrol + 2;
  
 }
 } 

 //again, all the code here is the same as the previous loops, just in a different direction for the oscialltion effect.
 if (tcontrol = 1800){
  while(tcontrol >1300){
  int raw = analogRead(0);
  int pwm  = map(raw,0,1023,0,255);
  analogWrite(dcspeed, pwm);
  int angle = map(tcontrol,1300,1800,0,60);
  
  Serial.print(pwm);
  Serial.print("  ");
  Serial.println(angle);
 


  digitalWrite(servo, HIGH);
  delayMicroseconds(tcontrol);
  digitalWrite(servo, LOW);
  delayMicroseconds(tperiod-tcontrol);
  
  tcontrol = tcontrol - 2;
 }
 }
 //small delay to keep processing somewhat smooth, this may be redundant. 
 delay (20);
 
 }

  

  

 
  
