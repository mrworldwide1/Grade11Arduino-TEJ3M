int buttonState = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(2); //read state of the push button
  Serial.println(buttonState);
  if (buttonState == HIGH ){
    digitalWrite(13, HIGH);
  }
  else {
    digitalWrite(13, LOW);
  }
  delay (10);
}
