//TODO: Add LED countdown for 5 leds based on milis/lightup duration

//INSTRUCTIONS: Turn dial to desired time then press button. Dial sets the time the LED will be lit for.

//SET VARIABLES
int timer = 0; //keeps track of target time
int lightUpDuration = 0; //length of timer in ms
int buttonPin = 2; //button output connected to digital pin 2
int buttonState = 0; //initialize var, set button state to off
int pressed = 1; //HIGH represented as variable to simplify code. 1 means button is pressed, 0 means no
int yellowLED = LED_BUILTIN; //yellow LED, connected to builtin LED pin
int potPin = A0; //potentiometer should be connected to A0 analog pin
int potVal = 0;//read value of potentiometer pin
int lock = 0; //Pressing the button again once the timer is started doesn't affect it

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT); //output button push status as variable
  pinMode(yellowLED, OUTPUT); //setup yellow LED power pin
  pinMode(potPin, INPUT);
}

void loop()
{
buttonState = digitalRead(buttonPin); //store button status as variable

//potentiometer
potVal = analogRead(potPin);
int lightUpDuration = potVal;
lightUpDuration = map(lightUpDuration, 0, 1023, 1000, 10000);
  
//output status of button & dial for debugging
if (buttonState == pressed) {
	Serial.print("Button is pressed. Time: ");
	Serial.print('\n');
	Serial.println(lightUpDuration);
	Serial.println(lock);
} else {
	Serial.print("Button is unpressed. Time: ");
	Serial.print('\n');
	Serial.println(lightUpDuration);
	Serial.println(lock);
}

if (buttonState == pressed && lock == 0) {
  timer = millis() + lightUpDuration; //change target time to chosen time from the current time
  lock = 1;
 }
 if (timer > millis()) {
   digitalWrite(yellowLED, HIGH); //turn on LED
  } else {
   digitalWrite(yellowLED, LOW); //if time runs out, turn off LED
   lock = 0;
   }
  delay(10); //delay a little bit to improve performance
}
