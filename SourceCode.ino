#define trigPin1 13
#define trigPin2 11 
#define trigPin3 9 
#define trigPin4 7
#define echoPin1 12 
#define echoPin2 10 
#define echoPin3 8
#define echoPin4 6
#define high 200
#define weight 100
#define ledhigh 5
#define ledweight 4
#define buzzer 3

long duration,distance, HSR, HSL, WSR, WSL;





void setup() {
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(trigPin4, OUTPUT);
  
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(echoPin4, INPUT);
  
  pinMode(ledhigh, OUTPUT);
  pinMode(ledweight, OUTPUT);

  pinMode(buzzer, OUTPUT);
  

}

void loop() {
   SonarSensor(trigPin1, echoPin1);
   HSR = distance;
   SonarSensor(trigPin2, echoPin2);
   HSL = distance;
   SonarSensor(trigPin3, echoPin3);
   WSR = distance;
   SonarSensor(trigPin4, echoPin4);
   WSL = distance;

   if (HSR < high || HSL < high) {
    LedBlinking(ledhigh, 100);
   } else { 
    digitalWrite(ledhigh, LOW);
    digitalWrite(buzzer, LOW);}

    if (WSR < weight || WSL < weight) {
    LedBlinking(ledweight, 100);
   } else { 
    digitalWrite(ledweight, LOW);
    digitalWrite(buzzer, LOW);}

  

  Serial.print(HSR);
  Serial.print(" - ");
  Serial.print(HSL);
  Serial.print(" - ");
  Serial.print(WSR);
  Serial.print(" - ");
  Serial.println(WSL);
}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
}


void LedBlinking(int led, int del) {
digitalWrite(led, HIGH);
delay(del);
digitalWrite(led, LOW);
delay(del);
digitalWrite(buzzer, HIGH);
delay(del);
digitalWrite(buzzer, LOW); 
delay(del);
}
