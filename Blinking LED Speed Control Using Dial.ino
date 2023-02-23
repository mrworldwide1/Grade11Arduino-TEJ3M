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
    digitalWrite(12, HIGH);
  Serial.print("Value is: ");
  Serial.println(value);
  delay(1000);
}
