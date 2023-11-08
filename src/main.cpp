#include <Arduino.h>

// put function declarations here:
int button1(8);
int stateButton1(0);
int lastsavedbuttonstate1(0);
int AmountOfPeople(0);
int button2(9);
int stateButton2(0);
int lastsavedbuttonstate2(0);
unsigned long time;
unsigned long lastime;
unsigned long debounce;

int YellowLed(7);
int BlueLed(6);
int GreenLed(5);
int OopLed(5);

int ledCount1to3(0);

int nummer0(0);
int nummer1(1);
int nummer2(2);
int nummer3(3);
int nummer4(4);
int debouncedelay(1000);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button1,INPUT_PULLUP);
  pinMode(button2,INPUT_PULLUP);
  pinMode(YellowLed, OUTPUT);
  pinMode(BlueLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  time = millis();
  debounce = time - lastime;
  
    lastsavedbuttonstate1 = stateButton1;
    stateButton1 = digitalRead(button1);
    lastsavedbuttonstate2 = stateButton2;
    stateButton2 = digitalRead(button2);
    
  if (stateButton1 == LOW and lastsavedbuttonstate1 == HIGH and debounce >=debouncedelay) {
    AmountOfPeople ++;
    Serial.print(AmountOfPeople);
    Serial.println("Aantal bezoekers");
    lastime = time;
    ledCount1to3 ++;
    if (ledCount1to3 == nummer4){
      ledCount1to3 = nummer1;
    }
    Serial.print(ledCount1to3);
    Serial.println("Led count");
  }

  if (stateButton2 == LOW and lastsavedbuttonstate2 == HIGH and AmountOfPeople >= 1 and debounce >=debouncedelay) {
    AmountOfPeople --;
    Serial.print(AmountOfPeople);
    Serial.println("Aantal bezoekers");
    lastime = time;
    ledCount1to3 --;
    if (ledCount1to3 == nummer0) {
      ledCount1to3 = nummer3;
    }
    
    Serial.print(ledCount1to3);
    Serial.println("Led count");
  }
  
  if (AmountOfPeople == nummer0) {
    ledCount1to3 = nummer0;
  }
  

  if (ledCount1to3 == nummer0){
    digitalWrite(YellowLed, LOW);
    digitalWrite(BlueLed, LOW);
    digitalWrite(GreenLed, LOW);
  }
  if (ledCount1to3 == nummer1){
    digitalWrite(YellowLed, HIGH);
    digitalWrite(BlueLed, LOW);
    digitalWrite(GreenLed, LOW);
  }
  if (ledCount1to3 == nummer2) {
    digitalWrite(BlueLed, HIGH);
    digitalWrite(YellowLed, LOW);
    digitalWrite(GreenLed, LOW);
  }
  if (ledCount1to3 == nummer3) {
    digitalWrite(GreenLed, HIGH);
    digitalWrite(YellowLed, LOW);
    digitalWrite(BlueLed, LOW);
  }

  
 
    
 


  
}

// put function definitions here:
