#include "Flasher.h"
#include "Sweeper.h"
#include "Nocturnal.h"

Flasher led1(24, 250, 750, 0); 
Flasher led2(25, 330, 400, 0);
Flasher led3(26, 150, 200, 0);
Flasher led4(27, 200, 100, 0);
Flasher led5(28, 200, 300, 0);

Sweeper sweeper1(9, 8, 1, 0); 

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
