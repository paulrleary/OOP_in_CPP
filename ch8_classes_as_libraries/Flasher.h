#ifndef Flasher_h
#define Flasher_h

 #include "Arduino.h"
 
class Flasher
{
    public:  
        int ledPin;      // the number of the LED pin
        long OnTime;     // milliseconds of on-time
        long OffTime;    // milliseconds of off-time
        bool printFlag;   // toggle state of Serial print
    // These maintain the current state
        int ledState;                 // ledState used to set the LED
        unsigned long previousMillis;   // will store last time LED was updated

        Flasher(int pin, long on, long off, bool printflag);
    
        void Update();
   
};

#endif
