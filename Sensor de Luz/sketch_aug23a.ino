int verde = 7;
int azul = 2;
int sensor = 0;
int armazenar = 0;


void apagaLeds() {
  digitalWrite(verde,LOW);
  digitalWrite(azul,LOW);
}


void setup() {
  
  pinMode(verde,OUTPUT);
  pinMode(azul,OUTPUT);
 
  apagaLeds();
  Serial.begin(9600);


}

void loop() {

 
  armazenar = analogRead(sensor);  
                                                                                        
  Serial.print("\nLendo valor...");  //   Imprime no monitor serial
  Serial.print(armazenar);  // Mostra o valor lido pela porta serial

  if(armazenar < 900){
    apagaLeds();   
    digitalWrite(verde,HIGH);
  } 

  else{   
    apagaLeds();
    digitalWrite(azul,HIGH);
  }
  
 
  delay(100);  // Aguarda 1 segundo

 

}
