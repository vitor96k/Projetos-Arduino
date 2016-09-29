#include <LiquidCrystal.h> 

LiquidCrystal lcd(2,3,4,5,6,7); //LCD parametros = portas digitais

int sensor = 0;
float temp;
int t=0;

void exibir(){

  lcd.setCursor(0,0);
  lcd.write("  Temperatura");
  lcd.setCursor(0,1);  
  
}


void setup() {
 
  lcd.begin(16, 2);  
  exibir();
  
  
}

void loop() {

  temp = analogRead(sensor);
  temp = (5.0 * temp * 100.0)/1024.0; 
  exibir();
  lcd.print("     ");
  lcd.print(temp);
  lcd.print(" C");  
  delay(1000);
  lcd.clear();

 

  
}
