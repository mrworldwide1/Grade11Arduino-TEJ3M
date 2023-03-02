//TODO: Add LED countdown for 5 leds based on milis/lightup duration
//TODO: Add potentionemter analog read, and set lightupduration to potentionmeter value via MAP function
//TODO: Add potpin for potentiometer referring to https://docs.arduino.cc/learn/electronics/potentiometer-basics

/*
Project to make an LED turn on when button is pressed, but also triggering a timer which will determine how long the LED will stay lit.  
A dial (potentiometer) is used to control the time. Multiple LEDs are utilised as a countdown for the timer.
By: Lucas Leung for TEJ3M0
March 1, 2023
*/

int timer = 0; //keeps track of target time
int buttonState = 0; //stores button on/off state as var, sets button to off
int lightUpDuration = 1000; //length of timer in ms, how long LED is lit up for
int buttonPin = 2; //button output connected to digital pin 2
int yellowLED = LED_BUILTIN; //yellow LED, connected to builtin LED pin

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT); //output button push status to button variable
  pinMode(yellowLED, OUTPUT); //setup yellow LED power pin
}

void loop()
{
buttonState = digitalRead(buttonPin); //store button status as variable

//output status of button for debugging
if (buttonState == 1) {
  Serial.print("Button is pressed");
  Serial.print('\n');
} else {
  Serial.print("Button is unpressed");
  Serial.print('\n');
}

if (buttonState == HIGH) {
   timer = millis() + lightUpDuration; //change target time to chosen time from the current time
 }
 if (timer > millis()) {
   digitalWrite(yellowLED, HIGH); //turn on LED
  } else {
    digitalWrite(yellowLED, LOW); //if time runs out, turn off LED
   }
  delay(10); //delay a little bit to improve performance
}
