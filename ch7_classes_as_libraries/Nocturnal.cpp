#include "Arduino.h"
#include "Nocturnal.h"


Nocturnal::Nocturnal(int pin, int Vthresh)
{
  readPin = pin;
  threshVoltage = Vthresh;

  Update();
}

void Nocturnal::Update()
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


bool Nocturnal::IsDark()
{
  Update();

  return darkState;
}
