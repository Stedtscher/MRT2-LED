int Triac_Pin = 3;
int SND_Pin = 6;
int gezaehlt = 0;
int Taster_1 = 0; // Hochsetzen
int Taster_2 = 1; // Runtersetzen
int verzoegerung = 5000;
int loopzaehler = 0;

void setup() {
  pinMode(Triac_Pin, OUTPUT);
  pinMode(SND_Pin, INPUT);
  pinMode(Taster_1, INPUT);
  pinMode(Taster_2, INPUT);
}

void loop() {

  loopzaehler++;
  if (digitalRead(Taster_1) && (loopzaehler >= 100))
  {
   loopzaehler = 0;
   verzoegerung = verzoegerung + 10;
    if (verzoegerung >= 9500)
    {
     verzoegerung = 9500;
    }
  }
  if (digitalRead(Taster_2) && (loopzaehler >= 100))
  {
   loopzaehler = 0;
   verzoegerung = verzoegerung - 10;
    if (verzoegerung <= 100)
    {
     verzoegerung = 100;
    }
  }
  if(!digitalRead(SND_Pin) && !gezaehlt)
  {
    gezaehlt = 1;
  }
  if (digitalRead(SND_Pin) && gezaehlt)
  {
    gezaehlt = 0;

    delayMicroseconds(verzoegerung); //MinimalerZündzeitpunkt
    digitalWrite(Triac_Pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(Triac_Pin, LOW);

  }
}
