int motorPin1 = 7; // Azul   - Pino 1 do motor 28BYJ-48
int motorPin2 = 6; // Rosa   - Pino 2 do motor 28BYJ-48
int motorPin3 = 5; // Amarelo - Pino 3 do motor 28BYJ-48
int motorPin4 = 4; // Laranja - Pino 4 do motor 28BYJ-48 
// O pino 5 (Vermelho) é o pino de alimentação do motor de passo (VCC)  

int velocMotor = 1000;  // Variáveis para configurar a velocidade do motor
int contagem = 0;  // Variável usada como contador de passos
int passosPorRotacao = 512;  // Número de passos por rontação completa

int LigaDesliga[8] = {8, 12, 4, 6, 2, 3, 1, 9};

void setup() {
  // Declara os pinos do motor como pinos de saída

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  Serial.begin(9600);
}

void loop(){

  for(int i=0;i<512;i++) sentidoHorario();
  for(int i=0;i<512;i++) sentidoAntiHorario();
  
}

void sentidoAntiHorario(){
  for(int i = 0; i < 8; i++){
    setOutput(i);
    delayMicroseconds(velocMotor);
  }
}

void sentidoHorario(){
  for(int i = 7; i >= 0; i--){
    setOutput(i);
    delayMicroseconds(velocMotor);  // delay em MicroSegundo 1 milisegundo = 1000 microSegundos
  }
}

void setOutput(int out){

  //bitRead gera 1 ou 0
    
  digitalWrite(motorPin1, bitRead(LigaDesliga[out], 0));
  digitalWrite(motorPin2, bitRead(LigaDesliga[out], 1));
  digitalWrite(motorPin3, bitRead(LigaDesliga[out], 2));
  digitalWrite(motorPin4, bitRead(LigaDesliga[out], 3));

 
}
