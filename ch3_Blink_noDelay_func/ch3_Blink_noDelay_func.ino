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

// Here we add a second LED, to blink at a different rate than the first

int ledPin2 =  25;      // the number of the LED pin
int ledState2 = LOW;             // ledState used to set the LED
unsigned long previousMillis2 = 0;        // will store last time LED was updated
long OnTime2 = 330;           // milliseconds of on-time
long OffTime2 = 400;          // milliseconds of off-time

int ledPin3 =  26;      // the number of the LED pin
int ledState3 = LOW;             // ledState used to set the LED
unsigned long previousMillis3 = 0;        // will store last time LED was updated
long OnTime3 = 150;           // milliseconds of on-time
long OffTime3 = 200;          // milliseconds of off-time


void setup()
{
  // set the digital pin as output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}


/*
  We can attempt to simplify our loop using a FUNCTION to update the LEDs

  Any function is defined:
  return_type name("input arguments (optional)")

  return_type refers to the type of variable (e.g. int) which we expect to see returned from a function.
  input arguments (if any) are values that are passed into a function, for it to use.
  These values are assigned to the variables which are declared in the function definition

  Youve seen 2 functions already, setup() and loop()
  In the case of setup() or loop(), which don't return anything, the return type is "void"

  You will see plenty of functions that return void, and plenty more that return other variable types.
  For example, a reasonable function:
  void print_result(int result)
  Which prints a result (of type int) to a screen, likely has no reason to return a variable

  However a function:
  int add_2_ints(int a, int b)
  probably should return an int, because telling a function to add 2 integers,
  but not asking for a result back, probably doesn't do much for us.

  Here, we've written a function called updateLed(arguments), which performs all time checks and returns the new ledState
*/

void loop()
{
  int newLedState;

  //Here, we feed our updateLED function all of the current information (called "input arguments") about the LED of interest, checks, and updates the state if necessary.  The function returns (called "output arguments") the newLedState.
  newLedState = updateLed(ledPin1, OnTime1, OffTime1, previousMillis1, ledState1, 0);

  if (ledState1 != newLedState) //Check if ledState changed.  Could also be written using "exclusive or", e.g. if(ledState1 ^ newLedState).
  {
    // if our updateLed(...) function changed the ledState, we now must update our "memory" (i.e. global variables) which are keeping track of this.
    ledState1 = newLedState;
    previousMillis1 = millis();
  }

  newLedState = updateLed(ledPin2, OnTime2, OffTime2, previousMillis2, ledState2, 0); // Do the same with the other LEDs

  if (ledState2 != newLedState)
  {
    ledState2 = newLedState;
    previousMillis2 = millis();
  }

  newLedState = updateLed(ledPin3, OnTime3, OffTime3, previousMillis3, ledState3, 1); // Just for fun, we'll turn on the "printFlag" for led3
  if (ledState3 != newLedState)
  {
    ledState3 = newLedState;
    previousMillis3 = millis();
  }

}

/* Check your understanding:

    Question: What is the scope  of variables ledPin, OnTime, etc?

    On that note:
    take a careful look at the line that says previousMillis = currentMillis;

*/
int updateLed(int ledPin, long OnTime, long OffTime, unsigned long previousMillis, int ledState, bool printFlag)
{
  unsigned long currentMillis = millis();

  if ((ledState == HIGH) && (currentMillis - previousMillis >= OnTime)) // check to see if it's time to change the state of the LED from HIGH to LOW
  {
    ledState = LOW;  // Turn it off
    previousMillis = currentMillis;  //CHECK YOUR UNDERSTANDING: Does this line do anything???
    digitalWrite(ledPin, ledState);  // Update the actual LED

    if (printFlag) //print ledState, if print is true
    {
      Serial.println(ledState);
    }
  }
  else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime)) // check to see if it's time to change the state of the LED from LOW to HIGH
  {
    ledState = HIGH;  // turn it on
    previousMillis = currentMillis;   //CHECK YOUR UNDERSTANDING: Does this line do anything???
    digitalWrite(ledPin, ledState);   // Update the actual LED

    if (printFlag)
    {
      Serial.println(ledState);
    }
  }

  return ledState;
}

