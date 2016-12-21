/* Temperature sensor test using a NTC thermistor (seeed v1.2) @5v
 *  
 * The resistance of a thermistor will increase when the ambient temperature decreases. 
 * The detectable range of this sensor is -40 - 125ºC, and the accuracy is ±1.5ºC
 * 
 * Resistance/B-Values calcaulations proivded in seeed.cc documentation
 * http://wiki.seeed.cc/Grove-Temperature_Sensor_V1.2/
 * 
 * Calculation and conversions separated from loop() to test use of functions
 */

#include <math.h>

int tempPin = A0;           // pin for sensor
const int Bvalue = 4275;    // B-constant value of thermistor from datasheet

void setup() {
  Serial.begin(9600);       // for logging.  A0 doesn't need pin mode setting
}

// Calculate the temperature in Celcius from thermistor
float tempCalc(float pinInput){
  float R = 1023.0/((float)pinInput)-1.0;
  R = 100000.0*R;
  float temperature=1.0/(log(R/100000.0)/Bvalue+1/298.15)-273.15;
  return temperature;
}

// convert celcius to fahrenheit
float cToF(float celcius){
  float fahrenheit = (celcius * 1.8) + 32;
  return fahrenheit;
}

// Read the pin, call the calculation function and output
void loop() {
  float pinInput = analogRead(tempPin);
  float celcius = tempCalc(pinInput);
  Serial.print("Temp(c): "); Serial.println(celcius);
  Serial.print("Temp(f): "); Serial.println(cToF(celcius));
  delay(10000);
}
