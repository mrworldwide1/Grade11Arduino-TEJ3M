int readPin = A5;

void setup()
{
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(A5, INPUT);
}

void loop()
{
//check value of potentiometer (dial). Potentiometer is outputting to Pin A5, aka readpin 
  int value = analogRead(readPin);
  Serial.print("Value is: ");
  Serial.println(value);
//light up pin12 LED
  if (value < 200) {
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(8, LOW);
//light up pin13 LED
  } else if (value >= 200 && value < 600) {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(8, LOW);
  } 
  else {
//light up pin8 LED
    digitalWrite(8, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
  delay(10); //delay for stability 
}
