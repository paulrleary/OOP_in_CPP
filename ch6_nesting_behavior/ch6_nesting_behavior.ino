#include <Servo.h>
// FLASHER CLASS
class Flasher
{
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
  public:
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
};

//SWEEPER CLASS
class Sweeper
{
    Servo servo;              // the servo
    int servoPin;          // the control pin for the servo
    int updateInterval;      // interval between updates
    int updateIncrement;        // increment to move for each interval
    bool printFlag;             // toggle state of Serial print

    int pos = 0;              // current servo position
    unsigned long lastUpdate; // last update of position

  public:
    Sweeper(int pin, int interval, int increment, bool printflag)
    {
      updateInterval = interval;
      updateIncrement = increment;
      servoPin = pin;
      Attach(servoPin);
      printFlag = printflag;

      servo.write(pos);

    }

    void Attach(int pin)
    {
      servo.attach(pin);
    }

    void Detach()
    {
      servo.detach();
    }

    void Update()
    {
      if ((millis() - lastUpdate) > updateInterval) // time to update
      {
        lastUpdate = millis();
        pos += updateIncrement;
        servo.write(pos);

        if (printFlag) //print servo position, if print is True
        {
          Serial.println(pos);
        }

        if ((pos >= 180) || (pos <= 0)) // end of sweep
        {
          // reverse direction
          updateIncrement = -updateIncrement;
        }
      }
    }
};

class Nocturnal
{

  public:
    int readPin;
    int readVoltage;
    int threshVoltage;

    bool darkState;

    Nocturnal(int pin, int Vthresh)
    {
      readPin = pin;
      threshVoltage = Vthresh;

      Update();
    }

    void Update()
    {
      readVoltage = analogRead(readPin);

      if (readVoltage <= threshVoltage)
      {
        darkState = true;
      }
      else
      {
        darkState = false;
      }
    }


    bool IsDark()
    {
      Update();

      return darkState;
    }

};

Flasher led1(24, 250, 750, 0); //Instantiates an instance of Flasher class, creating an object (of type Flasher) called led1(int pin, long on, long off, bool printflag)
Flasher led2(25, 330, 400, 0);
Flasher led3(26, 150, 200, 0);
Flasher led4(27, 200, 100, 0);
Flasher led5(28, 200, 300, 0);

Sweeper sweeper1(9, 8, 1, 0); //Instantiates an instance of Sweeper class, creating an object (of type Sweeper) called sweeper1(int pin, int interval, int increment, bool printflag)

Nocturnal party_tonight(A9, 500);


void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (party_tonight.IsDark()) {
    led1.Update();
    led2.Update();
    led3.Update();
    led4.Update();
    led5.Update();

    sweeper1.Update();
  }

}
