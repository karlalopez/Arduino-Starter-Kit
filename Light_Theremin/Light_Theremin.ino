int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
const int ledPin = 13; // we will set up an indicator that the sensor has finished calibrating, using the onboard led connected to pin 13.

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // callibration beggins
  while (millis() < 5000) {
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh - sensorValue;
    }
    if (sensorValue < sensorLow); {
      sensorLow = sensorValue;
    }
  }
  digitalWrite(ledPin, LOW); // calibration ends
}

void loop() {
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue,sensorLow,sensorHigh, 0, 4000); // the last 2 values here change the frequencies
  tone (8,pitch,2000); // the variables are: pin, sound frequency and how long to play the note
  delay(10); // for how long it will play
  Serial.print ("Sensor Value: ");
  Serial.print (sensorValue);
  Serial.print ("  ");
}

