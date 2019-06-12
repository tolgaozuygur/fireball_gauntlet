/*
 Fireball Gauntlet project
 by Tolga Ozuygur and Cem Sina Cetin
*/

#include<Wire.h>
const int MPU_addr=0x68;

struct Vector {
  float x;
  float y;
  float z;
};

float limit = 16000; 
Vector acc;

float trigger = 1.5;
float control = 1.5;

int delayTime = 50;
int ledBlinkTime = 100;

int led[] = {2,3,4};
int plug[] = {12,11,10};
int pCount = sizeof(plug) / sizeof(int);

int cp = 0;
int fireTime = 1000;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
  delay(200);
  for(int i = 0; i < pCount; i++) {
    pinMode(led[i], OUTPUT); 
    pinMode(plug[i], OUTPUT);
    digitalWrite(plug[i], LOW); 
  }

  intro();
}


void loop() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);
  acc.x = Wire.read()<<8|Wire.read();    
  acc.y = Wire.read()<<8|Wire.read();
  acc.z = Wire.read()<<8|Wire.read();

  acc.x /= limit;
  acc.y /= limit;
  acc.z /= limit;

  fireballCheck();
  delay(delayTime);
}

void fireballCheck() {
  if(acc.x > trigger && abs(acc.y) < control && abs(acc.z) < control) {
    if(cp < pCount) {  
      //fire!      
      fireball();
    } else {
      //out of ammo
      blinkLeds(5, LOW);
    }
  }
}

void fireball() {
  digitalWrite(plug[cp], HIGH);
  Serial.println("Firing barrel: " + String(cp));
  blinkLed(fireTime/ledBlinkTime, LOW, cp); //wait for the fireTime duration by blinking the led
  digitalWrite(plug[cp], LOW);   
  blinkLed(10, LOW, cp); //blink the leds for another second to prevent a misfire after firing
  cp++;
}

void intro() {
    ledToggle(0, HIGH);
    delay(300);    
    ledToggle(0, LOW);
    ledToggle(1, HIGH);
    delay(300);    
    ledToggle(1, LOW);
    ledToggle(2, HIGH);
    delay(300);    
    ledToggle(2, LOW);
    ledToggle(1, HIGH);
    delay(300);    
    ledToggle(1, LOW);
    ledToggle(0, HIGH);
    delay(300);   
    ledToggle(0, LOW);
    delay(300);      
    blinkLeds(3, HIGH);
}

void ledToggle(int ledId, int ledState) {
  digitalWrite(led[ledId], ledState);
}

void blinkLeds(int blinkCount, int endState) {
  //blink all leds
  for(int i = 0; i < blinkCount; i++) {
    for(int i = 0; i < pCount; i++) {
      ledToggle(i, HIGH);
    }    
    delay(ledBlinkTime);    
  
    for(int i = 0; i < pCount; i++) {
      ledToggle(i, LOW);
    }    
    delay(ledBlinkTime);    
  }  

  for(int i = 0; i < pCount; i++) {
      ledToggle(i, endState);
  }    
}

void blinkLed(int blinkCount, int endState, int ledId) {
  //blink single leds
  for(int i = 0; i < blinkCount; i++) {
    ledToggle(ledId, HIGH);
    delay(ledBlinkTime);    
    ledToggle(ledId, LOW);
    delay(ledBlinkTime);    
  }  

  ledToggle(ledId, endState);
}
