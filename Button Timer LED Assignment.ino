//TODO: Add LED countdown for 5 leds based on milis/lightup duration
//TODO: Add potentionemter analog read, and set lightupduration to potentionmeter value via MAT
//TODO: Add potpin for potentiometer referring to https://docs.arduino.cc/learn/electronics/potentiometer-basics

//SET VARIABLES
int timer = 0; //keeps track of target time
int lightUpDuration = 0; //length of timer in ms
int buttonPin = 2; //button output connected to digital pin 2
int buttonState = 0; //initialize var, set button state to off
int pressed = 1; //HIGH represented as variable to simplify code. 1 means button is pressed, 0 means no
int yellowLED = LED_BUILTIN; //yellow LED, connected to builtin LED pin
int on = 1; //for the LEDs, HIGH is represented as variable
int off = 0;//for the LEDs, LOW is represented as variable
int potPin = A0; //potentiometer should be connected to A0 analog pin
int potVal = analogRead(potPin); //read value of potentiometer pin

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT); //output button push status as variable
  pinMode(yellowLED, OUTPUT); //setup yellow LED power pin
}

void loop()
{
buttonState = digitalRead(buttonPin); //store button status as variable

////////////
potVal = analogRead(potPin);
int lightUpDuration = potVal;
lightUpDuration = map(lightUpDuration, 0, 1023, 1000, 10000);
//////////////
  
//output status of button for debugging
if (buttonState == pressed) {
  Serial.print("Button is pressed");
  Serial.print('\n');
  Serial.println(lightUpDuration);
} else {
  Serial.print("Button is unpressed");
  Serial.print('\n');
  Serial.println(lightUpDuration);

}

if (buttonState == pressed) {
   timer = millis() + lightUpDuration; //change target time to chosen time from the current time
 }
 if (timer > millis()) {
   digitalWrite(yellowLED, on); //turn on LED
  } else {
    digitalWrite(yellowLED, off); //if time runs out, turn off LED
   }
  delay(10); //delay a little bit to improve performance
}
