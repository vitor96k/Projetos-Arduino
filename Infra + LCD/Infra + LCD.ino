#include <IRremote.h>
#include <LiquidCrystal.h>  

LiquidCrystal lcd(2,3,4,5,6,7); //LCD parametros = portas digitais

void mais(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write("MAIS");  
}

void menos(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write("MENOS");  
}

void desconhecido(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write("DESCONHECIDO");
}
  
int pegar = 8; // Porta digital q esta conectado o sendor infra

IRrecv irrecv(pegar);  
decode_results resultado;  
  
void setup(){  
  Serial.begin(9600);
  irrecv.enableIRIn();  // Inicializa o receptor IR    
  lcd.begin(16, 2);   
} 

void loop(){  

  if (irrecv.decode(&resultado)== true){   //Verifica se recebeu algum sinal    
    Serial.print("Valor lido: ");//Mostra código
    Serial.println(resultado.value, HEX);
    if(resultado.value == 0x68733A46) mais();
    else if(resultado.value == 0x83B19366) menos();
    else desconhecido(); 
    irrecv.resume(); // "Descarrega" o valor lido    
  }
  
  delay(300);  
}  
