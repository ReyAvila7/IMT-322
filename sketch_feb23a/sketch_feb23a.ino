#define LEDROJO 2
#define LEDAMARILLO 3
#define LEDVERDE 4
#define TIME 200
void setup() {
pinMode(LEDROJO, OUTPUT);
pinMode(LEDAMARILLO, OUTPUT);
pinMode(LEDVERDE, OUTPUT);
}

void loop() {
  digitalWrite(LEDROJO, HIGH);
  digitalWrite(LEDAMARILLO,LOW);
  digitalWrite(LEDVERDE,LOW);
  delay(TIME);
  digitalWrite(LEDROJO, LOW);
  digitalWrite(LEDAMARILLO,HIGH);
  digitalWrite(LEDVERDE,LOW);
  delay(TIME);
  digitalWrite(LEDROJO, LOW);
  digitalWrite(LEDAMARILLO,LOW);
  digitalWrite(LEDVERDE,HIGH);
  delay(TIME);
}1
