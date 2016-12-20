// Control a LED brightness using the PWM pin and analog potentiometer

//define pins
int ledPin = 3;                           // PWM pin on arduino
int pPin = A0;                            // potentiometer pin

//define vars
int brightness = 0;                       // brightness of led for mapping
int pValue = 0;                           // potentio position

void setup(){}                            // nothing needed for PWM/analog pins

void loop() {
  pValue = analogRead(pPin);
  brightness = map(pValue,0,1023,0,255);  // map this different ranges (0-1023 = potentio), (0-255 = led range)
  analogWrite(ledPin, brightness);        // write the mapped brightness to the LED
  delay(100);                             
}
