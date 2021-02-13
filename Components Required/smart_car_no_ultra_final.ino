int motor1spin=7;
int motor1speed=6;
int motor2spin=5;
int motor2speed=4;
int buzzerpin=11;
int led=10;

#define trigPin 8
#define echoPin 9
char choice;
void setup(){
  pinMode(motor1spin,OUTPUT);
  pinMode(motor1speed,OUTPUT);
  pinMode(motor2spin,OUTPUT);
  pinMode(motor2speed,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(buzzerpin,OUTPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  }
void loop () {
  long duration , distance;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2)/29.1;
 if (distance < 15)
{ 

// This is where the LED On/Off happens

digitalWrite(buzzerpin,HIGH);
digitalWrite(led,HIGH);
}

 else {

digitalWrite(buzzerpin,LOW);
digitalWrite(led,LOW); 
}
  if(Serial.available()) {
  choice = Serial.read();
  if(choice == '1') {

    if(!distance<=5) {

        digitalWrite(motor1spin,HIGH);
    analogWrite(motor1speed,20);
  digitalWrite(motor2spin,HIGH);
  analogWrite(motor2speed,20);
    }
  }
  if(choice == '2') {
    digitalWrite(motor1spin,LOW);
    digitalWrite(motor2spin,LOW);
  }

    if(choice =='3') {
      digitalWrite(motor1spin,LOW);
     analogWrite(motor1speed,250);
     digitalWrite(motor2spin,LOW);
     analogWrite(motor2speed,220);
    }

    if(choice == '4') {
      digitalWrite(motor1spin,LOW);
      analogWrite(motor1speed,0);
      digitalWrite(motor2spin,LOW);
      analogWrite(motor2speed,0);
      
    }
      
    if(choice == '7') {
      digitalWrite(motor1spin,HIGH);
      analogWrite(motor1speed,1);
      digitalWrite(motor2spin,LOW);
      analogWrite(motor2speed,220); 
    }
    
    if(choice == '8') {
      digitalWrite(motor1spin,LOW);
      analogWrite(motor1speed,0);
      digitalWrite(motor2spin,LOW);
      analogWrite(motor2speed,0);
  }

    if(choice == '5') {
      digitalWrite(motor1spin,LOW);
      analogWrite(motor1speed,255);
      digitalWrite(motor2spin,HIGH);
      analogWrite(motor2speed,1);
    }
    
    if(choice == '6') {
      digitalWrite(motor1spin,LOW);
      analogWrite(motor1speed,0);
      digitalWrite(motor2spin,LOW);
      analogWrite(motor2speed,0);
    }
 }
}
