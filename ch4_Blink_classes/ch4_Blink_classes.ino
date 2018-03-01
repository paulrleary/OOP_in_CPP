/*Adapted from https://learn.adafruit.com/multi-tasking-the-arduino-part-1/overview
 *by Paul R. Leary, January 2018, 
 *Naval Postgraduate School
 *Monterey, CA
 *
 *for PC4015: Advanced Applied Physics Laboratory 
 */

/*
 * So now we can avoid a lot of our previously repetitve code by implementing the class Flasher, 
 * and instantiate it as an object for each led
*/

// FLASHER CLASS
class Flasher
{
  public:
  // Class Member Variables
  // These are initialized at startup
  int ledPin;      // the number of the LED pin
  long OnTime;     // milliseconds of on-time
  long OffTime;    // milliseconds of off-time
  bool printFlag;   // toggle state of Serial print
  // These maintain the current state
  int ledState;                 // ledState used to set the LED
  unsigned long previousMillis;   // will store last time LED was updated
 
  // Constructor - creates a Flasher 
  // and initializes the member variables and state
  Flasher(int pin, long on, long off, bool printflag)
  {
  ledPin = pin;
  pinMode(ledPin, OUTPUT);     
    
  OnTime = on;
  OffTime = off;

  printFlag = printflag;
  
  ledState = LOW; 
  previousMillis = 0;
  }
 
  void Update()
  {
    
    unsigned long currentMillis = millis();
     
    if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime)) // check to see if it's time to change the state of the LED from HIGH to LOW
    {
      ledState = LOW;  // Turn it off
      previousMillis = currentMillis;  // Remember the time
      digitalWrite(ledPin, ledState);  // Update the actual LED

      if(printFlag) //print ledState, if print is true
      {
        Serial.println(ledState);
      }
    }
    else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime)) // check to see if it's time to change the state of the LED from LOW to HIGH
    {
      ledState = HIGH;  // turn it on
      previousMillis = currentMillis;   // Remember the time
      digitalWrite(ledPin, ledState);   // Update the actual LED
      
      if(printFlag)
      {
        Serial.println(ledState);
      }
    }
  }
};


Flasher led1(24, 250, 750, 0); //Instantiates an instance of Flasher class, creating an object (of type Flasher) called led1(int pin, long on, long off, bool printflag)
Flasher led2(25, 330, 400, 0);
Flasher led3(26, 150, 200, 0);
Flasher led4(27, 200, 100, 0);
Flasher led5(28, 200, 300, 0);

void setup() 
{ 
  Serial.begin(9600);  

}

void loop() 
{ 
  // In the loop() function, now all we need to do is tell each object to "run", (i.e. Update())
  led1.Update();
  led2.Update();
  led3.Update();
  led4.Update();
  led5.Update();
  
 }
