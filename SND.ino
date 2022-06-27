int ledPin = 14;
int SND_Pin = 6;
int zaehler = 0;
int an = 1;
int gezaehlt = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(SND_Pin, INPUT);
}

void loop() {

  if(!digitalRead(SND_Pin) && !gezaehlt)
  {
    gezaehlt = 1;
  }
  if (digitalRead(SND_Pin) && gezaehlt)
  {
    zaehler++;
    gezaehlt = 0;
    if((zaehler >= 100))
    {
      zaehler = 0;
      an = 1;
      digitalWrite(ledPin, LOW);
    }
    else if((zaehler >= 50) && an)
    {
      digitalWrite(ledPin, HIGH);
      an = 0;
    }
  }

  digitalWrite(ledPin, HIGH);
}