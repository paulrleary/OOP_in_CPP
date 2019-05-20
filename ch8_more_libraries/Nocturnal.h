#ifndef Nocturnal_h
#define Nocturnal_h

#include "Arduino.h"



class Nocturnal
{

  public:
    int readPin;
    int readVoltage;
    int threshVoltage;

    bool darkState;

    Nocturnal(int pin, int Vthresh);
    

    void Update();
    

    bool IsDark();
    
};
#endif
