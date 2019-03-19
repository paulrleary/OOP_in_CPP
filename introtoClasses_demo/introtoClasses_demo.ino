/*
 *Written by Paul R. Leary, January 2018, 
 *Naval Postgraduate School
 *Monterey, CA
 *
 *for PC4015: Advanced Applied Physics Laboratory 
 */

/*
 Here we introduce the meat of Object oriented programming.
 
 An OBJECT is an instance of a CLASS, which defines its "properties" (technically called its DATA, MEMBER VARIABLES, or ATTRIBUTES) 
 and its METHODS (the procedures it can accomplish, like functions)

 While this all sounds pretty esoteric, it's actually no different than what you've seen already.
 In fact you've been dealing with objects and classes all along, albeit very simple ones.

 For example, the first thing we did in Blink, was declare an OBJECT,
 called "led", which was an instance of CLASS "int", and had one ATTRIBUTE:
 its value, 24.

 Functions are OBJECTS as well. They have a single METHOD, and no ATTRIBUTES.  

 Here, we are simply going to see what happens when start to create use OBJECTS
 which bundle together a larger set of ATTRIBUTES and METHODS, than a single variable or function.
 
 Classes are defined in C++ (and Arduino) as follows:
*/

 class UselessClass      //We've just said here that we want to define a new Class, which we'll call UntitledClass
 {  
  public:                 //This merely states that the values below are public and not private (i.e. hidden), You don't need to think about that too much right now
  
    int var1;            //Here we declare some attributes, which we can also call MEMBER VARIABLES
    bool var2;            //You can think of these as variables that are "global within the class",
    long var3;            //That is, they can be accessed and modified by any area of code within the class, 
    String var4;            //That is, they can be accessed and modified by any area of code within the class, 
    int var5;            //They are usually assigned values elsewhere, but this does not necessarily have to be true
    int index;
    /*
    Below the member variables we define the METHODS, which are the functions that we want the class to be able to carry out.
    The first method, however is special. This method is called the CONSTRUCTOR, and always has the same name as the class.
    The CONSTRUCTOR method runs automatically, when an instance of the class is created.  
    Often, the CONSTRUCTOR assigns the initial values to the member variables 
    and performs any other initial tasks required to make the object useable
    */
    
    UselessClass(int value1, bool value2, String value4)
    {
      var1 = value1;
      var2 = value2;
      var4 = value4;

      if(var2){
      var3 = var1+2;
      }
      else{
      var3 = 5;
      }
      
      index  = 0;         
    }
    
    /*
    After the constructor, we can add any other methods we like
    One thing that is nice about using classes, is they can operate directly on their attributes
    That is, we can have the convenience of using global variables, without the clutter.
    We'll see many other reasons why this is handy as we implement real tasks.
    */
    
    void Method1()
    {
      Serial.println("Hello, my name is "+var4);
      Serial.println();
    }

    void Method2()
    { 
      int localVar = var3 + var1;
      String str = "I just made and amazing discovery. It turns out that "+String(var3)+" + "+String(var1)+" = "+String(localVar)+"!!!";
      Serial.println(str);
      Serial.println();
    }    

    void DoSomethingUseless()
    {
      String bases_str[4] = {"binary", "octal", "decimal", "hexadecimal"};
      int bases[4] = {BIN, OCT, DEC, HEX};

      int localVar = var3 + var1;

      String str = "In "+bases_str[index]+" that would be "+String(var3, bases[index])+" + "+String(var1, bases[index])+" = "+String(localVar, bases[index])+"!!!";   
      Serial.println(str);
      Serial.println();
      
      index ++;
      if (index>3){
        index = 0;
      }
    }
    
 };

UselessClass useless(11, true, "fhgwgads");

 void setup() {
  Serial.begin(9600);
  delay(2000);
  
  useless.Method1();
  delay(1000);
  useless.Method2();
  delay(2000);
}

void loop() {
  delay(1500);

  useless.DoSomethingUseless();
 

}
