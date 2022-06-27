int Triac_Pin = 3;
int SND_Pin = 6;
int zaehler = 0;
int an = 1;
int gezaehlt = 0;

void setup() {
  pinMode(Triac_Pin, OUTPUT);
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
      delayMicroseconds(10);
      digitalWrite(Triac_Pin, LOW);
    }
    else if((zaehler >= 50) && an)
    {
    delayMicroseconds(10);
      digitalWrite(Triac_Pin, HIGH);
      an = 0;
    }
  }
}