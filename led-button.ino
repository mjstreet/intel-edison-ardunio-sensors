// Button to turn LED on/off.
// The button and LED have seperate circuits so the switching is controlled here

//define variables
int ledPin = 2;               // led pin number on arduino
int ledState = 0;             // set & track led status (off at start)

int buttonPin = 3;            // button pin number on arduino
int buttonState = 0;          // set & track button status (off at start)

//run once function
void setup(){
  Serial.begin(9600);         // setup Serial read for debugging
  pinMode(ledPin, OUTPUT);    // led pin type
  pinMode(buttonPin, INPUT);  // button pin type
}

//run indefinately
void loop() {
  //capture button click
  if ((buttonState == 0) && (digitalRead(buttonPin) == 1)){   // was the button released last loop AND is it pressed now?
    ledState = 1-ledState;                                    // if yes.. switch led state
    digitalWrite(ledPin, ledState);                           // write the new state to ledpin
  }
  buttonState = digitalRead(buttonPin);                       // each loop, set buttonState
  Serial.println(buttonState);                                // ..and log to Serial
  delay(100);                                                 // make serial easier to read
}
