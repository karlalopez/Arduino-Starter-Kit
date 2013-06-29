
int switchState = 0;

void setup(){    
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);    
  pinMode(5, OUTPUT);
  pinMode(1, INPUT);
}


void loop(){
  switchState = digitalRead(2);
  if (switchState == LOW) { 
    //the button is not pressed
    digitalWrite(3, HIGH); // green led
    digitalWrite(4, LOW);  // red led
    digitalWrite(5, LOW);  // red led
  }
  else { 
    // the button is pressed
    digitalWrite(3, LOW); // green led
    digitalWrite(4, HIGH);  // red led
    digitalWrite(5, HIGH);  // red led
    delay(250); // wait for 1/4 sec
    // toggle the leds
    digitalWrite(4, LOW);  // red led
    digitalWrite(5, LOW);  // red led
    delay(250); // wait for 1/4 sec
  }
}

