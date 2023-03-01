int timer = 0; //keeps track of target time
int buttonState = 0; //sets state of button to off
int lightupduration = 1000; //length of timer in ms, how long LED is lit up for

void setup() //setup for checking button press status
{
  Serial.begin(9600);
  pinMode(2, INPUT); //output button push status
  pinMode(LED_BUILTIN, OUTPUT); //setup LED power pin
}

void loop()
{
buttonState = digitalRead(2);

if (buttonState == 1) {
  Serial.print("Button is pressed");
  Serial.print('\n');
} else {
  Serial.print("Button is unpressed");
  Serial.print('\n');
}

if (buttonState == HIGH) {
   timer = millis() + lightupduration; //change target time to chosen time from the current time
 }
 if (timer > millis()) {
   digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW); //if time runs out, turn off LED
   }
  delay(10); //delay a little bit to improve performance
}
