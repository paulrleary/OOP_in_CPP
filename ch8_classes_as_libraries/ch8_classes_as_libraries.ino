/*
 * Once we have written our classes, re-packaging them as a library is quite trivial.
 * The only difference between a class, defined in global space, vs defined in an external library
 * is the separation of the DECLARATIONS of the member variables and functions and the SOURCE CODE
 * into a respective header file (".h") and its a source file (".cpp").
 * 
 * For more information on how to write your own libary, check out this tutorial:
 * https://www.arduino.cc/en/Hacking/LibraryTutorial
 * 
 * While the tutorial might clarify a few minor details, I bet you can figure out how libraries work, simply by
 * comparing the class definitions in previous lessons, to their .h and .cpp counterparts in this example.
 */

 
/*
  A subtle point on #include statements, 
  you may have noticed that these libraries are in quotes (i.e. #include "Flasher.h"), 
  while preceding includes uses brackets (e.g. #include <Servo.h>)

  The difference is that the "" notation is a special instruction to the compiler to first search for
  the library files in the same folder as the sketch (as in this example), before searching the core library 
  locations (such as Documents/Arduino/libraries, or others which are built into the compiler.

  Thus, using "" notation will work most of the time, and only create problems if you have multiple libraries with 
  the same filename on your computer (bad idea anyway). Using <> notation will miss libraries in the local sketch,
  and wouldn't work in this example.
 */
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
