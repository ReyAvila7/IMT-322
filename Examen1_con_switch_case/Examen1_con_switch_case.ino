int temporizador = 5;
int volumen = 5;
int cancion = 0;
int Baudrate = 9600;
long RandomNumber;
int play;
int subir;
bool pausa=false;
bool Aleat=true;
/*typedef enum{
  play,
  aleatorio,
  subir,
  bajar
}reproductor;
reproductor FSM = play;*/
void setup()
{
  Serial.begin(Baudrate);
}

void loop(){
 timer();
 play =  Serial.parseInt();
  switch(play){
   case 1:
    pausa = !pausa;
    
    break;
    
   case 2:
    Aleat = !Aleat;
    
    break;
   case 3:
    subirVolumen();
    break;
    
    case 4:
    bajarVolumen();
    break;
  }
    
  
}

void timer(){
 
  Serial.print("Reproduciendo la cancion: ");
  Serial.println(cancion);
  Serial.println("Tiempo de tu rolita bro");
  Serial.println(temporizador);
  if (pausa == false ){
  temporizador= temporizador -1;
  delay(1000);
  }
  else{
  
    temporizador = temporizador;
    Serial.println("su cancion esta en pausa");
    delay(1500);
    
  }
  
 if (temporizador<=0)
 {
    SaltoCancion();
  temporizador = 5;
 
 }
}
void Aleatoriedad(){

  RandomNumber = random(1,100);
  cancion = RandomNumber;
}

void SaltoCancion(){

  if (Aleat == true){
    cancion++;
  }
  else if (Aleat == false){
  
    Aleatoriedad();
  
  }
  
}

void subirVolumen(){

  if (volumen <=9){
  
    volumen++;
  
  Serial.print("El volumen esta en: ");
  Serial.println(volumen);
  }

}
void bajarVolumen(){

  if (volumen >=1){
  
    volumen--;
  
  Serial.print("El volumen esta en: ");
  Serial.println(volumen);
  }
}
