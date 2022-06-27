int Triac_Pin = 3;
int interrupt = 9;
int Taster_1 = 0; // Hochsetzen
int Taster_2 = 1; // Runtersetzen
int verzoegerung = 5000;
int loopzaehler = 0;

void setup() {
  pinMode(Triac_Pin, OUTPUT);
  attachInterrupt(digitalPintoInterrupt(interrupt), zuenden, RISING);
  pinMode(Taster_1, INPUT);
  pinMode(Taster_2, INPUT);
}

void loop() {

  if (digitalRead(Taster_1))
  {
    loopzaehler = 0;
    verzoegerung = verzoegerung + 10;
    if(verzoegerung >= 9500)
    {
      verzoegerung = 9500;
    }
  }
  if (digitalRead(Taster_2))
  {
    loopzaehler = 0;
    verzoegerung = verzoegerung - 10;
    if(verzoegerung <= 100)
    {
      verzoegerung = 100;
    }
}
void zuenden()
{
    delayMicroseconds(verzoegerung); //MinimalerZündzeitpunkt
    digitalWrite(Triac_Pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(Triac_Pin, LOW);
}
