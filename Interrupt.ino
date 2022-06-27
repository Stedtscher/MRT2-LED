int Triac_Pin = 3;
int interrupt = 9;
int Taster_1 = 0; // Hochsetzen
int Taster_2 = 1; // Runtersetzen
int delay = 294;

void setup() {
  pinMode(Triac_Pin, OUTPUT);
  attachInterrupt(digitalPintoInterrupt(interrupt), zuenden, RISING);
  pinMode(Taster_1, INPUT);
  pinMode(Taster_2, INPUT);
}

void loop() {

  if (digitalRead(Taster_1))
  {
    delay(333);
    delay = delay + 1000;
    if(delay >= 9500)
    {
      delay = 9500;
    }
  }
  if (digitalRead(Taster_2))
  {
    delay(333);
    delay = delay - 1000;
    if(delay <= 294)
    {
      delay = 294;
    }
}
void zuenden()
{
    delayMicroseconds(delay); //MinimalerZündzeitpunkt
    digitalWrite(Triac_Pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(Triac_Pin, LOW);
}
