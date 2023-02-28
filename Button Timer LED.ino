int timer = 0; //keeps track of target time
int buttonState = digitalRead(2);
int lightupduration = 1000 //sets length of timer in ms, how long LED is lit up for

void setup() //setup for checking button press status
{
  pinMode(2, INPUT); //output button push status
  pinMode(LED_BUILTIN, OUTPUT); //setup LED power pin
}

void loop()
{
buttonState = digitalRead(2);
Serial.println(buttonState)

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
