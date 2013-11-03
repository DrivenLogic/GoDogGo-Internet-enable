#include <SoftwareSerial.h>

/*

*/

// globals
//SoftwareSerial commandSerial(10, 11);
int throwSignalPin = 7;

///
/// Aurduino's init function
///
void setup()
{
  // configure pins
  pinMode(throwSignalPin, OUTPUT); 
  pinMode(A2, INPUT);
  
  // setup serial communication (high speeds appear unstable)
  Serial.begin(9600);
  //commandSerial.begin(9600);
  
  Serial.print("Setup complete");
}

///
/// The main control loop
///
void loop()
{

  // wait for serial commands
      // is ball ready
      ballIsReady();
      
      // throw
  
  
  delay(1000); // debug
}

///
/// Check for an ready ball.
///
boolean ballIsReady()
{
  // look for zero or a small potental at the microswitch.
  int microSwitchValue = analogRead(A2);
  
  if(microSwitchValue<10) //small analog interferance margin
  {
     Serial.print("Ball is ready, microswitch value was: ");
     Serial.println(microSwitchValue);
     return true;
  }
  
  Serial.print("Ball is NOT ready, microswitch value was: ");
  Serial.println(microSwitchValue);
  return false; 
}

///
/// 
///
void throwBall()
{
  // check that a ball is ready
  if(ballIsReady())
  {
    digitalWrite(throwSignalPin, HIGH); 
    delay(6800); // run motor for 6800 millis 
  }          
}


  
  
  
