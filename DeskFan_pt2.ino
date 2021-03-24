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
pinMode(12, INPUT);

//setting direction
digitalWrite(dc1, LOW);
digitalWrite(dc2, HIGH);
analogWrite(dcspeed, 0);

}

void loop() {




  //sets the integer for the raw signal and maps it for the pwm of the dc motor
  
  int raw = analogRead(0);
  float temp = ((.885*analogRead(5) + 6.92)*(9/5)+32);
  int tcontrol  = map(raw,0,1023,1300,1800);
  int switchh = digitalRead(12);
  int temppwm = map(temp, 590, 670, 0, 255);
  
  

  //maps the duty cycle of servo into an angle. 0-60 is used here for simpler calculations later in processing
  int angle = map(tcontrol,1300,1800,0,60);

  //printing values for processing to read and use
  Serial.print(temppwm);
  Serial.print("  ");
  Serial.print(angle);
  Serial.print("  ");
  Serial.println(switchh);

  //Serial.println(temp);

  
if(switchh == 1){
  //the actual control of the servo via manipulating the duty cycle.
  analogWrite(dcspeed, temppwm);
  digitalWrite(servo, HIGH);
  delayMicroseconds(tcontrol);
  digitalWrite(servo, LOW);
  delayMicroseconds(tperiod-tcontrol);
  

 
 delay(5);
}
if(switchh == 0){

  analogWrite(dcspeed, 0);
 
  delay(5);
}

}

  

 //again, all the code here is the same as the previous loops, just in a different direction for the oscialltion effect.

 

  

  

 
  
