int ledPin = 14;
int inPin = 0;
int speicher = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT);
}

void loop() {
  speicher = digitalRead(inPin);
  digitalWrite(ledPin, speicher);
}