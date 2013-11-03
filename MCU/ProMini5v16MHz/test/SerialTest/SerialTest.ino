
// A test for running both the primary serial port (on the programming header on a ProMini)
// and a software defined serial port on pins 10 and 11.

#include <SoftwareSerial.h>

SoftwareSerial softwareSerial(10, 11);

// globals
const int ledPin = 13; 
int SerialIncomingByte;     
int SoftwareSerialIncomingByte;

void setup() {
  
  // initialize serial communication (high speeds appear unstable)
  Serial.begin(9600);
  softwareSerial.begin(9600);
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  
  Serial.print("Serial Setup complete");
  softwareSerial.print("SoftwareSerial Setup complete");
}

void loop() {
   
  // see if there's incoming serial data
  if (Serial.available() > 0) {
    
   Serial.print("Serial working");
   
    // read the oldest byte in the serial buffer:
    SerialIncomingByte = Serial.read();
    
    // if it's a capital H (ASCII 72), turn on the LED:
    if (SerialIncomingByte == 'H') {
      digitalWrite(ledPin, HIGH);
    } 
    // if it's an L (ASCII 76) turn off the LED:
    if (SerialIncomingByte == 'L') {
      digitalWrite(ledPin, LOW);
    }
  }
  
  // see if there's incoming serial data:
  if (softwareSerial.available() > 0) {
    
    softwareSerial.print("Software Serial working");
   
    //read the oldest byte in the serial buffer:
    SoftwareSerialIncomingByte = softwareSerial.read();
    
    // if it's a capital H (ASCII 72), turn on the LED:
    if (SoftwareSerialIncomingByte == 'H') {
      digitalWrite(ledPin, HIGH);
    } 
    // if it's an L (ASCII 76) turn off the LED:
    if (SoftwareSerialIncomingByte == 'L') {
      digitalWrite(ledPin, LOW);
    }
  }
}
