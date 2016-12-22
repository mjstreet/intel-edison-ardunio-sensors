/* Simple Sound sensor test using a seeed Grove Sound Sensor running@5v
 * A  simple microphone based on the LM358 amplifier and an electret microphone. 
 * 
 * 1. Monitors sensor data to log sounds above threshold volume
 * 2. Highlight events with a single LED flash
 * 
 */

int   soundPin = A0;          // pin for sensor
int   ledPin = 7;             // pin for LED
int   threshold = 415;        // threshold for ambient noise
int   volNow,threshDiff = 0;  // calculation variables

void setup() {
  Serial.begin(9600);         // sensor output
  pinMode(ledPin, OUTPUT);    // pin type
}

void loop() {
  volNow = analogRead(soundPin);
  threshDiff = volNow-threshold;
  if (volNow >= threshold){                         // check if volume is greater than tolerance
    digitalWrite(ledPin, HIGH);                     // turn LED on
    Serial.print(volNow); Serial.print("(+");       // output text
    Serial.print(threshDiff);Serial.println(")");
    delay(1000);                                    //keep the LED a bit longer, slow loop down
  }
  else{
     digitalWrite(ledPin, LOW);                     // turn LED off
  }
}
