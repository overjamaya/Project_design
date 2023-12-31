double Level,Vout,P,Vs=5.0;
double aux;
double tolP=0.04; // Ajusta la medida de presión
int i, rho = 997;
double g=9.8;
#define pin 18

#include "config.h"
AdafruitIO_Feed *Level_M = io.feed("Nivel de agua"); // Medicion Adafruit

void setup()
{
  Serial.begin(9600);
  
  Serial.print("Conectando a Adafruit IO");
  io.connect();
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println(io.statusText());
  
}

void loop() 
{
  io.run();
   //Voltaje del Sensor MPC5010DP
   aux=0;
   for(i=0;i<10;i++){
    aux = aux + (float(analogRead(18))*5.0/1023.0); //v
    delay(5);
   }
   Vout=aux/10.0;
  
  //Presión en Kpa según gráfica 4 del Datasheet
  P = ( Vout - 0.04*Vs ) / (0.09 * Vs) + tolP; //kPa
   
  Level = ((P*1000)/(rho*g))*100;  //Medida de Nivel del tanque
  Level = 1.081349*Level + 0.219574;
  Serial.print("\n\nVoltaje:");
  Serial.print(Vout);
  Serial.println(" v");
  Serial.print("Presión:");
  Serial.print(P);
  Serial.println(" kPa");
  Serial.print("Nivel:");
  Serial.print(Level);
  Serial.println(" cm");

  Level_M->save(Level);
  
  delay(3000);

}
