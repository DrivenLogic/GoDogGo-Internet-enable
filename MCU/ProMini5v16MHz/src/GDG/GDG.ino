#include <SoftwareSerial.h>

/*

Arduino code for GDG automation

*/

// globals
SoftwareSerial commandSerial(10, 11); // RX, TX
int throwSignalPin = 6;
boolean throwInProgress = false;
int microSwitchReadPin = A2;
int serialCommandByte;
int analogInterferenceMargin = 100;

///
/// Aurduino's setup (init) function
///
void setup()
{
  // configure pins
  pinMode(throwSignalPin, OUTPUT); 
  digitalWrite(throwSignalPin, LOW); 
  
  pinMode(A2, INPUT);
  
  // setup serial communication (high speeds appear unstable)
  Serial.begin(9600);
  commandSerial.begin(9600);
  
  Serial.println("Setup complete");
}

///
/// The main control loop
///
void loop()
{
  if(throwInProgress==false)
  {
    // read the oldest byte from the serial command buffer
    serialCommandByte = commandSerial.read();
    
    // if it's a 'T' that is a throw command:
    if (serialCommandByte == 'T') {
      throwInProgress = true;
        throwBall(); // blocking call
      throwInProgress = false;
    } 
    
    // if it's a 'B' that is ball query command:
    if (serialCommandByte == 'B') {
      ballIsReady();
    } 
  }
}

///
/// Check for an ready ball - deals with serial notifications etc.
///
boolean ballIsReady()
{
  if(microSwitchIsClosed()) //small analog interferance margin
  {
     Serial.println("Ball is ready");
     commandSerial.println("B1");
     return true;
  }
  
  Serial.println("Ball is NOT ready");
  commandSerial.println("B0");
  return false; 
}

///
/// Issues the throw signal
///
void throwBall()
{
  // check that a ball is ready
  if(microSwitchIsClosed())
  {
    commandSerial.println("T1");
    Serial.println("Starting throw...");
    digitalWrite(throwSignalPin, HIGH); 
    
      // send the motor signal while the switch remains closed.
      // this is the same behaviour as the onboard PIC16F616
      while(microSwitchIsClosed()){}; 
    
    digitalWrite(throwSignalPin, LOW); 
    Serial.println("Throw Complete.");
  }
  else
  {
     Serial.println("Can't throw the ball is NOT ready");
     commandSerial.println("T0");
  }
}

///
/// See if the microswitch is open or closed. denotes the presence of a ball. 
///
boolean microSwitchIsClosed()
{
  // look for zero or a small potental at the microswitch.
  int microSwitchValue = analogRead(microSwitchReadPin);
  
  Serial.print("microSwitchValue: ");
  Serial.println(microSwitchValue);
     
  if(microSwitchValue<analogInterferenceMargin) //small analog interferance margin
  {
    return true;
  }
  
  return false;
}


  
  
  
