int Triac_Pin = 3;                                                    // Definieren des Pins der mit dem Triac verbunden ist
int interrupt = 9;                                                    // Definieren des Interrupt - Pins
int Taster_1 = 0;                                                     // Definieren des Pins für das Hochsetzen der Lampe
int Taster_2 = 1;                                                     // Definieren des Pins für das Heruntersetzen der Lampe
int verzoegerung = 5000; 
int loopzaehler = 0;                                                  // interne Zählung der Takte
int blinker = 0;                                                      // Interrupt-Interne Zählung der Takte

void setup() {
  pinMode(Triac_Pin, OUTPUT);                                         // Setzen der Pinmodes
  attachInterrupt(digitalPinToInterrupt(interrupt), zuenden, RISING); // Einfügen des Interrupts bei jeder steigenden Flanke des Spannungsnulldruchgangs mit der zugehörigen Interruptroutine: zuenden
  pinMode(Taster_1, INPUT);
  pinMode(Taster_2, INPUT);
}

void loop() {
  loopzaehler++;                                                      // Erhöhung des internen Zählers
  if (digitalRead(Taster_1) && (loopzaehler >= 100 ))                 // Zähler hat bestimmten Wert erreicht und Taster 1 wird gedrückt 
  {
    loopzaehler = 0;                                                  // Zurücksetzen des Zählers
    verzoegerung = verzoegerung + 10;                                 // Verzögerung Erhöhen
  }
  if(verzoegerung >= 7750)                                            // Verzögerung ist über ihrem Maximalwert 
  {
      verzoegerung = 7750;                                            // Verzögerung auf Maximalwert zurücksetzen
  }
  if (digitalRead(Taster_2) && (loopzaehler >= 100 ))                 // Zähler hat bestimmten Wert erreicht und Taster 2 wird gedrückt 
  {
    loopzaehler = 0;                                                  // Zurücksetzen des Zählers
    verzoegerung = verzoegerung - 10;                                 // Verzögerung senken
  }
  if(verzoegerung <= 100)                                             // Verzögerung ist unter ihrem Minimalwert
  {
      verzoegerung = 100;                                             // Verzögerung auf Minimalwert zurücksetzen
  }
}

void zuenden()                                                        // Interruptroutine zum Zünden des Triacs
{
  delayMicroseconds(verzoegerung);                                    // Programm um den Wert von verzoegerung verzögern ( in µs)
  blinker ++;                                                         // Erhöhen des Interrupt-Internen Zählers
  digitalWrite(Triac_Pin, HIGH);                                      // Triac zünden
  delayMicroseconds(10);                                              // Programm für ein Sicheres Zünden des Triacs Verzögern
  digitalWrite(Triac_Pin, LOW);                                       // Gatestrom des Triacs wieder entfernen
  if(blinker >= 100){                                                 // Interrupt-Interner Zähler über einem bestimmten Wert
    digitalWrite(Triac_Pin, LOW);                                     // Gatestrom des Triacs auf 0 halten
    delayMicroseconds(1000000);                                       // Programm verzögern um ein blinken der Lampe zu erreichen
    blinker = 0;                                                      // Interrupt-Interner Zähler wieder zurücksetzen
  }

}
