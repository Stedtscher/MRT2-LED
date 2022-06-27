int Triac_Pin = 3;
int SND_Pin = 6;
int gezaehlt = 0;
int Taster_1 = 0; // Hochsetzen
int Taster_2 = 1; // Runtersetzen
int delay = 294;

void setup() {
  pinMode(Triac_Pin, OUTPUT);
  pinMode(SND_Pin, INPUT);
  pinMode(Taster_1, INPUT);
  pinMode(Taster_2, INPUT);
}

void loop() {

  if (digitalRead(Taster_1))
  {
    delay = delay + 1000;
    if(delay >= 9500)
    {
      delay = 9500;
    }
  }
  if (digitalRead(Taster_2))
  {
    delay = delay - 1000;
    if(delay <= 294)
    {
      delay = 294;
    }
  }
  if(!digitalRead(SND_Pin) && !gezaehlt)
  {
    gezaehlt = 1;
  }
  if (digitalRead(SND_Pin) && gezaehlt)
  {
    gezaehlt = 0;
    delayMicroseconds(delay);
    digitalWrite(Triac_Pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(Triac_Pin, LOW);
  }
}