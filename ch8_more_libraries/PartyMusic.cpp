#include "Arduino.h"
#include "PartyMusic.h"

PartyMusic::PartyMusic(int pin, int interval){
  tonePin = pin;
  updateInterval = interval;
  lastUpdate = millis();
}

void PartyMusic::Update(){
  if((millis() - lastUpdate)>updateInterval){
    lastUpdate = millis();
//    noTone(tonePin);
    tone(tonePin, melody[toneIdx], updateInterval*0.6);
    toneIdx+=1;
    Serial.println(toneIdx);
    if (toneIdx>7){
      toneIdx = 0;
    }
  }
  
}

