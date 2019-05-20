#include "Arduino.h"
#include <Servo.h>
#include "Sweeper.h"


Sweeper::Sweeper(int pin, int interval, int increment, bool printflag)
{
  updateInterval = interval;
  updateIncrement = increment;
  servoPin = pin;
  Attach(servoPin);
  printFlag = printflag;

  servo.write(pos);

}

void Sweeper::Attach(int pin)
{
  servo.attach(pin);
}

void Sweeper::Detach()
{
  servo.detach();
}

void Sweeper::Update()
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
