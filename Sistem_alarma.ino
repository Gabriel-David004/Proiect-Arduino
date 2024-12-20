int led1 = 13;
int led2 = 12;
int led3 = 11;

int trig = 7;
int echo = 6;

int buzzer = 9;

int pinM1 = 4;
int pinM2 = 3;

int durata = 0;
int distanta = 0;

void setup(){

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(buzzer, OUTPUT);
  
  pinMode(pinM1, OUTPUT);
  pinMode(pinM2, OUTPUT);
  
  Serial.begin(9600);
}

void loop(){

  digitalWrite(trig, HIGH);
  delay(50);
  digitalWrite(trig, LOW);
  
  durata = pulseIn(echo, HIGH);
  distanta = (durata / 2) / 28.5;
  Serial.println(distanta);
  
  if(distanta < 60){
  
    digitalWrite(led1, HIGH);
  } else {
  
    digitalWrite(led1, LOW);
  }
  
  
  if(distanta < 40){
  
    digitalWrite(led2, HIGH);
    
    digitalWrite(pinM1, HIGH);
    digitalWrite(pinM2, LOW);
  } else {
  
    digitalWrite(led2, LOW);
    
    digitalWrite(pinM1, LOW);
    digitalWrite(pinM2, LOW);
  }
  
  
  if(distanta < 20){
  
    digitalWrite(led3, HIGH);
    tone(buzzer, 400);
  } else {
  
    digitalWrite(led3, LOW);
    noTone(buzzer);
  }
  
  
}