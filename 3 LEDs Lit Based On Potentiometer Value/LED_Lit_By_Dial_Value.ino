int readPin = A5;

void setup()
{
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(A5, INPUT);
}

void loop()
{
  int value = analogRead(readPin);
  Serial.print("Value is: ");
  Serial.println(value);
  if (value < 200) {
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(8, LOW);
  } else if (value >= 200 && value < 600) {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(8, LOW);
  } 
  else {
    digitalWrite(8, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
  delay(10);
}
