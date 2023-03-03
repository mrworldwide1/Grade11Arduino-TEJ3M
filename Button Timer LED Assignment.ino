//TODO: Add LED countdown for 5 leds based on milis/lightup duration

//TASK: Create a circuit where when a button is pressed an LED will turn on. This also triggers a timer which will determine how long the LED will stay lit. 
//A dial (potentiometer) can be used to control the time.

//VARIABLES
int timer = 0; //keeps track of target time
int lightUpDuration = 0; //length of timer in ms
int buttonPin = 2; //button output connected to digital pin 2
int buttonState = 0; //initialize var, set button state to off
int pressed = 1; //HIGH represented as variable to simplify code.
int yellowLED = LED_BUILTIN; //yellow LED, connected to builtin LED pin
int potPin = A0; //potentiometer should be connected to A0 analog pin
int potVal = 0;//read value of potentiometer pin
int lock = 0; //Pressing the button again once the timer is started doesn't affect it

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT); //output button push status as variable
  pinMode(yellowLED, OUTPUT); //setup yellow LED power pin
  pinMode(potPin, INPUT); //out button potentiometer status as variable
}

void loop()
{
buttonState = digitalRead(buttonPin); //store button status as variable

//potentiometer
potVal = analogRead(potPin);
int lightUpDuration = potVal;
lightUpDuration = map(lightUpDuration, 0, 1023, 1000, 10000);
  
//print status of button, timer & potentiometer to serial monitor for debugging.
if (buttonState == pressed) {
  if (lock == 1) {
    Serial.print("Button pressed & locked. Time (ms): ");
    Serial.println(lightUpDuration);
	//Serial.println(timer);
	//Serial.println(millis());
  } else {
    Serial.print("Button pressed & unlocked. Time (ms): ");
    Serial.println(lightUpDuration);
    //Serial.println(timer);
	//Serial.println(millis());
  }
} else {
	if (lock == 1) {
	Serial.print("Button unpressed & locked. Time (ms): ");
    Serial.println(lightUpDuration);
    //Serial.println(timer);
	//Serial.println(millis());
    } else {
    Serial.print("Button unpressed & unlocked. Time (ms): ");
   	Serial.println(lightUpDuration);
    //Serial.println(timer);
	//Serial.println(millis());
    }
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
