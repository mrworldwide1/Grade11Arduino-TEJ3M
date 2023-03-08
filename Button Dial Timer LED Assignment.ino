//TASK: Create a circuit where when a button is pressed an LED will turn on. Also triggers a timer which will determine how long the LED will stay lit. A dial (potentiometer) used to control the time.

int buttonPin = 2; //button connected to digital pin 2
int buttonState = 0; //define variable. set button state to off
int pressed = 1; //HIGH represented as variable to simplify code
int lock = 0; //Pressing the button again once the timer is started doesn't affect it
int blueLED = 10; //blue LED, connected to pin 10
int yellowLED = 12; //yellow LED, connected to pin 12
int greenLED = 11; //green LED, connected to pin 11
int redLED = LED_BUILTIN; //red LED, connected to builtin LED pin
int potPin = A0; //potentiometer connected to A0 analog pin
int potVal = 0;//read value of potentiometer pin
int lightUpDuration = 0; //define variable. length of timer in ms, selected by dial
long totalTime = 0; //define variable. keeps track of target time for LED countdown. Using long instead of int so the value doesn't overflow.
long storedMillis = 0; //needed for LED countdown. Using long instead of int to ensure it doesn't overflow. While debugging via serial monitor output, I found that storedMillis turned negative which broke the countdown.
//Arduino UNO stores a range of -32,768 to 32,767 for int. That's insufficent for this circuit given that 1000ms is 1 second, so the circuit could only run for up to 32.7 seconds before it breaks. Whereas long goes up to 2 billion.
int divideVar = 0; //define variable, required for LED countdown

void setup()
{
  Serial.begin(9600);
  pinMode(blueLED, OUTPUT); //setup blue LED power pin
  pinMode(yellowLED, OUTPUT); //setup yellow LED power pin
  pinMode(greenLED, OUTPUT); //setup green LED power pin
  pinMode(redLED, OUTPUT); //setup red LED power pin
  pinMode(buttonPin, INPUT); //output button push status as variable
  pinMode(potPin, INPUT); //setup potentiometer status as variable
}

void loop()
{
buttonState = digitalRead(buttonPin); //store button status as variable

//potentiometer setup
potVal = analogRead(potPin);
int lightUpDuration = potVal;
lightUpDuration = map(lightUpDuration, 0, 1023, 1000, 10000); //dial can set the time from 1 second to 10 seconds. 1000ms(1s)-10000ms(10s)
  
//print serial monitor status of button & potentiometer for debugging. To debug millis, totalTime or storedMillis, uncomment the respective lines
if (buttonState == pressed) {
  if (lock == 1) {
    Serial.print("Button pressed & locked. Time set (ms): ");
    Serial.println(lightUpDuration);
	  //Serial.println(totalTime);
	  //Serial.println(millis());
    //Serial.println(storedMillis);
  } else {
    Serial.print("Button pressed & unlocked. Time set (ms): ");
    Serial.println(lightUpDuration);
    //Serial.println(totalTime);
	  //Serial.println(millis());
    //Serial.println(storedMillis);
  }
} else {
    if (lock == 1) {
    Serial.print("Button unpressed & locked. Time set (ms): ");
    Serial.println(lightUpDuration);
	  //Serial.println(totalTime);
	  //Serial.println(millis());
    //Serial.println(storedMillis);
    } else {
    Serial.print("Button unpressed & unlocked. Time set (ms): ");
    Serial.println(lightUpDuration);
  	//Serial.println(totalTime);
  	//Serial.println(millis());
    //Serial.println(storedMillis);
    }
}

//TURN ON AND TURN OFF LEDs, DISPLAYING COUNTDOWN EFFECT
//EXPLANATION: to get countdown effect working for the 4 LEDs each LED turns on at 4 intervals. specifically, when 100% of the timer remains, when 75% remains, 50% remains, 25%, and lastly 0%.
//Example: 2000ms millis & dial set to 5000ms. all LEDs will turn off once millis reaches 7000ms. there are 4 LEDs so divide dial time by 4 (5000/4 = 1000). immediately after pressing button, blue LED is lit.
//then, when millis reaches 4000ms, green LED is lit. At 5000ms, yellow LED is lit. 6000ms, red LED is lit. at 7000ms, all LEDs are turned off.
//2000ms + 1000ms = 3000ms, 2000ms + (1000ms + 1000ms) = 4000ms, 2000ms + (1000ms + 1000ms + 1000ms) = 5000ms, etc.

if (buttonState == pressed && lock == 0) {
 lock = 1; //pressing the button won't do anything until countdown is over
 storedMillis = millis(); //notes millis when the button was pressed
 divideVar = lightUpDuration / 4; //4 LEDs used
 totalTime = storedMillis + lightUpDuration; //determine when all LEDs will turn off
 }

 if (millis() <= (storedMillis + divideVar)) {
   digitalWrite(blueLED, HIGH); //turn on blue LED at start of countdown
   digitalWrite(greenLED, LOW); //turn off green LED
   digitalWrite(yellowLED, LOW); //turn off yellow LED
   digitalWrite(redLED, LOW); //turn off red LED
  } else if ((millis() > (storedMillis + divideVar)) && (millis() <= (storedMillis + divideVar + divideVar))) {
   digitalWrite(blueLED, LOW); //turn off blue LED
  digitalWrite(greenLED, HIGH); //turn on green LED
   digitalWrite(yellowLED, LOW); //turn off yellow LED
   digitalWrite(redLED, LOW); //turn off red LED
  } else if ((millis() > (storedMillis + divideVar + divideVar)) && (millis() <= (storedMillis + divideVar + divideVar + divideVar))) {
   digitalWrite(blueLED, LOW); //turn off blue LED
    digitalWrite(greenLED, LOW); //turn off green LED
   digitalWrite(yellowLED, HIGH); //turn on yellow LED
   digitalWrite(redLED, LOW); //turn off red LED
  } else if ((millis() > (storedMillis + divideVar + divideVar + divideVar)) && (millis() < totalTime)) {
   digitalWrite(blueLED, LOW); //turn off blue LED
   digitalWrite(yellowLED, LOW); //turn off yellow LED
   digitalWrite(greenLED, LOW); //turn off green LED
   digitalWrite(redLED, HIGH); //turn on red LED
 } else if (millis() >= totalTime) {
   digitalWrite(blueLED, LOW); //turn off blue LED
   digitalWrite(yellowLED, LOW); //turn off yellow LED
   digitalWrite(greenLED, LOW); //turn off green LED
   digitalWrite(redLED, LOW); //turn off red LED
   lock = 0; //unlocks button. Pressing it can now start the countdown again.
 }
  delay(10); //delay a little bit to improve performance
}
