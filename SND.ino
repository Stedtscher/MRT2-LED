int ledPin = 14;
int SND_Pin = 6;
int zaehler = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(SND_Pin, INPUT);
}

void loop() {
  if (digitalRead(SND_Pin))
  {
    zaehler++;
    if(zaehler >= 100)
    {
      zaehler = 0;
      digitalWrite(ledPin, LOW);
    }
    else if(zaehler >= 50)
    {
      digitalWrite(ledPin, HIGH);
    }
  }

  digitalWrite(ledPin, HIGH);
}