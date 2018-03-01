
#include "Arduino.h"
#include "Flasher.h"    
 

Flasher::Flasher(int pin, long on, long off, bool printflag)
{
  ledPin = pin;
  pinMode(ledPin, OUTPUT);

  OnTime = on;
  OffTime = off;

  printFlag = printflag;

  ledState = LOW;
  previousMillis = 0;
}

void Flasher::Update()
{

  unsigned long currentMillis = millis();

  if ((ledState == HIGH) && (currentMillis - previousMillis >= OnTime)) // check to see if it's time to change the state of the LED from HIGH to LOW
  {
    ledState = LOW;  // Turn it off
    previousMillis = currentMillis;  // Remember the time
    digitalWrite(ledPin, ledState);  // Update the actual LED

    if (printFlag) //print ledState, if print is true
    {
      Serial.println(ledState);
    }
  }
  else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime)) // check to see if it's time to change the state of the LED from LOW to HIGH
  {
    ledState = HIGH;  // turn it on
    previousMillis = currentMillis;   // Remember the time
    digitalWrite(ledPin, ledState);   // Update the actual LED

    if (printFlag)
    {
      Serial.println(ledState);
    }
  }
}
