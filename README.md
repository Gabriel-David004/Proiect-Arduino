# Proiect-Arduino

# Sistem de alarma cu senzor de distanta

Acest proiect implementeaza un sistem de alarma folosind un senzor de distanta ultrasonic, mai multe LED-uri, un buzzer si un motor. Proiectul este util pentru detectarea obstacolelor sau pentru sisteme de siguranta de baza.

## Cum functioneaza acest sistem?
Sistemul utilizeaza un senzor ultrasonic pentru a masura distanta pana la un obstacol. In functie de distanta detectata, se activeaza diverse componente:

- **Distanta < 60 cm**: Se va aprinde LED-ul 1.
- **Distanta < 40 cm**: Se va aprinde LED-ul 2 si motorul va fi activat.
- **Distanta < 20 cm**: Se va aprinde LED-ul 3 si buzzer-ul va emite un sunet de alarma.

Valorile masurate sunt afisate in serial monitor pentru diagnosticare.

## Componentele necesare
- 1 x Arduino Uno (sau echivalent)
- 1 x Senzor ultrasonic (HC-SR04)
- 3 x LED-uri
- 3 x Rezistente (220 ohmi)
- 1 x Buzzer
- 1 x Motor DC
- 1 x Driver motor (H-Bridge)
- Cabluri jumper si breadboard

## Schema de conectare
1. Conectam senzorul ultrasonic in felul urmator:
   - TRIG -> Pinul digital 7
   - ECHO -> Pinul digital 6
2. Conectam LED-urile la pinii digitali 13, 12 si 11 (cu rezistente).
3. Conectam buzzer-ul la pinul digital 9.
4. Conectam motorul la pini digitali 4 si 3 prin driver-ul de motor.

## Instalare
1. Descarcati codul din acest repository.
2. Deschideti codul in Arduino IDE.
3. Conectati placa Arduino la computer si selectati portul corespunzator.
4. Incarcati codul pe placa.

## Utilizare
1. Alimentati circuitul.
2. Deschideti Serial Monitor din Arduino IDE (9600 baud) pentru a urmari distanta masurata.
3. Testati sistemul deplasandu-va un obiect in fata senzorului si observati modul in care LED-urile, motorul si buzzer-ul reactioneaza.

## Codul
Codul complet este disponibil mai jos:

```cpp
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

