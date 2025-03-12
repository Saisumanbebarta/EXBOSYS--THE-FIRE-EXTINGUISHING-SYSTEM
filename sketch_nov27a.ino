  int a;
  int i=0;
  #include <Servo.h>
  Servo servo;
  int pos = 0;   
  void setup() {
  pinMode(7,INPUT);
  pinMode(13,OUTPUT);
  pinMode(4,OUTPUT);
  servo.attach(3);
  Serial.begin(9600);
  }
  void loop() {
  a=digitalRead(7);
  if(a==LOW){
  delay(1000);
  i++;
  delay(1000);
  }
  Serial.println(i);
  if(i>0 && i<2){
  for (pos = 160; pos >= 90; pos -= 1) { 
    servo.write(pos);        
    delay(15);                       
  }
  delay(2000);
  for (pos = 90; pos <= 160; pos += 1) { 
    servo.write(pos);             
    delay(15);                       
  }
  digitalWrite(13,HIGH);///Node MCU Relay
  delay(50000);
  digitalWrite(13,LOW);
  i++;
  }
  else
  {
  for (pos = 160; pos <= 160; pos += 160) { 
    servo.write(pos);             
    delay(15);                       
  }  
  digitalWrite(13,LOW);
  }
  }
