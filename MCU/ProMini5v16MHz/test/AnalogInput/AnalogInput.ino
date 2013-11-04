/*
  Read the voltage and time of the GDG motor run signal.
  Shows and analog read converted to voltage and a stopwatch.
*/
 
unsigned long startTime;                    // start time for stop watch
unsigned long elapsedTime;                  // elapsed time for stop watch
boolean isTimerRunning = false;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("waiting for a voltage over 0.1");
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  
  if(voltage > 1) // dont run the timer without a signal.
  {
    if(!isTimerRunning)
    {
      startTime = millis(); 
      isTimerRunning = true;
      Serial.println("startTime");
      Serial.println(startTime);
    }
    
    Serial.println(voltage);
  }
  else
  {
    if((voltage < 1)&&(isTimerRunning))
    {
      elapsedTime = millis() - startTime;
      Serial.println("elapsedTime");
      Serial.println(elapsedTime);
      isTimerRunning = false;
    }
  }
}
