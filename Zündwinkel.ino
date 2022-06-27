int Triac_Pin = 3;
int SND_Pin = 6;
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
    gezaehlt = 0;
    delayMicroseconds(294);
    digitalWrite(Triac_Pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(Triac_Pin, LOW);
  }
}