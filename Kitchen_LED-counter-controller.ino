
int relayPin=10;
int lightPin=1;
int lightValue=0;

// smoothReadLight() variables
const int numReadings = 10;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int readDelay=2;                // delay between readings
int total = 0;                  // the running total
int average = 0;                // the average


// the loop routine runs over and over again forever:
void loop() {
  
  smoothReadLight();        // reads light avg value into global variable lightValue
  Serial.print("lightValue=");
  Serial.println(lightValue);  
  delay(100);

  if(lightValue > 500){
    digitalWrite(relayPin, HIGH);
    delay(2000);
  } else {
    digitalWrite(relayPin, LOW);
  }


  
  delay(1);        // delay in between reads for stability
}


void smoothReadLight(){
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(lightPin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  lightValue=average;
}


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(relayPin,OUTPUT);

  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}
