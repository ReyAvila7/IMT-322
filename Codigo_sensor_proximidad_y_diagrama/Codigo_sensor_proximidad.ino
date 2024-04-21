#define echoPin 13
#define trigPin 12
#define BOTON 2
int Baudrate = 9600;
volatile unsigned long lasttime = 0;
volatile unsigned long debounceDelay = 50;

typedef enum{
  ESPERA,
  MEDIR
}lectura;
lectura FSM = ESPERA;
long duracion, distancia;
void setup()
{
Serial.begin(Baudrate);
pinMode(BOTON, INPUT_PULLUP);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
digitalWrite(trigPin, LOW);
attachInterrupt(digitalPinToInterrupt(BOTON), CAMBIO_DE_ESTADO, RISING);
}
void loop(){
        switch (FSM){
          case ESPERA:
          Serial.println("El sensor no está midiendo");
          delay(3000);
          break;
          case MEDIR:
          for (int i=1, i=10,i++)
          {
          digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
          duracion = pulseIn(echoPin, HIGH);
          distancia = duracion/59;
          Serial.println("El sensor esta midiendo a: ");
          Serial.println(distancia);
          FSM = ESPERA;  
          break;
          }
      }
    
  }
void CAMBIO_DE_ESTADO()
{
    if (millis() - lasttime > debounceDelay) {
    FSM=MEDIR;
    lasttime = millis();
  }
}
  
