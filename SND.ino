int ledPin = 14;
int SND_Pin = 0;
int speicher = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(SND_Pin, INPUT);
}

void loop() {
  speicher = digitalRead(SND_Pin);
  digitalWrite(ledPin, speicher);
}