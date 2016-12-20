// A version of the standard blink test

// define variables
int ledPin = 2;               // pin number on arduino
int delayTime = 1000;         // 1 second blink

//function to control ledPin
void blink(){
  digitalWrite(ledPin, HIGH); // source set to 5v
  delay(delayTime);           // wait..
  digitalWrite(ledPin, LOW);  // source set to 0v
  delay(delayTime);           //wait..
}

//run once function
void setup(){
  pinMode(ledPin, OUTPUT);    // set our pin type
}

//run indefinately
void loop() {
  blink();                    // call led control function
}
