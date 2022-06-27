int ledPin = 14;
int SND_Pin = 6;
int zaehler = 0;
int an = 1;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(SND_Pin, INPUT);
}

void loop() {
  if (digitalRead(SND_Pin))
  {
    zaehler++;
    if((zaehler >= 50) &&  an)
    {
      digitalWrite(ledPin, HIGH);
    }
    if(zaehler >= 100)
    {
      an = 0;
      zaehler = 0;
      digitalWrite(ledPin, LOW);
    }
  }

  digitalWrite(ledPin, HIGH);
}