int IN1 = 2; //to control the channel relay, define control pins on the Arduino board (digital signal)

int Pin1 = A0; // analog port defined to receive the analog signal from the moisture sensor

float sensor1Value = 0; // to store the value detected by the sensor

void setup()
{
  Serial.begin(9600); // tells the Arduino to get ready to exchange messages with the Serial Monitor at a data rate of 9600 bits per second

  pinMode(IN1, OUTPUT); // set IN1 to output function

  pinMode(Pin1, INPUT); // set Pin1 to input function

  digitalWrite(IN1, HIGH);  // set digital signal sent to Pin1 to HIGH (=1/On) which sets the armature on the channel relay to normally open 

  delay(500); // moves to next line of code after 500 milliSeconds (Pauses the program for 500 milliSeconds)
}

void loop()
{

  Serial.print("Plant 1 - Moisture Level: "); // prints the phrse between brackets as it is (when using Serial Monitor)
  sensor1Value = analogRead(Pin1); //reads sensor values and stores them in sensor1Value
  Serial.println(sensor1Value); // prints sensor1Value (when using Serial Monitor)

  if (sensor1Value > 450) // Pump works as long as the sensor reads values that are greater than 450
  {
    digitalWrite(IN1, HIGH);
  }
  else 
  {
    digitalWrite(IN1, LOW);
  }
}
