/*
  Modified from Arduino example: Blink
  by Paul R. Leary, January 2018,
  Naval Postgraduate School
  Monterey, CA

  for PC4015: Advanced Applied Physics Laboratory
*/



/*
  This area of the code (above setup()) stores our GLOBAL VARIABLES
  GLOBAL VARIABLES are variables that are "global" in SCOPE.
  That is, they are accessible and modifiable from within any area/function in the code.

  Variables, whether global or not, are always defined:

  type name

  Below we "Declare" a global variable which we call led, of type int (integer).

  We don't necessarily have to give it a value here, but we do in this case.
  "Declaring" a variable simply means to set aside a space in memory to store a variable of a specific type
  Different types of variables require different amounts of memory.

  The tendency in many intro to Arduino tutorials is to just make all variables global.
  However this wastes memory, and can make code unecessarily complicated/messy when we graduate to more complex tasks.

  Learning how and why to manage the scope of variables (and other objects) is a core value of this lab.
*/

int led = 24;

/*
  All Arduino programs, at minimum, have 2 functions:
  setup(), which runs once, immediately after power-up
  loop(), which runs indefinitely, after setup()
*/


void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second

  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second

  // BUT WHAT IF WE WANT TO DO SOMETHING ELSE DURING THE DELAY???
  // WOULD IT BE POSSIBLE TO ADD A SECOND LED WITH A DIFFERENT BLINK RATE???
}
