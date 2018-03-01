#ifndef Sweeper_h
#define Sweeper_h

#include "Arduino.h"
#include <Servo.h>


class Sweeper
{
    public:

    Servo servo;              // the servo
    int servoPin;          // the control pin for the servo
    int updateInterval;      // interval between updates
    int updateIncrement;        // increment to move for each interval
    bool printFlag;             // toggle state of Serial print

    int pos = 0;              // current servo position
    unsigned long lastUpdate; // last update of position


    Sweeper(int pin, int interval, int increment, bool printflag);
    

    void Attach(int pin);
    

    void Detach();
    
    void Update();
    
};
#endif