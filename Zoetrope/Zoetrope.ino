const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int onOffSwitchStateSwitchPin = 0;
const int potPin = A0;

int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup(){
  Serial.begin(9600); // open serial port
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchStateSwitchPin, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  
  digitalWrite(enablePin, LOW); // The doesn't spin right away
}

void loop(){
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);
  motorSpeed = analogRead(potPin)/4;
  
  if(onOffSwitchState != previousOnOffSwitchState){
    if(onOffSwitchState == HIGH){
        Serial.print("ON ");
        motorEnabled = !motorEnabled; // it means NOT.motorEnabled (0 or 1)
    }
  }
  
  if (directionSwitchState != previousDirectionSwitchState){
    if (directionSwitchState == HIGH){
      motorDirection = !motorDirection;
    }
  }
  
  if (motorDirection == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
    Serial.print("Direita ");
  }
  
  else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
    Serial.print("Esquerda ");
  }
  
  if (motorEnabled == 1){
    analogWrite(enablePin, motorSpeed);
  }
  else {
    analogWrite(enablePin, 0);
  }
  
  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;
  
}
  
  
  
