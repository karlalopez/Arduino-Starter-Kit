int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
const int ledPin = 13; // This is an indicator that the sensor has finished calibrating, using the onboard led connected to pin 13.

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  while (millis() < 5000) {
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh - sensorValue;
    }
    if (sensorValue < sensorLow); {
      sensorLow = sensorValue;
    }
  }
  digitalWrite(ledPin, LOW);
}

void loop() {
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue,sensorLow,sensorHigh, 0, 4000); 
  tone (8,pitch,2000);
  delay(10);
  Serial.print ("Sensor Value: ");
  Serial.print (sensorValue);
}

