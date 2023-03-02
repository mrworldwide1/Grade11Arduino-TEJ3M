//TODO: Add LED countdown for 5 leds based on milis/lightup duration
//TODO: Add potentionemter analog read, and set lightupduration to potentionmeter value via MAT
//TODO: Add potpin for potentiometer referring to https://docs.arduino.cc/learn/electronics/potentiometer-basics

int timer = 0; //keeps track of target time
int buttonState = 0; //initialize var, set button to off
int lightUpDuration = 1000; //length of timer in ms, how long LED is lit up for
int buttonPin = 2; //button output connected to digital pin 2
int yellowLED = LED_BUILTIN; //yellow LED, connected to builtin LED pin
int pressed = 1; //1 means button is pressed, 0 means no

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
if (buttonState == pressed) {
  Serial.print("Button is pressed");
  Serial.print('\n');
} else {
  Serial.print("Button is unpressed");
  Serial.print('\n');
}

if (buttonState == pressed) {
   timer = millis() + lightUpDuration; //change target time to chosen time from the current time
 }
 if (timer > millis()) {
   digitalWrite(yellowLED, HIGH); //turn on LED
  } else {
    digitalWrite(yellowLED, LOW); //if time runs out, turn off LED
   }
  delay(10); //delay a little bit to improve performance
}
