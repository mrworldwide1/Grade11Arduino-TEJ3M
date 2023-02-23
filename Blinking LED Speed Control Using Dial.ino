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
  digitalWrite(12, HIGH);
  delay(value);
  digitalWrite(12, LOW);
  delay(value);
}
