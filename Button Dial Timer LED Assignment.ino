//TODO: Add LED countdown for 5 leds based on milis/lightup duration https://www.w3schools.com/cpp/cpp_switch.asp
//TASK: Create a circuit where when a button is pressed an LED will turn on. 
//This also triggers a timer which will determine how long the LED will stay lit. 
//A dial (potentiometer) can be used to control the time.

int buttonPin = 2; //button connected to digital pin 2
int buttonState = 0; //initialize variable, set button state to off
int pressed = 1; //HIGH represented as variable to simplify code
int greenLED = 10; //green LED, connected to pin 10
int yellowLED = 11; //yellow LED, connected to pin 11
int orangeLED = 12; //orange LED, connected to pin 12
int redLED = LED_BUILTIN; //red LED, connected to builtin LED pin
int potPin = A0; //potentiometer connected to A0 analog pin
int potVal = 0;//read value of potentiometer pin
int lightUpDuration = 0; //length of timer in ms
int totalTime = 0; //keeps track of target time
int lock = 0; //Pressing the button again once the timer is started doesn't affect it
int storedMillis = 0; //make LEDs countdown work
int divideVar = 0; //make LEDs countdown work

void setup()
{
  Serial.begin(9600);
  pinMode(greenLED, OUTPUT); //setup green LED power pin
  pinMode(yellowLED, OUTPUT); //setup yellow LED power pin
  pinMode(orangeLED, OUTPUT); //setup orange LED power pin
  pinMode(redLED, OUTPUT); //setup red LED power pin
  pinMode(buttonPin, INPUT); //output button push status as variable
  pinMode(potPin, INPUT); //setup potentiometer status as variable
}

void loop()
{
buttonState = digitalRead(buttonPin); //store button status as variable

//potentiometer
potVal = analogRead(potPin);
int lightUpDuration = potVal;
lightUpDuration = map(lightUpDuration, 0, 1023, 1000, 10000);
  
//print status of button, potentiometer, millis and timer to serial monitor for debugging
if (buttonState == pressed) {
  if (lock == 1) {
    Serial.print("Button pressed & locked. Time set (ms): ");
    Serial.println(lightUpDuration);
	//Serial.println(totalTime);
	//Serial.println(millis());
  } else {
    Serial.print("Button pressed & unlocked. Time set (ms): ");
    Serial.println(lightUpDuration);
    	//Serial.println(totalTime);
	//Serial.println(millis());
  }
} else {
    if (lock == 1) {
    Serial.print("Button unpressed & locked. Time set (ms): ");
    Serial.println(lightUpDuration);
	//Serial.println(totalTime);
	//Serial.println(millis());
    } else {
    Serial.print("Button unpressed & unlocked. Time set (ms): ");
    Serial.println(lightUpDuration);
	//Serial.println(totalTime);
	//Serial.println(millis());
    }
}

//TURN ON AND TURN OFF LEDs, DISPLAYING COUNTDOWN
if (buttonState == pressed && lock == 0) {
 lock = 1; //during the countdown, pressing the button won't start another one
 storedMillis = millis(); //notes millis when the button was pressed
 divideVar = lightUpDuration / 4; //4 LEDs used
 totalTime = storedMillis + lightUpDuration; //change target time to chosen time from the current time
 }
 if (millis() <= (storedMillis + divideVar)) {
   digitalWrite(greenLED, HIGH); //turn on green LED at start of countdown
   digitalWrite(yellowLED, LOW); //turn off yellow LED
   digitalWrite(orangeLED, LOW); //turn off orange LED
   digitalWrite(redLED, LOW); //turn off red LED
  } else if ((millis() > (storedMillis + divideVar)) && (millis() <= (storedMillis + divideVar + divideVar))) {
   digitalWrite(greenLED, LOW); //turn off green LED
   digitalWrite(yellowLED, HIGH); //turn on yellow LED
   digitalWrite(orangeLED, LOW); //turn off orange LED
   digitalWrite(redLED, LOW); //turn off red LED
  } else if ((millis() > (storedMillis + divideVar + divideVar)) && (millis() <= (storedMillis + divideVar + divideVar + divideVar))) {
   digitalWrite(greenLED, LOW); //turn off green LED
   digitalWrite(yellowLED, LOW); //turn off yellow LED
   digitalWrite(orangeLED, HIGH); //turn on orange LED
   digitalWrite(redLED, LOW); //turn off red LED
  } else if ((millis() > (storedMillis + divideVar + divideVar + divideVar)) && (millis() < totalTime)) {
   digitalWrite(greenLED, LOW); //turn off green LED
   digitalWrite(yellowLED, LOW); //turn off yellow LED
   digitalWrite(orangeLED, LOW); //turn off orange LED
   digitalWrite(redLED, HIGH); //turn on red LED
 } else if (millis() >= totalTime) {
   digitalWrite(greenLED, LOW); //turn off green LED
   digitalWrite(yellowLED, LOW); //turn off yellow LED
   digitalWrite(orangeLED, LOW); //turn off orange LED
   digitalWrite(redLED, LOW); //turn off red LED
   lock = 0;
 }
  delay(10); //delay a little bit to improve performance
}
