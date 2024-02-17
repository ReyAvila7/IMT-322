int pwmPin = 9; // Pin PWM (puedes cambiarlo según tu placa)
int onTime = 24; // Tiempo de encendido en microsegundos (0.000024 segundos)
int offTime = 16; // Tiempo de apagado en microsegundos (0.000016 segundos)

void setup() {
  pinMode(pwmPin, OUTPUT);
}

void loop() {
  // Enciende el pin PWM durante el tiempo de encendido
  digitalWrite(pwmPin, HIGH);
  delayMicroseconds(onTime);

  // Apaga el pin PWM durante el tiempo de apagado
  digitalWrite(pwmPin, LOW);
  delayMicroseconds(offTime);
}
