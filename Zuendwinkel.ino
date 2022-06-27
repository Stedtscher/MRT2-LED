int Triac_Pin = 3;
int SND_Pin = 6;
int gezaehlt = 0;
int Taster_1 = 0; // Hochsetzen
int Taster_2 = 1; // Runtersetzen
int verzoegerung = 294;

void setup() {
  pinMode(Triac_Pin, OUTPUT);
  pinMode(SND_Pin, INPUT);
  pinMode(Taster_1, INPUT);
  pinMode(Taster_2, INPUT);
}

void loop() {

  if (digitalRead(Taster_1))
  {
   delay(333);
   verzoegerung = verzoegerung + 1000;
    if verzoegerung >= 9500)
    {
     verzoegerung = 9500;
    }
  }
  if (digitalRead(Taster_2))
  {
   delay(333);
   verzoegerung = verzoegerung - 1000;
    if verzoegerung <= 294)
    {
     verzoegerung = 294;
    }
  }
  if(!digitalRead(SND_Pin) && !gezaehlt)
  {
    gezaehlt = 1;
  }
  if (digitalRead(SND_Pin) && gezaehlt)
  {
    gezaehlt = 0;

   delayMicroseconds verzoegerung); //MinimalerZündzeitpunkt
    digitalWrite(Triac_Pin, HIGH);
   delayMicroseconds(10);
    digitalWrite(Triac_Pin, LOW);
  }
}
