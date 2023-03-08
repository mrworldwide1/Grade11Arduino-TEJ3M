/*
 * https://randomnerdtutorials.com
 * Complete Guide for Ultrasonic Sensor HC-SR04
    Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Pin11
        Echo: Echo (OUTPUT) - Pin 12
        GND: GND
 */
int trigPin = 11;    // Trigger connected to pin 11
int echoPin = 12;    // Echo connected to pin 12
long duration, cm; //setup distance variables
int greenLED = LED_BUILTIN; //green LED, connected to builtin led
int yellowLED = 10; //yellow LED, connected to pin 10
int redLED = 9; //red LED, connected to pin 9
 
void setup() {
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLED, OUTPUT); //setup green LED power pin
  pinMode(redLED, OUTPUT); //setup red LED power pin
  pinMode(yellowLED, OUTPUT); //setup yellow LED power pin
}
 
void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds. Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Read the signal from the sensor: a HIGH pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  // Convert time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  
  // serial monitor debugging
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(50);

//light up LEDs based on distance
 if (cm <= 35) {
    digitalWrite(yellowLED, HIGH); //turn off yellow LED
    digitalWrite(greenLED, HIGH); //turn off green LED
    digitalWrite(redLED, HIGH); //turn off red LED
  } else {
    digitalWrite(yellowLED, LOW); //turn off yellow LED
    digitalWrite(greenLED, LOW); //turn off green LED
    digitalWrite(redLED, LOW); //turn off red LED
  }
  delay(30);

}
