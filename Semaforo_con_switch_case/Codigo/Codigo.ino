#define pinROJO 13
#define pinAMARILLO 12
#define pinVERDE 11
int Baudrate = 9600;
typedef enum{
  ROJO,
    AMARILLO,
    VERDE
} semaforo;
//int dato = 0;
semaforo FSM = ROJO;
void setup()
{
Serial.begin(Baudrate);
pinMode(pinVERDE,OUTPUT);
pinMode(pinAMARILLO,OUTPUT);
pinMode(pinROJO,OUTPUT);

}


void loop(){
  switch (FSM){
      case ROJO:
        digitalWrite(pinVERDE,HIGH);
        digitalWrite(pinAMARILLO,LOW);
        digitalWrite(pinROJO,LOW);
        delay(2000);
        FSM = AMARILLO;
        break;
      case AMARILLO:
        digitalWrite(pinVERDE,LOW);
        digitalWrite(pinAMARILLO,HIGH);
        digitalWrite(pinROJO,LOW);
        delay(1000);
        FSM = VERDE;
        break;
      case VERDE:
        digitalWrite(pinVERDE,LOW);
        digitalWrite(pinAMARILLO,LOW);
        digitalWrite(pinROJO,HIGH);
        delay(2000);
        FSM = ROJO;
        break;
  }
}
