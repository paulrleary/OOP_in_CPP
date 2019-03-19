/*Adapted from https://learn.adafruit.com/multi-tasking-the-arduino-part-1/overview
  by Paul R. Leary, January 2018,
  Naval Postgraduate School
  Monterey, CA

  for PC4015: Advanced Applied Physics Laboratory
*/

int ledPin1 =  24;      // the number of the LED pin
int ledState1 = LOW;             // ledState used to set the LED
unsigned long previousMillis1 = 0;        // will store last time LED was updated
long OnTime1 = 250;           // milliseconds of on-time
long OffTime1 = 750;          // milliseconds of off-time
bool printFlag1 = 0;          // toggle print of ledstate

// Here we add a second LED, to blink at a different rate than the first

int ledPin2 =  25;      // the number of the LED pin
int ledState2 = LOW;             // ledState used to set the LED
unsigned long previousMillis2 = 0;        // will store last time LED was updated
long OnTime2 = 330;           // milliseconds of on-time
long OffTime2 = 400;          // milliseconds of off-time
bool printFlag2 = 0;          // toggle print of ledstate

//int ledPin3 =  26;      // the number of the LED pin
//int ledState3 = LOW;             // ledState used to set the LED
//unsigned long previousMillis3 = 0;        // will store last time LED was updated
//long OnTime3 = 150;           // milliseconds of on-time
//long OffTime3 = 200;          // milliseconds of off-time
//bool printFlag3 = 0;          // toggle print of ledstate


void setup()
{
  // set the digital pin as output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  //  pinMode(ledPin3, OUTPUT);
}

void loop()
{
  /*
    With the second LED in the mix, the code runs perfectly fine, although we've doubled its size
    Further, much of this code is now extremely repetitive.
    That is, we've "hard coded" the same task over and over, just for different sets of variables.

    We have a a third set of variables and code to run a third led, which is commented out,
    If we uncomment, we can see the third led behavior, although we have now tripled the original length
  */
  unsigned long currentMillis = millis();

  if ((ledState1 == HIGH) && (currentMillis - previousMillis1 >= OnTime1))
  {
    ledState1 = LOW;  // Turn it off
    previousMillis1 = currentMillis;  // Remember the time
    digitalWrite(ledPin1, ledState1);  // Update the actual LED
    if (printFlag1) //print ledState, if print is true
    {
      Serial.println(ledState1);
    }
  }
  else if ((ledState1 == LOW) && (currentMillis - previousMillis1 >= OffTime1))
  {
    ledState1 = HIGH;  // turn it on
    previousMillis1 = currentMillis;   // Remember the time
    digitalWrite(ledPin1, ledState1);    // Update the actual LED
    if (printFlag1) //print ledState, if print is true
    {
      Serial.println(ledState1);
    }
  }

  if ((ledState2 == HIGH) && (currentMillis - previousMillis2 >= OnTime2))
  {
    ledState2 = LOW;  // Turn it off
    previousMillis2 = currentMillis;  // Remember the time
    digitalWrite(ledPin2, ledState2);  // Update the actual LED
    if (printFlag2) //print ledState, if print is true
    {
      Serial.println(ledState2);
    }
  }
  else if ((ledState2 == LOW) && (currentMillis - previousMillis2 >= OffTime2))
  {
    ledState2 = HIGH;  // turn it on
    previousMillis2 = currentMillis;   // Remember the time
    digitalWrite(ledPin2, ledState2);   // Update the actual LED
    if (printFlag2) //print ledState, if print is true
    {
      Serial.println(ledState2);
    }
  }

  //  if((ledState3 == HIGH) && (currentMillis - previousMillis3 >= OnTime3))
  //  {
  //    ledState3 = LOW;  // Turn it off
  //    previousMillis3 = currentMillis;  // Remember the time
  //    digitalWrite(ledPin3, ledState3);  // Update the actual LED
  //    if(printFlag3) //print ledState, if print is true
  //          {
  //            Serial.println(ledState3);
  //          }
  //
  //  }
  //  else if ((ledState3 == LOW) && (currentMillis - previousMillis3 >= OffTime3))
  //  {
  //    ledState3 = HIGH;  // turn it on
  //    previousMillis3 = currentMillis;   // Remember the time
  //    digitalWrite(ledPin3, ledState3);   // Update the actual LED
  //    if(printFlag3) //print ledState, if print is true
  //          {
  //            Serial.println(ledState3);
  //          }
  //  }
}

