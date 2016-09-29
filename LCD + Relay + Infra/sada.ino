#include <IRremote.h>
#include <LiquidCrystal.h>  

LiquidCrystal lcd(2,3,4,5,6,7); //LCD parametros = portas digitais

void mais(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write("ACESO");  
}

void menos(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write("APAGADO");  
}

void desconhecido(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write("OPERACAO");
  lcd.setCursor(0,1);
  lcd.write("NEGADA");
}
  
int pegar = 8; // Porta digital q esta conectado o sendor infra
int rele = 9;

void acender(){
  digitalWrite(rele,0);
}

void apagar(){
  digitalWrite(rele,1);
}

IRrecv irrecv(pegar);  
decode_results resultado;  
  
void setup()  
{  
  pinMode(rele,OUTPUT);
   
  
  Serial.begin(9600);
  irrecv.enableIRIn();  // Inicializa o receptor IR    
  lcd.begin(16, 2);  
  
 
}  
void loop(){  
  
  if (irrecv.decode(&resultado)== true){   //VerdigitalWrite(rele,1);ifica se recebeu algum sinal    
    Serial.print("Valor lido: ");//Mostra código
    Serial.println(resultado.value, HEX);
    if(resultado.value == 0x68733A46){ 
      acender();
      mais();
    }else if(resultado.value == 0x83B19366){
      apagar();
      menos();
    }else desconhecido(); 
    irrecv.resume(); // "Descarrega" o valor lido    
  }
  
  delay(300);  
}  

