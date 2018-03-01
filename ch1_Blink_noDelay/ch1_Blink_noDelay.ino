/*Adapted from https://learn.adafruit.com/multi-tasking-the-arduino-part-1/overview
  by Paul R. Leary, January 2018,
  Naval Postgraduate School
  Monterey, CA

  for PC4015: Advanced Applied Physics Laboratory
*/


/*
  Here, we show how we might blink an led without the use of delay()
*/

// These global variables store the flash pattern
// and the current state of the LED

int ledPin =  24;      // the number of the LED pin
int ledState = LOW;             // ledState used to set the LED
unsigned long previousMillis = 0;        // will store last time LED was updated
long OnTime = 250;           // milliseconds of on-time
long OffTime = 750;          // milliseconds of off-time

void setup()
{
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  /*
     First we need to get the current time, with the build in in function millis()
     We declare the variable currentMillis to store the time.

     currentMillis is now a LOCAL VARIABLE.  Its SCOPE is not global
     but rather, limited to within the loop() function.
     If we tried to access it elsewhere, we would likey get an error:
     "Variable not declared in this scope"

     We use currentMillis as a LOCAL VARIABLE because, once we've used its value in the loop,
     we don't care about it again.  If we are going to change a variable each time a function
     is called, it doesn't really make sense to store it globally
  */

  unsigned long currentMillis = millis(); //note that currentMillis is not a Global variable, therefore we need to declare it here.  Thus, currentMillis is not accessible outside the loop() function.


  if ((ledState == HIGH) && (currentMillis - previousMillis >= OnTime)) // check to see if it's time to change the state of the LED
  {
    ledState = LOW;  // Turn it off
    previousMillis = currentMillis;  // Remember the time, that update the GLOBAL VARIABLE previousMillis, with the value of the LOCAL VARIABLE currentMillis.
    digitalWrite(ledPin, ledState);  // Update the actual LED
  }
  else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
  {
    ledState = HIGH;  // turn it on
    previousMillis = currentMillis;   // Remember the time
    digitalWrite(ledPin, ledState);    // Update the actual LED
  }
}

