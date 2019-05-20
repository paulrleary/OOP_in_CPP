#ifndef Spinner_h
#define Spinner_h
#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

class Spinner
{
    public:

    Adafruit_NeoPixel ring;              // the neopixel ring
    int ringPin;          // the control pin for the ring
    int updateInterval;      // interval between updates
    int updateIncrement = 1;        // increment to move for each interval
    bool printFlag;             // toggle state of Serial print

    int pos = 0;              // current ring position
    unsigned long lastUpdate; // last update of position


    int pixel = 0;
    int angle = -180;

    int color ;
    Spinner(int pin, int interval);
    
    void Update();

    int pixelAngle(int angle);
};

#endif
