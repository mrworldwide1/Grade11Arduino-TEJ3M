int timer = 0; //keeps track of target time
int buttonState = digitalRead(2);

void setup()
{
  pinMode(2, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
buttonState = digitalRead(2);

if (buttonState == HIGH) {
   timer = millis() + 1000; //change targest time to 1s from the current time
 }
 if (timer > millis()) {
   digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
   }
  delay(10); //delay a little bit to improve performance
}
